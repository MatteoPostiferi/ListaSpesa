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

    int countItems(){
        int count= 0;
        for(auto s: subject->getList()){
            if(s.second.isBought()==false)
            count++;
        }
        return count;
    }


    void update() override {
        int count= countItems();
        std::cout<<"There are : "<< count << " items left to buy in: "<< subject->getListName()<< std::endl;
    }

private:
    ShoppingList* subject;
};


#endif //LISTASPESA_ITEMSLISTCOUNTER_H
