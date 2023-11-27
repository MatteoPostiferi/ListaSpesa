//
// Created by matte on 24/11/2023.
//

#ifndef LISTASPESA_ITEM_H
#define LISTASPESA_ITEM_H


#include <string>

class Item {
public:
    Item(const std::string &description, const std::string &category, int quantity, bool bought = false) : description(
            description), category(category), quantity(quantity), bought(bought) {}

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

    bool operator==(const Item& right){
        if (description==right.description && category==right.category)
            return true;
        else return false;
    }


private:
    std::string description;
std::string category;
int quantity;
bool bought;

};


#endif //LISTASPESA_ITEM_H
