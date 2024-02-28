//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_ITEM_H
#define LISTASPESA_ITEM_H

#include <string>
#include <stdexcept>

class Item {
public:
    Item(const std::string &description, const std::string &category, int quantity) : description(
            description), category(category), quantity(quantity){
        if (quantity < 0)
            throw std::invalid_argument("Quantity must be positive");
    }

    virtual ~Item() {}

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        Item::description = description;
    }

    const std::string &getCategory() const {
        return category;
    }

    void setCategory(const std::string &category) {
        Item::category = category;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Item::quantity = quantity;
    }

    bool isBought() const {
        return bought;
    }

    void setBought(bool bought) {
        Item::bought = bought;
    }

    bool operator== (const Item &right) {         // elementi con stesse descrizione e categoria sono uguali
        if (description == right.description && category == right.category)
            return true;
        else return false;
    }


private:
    std::string description;
    std::string category;
    int quantity;
    bool bought {false};

};


#endif //LISTASPESA_ITEM_H
