//
// Created by Guglielmo Fratticioli on 09/07/19.
//

#ifndef MYTEST_MAINWINDOW_H
#define MYTEST_MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;
class QWidget;
class DrumKitWidget;

class MainWindow : public QMainWindow {
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QWidget * mainWidget;
    DrumKitWidget* drumKitWidget;
    QGridLayout* mainLayout;
};


#endif //MYTEST_MAINWINDOW_H
