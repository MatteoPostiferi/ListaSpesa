//
// Created by Matteo Postiferi on 27/11/2023.
//

#ifndef LISTASPESA_TOTALITEMSCOUNTER_H
#define LISTASPESA_TOTALITEMSCOUNTER_H


#include "Observer.h"
#include "ItemsToBuyCounter.h"

class TotalItemsCounter : public Observer
{
    // classe che conta il numero di articoli ancora da comprare in tutte le liste
public:
    explicit TotalItemsCounter(ShoppingList* subject);

    ~TotalItemsCounter() override;

    void update() const override;

private:
    ShoppingList* subject;
    ItemsToBuyCounter* itemsListCounter;
};


#endif //LISTASPESA_TOTALITEMSCOUNTER_H
