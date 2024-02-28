//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H


#include <string>
#include <map>
#include <list>
#include "Item.h"
#include "Subject.h"
#include "ItemNotFound.h"
#include "NegativeQuantity.h"
#include <stdexcept>
#include <iostream>



class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string &listName) : listName(listName) {
    }

    virtual ~ShoppingList() {}

    void notify() override {
        for (auto o: observerList)
            o->update();
    }

    void registerObserver(Observer *o) override {
        observerList.push_back(o);
    }

    void unregisterObserver(Observer *o) override {
        observerList.remove(o);
    }


    auto search (const Item &item) {                                                // ricerca di un elemento nella lista
        for (auto itr = list.begin(); itr != list.end(); itr++) {
            if (itr->second == item) {
                return itr;                                                         // restituisce l'iteratore all'elemento se lo trova
            }
        }
        throw ItemNotFound();                                                       // se non trova l'elemento lancia un'eccezione
    }


  /*  void addToList (const Item &item) {
        decltype(list.begin()) itr;                                                 // dichiaro un iteratore
        std::string desc = item.getDescription();
        try {
            itr = search(item);                                                     // provo ad assegnare l'iteratore al risultato della ricerca
            itr->second.setQuantity(itr->second.getQuantity() +
                                    item.getQuantity());                            // se l'elemento è già presente nella lista aggiorno la quantità
            std::cout << "Elemento gia presente, aggiorno la quantita di: " << desc << itr->second.getQuantity() << std::endl;
        }
        catch (const ItemNotFound &e) {
            std::cerr << e.what() << ", aggiungo " << desc << " alla lista" << std::endl;
            list.insert({desc,item});                                               // se l'elemento non è presente lo aggiungo
        }
        notify();
    }
    */
  void addToList(const Item &item){
      bool found = false;
      auto itr = list.begin();
      while(found == false && itr != list.end()){
          if (itr->second == item){
              itr->second.setQuantity(itr->second.getQuantity() + item.getQuantity()); // se l'elemento è già presente nella lista aggiorno la quantità
                found = true;
            }
          itr++;
      }
        if (found == false){
            list.insert({item.getDescription(), item});                             // altrimenti lo aggiungo
        }
  }


    void decreaseQty(const Item &item) {
        decltype(list.begin()) itr;                                                 // dichiaro un iteratore
        std::string desc = item.getDescription();

        try {
            itr = search(item);                                                     // provo ad assegnare l'iteratore al risultato della ricerca
            int newQty = itr->second.getQuantity() -
                         item.getQuantity();                                        // se la ricerca fallisce search lancia eccezione
            if (newQty < 0)                                                         // se la quantità da rimuovere è maggiore di quella presente lancia eccezione
                throw NegativeQuantity();
            else {
                if (newQty == 0) {                                                  // se la quantità da rimuovere è uguale a quella presente rimuovo l'elemento
                    list.erase(itr);
                    std::cout << desc << ": non piu nella lista" << std::endl;
                } else {
                    itr->second.setQuantity(newQty);                                // altrimenti aggiorno la quantità
                    std::cout << "Quantita aggiornata di " << desc << ": " << itr->second.getQuantity() << std::endl;
                }
            }
            notify();
        }

        catch (const ItemNotFound &e) {
            std::cerr << e.what() << std::endl;
        }

        catch (const NegativeQuantity &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void removeFromList(const Item &item) {                                         // cancello un elemento (se presente nella lista) se non voglio più comprarlo
        decltype(list.begin()) itr;                                                 // dichiaro un iteratore
        try {
            itr = search(item);                                                     // provo ad assegnare l'iteratore al risultato della ricerca
                list.erase(itr);
                std::cout << itr->second.getDescription() << ": non piu nella lista" << std::endl;
                notify();

        }
        catch (const ItemNotFound &e) {
            std::cerr << "Eccezione catturata " << e.what() << std::endl;
        }
    }


    void buyItem(Item &item) {
        decltype(list.begin()) itr;
        std::string desc = item.getDescription();

        try {
            itr = search(item);                                                    // provo ad assegnare l'iteratore al risultato della ricerca
            int newQty = itr->second.getQuantity() - item.getQuantity();
            if (newQty >0) {                                                       // se la  quantità ancora da comprare è > 0 la aggiorno
                itr->second.setQuantity(newQty);
                std::cout << "Quantita ancora da comprare di " << desc << ": " << itr->second.getQuantity() << std::endl;
            }
            else {
                itr->second.setBought(true);                                       // se la quantità è <= 0 setto l'elemento come comprato
                std::cout << desc << ": comprato " << std::endl;
            }
            notify();
        }

            catch (const ItemNotFound &e) {
                std::cerr << e.what() << std::endl;
            }

    }


    const std::multimap<std::string, Item> &getList() const {
        return list;
    }

    const std::string &getListName() const {
        return listName;
    }


private:
    std::string listName;
    std::multimap<std::string, Item> list;
    std::list<Observer *> observerList;;
};


#endif //LISTASPESA_SHOPPINGLIST_H
