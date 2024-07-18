//
// Created by Matteo Postiferi on 27/11/2023.
//

#include "TotalItemsCounter.h"

TotalItemsCounter::TotalItemsCounter(ShoppingList* subject) : subject(subject)
{
    subject->registerObserver(this);
}

void TotalItemsCounter::update() const
{
    std::cout << "There are " << subject->getTotalItems() << " items in total in the list" << std::endl;
}

TotalItemsCounter::~TotalItemsCounter()
{
    subject->unregisterObserver(this);
}
