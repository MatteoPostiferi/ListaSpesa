//
// Created by matte on 06/05/2024.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H

#include "ShoppingList.h"

class User{
public:
    User(const std::string &name, const std::string &surname);

    void addList(ShoppingList* list);                     //aggiunge una lista esistente

    void addList(const std::string &listName);

    void removeList(std::string name);

    void changeName(const std::string &name);

private:
    std::string name;
    std::map<std::string, ShoppingList*> lists;            //liste in gestione all'utente


};


#endif //LISTASPESA_USER_H
