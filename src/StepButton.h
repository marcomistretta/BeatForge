//
// Created by Guglielmo Fratticioli on 03/08/19.
//

#ifndef TESTQTGUI_STEPBUTTON_H
#define TESTQTGUI_STEPBUTTON_H

#include <QPushButton>

class StepButton: public QPushButton{
    Q_OBJECT
public:
    explicit StepButton(QWidget * parent = nullptr);
    void setBackground(QColor color);

    void setPosition(int position) {
        StepButton::position = position;
    }


private slots:
    void on_clicked();

private:
    int position;
};


#endif //TESTQTGUI_STEPBUTTON_H
