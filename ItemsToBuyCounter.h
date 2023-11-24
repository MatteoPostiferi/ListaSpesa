//
// Created by matte on 24/11/2023.
//

#ifndef LISTASPESA_ITEMSTOBUYCOUNTER_H
#define LISTASPESA_ITEMSTOBUYCOUNTER_H


#include <iostream>
#include "Observer.h"
#include "ShoppingList.h"

class ItemsToBuyCounter : public Observer {
public:
    explicit ItemsToBuyCounter(ShoppingList *subject) : subject(subject) {
        subject->registerObserver(this);
    }

    ~ItemsToBuyCounter() override {
        subject->unregisterObserver(this);
    }

    void update() override {
        int count= 0;
        for(auto s: subject->getList()){
            count++;
        }
        std::cout<<"There are : "<< count<<" items left to buy" << std::endl;
    }

private:
    ShoppingList* subject;
};


#endif //LISTASPESA_ITEMSTOBUYCOUNTER_H
