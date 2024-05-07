//
// Created by Matteo Postiferi on 24/11/2023.
//
#include "ShoppingList.h"

std::map<std::string,Item>::iterator ShoppingList::searchItem(const std::string &descr){    // cerca un Item tramite la sua chiave (descrizione)
    for (auto itr = list.begin(); itr != list.end(); itr++) {
        if (itr->first == descr)
            return itr;                                                      // ritorna itr all'oggetto se la ricerca va a buon fine
    }
    return list.end();                                                       // altrimenti iteratore vuoto
}


void ShoppingList::addToList(const Item &item) {
    std::string key = item.getDescription();
    if (list.find(key) !=list.end())
        list[key].setQuantity(list[key].getQuantity() + item.getQuantity());  // se l'elemento esiste, incremento la quantità

        else
        list.insert({item.getDescription(), item});                           // altrimenti lo aggiungo
        std::cout << key << " : added to list" << std::endl;
    notify();
}

void ShoppingList::decreaseQty(const Item &item) {                            // se voglio comprare meno elementi di quanti sono segnati sulla lista, decremento la quantità
    std::string desc = item.getDescription();
    if (list.find(desc) !=list.end()) {
        int newQty = list[desc].getQuantity() - item.getQuantity();
        if (newQty > 0) {
            list[desc].setQuantity(newQty);
            std::cout << "New " << desc << " quantity: " << list[desc].getQuantity() << std::endl;
        }
        else {
            if (newQty == 0) {                                                // se la quantità aggiornata è 0, elimino l'elemento
                list.erase(desc);
                std::cout << desc<< " has been removed " << std::endl;
            }
            else                                                              // se è minore di 0, stampa messaggio di errore
                std::cout << "Error, you are trying to remove too many elements" << std::endl;
        }
    }
    else
        std::cout << "Item not found, you can't decrease its quantity" << std::endl;
    notify();
}


void ShoppingList::removeFromList(const Item &item) {                         // elimino dalla lista elementi che non voglio più comprare
    std::string desc = item.getDescription();
    if (list.find(desc) !=list.end()) {
        list.erase(desc);
        std::cout << desc << " has been removed" << std::endl;
    }
    else
        std::cout << "Item not found, you can't remove it" << std::endl;
    notify();
}


void ShoppingList::buyItem(Item &item) {
    std::string desc = item.getDescription();
    if (list.find(desc) !=list.end()) {
        int newQty = list[desc].getQuantity() - item.getQuantity();
        if (newQty > 0) {                                                      // se la quantità ancora da comprare è > 0 la aggiorno
            list[desc].setQuantity(newQty);
            std::cout << "Quantity of: " << desc << " left to buy: " << list[desc].getQuantity()<< std::endl;
        }
        else {
            if (newQty == 0) {
                list[desc].setBought(
                        true);                                    // se la quantità è = 0 setto l'elemento come comprato
                std::cout << desc << ": bought " << std::endl;
            } else
                std::cout << "Error, you are trying to buy too many elements" << std::endl;
        }
    }
    else
        std::cout << "Item not found, you can't buy it" << std::endl;
    notify();
}



