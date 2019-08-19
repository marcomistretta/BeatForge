//
// Created by Guglielmo Fratticioli on 09/07/19.
//
#define MWIND_POSX 200
#define MWIND_POSY 200
#define MWIND_LENGHT 1080
#define MWIND_HIGHT 720

#include <QtWidgets/QGridLayout>
#include <QToolBar>
#include "MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent) {
    MainWindow::setUpGui();
}

void MainWindow::setUpGui() {
    this->setGeometry(MWIND_POSX, MWIND_POSY, MWIND_LENGHT, MWIND_HIGHT);
    QWidget *MainWidget = new QWidget(this);
    MainWidget->setGeometry(MWIND_POSX, MWIND_POSY, MWIND_LENGHT, MWIND_HIGHT);
    //TODO INSTANTIATE WIDGETS FOR MAIN WINDOW

    QGridLayout *MainLayout = new QGridLayout;
    //TODO ADD WIDGETS TO GRID_LAYOUT

    MainWidget->setLayout(MainLayout);
}