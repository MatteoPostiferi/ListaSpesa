//
// Created by matte on 23/02/2024.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../Item.h"

TEST(ShoppingListTest, Constructor) {
    std::cout << "Test ShoppingList Constructor" << std::endl;
    ShoppingList shoppingList("List1");
    EXPECT_EQ(shoppingList.getListName(), "List1");
    std::cout << "Test ShoppingList Constructor Done" << std::endl;

}
TEST(ShoppingListTest, AddToList) {
    std::cout << "Test ShoppingList AddItem" << std::endl;
    Item item("Description", "Category", 8);
    Item item2("Description2", "Category2", 4);
    ShoppingList shoppingList("List1");

    EXPECT_EQ(shoppingList.getList().size(), 0);                         //controllo che la lista sia vuota

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    EXPECT_EQ(shoppingList.getList().size(), 2);                         //aggiungo elementi non presenti

    shoppingList.addToList(item);
    EXPECT_EQ(shoppingList.getList().size(), 2);                         //aggiungo elemento già presente, dunque incremento la quantità
    EXPECT_EQ(shoppingList.getList().begin()->second.getQuantity(), 16); //controllo che la quantità sia stata incrementata

}
C