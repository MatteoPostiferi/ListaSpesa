//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H


#include <string>
#include <map>
#include <list>
#include "Item.h"
#include "Subject.h"


class ShoppingList : public Subject
{
public:
    explicit ShoppingList(const std::string& listName) : listName(listName)
    {
    }

    virtual ~ShoppingList()
    {
    }

    void notify() override
    {
        for (auto o : observerList)
            o->update();
    }

    void registerObserver(Observer* o) override
    {
        observerList.push_back(o);
    }

    void unregisterObserver(Observer* o) override
    {
        observerList.remove(o);
    }

    const std::map<std::string, Item>& getList() const
    {
        return list;
    }

    const std::string& getListName() const
    {
        return listName;
    }

    const int getTotalItems() const
    {
        return totalItems;
    }

    const int getToBuyItems() const
    {
        return toBuyItems;
    }

    std::map<std::string, Item>::iterator searchItem(const std::string& descr);
    // dato il nome di un oggetto, restituisce l'iteratore a quell'oggetto

    void addToList(const Item& item); // aggiungere un elemento alla lista

    void decreaseQty(const Item& item);
    // decrementare la quantità di un elemento, se vogliamo comprarne meno di quanto già scritto

    void removeFromList(const std::string& item); // cancellare un elemento se non vogliamo più comprarlo

    void buyItem(const Item& item); // comprare un elemento


private:
    std::string listName;
    std::map<std::string, Item> list;
    // A ogni stringa, che rappresenta la categoriaasx<<z dell'oggetto, associo l'oggetto in questione
    std::list<Observer*> observerList;
    int totalItems = 0;
    int toBuyItems = 0;
};


#endif //LISTASPESA_SHOPPINGLIST_H
