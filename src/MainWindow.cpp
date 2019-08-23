//
// Created by Guglielmo Fratticioli on 09/07/19.
//



#include "MainWindow.h"
#include "DrumKit.h"
#include "DrumKitWidget.h"

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent) {

    this->setGeometry(0,0,1000,500);
    mainWidget = new QWidget(this);
    mainWidget->setGeometry(0,0,1000,500);

    drumKitWidget = new DrumKitWidget(this);

    mainLayout = new QGridLayout();
    mainLayout->addWidget(drumKitWidget);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(drumKitWidget);
}
