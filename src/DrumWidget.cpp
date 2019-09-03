
#include "DrumWidget.h"
#include "Drum.h"
#include "StepButton.h"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QPalette>
#include <QDebug>
DrumWidget::~DrumWidget() {
    drum->removeObserver(this);
}
DrumWidget::DrumWidget( QWidget *parent): QWidget(parent) {
    int mainWidth = static_cast<QMainWindow*>(this->parent()->parent()->parent())->size().width();
    int mainHeight = static_cast<QMainWindow*>(this->parent()->parent()->parent())->size().height();

    this->setStyleSheet(QString("*{image: url(../res/DrumWidget.png);}"));
    //DECLARING HORIZONTAL LAYOUT
    layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(10);
    layout->setMargin(0);
    //BUILDING INFO BOX

    drum_info = new QPushButton();

    drum_info->setStyleSheet(QString("*{background: rgb(140,200,255);}"));
    drum_info->setFixedSize(mainWidth/10,mainHeight/31);

    layout->addWidget(drum_info,Qt::AlignLeft,Qt::AlignVCenter);

    //BUILDING PLAY-PAUSE-MUTE-SOLO

    muteButton = new QPushButton();
    QIcon playicon;
    playicon.addFile(QString("../res/icons/MuteButton-OFF.png"));
    muteButton->setFixedSize(mainHeight/35,mainHeight/35);
    muteButton->setIcon(playicon);

    soloButton = new QPushButton();
    QIcon soloicon;
    soloicon.addFile(QString("../res/icons/SoloButton-OFF.png"));
    soloButton->setFixedSize(mainHeight/35,mainHeight/35);
    soloButton->setIcon(soloicon);


    layout->addWidget(muteButton,0,0);
    layout->addWidget(soloButton,1,0);

    //SPACING
    QWidget* space = new QWidget;
    space->setStyleSheet(QString(" background: transparent;"));
    space->setFixedWidth(30);
    space->setFixedHeight(mainHeight/22);

    layout->addWidget(space);


    //BUILDING STEP_BUTTONS
    for (int i = 0; i < 16; i++) {
        buttons[i] = new StepButton(this);
        buttons[i]->setStyleSheet(QString("*{background: white;}"));
        buttons[i]->setFixedSize(mainWidth/30,mainHeight/32);
        buttons[i]->setPosition(i);

        layout->addWidget(buttons[i]);
        layout->setStretchFactor(buttons[i], 1);
    }

    this->setLayout(layout);                                                                //SETTING THE LAYOUT
     }
void DrumWidget::obsUpdate() {
    qDebug()<<"Observer Updating";
    for(int pos = 0; pos<16; pos ++){
        if (drum->isChecked(pos))
            buttons[pos]->setBackground(Qt::red);
        else
            buttons[pos]->setBackground(Qt::white);
    }
}




