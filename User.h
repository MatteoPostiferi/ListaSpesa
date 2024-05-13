//
// Created by matte on 06/05/2024.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H

#include "ShoppingList.h"
#include <memory>

class User{
public:
    User(const std::string &name);

    void addList(ShoppingList* list);                     //aggiunge una lista esistente

    void addList(const std::string &listName);

    void removeList(const std::string name);

    void changeName(const std::string &name);

    void printLists() const;

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::map<std::string, ShoppingList *> &getLists() const;

    void setLists(const std::map<std::string, ShoppingList *> &lists);

private:
    std::string name;
    std::map<std::string, ShoppingList* > lists;            //liste in gestione all'utente


};


#endif //LISTASPESA_USER_H
