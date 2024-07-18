//
// Created by Matteo Postiferi on 24/11/2023.
//

#include "ItemsToBuyCounter.h"

ItemsToBuyCounter::ItemsToBuyCounter(ShoppingList* subject) : subject(subject)
{
    subject->registerObserver(this);
}

ItemsToBuyCounter::~ItemsToBuyCounter()
{
    subject->unregisterObserver(this);
}

void ItemsToBuyCounter::update() const
{
    std::cout << subject->getListName() << ": there are " << subject->getToBuyItems() << " items left to buy"
        << std::endl;
}
