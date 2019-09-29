
#include "DrumWidget.h"
#include "Drum.h"
#include "Enum.h"
#include "StepButton.h"
#include "MyDial.h"

#include <QMainWindow>
#include <QDial>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QPalette>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QLabel>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>


DrumWidget::~DrumWidget() {
    drum->removeObserver(this);
    delete layout;
    delete drum_info;
    delete muteButton;
    delete soloButton;
    delete drum;
    for (auto i : buttons)
        delete[] i;
    delete menu;
    delete volumeDial;
    delete dir;

}


DrumWidget::DrumWidget(QWidget *parent) : QWidget(parent) {
    dir = new QDir(QDir::currentPath());
    path = dir->absoluteFilePath("res/icons/");
    this->setStyleSheet(QString("*{image: url(res/icons/DrumWidget.png);}"));

    //DECLARING HORIZONTAL LAYOUT
    layout = new QHBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    //BUILDING INFO BOX
    drum_info = new QPushButton();
    connect(drum_info, SIGNAL(clicked()), this, SLOT(on_drum_info_pressed()));
    drum_info->setStyleSheet(QString("*{background: rgb(136,155,97);}"));
    drum_info->setFixedSize(this->width()*1.5 , this->height() );

    //BUILDING MENU
    //TODO IMPLEMENT QDIR FOR EACH
    menu = new QMenu();
    menu->setStyleSheet(QString("*{background: rgb(136,155,97);}"));
    menu->setFixedWidth(this->width()*1.5);
    QAction *kickPressed = new QAction(QString("KICK"), this);
    connect(kickPressed, SIGNAL(triggered()), this, SLOT(on_kick_pressed()));
    QAction *SnarePressed = new QAction(QString("SNARE"), this);
    connect(SnarePressed, SIGNAL(triggered()), this, SLOT(on_snare_pressed()));
    QAction *HatPressed = new QAction(QString("HAT"), this);
    connect(HatPressed, SIGNAL(triggered()), this, SLOT(on_hat_pressed()));
    QAction *TomPressed = new QAction(QString("TOM"), this);
    connect(TomPressed, SIGNAL(triggered()), this, SLOT(on_tom_pressed()));
    //....
    menu->addAction(kickPressed);
    menu->addAction(SnarePressed);
    menu->addAction(HatPressed);
    menu->addAction(TomPressed);
    drum_info->setMenu(menu);
    layout->addWidget(drum_info, Qt::AlignLeft, Qt::AlignVCenter);

    //BUILDING PLAY-PAUSE-MUTE-SOLO
    muteButton = new QPushButton();
    QIcon playicon;
    playicon.addFile(QString(path + "/MuteButton-OFF.png"));
    muteButton->setFixedSize(this->height()/2 , this->height()/2 );
    muteButton->setIcon(playicon);
    connect(muteButton, SIGNAL(clicked()), this, SLOT(on_mute_pressed()));
    soloButton = new QPushButton();
    QIcon soloicon;
    soloicon.addFile(QString(path + "/SoloButton-OFF.png"));
    soloButton->setFixedSize(this->height()/2 , this->height()/2 );
    soloButton->setIcon(soloicon);
    connect(soloButton, SIGNAL(clicked()), this, SLOT(on_solo_pressed()));

    layout->addItem(new QSpacerItem(this->width()/12,0));
    layout->addWidget(muteButton, 0, 0);
    layout->addItem(new QSpacerItem(this->width()/12,0));
    layout->addWidget(soloButton, 1, 0);

    //SPACING
    layout->addItem(new QSpacerItem(this->width()/5,0));

    //BUILDING STEP_BUTTONS
    for (int i = 0; i < 16; i++) {
        buttons[i] = new StepButton(this);
        buttons[i]->setStyleSheet(QString("*{background: white;}"));
        buttons[i]->setFixedSize(this->width()/2.5 , this->height()/1.2 );
        buttons[i]->setPosition(i);
        layout->addWidget(buttons[i]);
        layout->addItem(new QSpacerItem(this->width()/10,0));
        layout->setStretchFactor(buttons[i], 1);
    }

    //BUILDING VOLUME DIAL
    volumeDial = new MyDial(this);
    volumeDial->setRange(0, 100);
    connect(volumeDial, SIGNAL(valueChanged(int)), this, SLOT(on_volume_changed()));
    volumeDial->setFixedSize(this->width()/2.5 , this->width()/2.5 );
    layout->addWidget(volumeDial);

    //SETTING THE LAYOUT
    this->setLayout(layout);
}

void DrumWidget::obsUpdate() {
    qDebug() << "DrumWidget Updated";

    //STEP
    for (int pos = 0; pos < 16; pos++) {
        if (drum->isActive(pos))
            buttons[pos]->setBackground(Qt::red);
        else
            buttons[pos]->setBackground(Qt::white);
    }

    //VOLUME DIAL
    volumeDial->setValue(drum->getVolume());
    volumeDial->getvolumeLabel()->setText(QString::number(drum->getVolume()));

    //MENU
    QString drumType;
    switch (drum->getDrumType()) {
        case KICK : {
            drumType = QString("KICK");
        }
            break;
        case SNARE : {
            drumType = QString("SNARE");
        }
            break;
        case HAT : {
            drumType = QString("HAT");
        }
            break;
        case TOM : {
            drumType = QString("TOM");
        }
            break;
    }
    drum_info->setText(drumType);
}

//SLOTS
//TODO RIMETTERE alcune parti NELL'OBS
void DrumWidget::on_mute_pressed() {
    QIcon muteicon;
    if (drum->getMuteState() == NOMUTED) {
        drum->setMuteState(MUTED);
        muteicon.addFile(QString(path + "MuteButton-ON.png"));
        qDebug() << "Mute Updating to MUTED";

    } else {
        drum->setMuteState(NOMUTED);
        muteicon.addFile(QString(path + "MuteButton-OFF.png"));
        qDebug() << "Mute Updating to NOMUTED";
    }
    muteButton->setIcon(muteicon);
}

//TODO RIMETTERE alcune parti NELL'OBS
void DrumWidget::on_solo_pressed() {
    QIcon soloicon;
    if (drum->getSoloState() == NOSOLO) {
        drum->setSoloState(SOLO);
        soloicon.addFile(QString(path + "SoloButton-ON.png"));
        qDebug() << "Solo Updating to SOLO";
    } else {
        drum->setSoloState(NOSOLO);
        soloicon.addFile(QString(path + "SoloButton-OFF.png"));
        qDebug() << "Solo Updating to NOSOLO";
    }
    soloButton->setIcon(soloicon);
}

void DrumWidget::on_drum_info_pressed() {
    qDebug() << "Infobox clicked";
}

void DrumWidget::on_volume_changed() {
    drum->setVolume(volumeDial->value());
}

void DrumWidget::on_kick_pressed() {
    drum->setDrumType(KICK);
}

void DrumWidget::on_snare_pressed() {
    drum->setDrumType(SNARE);
}

void DrumWidget::on_hat_pressed() {
    drum->setDrumType(HAT);
}

void DrumWidget::on_tom_pressed() {
    drum->setDrumType(TOM);
}

Drum *DrumWidget::getDrum() const {
    return drum;
}

void DrumWidget::setDrum(Drum *drum) {
    DrumWidget::drum = drum;
}

void DrumWidget::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}