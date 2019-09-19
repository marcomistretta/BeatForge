//
// Created by Guglielmo Fratticioli on 19/08/19.
//

#ifndef MYTEST_DRUMKITWIDGET_H
#define MYTEST_DRUMKITWIDGET_H

#include <QWidget>
#include "Observer.h"

class DrumWidget;

class DrumKit;

class QVBoxLayout;

class QPushButton;

class DrumKitWidget : public QWidget, public Observer {
Q_OBJECT
public:
    //CONSTRUCTOR
    explicit DrumKitWidget(DrumKit *drumkit, QWidget *parent = nullptr);

    //OBSERVER
    void obsUpdate() override;

    //GETTER
    DrumKit *getDrumKit() const {
        return drumKit;
    }

private slots:

    //WHEN YOU CLICK ADD TO ADD A DRUM
    void on_add_pressed();

private:
    QVBoxLayout *layout;
    DrumKit *drumKit;
    QPushButton *addbutton;
    QVector<DrumWidget *> drumWidgets;
};

#endif //MYTEST_DRUMKITWIDGET_H
