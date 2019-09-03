
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
    ~DrumWidget();

    DrumWidget(QWidget *parent);

    void obsUpdate() override;

    void setDrum(Drum *drum) {
        DrumWidget::drum = drum;
    }

    Drum *getDrum() const {
        return drum;
    }

private:
    QHBoxLayout *layout;
    QPushButton *drum_info;
    //FIXME il nome dei bottoni è giusto
    QPushButton *muteButton;
    QPushButton *soloButton;
    Drum *drum;
    StepButton *buttons[16];

private slots:
    //FIXME da implementare
    void on_mute_pressed();
    void on_solo_pressed();
    void on_drum_info_pressed();

};

#endif //TESTQTGUI_DRUMWIDGET_H
