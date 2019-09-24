//
// Created by Guglielmo Fratticioli on 22/09/19.
//

#ifndef MYTEST_MYDIAL_H
#define MYTEST_MYDIAL_H
class QWidget;
class QLabel;

#include <QDial>

class MyDial : public QDial {
public:
    //CONSTRUCTOR
    MyDial(QWidget *parent);

    //SLOTS OVERRIDE
    void mousePressEvent(QMouseEvent *me) override;

    void mouseReleaseEvent(QMouseEvent *me) override;

    //GETTER
    QLabel *getvolumeLabel() const {
        return volumeLabel;
    }

private:
    QLabel *volumeLabel;
};

#endif //MYTEST_MYDIAL_H
