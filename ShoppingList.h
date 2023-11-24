//
// Created by matte on 24/11/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H


#include <string>
#include <map>
#include <vector>
#include <list>
#include "Item.h"
#include "Subject.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string &listName) : listName(listName) {}

    virtual ~ShoppingList() {}

    void notifyObservers() override {
        for (auto o:observerList)
            o->update();
    }

    void registerObserver(Observer *o) override {
        observerList.push_back(o);
    }

    void unregisterObserver(Observer *o) override {
        observerList.remove(o);
    }

    void addItem(const Item& item){
        list.insert({item.getDescription(),item});
    }

    void addItemPos(const Item& item, int position){
        int count=0;
        auto iterator= list.begin();
        while(count<position) {
            iterator++;
            count++;
        }
        list.insert({item.getDescription(), item});
    }



private:
    std::string listName;
std::multimap<std::string, Item> list;
std::list<Observer*> observerList;

};


#endif //LISTASPESA_SHOPPINGLIST_H
