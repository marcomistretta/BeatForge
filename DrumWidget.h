
#ifndef TESTQTGUI_DRUMWIDGET_H
#define TESTQTGUI_DRUMWIDGET_H

#include "Drum.h"
#include "StepButton.h"

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>




class DrumWidget: public QWidget, public Observer {

public:
    ~DrumWidget();
    DrumWidget(QWidget* parent);
    void obsUpdate() override;
    void setUpGui();

    Drum *getDrum() const {
        return drum;
    }



private:

    QHBoxLayout * layout;
    QPushButton* drum_info;
    QPushButton* playButton;
    QPushButton* pauseButton;
    Drum* drum;
    StepButton* buttons[16];

};

#endif //TESTQTGUI_DRUMWIDGET_H
