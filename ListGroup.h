//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_LISTGROUP_H
#define LISTASPESA_LISTGROUP_H

#include "ShoppingList.h"
#include "Subject.h"


class ListGroup : Subject {
public:
    explicit ListGroup(const std::string &listGroupName) : listGroupName(listGroupName) {
        notify();
    }

    virtual ~ListGroup() {};

    void notify() override {
        for (auto l: listGroup) {
            l.notify();
        }
    }

    void registerObserver(Observer *o) override {
        observerList.push_back(o);
    }

    void unregisterObserver(Observer *o) override {
        observerList.remove(o);
    }

    void const addList(const ShoppingList &l) {
        listGroup.push_back(l);
        notify();
    }

    void const removeList(const ShoppingList &l) {
        for (auto itr = listGroup.begin(); itr != listGroup.end(); itr++) {
            if (l.getListName() == itr->getListName())
                listGroup.erase(itr);
        }
        notify();
    }

    const std::list<ShoppingList> &getListGroup() const {
        return listGroup;
    }

private:
    std::list<ShoppingList> listGroup;
    std::string listGroupName;
    std::list<Observer *> observerList;


};


#endif //LISTASPESA_LISTGROUP_H
