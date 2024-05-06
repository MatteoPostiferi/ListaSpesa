//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_ITEMSTOBUYCOUNTER_H
#define LISTASPESA_ITEMSTOBUYCOUNTER_H


#include <iostream>
#include "Observer.h"
#include "ShoppingList.h"

class ItemsToBuyCounter : public Observer {             // classe che conta il numero di articoli ancora da comprare in una lista
public:
    explicit ItemsToBuyCounter(ShoppingList *subject) : subject(subject) {
        subject->registerObserver(this);
    }

    ~ItemsToBuyCounter() override {
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
        std::cout << subject->getListName() << ": ci sono " << count << " articoli ancora da comprare nella lista" << std::endl << std::endl;

    }

private:
    ShoppingList *subject;
};


#endif //LISTASPESA_ITEMSTOBUYCOUNTER_H
