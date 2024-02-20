//
// Created by matte on 24/11/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H


#include <string>
#include <map>
#include <list>
#include <algorithm>
#include "Item.h"
#include "Subject.h"
#include <stdexcept>
#include <iostream>

class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string &listName) : listName(listName) {}

    virtual ~ShoppingList() {}

    void notify() override {       //  ogni cambiamento del subject viene segnalato all'observer
        for (auto o: observerList)
            o->update();
    }

    void registerObserver(Observer *o) override {
        observerList.push_back(o);
    }

    void unregisterObserver(Observer *o) override {
        observerList.remove(o);
    }

    auto search(const Item &item) {
        for (auto itr = list.begin(); itr != list.end(); itr++) {
            if (itr->second == item) {
                return itr;
            }
        }
        return list.end();
    }

    void addToList(const Item &item) {  // se l'elemento è gia presente si incrementa la quantità, altrimenti si aggiunge
        auto itr = search(item);
        if (search(item) != list.end())
            itr->second.setQuantity (itr->second.getQuantity() + item.getQuantity());
        else
            list.insert({item.getCategory(), item});
        notify();
    }

    void decreaseQty(const Item &item) {         // diminuisco la quantità che voglio comprare di un prodotto
                                                 // se l'elemento si trova nella lista aggiorno la quantità da comprare
                                                 // altrimenti lancio eccezione

        auto itr = search(item);
        if (search(item) != list.end())
            itr->second.setQuantity (itr->second.getQuantity() - item.getQuantity());
        else
            throw std::runtime_error("Elemento non presente nella lista");
   }

   void removeFromList(const Item &item) {      // cancello un elemento dalla lista se non voglio più comprarlo
        auto itr = search(item);
        if (search((item)) != list.end())
            list.erase(itr);
        else
           throw std::runtime_error("Elemento non presente nella lista");
   }


   void buyItem(Item &item) {  // imposto bool a true se
       decreaseQty(item);
       if (decreaseQty(item) <= 0)
           item.setBought(true);
       notify();
   }

   /*void buyItem(const Item &item) {
       for (auto l: list) {
           if (l.second == item) {
               l.second.setQuantity(l.second.getQuantity() - item.getQuantity());
               if (l.second.getQuantity() <= 0)
                   l.second.setBought(true);
               notify();

           }
       }
   }*/

    const std::multimap<std::string, Item> &getList() const {
        return list;
    }

    const std::string &getListName() const {
        return listName;
    }


private:
    std::string listName;
    std::multimap<std::string, Item> list;
    std::list<Observer *> observerList;;
};


#endif //LISTASPESA_SHOPPINGLIST_H
