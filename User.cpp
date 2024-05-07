//
// Created by matte on 06/05/2024.
//
#include "User.h"

User::User(const std::string &name, const std::string &surname) : name(name) {}

void User::addList(ShoppingList* list){                     //aggiunge una lista esistente
    lists.insert({list->getListName(),list });
    std::cout<< list->getListName() << " is now a " << name << "'s responsibility" << std::endl;

}

void User::addList(const std::string &listName){
    ShoppingList* list = new ShoppingList(listName);        //crea una nuova lista e la aggiunge
    lists.insert({listName,list });
    std::cout<< listName <<" is now a " << name << "'s responsibility" << std::endl;
}

void User::removeList(std::string listName){
    auto it = lists.find(name);
    if(it == lists.end()){
        std::cout << listName << " not found" << std::endl;
        return;
    }
    lists.erase(it);
    std::cout << listName << " is not a " << name << "'s responsibility anymore" << std::endl;

}

void User::changeName(const std::string &name){
    auto oldName = this->name;
    this->name = name;
    std::cout << "Name changed from " << oldName << " to " << name << std::endl;
}
