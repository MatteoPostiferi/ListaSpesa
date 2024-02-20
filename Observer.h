//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_OBSERVER_H
#define LISTASPESA_OBSERVER_H


class Observer {
public:
    virtual void update() const = 0;
    virtual ~Observer() {}

};


#endif //LISTASPESA_OBSERVER_H
