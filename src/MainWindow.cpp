//
// Created by Guglielmo Fratticioli on 09/07/19.
//



#include "MainWindow.h"
#include "DrumKit.h"
#include "DrumKitWidget.h"
#include "MetronomeWidget.h"
#include "PlayerWidget.h"
#include "Player.h"
#include "Timeline.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent) {

    this->showMaximized();
    int mainWidth = this->size().width();
    int mainHeight = this->size().height();

    this->setFixedSize(mainWidth,mainHeight);
    //TODO PATH
    this->setStyleSheet(QString("*{image: url(../res/icons/Background.png);};"));
    this->setContentsMargins(0,0,0,0);

    mainWidget = new QWidget(this);
    mainWidget->setContentsMargins(0,0,0,0);
    mainWidget->setStyleSheet(QString("*{image: url(../res/icons/transparence.png);}"));
    mainLayout = new QGridLayout;
    mainWidget->setLayout(mainLayout);


    drumKit = new DrumKit();

    drumKitWidget = new DrumKitWidget(drumKit,mainWidget);
    drumKitWidget->setFixedSize(mainWidth * 6.12, mainHeight * 4.4);
    DrumKit *addrDrumKit = drumKitWidget->getDrumKit();

    metronome = new Metronome();

    metronomeWidget = new MetronomeWidget(metronome,mainWidget);
    metronomeWidget->setFixedSize(mainHeight,mainHeight/1.18);
    metronomeWidget->obsUpdate();


    player = new Player();

    playerWidget = new PlayerWidget(player,mainWidget);
    playerWidget->getplayButton()->setFixedSize(mainHeight/2,mainWidth/34*10);
    playerWidget->getstopButton()->setFixedSize(mainHeight/2,mainWidth/34*10);
    playerWidget->getplayButton()->setIconSize(playerWidget->getplayButton()->size());
    playerWidget->getstopButton()->setIconSize(playerWidget->getstopButton()->size());
    playerWidget->obsUpdate();

    timeline = new Timeline(player,mainWidget);


    player->setDrumKit(addrDrumKit);
    player->setMetronome(metronome);

    mainLayout->setContentsMargins(mainWidth*40/100,mainHeight*1.8,mainHeight*10,0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(metronomeWidget,0,0,Qt::AlignLeft);
    mainLayout->addWidget(playerWidget, 0, 1,Qt::AlignRight);
    mainLayout->addWidget(timeline,1,1,Qt::AlignBaseline);
    mainLayout->addWidget(drumKitWidget,2,0,Qt::AlignLeft);
    this->setCentralWidget(mainWidget);
}

