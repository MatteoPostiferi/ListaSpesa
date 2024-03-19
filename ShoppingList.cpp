//
// Created by Matteo Postiferi on 24/11/2023.
//
#include "ShoppingList.h"

auto ShoppingList::searchItem(const std::string &descr) {
    for(auto itr = list.begin(); itr!= list.end(); itr++){
        if (itr->first == descr)
            return itr->second;
    }
    std::cout << "Elemento non presente nella lista" << std::endl;
}



void ShoppingList::addToList(const Item &item) {
    std::string key = item.getDescription();
    if (list.find(key) !=list.end())
        list[key].setQuantity(list[key].getQuantity() + item.getQuantity());  // se l'elemento esiste, incremento la quantità

        else
        list.insert({item.getDescription(), item});                           // altrimenti lo aggiungo
        std::cout << key << " : aggiunto alla lista" << std::endl;
    notify();
}

void ShoppingList::decreaseQty(const Item &item) {                            // se voglio comprare meno elementi di quanti sono segnati sulla lista, decremento la quantità
    std::string desc = item.getDescription();
    if (list.find(desc) !=list.end()) {
        int newQty = list[desc].getQuantity() - item.getQuantity();
        if (newQty > 0) {
            list[desc].setQuantity(newQty);
            std::cout << "Quantità aggiornata di " << desc << ": " << list[desc].getQuantity() << std::endl;
        }
        else {
            if (newQty == 0) {                                                // se la quantità aggiornata è 0, elimino l'elemento
                list.erase(desc);
                std::cout << "Il seguente elemento è stato eliminato: " << desc << std::endl;
            }
            else                                                              // se è minore di 0, stampa messaggio di errore
                std::cout << "Errore, si vogliono rimuovere piu elementi di quanti ce ne sono" << std::endl;
        }
    }
    else
        std::cout << "Elemento non presente, impossibile rimuoverlo" << std::endl;
    notify();
}


void ShoppingList::removeFromList(const Item &item) {                         // elimino dalla lista elementi che non voglio più comprare
    std::string desc = item.getDescription();
    if (list.find(desc) !=list.end()) {
        list.erase(desc);
        std::cout << "Il seguente oggetto è stato eliminato: " << desc << std::endl;
    }
    else
        std::cout << "Elemento non presente, impossibile rimuoverlo" << std::endl;
    notify();
}


void ShoppingList::buyItem(Item &item) {
    std::string desc = item.getDescription();
    if (list.find(desc) !=list.end()) {
        int newQty = list[desc].getQuantity() - item.getQuantity();
        if (newQty > 0) {                                                      // se la quantità ancora da comprare è > 0 la aggiorno
            list[desc].setQuantity(newQty);
            std::cout << "Quantita ancora da comprare di " << desc << ": " << list[desc].getQuantity()<< std::endl;
        }
        else {
            if (newQty == 0) {
                list[desc].setBought(
                        true);                                    // se la quantità è = 0 setto l'elemento come comprato
                std::cout << desc << ": comprato " << std::endl;
            } else
                std::cout << "Errore, si vogliono comprare più oggetti di quelli segnati nella lista" << std::endl;
        }
    }
    else
        std::cout << "Elemento non presente nella lista, impossibile comprarlo" << std::endl;
    notify();
}


