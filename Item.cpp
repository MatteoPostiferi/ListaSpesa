//
// Created by Matteo Postiferi on 24/11/2023.
//

#include "Item.h"

Item::Item(const std::string& description, const std::string& category, int quantity) : description(
        description), category(category), quantity(quantity)
{
    if (quantity <= 0)
        throw NegativeQuantity();
}

Item::~Item()
{
}

const std::string& Item::getDescription() const
{
    return description;
}

void Item::setDescription(const std::string& description)
{
    Item::description = description;
}

const std::string& Item::getCategory() const
{
    return category;
}

void Item::setCategory(const std::string& category)
{
    Item::category = category;
}

int Item::getQuantity() const
{
    return quantity;
}

void Item::setQuantity(int quantity)
{
    Item::quantity = quantity;
}

bool Item::isBought() const
{
    return bought;
}

void Item::setBought(bool bought)
{
    Item::bought = bought;
}

bool Item::operator ==(const Item& right) const
{
    // elementi con stesse descrizione e categoria sono uguali
    if (description == right.description && category == right.category)
        return true;
    else return false;
}
