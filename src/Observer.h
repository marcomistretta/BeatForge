//
// Created by Guglielmo Fratticioli on 17/08/19.
//

#ifndef MYTEST_OBSERVER_H
#define MYTEST_OBSERVER_H


class Observer {
public:
    ~Observer(){};
    virtual void obsUpdate() = 0;
};


#endif //MYTEST_OBSERVER_H
