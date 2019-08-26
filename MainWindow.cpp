//
// Created by Guglielmo Fratticioli on 09/07/19.
//



#include "MainWindow.h"
#include "DrumKit.h"
#include "DrumKitWidget.h"
#include "MetronomeWidget.h"

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent) {

    this->setGeometry(0,0,1000,500);
    mainWidget = new QWidget(this);
    mainWidget->setGeometry(0,0,1000,500);
    mainWidget->setStyleSheet("background-color:#6b4f30");


    drumKitWidget = new DrumKitWidget(mainWidget);
    metronomeWidget = new MetronomeWidget(mainWidget);

    drumKitWidget->setStyleSheet("background-color:#304c6b");
    metronomeWidget->setStyleSheet("background-color:white");

    drumKitWidget->setFixedSize(1000,450);
    metronomeWidget->setFixedSize(50,50);
    metronomeWidget->setIconSize(QSize(50,50));
    mainLayout = new QGridLayout();
    mainLayout->addWidget(metronomeWidget,1,1);
    mainLayout->addWidget(drumKitWidget,2,1);


    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
}
