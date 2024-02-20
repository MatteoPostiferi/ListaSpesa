//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_ITEMSLISTCOUNTER_H
#define LISTASPESA_ITEMSLISTCOUNTER_H


#include <iostream>
#include "Observer.h"
#include "ShoppingList.h"

class ItemsListCounter : public Observer {
public:
    explicit ItemsListCounter(ShoppingList *subject) : subject(subject) {
        subject->registerObserver(this);
    }

    ~ItemsListCounter() override {
        subject->unregisterObserver(this);
    }

    int countItems() const {
        int count = 0;
        for (auto s: subject->getList()) {
            if (s.second.isBought() == false)
                count++;
        }
        return count;
    }


    void update() const override {
        int count = countItems();
        std::cout << subject->getListName() << ": ci sono " << count << " articoli ancora da comprare" << std::endl << std::endl;

    }

private:
    ShoppingList *subject;
};


#endif //LISTASPESA_ITEMSLISTCOUNTER_H
