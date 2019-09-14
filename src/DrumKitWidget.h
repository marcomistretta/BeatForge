//
// Created by Guglielmo Fratticioli on 19/08/19.
//

#ifndef MYTEST_DRUMKITWIDGET_H
#define MYTEST_DRUMKITWIDGET_H

#include <QWidget>
#include "Subject.h"

class DrumWidget;

class DrumKit;

class QVBoxLayout;

class QPushButton;

class DrumKitWidget : public QWidget, public Observer {
Q_OBJECT
public:
    explicit DrumKitWidget(QWidget *parent = nullptr);

    void obsUpdate() override;

    DrumKit *getDrumKit() const;

    void setDrumKit(DrumKit *drumKit);

private slots:

    void on_add_pressed();

private:
    QVBoxLayout *layout;
    DrumKit *drumKit;
    QPushButton *addbutton;
    QVector<DrumWidget *> drumWidgets;
};


#endif //MYTEST_DRUMKITWIDGET_H
