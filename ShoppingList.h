//
// Created by matte on 24/11/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H


#include <string>
#include <map>
#include <list>
#include "Item.h"
#include "Subject.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string &listName) : listName(listName) {}

    virtual ~ShoppingList() {}

    void notify() override {
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
        for(auto l:list ){
            if (l.second == item){
                l.second.setQuantity(l.second.getQuantity()+item.getQuantity());
                notify();
                break;
            }
        }
        list.insert({item.getDescription(),item});
        notify();
    }

    void removeItem(const Item& item){
        for(auto l:list ){
            if (l.second == item){
                l.second.setQuantity(l.second.getQuantity()-item.getQuantity());
                if(l.second.getQuantity()<= 0){
                    list.erase(l.first);
                    notify();
                }
                break;
            }
        }

    }

    const std::multimap<std::string, Item> &getList() const {
        return list;
    }

    const std::string &getListName() const {
        return listName;
    }


private:
    std::string listName;
std::multimap<std::string, Item> list;
std::list<Observer*> observerList;

};


#endif //LISTASPESA_SHOPPINGLIST_H
