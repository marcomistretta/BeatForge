//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#include "Drum.h"
#include <QString>

Drum::Drum(QWidget *parent) {}
Drum::Drum(QWidget *parent, QString  sample_Path): sample_Path(sample_Path) {}

void Drum::addObserver(Observer *o) {
    Observers.push_back(o);
}
void Drum::removeObserver(Observer *o) {
    Observers.remove(o);
}
void Drum::notify() {
     for (Observer* observer : Observers)
        observer->obsUpdate();
}
bool Drum::isChecked(int position) {
    if(groove[position] == ON)
        return true;
    else
        return false;
}
void Drum::editStep(int step) {
    if(this->isChecked(step))
        groove[step] = OFF;
    else
        groove[step] = ON;
    notify();
}