
#ifndef TESTQTGUI_DRUMWIDGET_H
#define TESTQTGUI_DRUMWIDGET_H

#include "Observer.h"

#include <QWidget>
#include <QDial>

class QPushButton;

class QHBoxLayout;

class StepButton;

class Drum;

class QMenu;

class QLabel;

//DIAL RE-IMPLEMENTATION
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

//DRUM WIDGET
class DrumWidget : public QWidget, public Observer {
Q_OBJECT
public:
    //CONSTRUCTOR
    DrumWidget(QWidget *parent = nullptr);

    //DESTRUCTOR
    ~DrumWidget() override;

    void paintEvent(QPaintEvent *event) override;

    //OBSERVER
    void obsUpdate() override;

    //GETTER & SETTER
    Drum *getDrum() const;

    void setDrum(Drum *drum);

private slots:

    //BUTTON & DIAL SLOTS
    void on_volume_changed();

    void on_mute_pressed();

    void on_solo_pressed();

    void on_drum_info_pressed();

    //MENU SLOTS
    void on_kick_pressed();

    void on_snare_pressed();

    void on_hat_pressed();

    void on_tom_pressed();

private:
    QHBoxLayout *layout;
    QPushButton *drum_info;
    QPushButton *muteButton;
    QPushButton *soloButton;
    Drum *drum;
    StepButton *buttons[16];
    QMenu *menu;
    MyDial *volumeDial;

};

#endif //TESTQTGUI_DRUMWIDGET_H
