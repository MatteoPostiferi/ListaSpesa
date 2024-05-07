//
// Created by Matteo Postiferi on 27/11/2023.
//

#include "TotalItemsCounter.h"

TotalItemsCounter::TotalItemsCounter(ShoppingList *subject) : subject(subject) {
    subject->registerObserver(this);
}

void TotalItemsCounter::update() const {
    int count = 0;
    for (auto l: subject->getList()) {
        count += itemsListCounter->countItems();
    }
    std::cout << "There are : " << count << " items in total in the list" << std::endl << std::endl;
}

TotalItemsCounter::~TotalItemsCounter() {
    subject->unregisterObserver(this);
}
