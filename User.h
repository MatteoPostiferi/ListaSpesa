//
// Created by matte on 06/05/2024.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H


#include <string>
#include <vector>
#include "ShoppingList.h"

class User{
public:
    User(const std::string &name, const std::string &surname) : name(name), surname(surname) {}

    ShoppingList findListByName(std::string listName) {
        for (auto l: lists) {
            if (l->getListName() == listName)
                return *l;
        }
    }

    void newListToManage(std::string listName) {


    }







private:
    std::string name;
    std::string surname;
    std::vector<ShoppingList*> lists;


};


#endif //LISTASPESA_USER_H
