//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_SUBJECT_H
#define LISTASPESA_SUBJECT_H

#include "Observer.h"


class Subject {
public:
    virtual void notify() = 0;
    virtual void registerObserver(Observer* o) = 0;
    virtual void unregisterObserver(Observer* o) = 0;
    virtual ~Subject(){}

};


#endif //LISTASPESA_SUBJECT_H
