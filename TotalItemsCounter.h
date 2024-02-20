//
// Created by Matteo Postiferi on 27/11/2023.
//

#ifndef LISTASPESA_TOTALITEMSCOUNTER_H
#define LISTASPESA_TOTALITEMSCOUNTER_H


#include "Observer.h"
#include "ListGroup.h"
#include "ItemsListCounter.h"

class TotalItemsCounter : public Observer {
public:
    explicit TotalItemsCounter(ListGroup *subject) : subject(subject) {
        subject->registerObserver(this);
    }

    ~TotalItemsCounter() override {
        subject->unregisterObserver(this);
    }

    void update() override {
        int count = 0;
        for (auto l: subject->getListGroup()) {
            count += itemsListCounter->countItems();
        }
        std::cout << "There are : " << count << " items left to buy in all lists" << std::endl;
    }

private:
    ListGroup *subject;
    ItemsListCounter *itemsListCounter;


};


#endif //LISTASPESA_TOTALITEMSCOUNTER_H
