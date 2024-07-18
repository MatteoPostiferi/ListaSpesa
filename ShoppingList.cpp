//
// Created by Matteo Postiferi on 24/11/2023.
//
#include "ShoppingList.h"
#include <iostream>


std::map<std::string, Item>::iterator ShoppingList::searchItem(const std::string& descr)
{
    // cerca un Item tramite la sua chiave (descrizione)
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        if (itr->second.getDescription() == descr)
            return itr; // ritorna itr all'oggetto se la ricerca va a buon fine
    }
    return list.end(); // altrimenti iteratore vuoto
}


void ShoppingList::addToList(const Item& item)
{
    std::string desc = item.getDescription();
    bool added = false;
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        if (itr->second.getDescription() == desc)
        {
            // se l'elemento esiste, incremento la quantità
            itr->second.setQuantity(itr->second.getQuantity() + item.getQuantity());
            std::cout << desc << " quantity updated: " << itr->second.getQuantity() << std::endl;
            added = true;
        }
    }
    if (!added)
    {
        list.insert({item.getCategory(), item}); // altrimenti lo aggiungo
        totalItems++;
        toBuyItems++;
        std::cout << desc << " added to list" << std::endl;
    }
    notify();
}

void ShoppingList::decreaseQty(const Item& item)
// se voglio comprare meno elementi di quanti sono segnati sulla lista, decremento la quantità
{
    bool decreased = false;
    std::string desc = item.getDescription();
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        int newQty = itr->second.getQuantity() - item.getQuantity();
        if (itr->second.getDescription() == desc)
        {
            int newQty = itr->second.getQuantity() - item.getQuantity();
            if (newQty > 0)
            {
                std::cout << "old " << desc << " quantity " << itr->second.getQuantity() << " --> new quantity " <<
                    newQty << std::endl;
                itr->second.setQuantity(newQty);
                decreased = true;
                break;
            }
            if (newQty == 0) // se la quantità aggiornata è 0, elimino l'elemento
            {
                list.erase(itr);
                totalItems--;
                toBuyItems--;
                std::cout << desc << " new quantity was 0, so " << item.getDescription() << " has been removed " <<
                    std::endl;
                decreased = true;
                break;
            }
            if (newQty < 0)
            {
                decreased = true;
                std::cout << "Error, you are trying to remove too many elements" << std::endl;
                // se è minore di 0, stampa messaggio di errore
                break;
            }
        }
    }
    if (!decreased)
    {
        std::cout << "this item is not in the list, you can't decrease its quantity" << std::endl;
    }
    notify();
}


void ShoppingList::removeFromList(const std::string& item) // elimino dalla lista elementi che non voglio più comprare
{
    bool removed = false;
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        if (itr->second.getDescription() == item)
        {
            removed = true;
            list.erase(itr);
            totalItems--;
            toBuyItems--;
            std::cout << item << " has been removed" << std::endl;
            break;
        }
    }
    if (!removed)
        std::cout << "this item is not in the list, you can't remove it" << std::endl;
    notify();
}

void ShoppingList::buyItem(const Item& item)
{
    bool bought = false;
    std::string desc = item.getDescription();
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        if (itr->second.getDescription() == desc)
        {
            int newQty = itr->second.getQuantity() - item.getQuantity();
            if (newQty > 0)
            {
                // se la quantità ancora da comprare è > 0 la aggiorno
                itr->second.setQuantity(newQty);
                std::cout << desc << "'s remaining quantity to buy: " << itr->second.getQuantity() << std::endl;
                bought = true;
                break;
            }
            if (newQty == 0)
            {
                itr->second.setBought(true); // se la quantità è = 0 setto l'elemento come comprato
                toBuyItems--;
                std::cout << desc << ": bought " << std::endl;
                bought = true;
                break;
            }
            if (newQty < 0)
            {
                bought = true;
                std::cout << "Error, you are trying to buy too many elements" << std::endl;
                break;
            }
        }
    }
    if (!bought)
        std::cout << "Item not found, you can't buy it" << std::endl;
    notify();
}
