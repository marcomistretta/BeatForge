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
#include "DisplayWidget.h"
#include <QGridLayout>
#include <QSpacerItem>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), mainWidget(new QWidget(this)), drumKit(new DrumKit()),
metronome(new Metronome()), player(new Player())
{
    player->setMetronome(metronome);
    player->setDrumKit(drumKit);

    verticalLayout = new QVBoxLayout(mainWidget);
    upperWidget = new QWidget(mainWidget);
    midWidget = new QWidget(mainWidget);
    bottomWidget = new QWidget(mainWidget);

    upperLayout = new QHBoxLayout(upperWidget);
    midLayout = new QHBoxLayout(midWidget);
    bottomLayout = new QHBoxLayout(bottomWidget);

    metronomeWidget = new MetronomeWidget(metronome,upperWidget);
    playerWidget = new PlayerWidget(player, upperWidget);
    displayWidget = new DisplayWidget(player,drumKit, upperWidget);

    timeline = new Timeline(player, midWidget);
    drumKitWidget = new DrumKitWidget(drumKit, bottomWidget);



    setUpGui();
}

void MainWindow::setUpGui() {
    QDir * dir = new QDir(QDir::currentPath());
    QString path = dir->absoluteFilePath("res/icons/");


    QDesktopWidget dw;
    this->setStyleSheet(QString("*{image: url(%1Background.png);};").arg(path));
    //TODO 0.7 on Inspiron, 0.9 on vostro
    this->height = dw.size().width() * 0.7;
    this->width = dw.size().height() * 0.7;
    this->setFixedSize(height, width);
    this->setContentsMargins(0, 0, 0, 0);
    mainWidget->setStyleSheet(QString("*{image: url(../icons/Transparency.png);};"));
    mainWidget->setContentsMargins(0, height / 62, 0, 0);
    upperWidget->setFixedSize(width * 1.67, height / 6);
    upperLayout->addItem(new QSpacerItem(width * 10 / 100, 0));
    metronomeWidget->setFixedSize(width * 35 / 100, height * 23 / 100);
    upperLayout->addWidget(metronomeWidget);
    playerWidget->setFixedSize(width * 20 / 100, height * 22.5 / 100);
    upperLayout->addItem(new QSpacerItem(width * 10 / 100, 0));
    upperLayout->addWidget(playerWidget);
    upperLayout->addItem(new QSpacerItem(width * 50 / 100, 0));
    displayWidget->setFixedSize(width / 2.1, height / 5.5);
    upperLayout->addWidget(displayWidget);
    upperWidget->setLayout(upperLayout);

    midWidget->setFixedSize(width * 1.67, height / 40);
    midLayout->addItem(new QSpacerItem(width * 35 / 100, 0));
    timeline->setFixedSize(width * 1.22, height * 2.3 / 100);
    midLayout->addWidget(timeline, Qt::AlignTop);
    midWidget->setLayout(midLayout);


    bottomWidget->setFixedSize(width * 1.69, height / 3);

    bottomLayout->addItem(new QSpacerItem(width * 7.5 / 100, 0));
    drumKitWidget->setFixedSize(width * 1.59, height / 3);
    bottomLayout->addWidget(drumKitWidget, Qt::AlignTop);
    bottomWidget->setLayout(bottomLayout);

    verticalLayout->addWidget(upperWidget);
    verticalLayout->addWidget(midWidget);
    verticalLayout->addWidget(bottomWidget);
    mainWidget->setLayout(verticalLayout);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() {
    delete drumKit;
    delete drumKitWidget;
    delete metronome;
    delete metronomeWidget;
    delete player;
    delete playerWidget;
    delete displayWidget;
    delete timeline;
    delete upperLayout;
    delete midLayout;
    delete bottomLayout;
    delete verticalLayout;
    delete upperWidget;
    delete midWidget;
    delete bottomWidget;
    delete mainWidget;
}

