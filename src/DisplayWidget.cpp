//
// Created by Guglielmo Fratticioli on 19/09/19.
//

#include "DisplayWidget.h"
#include "Player.h"
#include "DrumKit.h"
#include <QSpacerItem>
#include <QFont>

#define WHEEL_SCROLL_OFFSET 50000.0

AbstractWheelWidget::AbstractWheelWidget(bool touch, QWidget *parent): QWidget(parent), m_currentItem(0), m_itemOffset(0)
{
// ![0]
//NON HO TROVATO UN SIGNAL PER IL TOUCH SCROLL
    //QScroller::grabGesture(this, touch ? QScroller::TouchGesture : QScroller::LeftMouseButtonGesture);
// ![0]
}
AbstractWheelWidget::~AbstractWheelWidget()
{ }
int AbstractWheelWidget::currentIndex() const
{
    return m_currentItem;
}
void AbstractWheelWidget::setCurrentIndex(int index)
{
    if (index >= 0 && index < itemCount()) {
        m_currentItem = index;
        m_itemOffset = 0;
        update();
    }
}
bool AbstractWheelWidget::event(QEvent *e)
{
    switch (e->type()) {
// ![1]
        case QEvent::ScrollPrepare:
        {
            // We set the snap positions as late as possible so that we are sure
            // we get the correct itemHeight
            QScroller *scroller = QScroller::scroller(this);
            scroller->setSnapPositionsX( WHEEL_SCROLL_OFFSET, itemWidth() );

            QScrollPrepareEvent *se = static_cast<QScrollPrepareEvent *>(e);
            se->setViewportSize(QSizeF(size()));
            // we claim a huge scrolling area and a huge content position and
            // hope that the user doesn't notice that the scroll area is restricted
            se->setContentPosRange(QRectF(0.0,0.0,WHEEL_SCROLL_OFFSET * 2,0.0));
            se->setContentPos(QPointF( WHEEL_SCROLL_OFFSET + m_currentItem * itemWidth() + m_itemOffset,0.0));
            se->accept();
            return true;
        }
// ![1]
// ![2]
        case QEvent::Scroll:
        {
            QScrollEvent *se = static_cast<QScrollEvent *>(e);

            qreal x = se->contentPos().x();
            int ix = x - WHEEL_SCROLL_OFFSET;
            int iw = itemWidth();
// ![2]
// ![3]
            // -- calculate the current item position and offset and redraw the widget
            int ic = itemCount();
            if (ic>0) {
                m_currentItem = ix / iw % ic;
                m_itemOffset = ix % iw;
                // take care when scrolling backwards. Modulo returns negative numbers
                if (m_itemOffset < 0) {
                    m_itemOffset += iw;
                    m_currentItem--;
                }
                if (m_currentItem < 0)
                    m_currentItem += ic;
            }
            // -- repaint
            update();

            se->accept();
            return true;
// ![3]
        }
        default:
            return QWidget::event(e);
    }
    return true;
}
void AbstractWheelWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED( event );

    // -- first calculate size and position.
    int w = width();
    int h = height();

    QPainter painter(this);
    QPalette palette = QApplication::palette();
    QPalette::ColorGroup colorGroup = isEnabled() ? QPalette::Active : QPalette::Disabled;

    // paint the items
    painter.setClipRect( QRect( 3, 3, w-6 , h-6 ) );
    painter.setPen(QColor(qRgba(16,16,16,200)));

    int iW = itemWidth();
    int iC = itemCount();
    if (iC > 0) {

        m_itemOffset = m_itemOffset % iW;

        for (int i=-w/2/iW; i<=w/2/iW+1; i++) {

            int itemNum = m_currentItem + i;
            while (itemNum < 0)
                itemNum += iC;
            while (itemNum >= iC)
                itemNum -= iC;

            paintItem(&painter, itemNum, QRect( w/2 +i*iW - m_itemOffset - iW/2,6, iW , h-6 ));
        }
    }

}
/*!
    Rotates the wheel widget to a given index.
    You can also give an index greater than itemCount or less than zero in which
    case the wheel widget will scroll in the given direction and end up with
    (index % itemCount)
*/
void AbstractWheelWidget::scrollTo(int index)
{

    QScroller *scroller = QScroller::scroller(this);

    scroller->scrollTo(QPointF(50000.0 + index * itemWidth(),0 ), 2500);
}

/*!
    \class StringWheelWidget
    \brief The StringWheelWidget class is an implementation of the AbstractWheelWidget class that draws QStrings as items.
    \sa AbstractWheelWidget
*/

BpmSpinBox::BpmSpinBox(QWidget *parent): QWidget(parent), boxLayout(new QHBoxLayout(this)), leftWidget( new QWidget(this)), rightWidget(new QWidget(this))
{
    leftLayout = new QVBoxLayout(leftWidget);
    bpmLabel = new QLabel(leftWidget);

    rightLayout = new QVBoxLayout(rightWidget);
    upBpm = new QPushButton(rightWidget);
    downBpm = new QPushButton(rightWidget);

    rightLayout->setDirection(QVBoxLayout::TopToBottom);
    upBpm->setFlat(true);
    upBpm->setFixedSize(this->height()/3, this->height()/3);
    QIcon upIcon;
    upIcon.addFile(QString("../res/icons/upBpm.png"));
    upBpm->setIcon(upIcon);
    upBpm->setIconSize(upBpm->size());
    rightLayout->addWidget(upBpm);

    downBpm->setIconSize(downBpm->size());
    downBpm->setFlat(true);
    downBpm->setFixedSize(this->height()/3, this->height()/3);
    QIcon downIcon;
    downIcon.addFile(QString("../res/icons/downBpm.png"));
    downBpm->setIcon(downIcon);
    downBpm->setIconSize(downBpm->size());
    rightLayout->addWidget(downBpm);

    rightWidget->setLayout(rightLayout);

    leftLayout->addWidget(bpmLabel);
    QFont serifFont("EditUndoBRK", this->height()/2);
    bpmLabel->setFont(serifFont);
    bpmLabel->setFixedHeight(this->height());

    bpmLabel->setAlignment(Qt::AlignRight);
    leftWidget->setLayout(leftLayout);

    boxLayout->addWidget(leftWidget);
    boxLayout->addWidget(rightWidget);
    this->setLayout(boxLayout);
}
void BpmSpinBox::updateBpm(int Bpm) {
    bpmLabel->setText(QString("%1 BPM").arg(Bpm));
}


StringWheelWidget::StringWheelWidget(bool touch, QWidget* parent)
        : AbstractWheelWidget(touch,parent)
{
    setCurrentIndex(2);
}
QStringList StringWheelWidget::items() const
{
    return m_items;
}
void StringWheelWidget::setItems( const QStringList &items )
{
    m_items = items;
    if (m_currentItem >= items.count())
        m_currentItem = items.count()-1;
    update();
}
QSize StringWheelWidget::sizeHint() const
{
    // determine font size
    QFontMetrics fm(font());

    return QSize( fm.height() * 7 + 6, fm.width("m")/2);
}
QSize StringWheelWidget::minimumSizeHint() const
{
    QFontMetrics fm(font());

    return QSize(fm.width("m"),fm.height());
}
void StringWheelWidget::paintItem(QPainter* painter, int index, const QRect &rect)
{
    painter->drawText(rect, Qt::AlignCenter, m_items.at(index));
}
int StringWheelWidget::itemWidth() const
{
    QFontMetrics fm(font());
    return fm.height()*6;
}
int StringWheelWidget::itemCount() const {
    return m_items.count();
}



DisplayWidget::DisplayWidget(Player* player, DrumKit* drumKit, QWidget *parent): Observer(), QWidget(parent),player(player), drumKit(drumKit),
leftWidget(new QWidget(this)), rightWidget(new QWidget(this)),
boxLayout(new QHBoxLayout(this))
{

    player->addObserver(this);
    drumKit->addObserver(this);

    bpmBox = new BpmSpinBox(leftWidget);
    bpmBox->updateBpm(120);
    connect(bpmBox->getupBpm(), SIGNAL(clicked()), this, SLOT(on_upBpm_clicked()));
    connect(bpmBox->getdownBpm(), SIGNAL(clicked()), this, SLOT(on_downBpm_clicked()));
    saveButton = new QPushButton(leftWidget);
    loadButton = new QPushButton(leftWidget);
    leftLayout = new QVBoxLayout(leftWidget);

    styleButtonWidget = new QWidget(rightWidget);
    styleButtonWidget->setStyleSheet(QString("*{ background-color: #6B8046; }"));
    stylesWheel = new StringWheelWidget(false,rightWidget);
    connect(stylesWheel,SIGNAL(stopped()),this,SLOT(on_style_changed()));

    rightLayout = new QVBoxLayout(rightWidget);
    leftStyle = new QPushButton(styleButtonWidget);
    connect(leftStyle,SIGNAL(clicked()),this,SLOT(on_leftStyle_pressed()));

    QIcon leftIcon;
    leftIcon.addFile(QString("../res/icons/leftStyle.png"));
    leftStyle->setFlat(true);

    leftStyle->setIcon(leftIcon);
    leftStyle->setIconSize(leftStyle->size());
    rightStyle = new QPushButton(styleButtonWidget);
    connect(rightStyle,SIGNAL(clicked()),this,SLOT(on_rightStyle_pressed()));

    QIcon rightIcon;
    rightIcon.addFile(QString("../res/icons/rightStyle.png"));
    rightStyle->setIcon(rightIcon);
    rightStyle->setFlat(true);
    rightStyle->setIconSize(rightStyle->size());
    styleButtonLayout = new QHBoxLayout(styleButtonWidget);


    QStringList genre;
    genre << "Jazz" << "Rock" << "Pop";
    stylesWheel->setItems(genre);
    QFont serifFont("Atari", this->height());
    stylesWheel->setFont(serifFont);

    leftLayout->setDirection(QVBoxLayout::TopToBottom);
    bpmBox->setStyleSheet(QString("*{ background-color: #6B8046; }"));
    bpmBox->setFixedSize(this->width()*2,this->height()*1.6);
    leftLayout->addWidget(bpmBox);

    leftLayout->addWidget(saveButton);
    saveButton->setFlat(true);
    leftLayout->addWidget(loadButton);
    loadButton->setFlat(true);
    leftWidget->setLayout(leftLayout);

    styleButtonLayout->addWidget(leftStyle);
    styleButtonLayout->addItem(new QSpacerItem(this->width()*80/100,0));
    styleButtonLayout->addWidget(rightStyle);
    styleButtonWidget->setLayout(styleButtonLayout);

    rightLayout->setDirection(QVBoxLayout::TopToBottom);
    rightLayout->addWidget(stylesWheel, Qt::AlignTop);
    stylesWheel->setFixedHeight(height()*2.5);
    rightLayout->addWidget(styleButtonWidget);
    rightWidget->setLayout(rightLayout);

    leftWidget->setFixedHeight(this->height()*4);
    rightWidget->setFixedHeight(this->height()*4.45);
    boxLayout->addWidget(leftWidget);
    boxLayout->addWidget(rightWidget);


}
DisplayWidget::~DisplayWidget() {}
void DisplayWidget::obsUpdate() {
    bpmBox->updateBpm(player->getBpm());
    stylesWheel->scrollTo(drumKit->getDrumStyle());
}
void DisplayWidget::on_downBpm_clicked() {
    player->setBpm(player->getBpm()-1);
}
void DisplayWidget::on_upBpm_clicked() {
    player->setBpm(player->getBpm()+1);
}

void DisplayWidget::on_save_pressed(){}
void DisplayWidget::on_load_pressed(){}
void DisplayWidget::on_leftStyle_pressed(){
    if(drumKit->getDrumStyle() != JAZZ) {
        DRUM_STYLE style;
        switch(drumKit->getDrumStyle() -1){
            case 0:  style = JAZZ; break;
            case 1: style = ROCK; break;
            case 2: style = POP; break;
        }
        drumKit->setDrumStyle( style );
    }
}
void DisplayWidget::on_rightStyle_pressed(){
    if(drumKit->getDrumStyle() != POP) {
        DRUM_STYLE style;
        switch(drumKit->getDrumStyle() +1){
            case 0:  style = JAZZ; break;
            case 1: style = ROCK; break;
            case 2: style = POP; break;
        }
        drumKit->setDrumStyle( style );
    }
}
void DisplayWidget::on_style_changed(){}

