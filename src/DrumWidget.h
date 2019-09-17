
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

class MyDial : public QDial {
public:
    MyDial(QWidget* parent);
    void mousePressEvent(QMouseEvent *me) override;
    void mouseReleaseEvent(QMouseEvent *me) override;
    QLabel* getvolumeLabel() const {
        return volumeLabel;
    }
private:
    QLabel* volumeLabel;
};


class DrumWidget : public QWidget, public Observer {
Q_OBJECT
public:

    DrumWidget(QWidget *parent = nullptr);
    ~DrumWidget() override;
    void paintEvent(QPaintEvent *event) override;

    void obsUpdate() override;

    Drum *getDrum() const;
    void setDrum(Drum *drum);

private slots:

    void on_volume_changed();
    void on_mute_pressed();
    void on_solo_pressed();
    void on_drum_info_pressed();

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
    QMenu* menu;
    MyDial* volumeDial;

};

#endif //TESTQTGUI_DRUMWIDGET_H
