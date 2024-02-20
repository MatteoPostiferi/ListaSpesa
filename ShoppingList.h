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
#include "ItemNotFound.h"
#include "NegativeQuantity.h"
#include <stdexcept>
#include <iostream>

class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string &listName) : listName(listName) {}

    virtual ~ShoppingList() {}

    void
    notify() override {                                      // ogni cambiamento del subject viene segnalato all'observer
        for (auto o: observerList)
            o->update();
    }

    void registerObserver(Observer *o) override {
        observerList.push_back(o);
    }

    void unregisterObserver(Observer *o) override {
        observerList.remove(o);
    }


    auto search(const Item &item){                                  // ricerca di un elemento nella lista

        for (auto itr = list.begin(); itr != list.end(); itr++) {
            if (itr->second == item) {
                return itr;                                         // restituisce l'iteratore all'elemento se lo trova
            }
        }
        throw ItemNotFound();                                       // se non trova l'elemento lancia un'eccezione
}



    void addToList(const Item &item) {                                              // aggiungo elemento alla lista
        auto itr = search(item);
        if (search(item) != list.end())
            itr->second.setQuantity(itr->second.getQuantity() +item.getQuantity()); // se l'elemento è già presente nella lista aggiorno la quantità
        else
            list.insert({item.getCategory(), item});                                // altrimenti lo aggiungo
        notify();
    }


    void decreaseQty(const Item &item) {
        decltype(list.begin()) itr;                               //dichiaro un iteratore
        try {
            itr = search(item);                                  //provo ad assegnare l'iteratore al risultato della ricerca
            int oldQuantity = itr->second.getQuantity();         // se la ricerca fallisce search lancia eccezione
            if (oldQuantity < item.getQuantity())                // se la quantità da rimuovere è maggiore di quella presente lancia eccezione
                throw NegativeQuantity();
            else
                int newQuantity = itr->second.getQuantity() - item.getQuantity(); // altrimenti aggiorno la quantità
        }

        catch (const ItemNotFound &e) {
            std::cerr << "Eccezione catturata " << e.what() << std::endl;
        }

        catch (const NegativeQuantity &e) {
            std::cerr << "Eccezione catturata" << e.what() << std::endl;
        }
    }

    void removeFromList(
            const Item &item) {                               // cancello un elemento (se presente nella lista) se non voglio più comprarlo
        auto itr = search(item);
        try {
            if (search((item)) != list.end())
                list.erase(itr);
            else
                throw std::runtime_error(
                        "Elemento non presente nella lista"); // lancio un'eccezione se l'elemento non è presente nella lista
            notify();
        }
        catch (const std::exception &e) {
            std::cerr << "Eccezione catturata " << e.what() << std::endl;
        }
    }


    void buyItem(Item &item) {                                             //compro un elemento
        auto itr = search(item);
        try {
            if (search(item) != list.end()) {
                int newQty = itr->second.getQuantity() - item.getQuantity();
                if (newQty >
                    0)                                               // se la  quantità ancora da comprare è > 0 la aggiorno
                    itr->second.setQuantity(newQty);
                else
                    itr->second.setBought(
                            true);                             // se la quantità è <= 0 setto l'elemento come comprato
            } else
                throw std::runtime_error(
                        "Elemento non presente nella lista"); // se l'elemento non è presente nella lista lancio un'eccezione
            notify();
        }
        catch (const std::exception &e) {
            std::cerr << "Eccezione catturata " << e.what() << std::endl;
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
    std::list<Observer *> observerList;;
};


#endif //LISTASPESA_SHOPPINGLIST_H
