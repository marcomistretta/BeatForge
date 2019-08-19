//
// Created by Guglielmo Fratticioli on 09/07/19.
//

#ifndef MYTEST_MAINWINDOW_H
#define MYTEST_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:

    //void paintEvent(QPaintEvent * e) override;

private:

    void setUpGui();
};


#endif //MYTEST_MAINWINDOW_H
