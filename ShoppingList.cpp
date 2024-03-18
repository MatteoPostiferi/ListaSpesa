//
// Created by Matteo Postiferi on 24/11/2023.
//
#include "ShoppingList.h"

auto ShoppingList::find(const Item &item) {
    for (auto itr = list.begin(); itr != list.end(); itr++) {
        if (itr->second == item) {
            return itr;                                                         // restituisce l'iteratore all'elemento se lo trova
        }
    }
    throw ItemNotFound();                                                       // se non trova l'elemento lancia un'eccezione
}

auto ShoppingList::searchItem(const std::string &descr) {
    auto itr = list.find(descr);
    if (itr != list.end()) {
        auto item = itr->second;
        std::cout << "Description: " << itr->first << std::endl;
        std::cout << "Category: " << item.getDescription() << std::endl;
        std::cout << "Quantity: " << item.getQuantity() << std::endl;
        std::cout << "Is Bought: " << item.isBought() << std::endl;
        return itr->second;


    } else
        throw ItemNotFound();
}

void ShoppingList::addToList(const Item &item) {
    auto key = item.getDescription();
    if (list.find(key) !=
        list.end())
        list[key].setQuantity(list[key].getQuantity() + item.getQuantity());  // se l'elemento esiste, incremento la quantità

    list.insert({item.getDescription(), item});                               // altrimenti lo aggiungo
}

void ShoppingList::decreaseQty(const Item &item) {
    decltype(list.begin()) itr;                                               // dichiaro un iteratore
    std::string desc = item.getDescription();

    try {
        itr = find(
                item);                                                        // provo ad assegnare l'iteratore al risultato della ricerca
        int newQty = (itr->second.getQuantity() -
                      item.getQuantity());                                    // se la ricerca fallisce, search lancia eccezione
        if (newQty <
            0)                                                                // se la quantità da rimuovere è maggiore di quella presente, lancia eccezione
            throw NegativeQuantity();
        else {
            if (newQty ==
                0) {                                                          // se la quantità da rimuovere è uguale a quella presente rimuovo l'elemento
                list.erase(itr->first);
                std::cout << desc << ": non piu nella lista" << std::endl;
            } else {
                itr->second.setQuantity(newQty);                              // altrimenti aggiorno la quantità
                std::cout << "Quantita aggiornata di " << desc << ": " << itr->second.getQuantity() << std::endl;
            }
        }
        notify();
    }

    catch (const ItemNotFound &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }

    catch (const NegativeQuantity &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }

}


void ShoppingList::removeFromList(
        const Item &item) {
    decltype(list.begin()) itr;                                            // dichiaro un iteratore
    try {
        itr = find(
                item);                                                     // provo ad assegnare l'iteratore al risultato della ricerca
        list.erase(itr);
        std::cout << itr->second.getDescription() << ": non piu nella lista" << std::endl;
        notify();

    }
    catch (const ItemNotFound &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}


void ShoppingList::buyItem(Item &item) {
    decltype(list.begin()) itr;
    std::string desc = item.getDescription();

    try {
        itr = find(
                item);                                                    // provo ad assegnare l'iteratore al risultato della ricerca
        int newQty = itr->second.getQuantity() - item.getQuantity();
        if (newQty >
            0) {                                                          // se la quantità ancora da comprare è > 0 la aggiorno
            itr->second.setQuantity(newQty);
            std::cout << "Quantita ancora da comprare di " << desc << ": " << itr->second.getQuantity()
                      << std::endl;
        } else {
            if (newQty == 0) {
                itr->second.setBought(
                        true);                                            // se la quantità è <= 0 setto l'elemento come comprato
                std::cout << desc << ": comprato " << std::endl;
            } else
                throw NegativeQuantity();                                 // se la quantità da comprare è < 0 lancia eccezione
        }
        notify();
    }

    catch (const ItemNotFound &e) {
        std::cerr << e.what() << std::endl;
    }

}
