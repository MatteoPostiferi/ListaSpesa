//
// Created by matte on 24/11/2023.
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

    int update() override {
        int count= 0;
        for(auto s: subject->getList()){
            if(s.second.isBought()== false)
            count++;
        }
        std::cout<<"There are : "<< count << " items left to buy in: "<< subject->getListName()<< std::endl;
        return count;
    }

private:
    ShoppingList* subject;
};


#endif //LISTASPESA_ITEMSLISTCOUNTER_H
