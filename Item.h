//
// Created by Matteo Postiferi on 24/11/2023.
//

#ifndef LISTASPESA_ITEM_H
#define LISTASPESA_ITEM_H

#include <string>
#include "NegativeQuantity.h"

class Item {
public:
    Item(const std::string &description, const std::string &category, int quantity);

    virtual ~Item();

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getCategory() const;

    void setCategory(const std::string &category);

    int getQuantity() const;

    void setQuantity(int quantity);

    bool isBought() const;

    void setBought(bool bought);

    bool operator==(const Item &right) const;        // elementi con stesse descrizione e categoria sono uguali

private:
    std::string description;
    std::string category;
    int quantity;
    bool bought{false};

};


#endif //LISTASPESA_ITEM_H
