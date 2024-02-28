//
// Created by matte on 23/02/2024.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingListTest, Constructor) {
    std::cout << "Test ShoppingList Constructor" << std::endl;
    ShoppingList shoppingList("List1");
    ASSERT_EQ(shoppingList.getListName(), "List1");

}
TEST(ShoppingListTest, AddItem) {
