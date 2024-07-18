//
// Created by matte on 06/05/2024.
//
#include "User.h"
#include <iostream>

User::User(const std::string& name) : name(name)
{
}

void User::addList(ShoppingList* list)
{
    //aggiunge una lista esistente
    lists.insert({list->getListName(), list});
    std::cout << list->getListName() << " is now a " << name << "'s responsibility" << std::endl;
}

void User::addList(const std::string& listName)
{
    //crea una nuova lista e la aggiunge
    ShoppingList* list = new ShoppingList(listName);
    lists.insert({listName, list});
    std::cout << listName << " is now a " << name << "'s responsibility" << std::endl;
}

void User::removeList(const std::string listName)
{
    auto it = lists.find(listName);
    if (it == lists.end())
    {
        std::cout << "Error, you are trying to remove " << listName << ", which doesn't exist " << std::endl;
        return;
    }
    //delete it->second;
    lists.erase(it);
    std::cout << listName << " is not a " << name << "'s responsibility anymore" << std::endl;
}

void User::changeName(const std::string& name)
{
    auto oldName = this->name;
    if (oldName == name)
    {
        std::cout << "name " << name << " is already in use" << std::endl;
    }
    else
    {
        this->name = name;
        std::cout << "name changed from " << oldName << " to " << name << std::endl;
    }
}

void User::printLists() const
{
    std::cout << "Lists in " << name << "'s management: ";
    for (auto l : lists)
    {
        std::cout << l.first << " ";
    }
    std::cout << std::endl;
}


const std::string& User::getName() const
{
    return name;
}

void User::setName(const std::string& name)
{
    User::name = name;
}

const std::map<std::string, ShoppingList*>& User::getLists() const
{
    return lists;
}

void User::setLists(const std::map<std::string, ShoppingList*>& lists)
{
    User::lists = lists;
}
