
#ifndef TESTQTGUI_DRUMWIDGET_H
#define TESTQTGUI_DRUMWIDGET_H

#include "Observer.h"
#include <QDir>
#include <QWidget>
#include <QDial>

class QPushButton;
class MyDial;
class QHBoxLayout;

class StepButton;

class Drum;
class QMenu;
class QLabel;

class DrumWidget : public QWidget, public Observer {
Q_OBJECT
public:
    //CONSTRUCTOR & DESTRUCTOR
    DrumWidget(QWidget *parent = nullptr);

    ~DrumWidget() override;

    void paintEvent(QPaintEvent *event) override;

    //OBSERVER
    void obsUpdate() override;

    //GETTER & SETTER
    Drum *getDrum() const;

    void setDrum(Drum *drum);

    StepButton *const *getButtons() const {
        return buttons;
    }

    QHBoxLayout *getLayout() const {
        return layout;
    }

    QPushButton *getDrumInfo() const {
        return drum_info;
    }

    QPushButton *getMuteButton() const {
        return muteButton;
    }

    QPushButton *getSoloButton() const {
        return soloButton;
    }

    QMenu *getMenu() const {
        return menu;
    }

    MyDial *getVolumeDial() const {
        return volumeDial;
    }

    QDir *getDir() const {
        return dir;
    }

    const QString &getPath() const {
        return path;
    }

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
    QDir *dir;
    QString path;

};

#endif //TESTQTGUI_DRUMWIDGET_H
