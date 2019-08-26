//
// Created by misterm on 11/05/19.
//

#include <QtMultimedia/QSound>
#include "Metronome.h"
#include <QDebug>

Metronome::Metronome(): state(OFF){
    qDebug()<<"Metronome constructed";
}
void Metronome::notify() {
    for(Observer * observer : observers)
        observer->obsUpdate();
    qDebug()<<"MetroWidgt notified";

}
void Metronome::addObserver(Observer *o) {
    qDebug()<<"Observer added";
    observers.push_back(o);
}
void Metronome::removeObserver(Observer *o) {
    qDebug()<<"Observer removed";
    observers.remove(o);
}
bool Metronome::isActive() {
    if(this->state == ON)
        return true;
    else
        return false;
}
