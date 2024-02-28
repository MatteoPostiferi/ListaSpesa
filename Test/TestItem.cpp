//
// Created by matte on 23/02/2024.
//
#include "../Item.h"
#include <gtest/gtest.h>

TEST (ItemTest, Constructor) {                               // provo a creare un oggetto
    std::cout << "Test Item Constructor" << std::endl;
    std::string description = "Petto di pollo";
    std::string category = "Carne";
    std::string quantity = "2";
    std::string bought = "false";

    Item item("Petto di pollo", "Carne", 2);
    EXPECT_EQ(item.getDescription(), "Petto di pollo");
    EXPECT_EQ(item.getCategory(), "Carne");
    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_FALSE(item.isBought());

    Item item2("Petto di pollo", "Carne", -4);
    EXPECT_THROW(item2.getQuantity(), std::invalid_argument); // controllo che il costruttore lanci un'eccezione se la quantità è negativa

    std::cout << "Test Item Constructor" << std::endl;

}
