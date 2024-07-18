//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_ITEMSTOBUYCOUNTER_H
#define LISTASPESA_ITEMSTOBUYCOUNTER_H


#include <iostream>
#include "Observer.h"
#include "ShoppingList.h"

class ItemsToBuyCounter : public Observer
{
    // classe che conta il numero di articoli ancora da comprare in una lista
public:
    explicit ItemsToBuyCounter(ShoppingList* subject);

    ~ItemsToBuyCounter() override;

    void update() const override;

private:
    ShoppingList* subject;
};


#endif //LISTASPESA_ITEMSTOBUYCOUNTER_H
