//
// Created by Guglielmo Fratticioli on 09/07/19.
//



#include "MainWindow.h"
#include "DrumKit.h"
#include "DrumKitWidget.h"
#include "MetronomeWidget.h"
#include <QGridLayout>
#include "PlayerWidget.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent) {

    this->showMaximized();
    int mainWidth = this->size().width();
    int mainHeight = this->size().height();

    this->setFixedSize(mainWidth,mainHeight);
    this->setStyleSheet(QString("*{image: url(../res/icon/Background.png);};"));
    this->setContentsMargins(0,0,0,0);

    mainWidget = new QWidget(this);
    mainWidget->setContentsMargins(0,0,0,0);
    mainWidget->setStyleSheet(QString("*{background: transparent;}"));
    mainWidget->setLayout(mainLayout);

    drumKitWidget = new DrumKitWidget(mainWidget);
    drumKitWidget->setFixedSize(mainWidth * 6, mainHeight * 4.4);

    metronomeWidget = new MetronomeWidget(mainWidget);
    metronomeWidget->obsUpdate();
    metronomeWidget->setFixedSize(mainHeight,mainHeight);
    metronomeWidget->setIconSize(QSize(50,50));

    playerWidget = new PlayerWidget(mainWidget);
    playerWidget->obsUpdate();
    playerWidget->setFixedSize(mainHeight, mainHeight);
    playerWidget->setIconSize(QSize(50, 50));

    mainLayout = new QGridLayout();
    mainLayout->setContentsMargins(mainWidth*40/100,mainHeight*1.8,0,0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(metronomeWidget,0,0,Qt::AlignLeft);
    mainLayout->addWidget(drumKitWidget,1,0,Qt::AlignLeft);

    this->setCentralWidget(mainWidget);
}

