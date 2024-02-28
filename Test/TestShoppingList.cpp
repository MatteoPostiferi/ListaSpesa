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
    ShoppingList shoppingList("Generic List");

    EXPECT_EQ(shoppingList.getList().size(), 0);                         //controllo che la lista sia vuota

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    EXPECT_EQ(shoppingList.getList().size(), 2);                         //aggiungo elementi non presenti

    shoppingList.addToList(item);
    EXPECT_EQ(shoppingList.getList().size(), 2);                         //aggiungo elemento già presente, dunque incremento la quantità
    EXPECT_EQ(shoppingList.getList().begin()->second.getQuantity(), 16); //controllo che la quantità sia stata incrementata

    std::cout << "Test ShoppingList AddItem Done" << std::endl;
}

TEST(ShoppingListTest, RemoveFromList) {
    std::cout << "Test ShoppingList RemoveItem" << std::endl;
    Item item("Description", "Category", 8);
    Item item2("Description2", "Category2", 4);
    Item item3("Description3", "Category3", 4);
    ShoppingList shoppingList(" Generic List");

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    EXPECT_EQ(shoppingList.getList().size(), 2);                        //controllo che la lista sia stata riempita

    shoppingList.removeFromList(item);
    EXPECT_EQ(shoppingList.getList().size(), 1);                        //rimuovo un elemento
    shoppingList.removeFromList(item2);
    EXPECT_EQ(shoppingList.getList().size(), 0);                        //rimuovo l'ultimo elemento
    std::cout << "Test ShoppingList RemoveItem Done" << std::endl;

    EXPECT_THROW(shoppingList.removeFromList(item3), ItemNotFound);     //rimuovo un elemento non presente

    std::cout << "Test ShoppingList RemoveItem Done" << std::endl;
}

TEST(ShoppingListTest, decreaseQuantity) {
    std::cout << "Test ShoppingList decreaseQuantity" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    Item item3("Uova", "Proteine", 4);
    Item item4("Pizza", "Carboidrati", 4);
    ShoppingList shoppingList("Generic List");

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    EXPECT_EQ(shoppingList.getList().size(), 2);                        //controllo che la lista sia stata riempita

    shoppingList.decreaseQty(item3);
    EXPECT_EQ(shoppingList.getList().begin()->second.getQuantity(), 4); //decremento la quantità di un elemento
    EXPECT_EQ(shoppingList.getList().size(), 2);                        //controllo che la lista mantenga la stessa dimensione

    shoppingList.decreaseQty(item3);
    EXPECT_EQ(shoppingList.getList().size(), 1);                        //decremento la quantità di un elemento fino a 0 e
                                                                        // controllo che l'elemento venga rimosso

    EXPECT_THROW(shoppingList.decreaseQty(item4), NegativeQuantity);    //provo a diminuire la quantità di un elemento non presente e
                                                                        // lancio eccezione

    std::cout << "Test ShoppingList decreaseQuantity Done" << std::endl;

}
TEST(ShoppingListTest, buyItem) {
    std::cout << "Test ShoppingList buyItem" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    Item item3("Uova", "Proteine", 4);
    Item item4("Pizza", "Carboidrati", 4);
    ShoppingList shoppingList("Generic List");

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    shoppingList.buyItem(item3);
    EXPECT_EQ(shoppingList.getList().begin()->second.getQuantity(), 4); //decremento la quantità di un elemento
    EXPECT_FALSE(shoppingList.getList().begin()->second.isBought());    //controllo che l'elemento sia ancora da finire di comprare

    shoppingList.buyItem(item3);
    EXPECT_TRUE(shoppingList.getList().begin()->second.isBought());     //decremento la quantità di un elemento fino a 0 e
                                                                        // controllo che l'elemento venga segnato come comprato

    EXPECT_THROW(shoppingList.buyItem(item4), ItemNotFound);            //provo a comprare un elemento non presente e lancio eccezione

    std::cout << "Test ShoppingList buyItem Done" << std::endl;
}


