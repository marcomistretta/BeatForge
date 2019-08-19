//
// Created by Guglielmo Fratticioli on 03/08/19.
//

#ifndef TESTQTGUI_STEPBUTTON_H
#define TESTQTGUI_STEPBUTTON_H

#include <QPushButton>

class StepButton: public QPushButton{
public:
    explicit StepButton(QWidget * parent = nullptr);
    int getPosition() const {
        return position;
    }
    void setPosition(int position) {
        StepButton::position = position;
    }
    void setBackground(QColor color);

private slots:
    void on_clicked();

private:
    int position;
};


#endif //TESTQTGUI_STEPBUTTON_H
