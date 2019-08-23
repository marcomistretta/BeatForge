//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#ifndef MYTEST_SUBJECT_H
#define MYTEST_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    ~Subject(){};
    virtual void notify() = 0;
    virtual void addObserver(Observer * o) = 0;
    virtual void removeObserver(Observer  * o) = 0;

};



#endif //MYTEST_SUBJECT_H
