//
// Created by Matteo Postiferi on 27/11/2023.
//

#ifndef LISTASPESA_TOTALITEMSCOUNTER_H
#define LISTASPESA_TOTALITEMSCOUNTER_H


#include "Observer.h"
#include "ItemsToBuyCounter.h"

class TotalItemsCounter : public Observer {          // classe che conta il numero di articoli ancora da comprare in tutte le liste
public:
    explicit TotalItemsCounter(ShoppingList *subject) : subject(subject) {
        subject->registerObserver(this);
    }

    ~TotalItemsCounter() override {
        subject->unregisterObserver(this);
    }

    void update() const override{
        int count = 0;
        for (auto l: subject->getList()) {
            count += itemsListCounter->countItems();
        }
        std::cout << "Ci sono : " << count << " articoli in totale nella lista" << std::endl << std::endl;
    }

private:
    ShoppingList *subject;
    ItemsToBuyCounter *itemsListCounter;


};


#endif //LISTASPESA_TOTALITEMSCOUNTER_H
