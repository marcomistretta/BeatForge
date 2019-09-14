
#ifndef TESTQTGUI_DRUMWIDGET_H
#define TESTQTGUI_DRUMWIDGET_H

#include "Observer.h"
#include <QWidget>

class QPushButton;
class QHBoxLayout;
class StepButton;
class Drum;

class DrumWidget : public QWidget, public Observer {
Q_OBJECT
public:
    explicit DrumWidget(QWidget *parent);

    ~DrumWidget() override;

    void obsUpdate() override;

    Drum *getDrum() const;

    void setDrum(Drum *drum);

private slots:

    void on_mute_pressed();

    void on_solo_pressed();

    void on_drum_info_pressed();

private:
    QHBoxLayout *layout;
    QPushButton *drum_info;
    QPushButton *muteButton;
    QPushButton *soloButton;
    Drum *drum;
    StepButton *buttons[16];


};

#endif //TESTQTGUI_DRUMWIDGET_H
