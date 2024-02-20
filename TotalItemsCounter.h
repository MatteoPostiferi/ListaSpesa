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

    void update() const override{
        int count = 0;
        for (auto l: subject->getListGroup()) {
            count += itemsListCounter->countItems();
        }
        std::cout << "Ci sono : " << count << " articoli ancora da comprare in totale" << std::endl << std::endl;
    }

private:
    ListGroup *subject;
    ItemsListCounter *itemsListCounter;


};


#endif //LISTASPESA_TOTALITEMSCOUNTER_H
