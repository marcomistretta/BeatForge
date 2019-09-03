
#ifndef TESTQTGUI_DRUMWIDGET_H
#define TESTQTGUI_DRUMWIDGET_H

#include "Observer.h"
#include <QWidget>

class QPushButton;
class QHBoxLayout;
class StepButton;
class Drum;

class DrumWidget: public QWidget, public Observer {

public:
    ~DrumWidget();
    DrumWidget(QWidget* parent);

    void obsUpdate() override;
    void setDrum(Drum *drum) {
        DrumWidget::drum = drum;
    }
    Drum *getDrum() const {
        return drum;
    }

private:
    QHBoxLayout * layout;
    QPushButton* drum_info;
    QPushButton* muteButton;
    QPushButton* soloButton;
    Drum* drum;
    StepButton* buttons[16];

};

#endif //TESTQTGUI_DRUMWIDGET_H
