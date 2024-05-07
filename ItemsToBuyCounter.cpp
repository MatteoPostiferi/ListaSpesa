//
// Created by Matteo Postiferi on 24/11/2023.
//

#include "ItemsToBuyCounter.h"

ItemsToBuyCounter::ItemsToBuyCounter(ShoppingList *subject) : subject(subject) {
    subject->registerObserver(this);
}

ItemsToBuyCounter::~ItemsToBuyCounter() {
    subject->unregisterObserver(this);
}

int ItemsToBuyCounter::countItems() const {
    int count = 0;
    for (auto s: subject->getList()) {
        if (s.second.isBought() == false)
            count++;
    }
    return count;
}


void ItemsToBuyCounter::update() const {
    int count = countItems();
    std::cout << subject->getListName() << ": there are " << count << " items left to buy"
              << std::endl << std::endl;

}
