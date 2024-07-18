//
// Created by matte on 23/02/2024.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../TotalItemsCounter.h"

TEST(ShoppingListTest, Constructor)
{
    // provo a creare una lista
    std::cout << "Test ShoppingList Constructor" << std::endl;
    ShoppingList shoppingList("Test List");
    EXPECT_EQ(shoppingList.getListName(), "Test List"); // verifico il nome della lista
    std::cout << "list -" << shoppingList.getListName() << "- has been created" << std::endl;
    std::cout << "Test ShoppingList Constructor Done" << std::endl << std::endl;
}

TEST(ShoppingListTest, searchItem)
{
    std::cout << "Test ShoppingList searchItem" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    ShoppingList shoppingList("Test List");
    shoppingList.addToList(item2);
    std::cout << "searching item -" << item2.getDescription() << "- by using its description..." << std::endl;
    auto itr = shoppingList.searchItem("Pane");
    // provo a cercare un elemento presente nella lista tramite la sua chiave
    EXPECT_EQ(itr->second, item2); // controllo che l'elemento cercato sia quello corretto
    auto itr2 = shoppingList.searchItem("Uova");
    // provo a cercare un elemento non presente nella lista tramite la sua chiave
    EXPECT_EQ(itr2, shoppingList.getList().end()); // controllo che l'elemento cercato non sia presente

    std::cout << "Item -" << itr->second.getDescription() << "- has been found" << std::endl;
    std::cout << "Test ShoppingList searchItem Done" << std::endl << std::endl;
}

TEST(ShoppingListTest, AddToList)
{
    std::cout << "Test ShoppingList AddItem" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);

    ShoppingList shoppingList("Test List");

    EXPECT_EQ(shoppingList.getList().size(), 0); // controllo che la lista sia vuota
    std::cout << "list is empty" << std::endl;

    shoppingList.addToList(item);
    shoppingList.addToList(item2); // aggiungo elementi non presenti e controllo che
    EXPECT_EQ(shoppingList.getList().size(), 2); // vengano inseriti come nuovi elementi
    std::cout << "list size: " << shoppingList.getList().size() << std::endl;

    shoppingList.addToList(item); // aggiungo elemento già presente, dunque incremento la quantità
    EXPECT_EQ(shoppingList.getList().size(), 2); // degli elementi già presenti, ma non inserisco nuovi elementi

    auto itr = shoppingList.searchItem("Uova");
    EXPECT_EQ(itr->second.getQuantity(), 16); //controllo che la quantità sia stata incrementata
    std::cout << "quantity of " << itr->second.getDescription() << ":" << itr->second.getQuantity() << ", as expected"
        << std::endl;

    shoppingList.addToList(item2); // aggiungo elemento già presente, dunque incremento la quantità
    auto itr2 = shoppingList.searchItem("Pane");
    EXPECT_EQ(itr2->second.getQuantity(), 8); //controllo che la quantità sia stata incrementata
    std::cout << "quantity of " << itr2->second.getDescription() << ":" << itr2->second.getQuantity() << ", as expected"
        << std::endl;

    std::cout << "Test ShoppingList AddItem Done" << std::endl << std::endl;
}

TEST(ShoppingListTest, removeFromList)
{
    std::cout << "Test ShoppingList RemoveItem" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    Item item3("Carne", "Proteine", 4);
    ShoppingList shoppingList(" Generic List");

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    EXPECT_EQ(shoppingList.getList().size(), 2); //controllo che la lista sia stata riempita
    std::cout << "list size: " << shoppingList.getList().size() << std::endl;

    shoppingList.removeFromList("Uova"); //rimuovo un elemento presente nella lista
    EXPECT_EQ(shoppingList.getList().size(), 1);
    std::cout << "list size: " << shoppingList.getList().size() << std::endl;

    std::cout << "Trying to remove " << item3.getDescription() << ": ";
    shoppingList.removeFromList("Uova");
    //rimuovo un elemento non presente nella lista, la quale non cambierà dimensione
    EXPECT_EQ(shoppingList.getList().size(), 1);

    shoppingList.removeFromList("Pane");
    std::cout << "list size: " << shoppingList.getList().size() << std::endl;

    EXPECT_EQ(shoppingList.getList().size(), 0); //rimuovo l'ultimo elemento e controllo che la lista sia vuota

    std::cout << "Test ShoppingList RemoveItem Done" << std::endl << std::endl;
}

TEST(ShoppingListTest, DecreaseQuantity)
{
    std::cout << "Test ShoppingList decreaseQuantity" << std::endl;
    Item item("Pasta", "Carboidrati", 6);
    Item item2("Pasta", "Carboidrati", 3);
    Item item3("Carne", "Proteine", 4);
    Item item4("Carne", "Proteine", 6);
    Item item5("Pizza", "Carboidrati", 2);
    ShoppingList list("Test List");

    list.addToList(item);
    list.addToList(item3);

    std::cout << "trying to decrease " << item2.getDescription() << " quantity..." << std::endl;
    list.decreaseQty(item2);
    EXPECT_EQ(list.searchItem("Pasta")->second.getQuantity(), 3); //decremento la quantità di un elemento
    EXPECT_EQ(list.getList().size(), 2); //controllo che la lista non sia cambiata

    std::cout << "trying to decrease " << item2.getDescription() << " quantity..." << std::endl;
    list.decreaseQty(item2);
    EXPECT_EQ(list.getList().size(), 1); //controllo che l'elemento sia stato rimosso dalla lista

    std::cout << "trying to decrease " << item4.getDescription() << " quantity..." << std::endl;
    list.decreaseQty(item4);
    EXPECT_EQ(list.getList().size(), 1); //controllo che la lista non sia cambiata

    std::cout << "trying to decrease " << item5.getDescription() << " quantity..." << std::endl;
    list.decreaseQty(item5);

    std::cout << "Test ShoppingList decreaseQuantity Done" << std::endl << std::endl;
}

TEST(ShoppingListTest, buyItem)
{
    std::cout << "Test ShoppingList buyItem" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    Item item3("Uova", "Proteine", 4);
    Item item4("Pane", "Carboidrati", 5);
    Item item5("Pizza", "Carboidrati", 4);
    ShoppingList shoppingList("Generic List");

    shoppingList.addToList(item);
    shoppingList.addToList(item2);
    std::cout << "trying to buy " << item3.getDescription() << "..." << std::endl;
    shoppingList.buyItem(item3);
    EXPECT_EQ(shoppingList.searchItem("Uova")->second.getQuantity(), 4); //decremento la quantità di un elemento
    EXPECT_FALSE(shoppingList.searchItem("Uova")->second.isBought());
    //controllo che l'elemento sia ancora da finire di comprare

    std::cout << "trying to buy " << item3.getDescription() << "..." << std::endl;
    shoppingList.buyItem(item3);
    EXPECT_TRUE(shoppingList.searchItem("Uova")->second.isBought());
    //controllo che l'elemento venga segnato come comprato

    std::cout << "trying to buy " << item4.getDescription() << "..." << std::endl;
    shoppingList.buyItem(item4);
    EXPECT_EQ(shoppingList.getList().size(), 2);

    std::cout << "trying to buy " << item5.getDescription() << "..." << std::endl;
    shoppingList.buyItem(item5);

    std::cout << "Test ShoppingList buyItem Done" << std::endl << std::endl;
}

TEST(ShoppingListTest, ItemsToBuyCounter)
{
    std::cout << "Test ShoppingList ItemsToBuyCounter" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    Item item3("Uova", "Proteine", 4);
    Item item4("Uova", "Proteine", 12);

    ShoppingList list("Test List");
    ItemsToBuyCounter counter(&list);
    list.addToList(item);
    list.addToList(item);
    list.addToList(item2);
    list.buyItem(item3);
    list.buyItem(item4);
    list.removeFromList(item2.getDescription());
    std::cout << "Test ShoppingList ItemsToBuyCounter done" << std::endl << std::endl;
}


TEST(ShoppingListTest, TotalItemsCounter)
{
    std::cout << "Test ShoppingList TotalItemsCounter" << std::endl;
    Item item("Uova", "Proteine", 8);
    Item item2("Pane", "Carboidrati", 4);
    Item item3("Uova", "Proteine", 16);
    Item item5("Pizza", "Carboidrati", 4);
    ShoppingList list("Test List");
    TotalItemsCounter totalCounter(&list);

    list.addToList(item);
    list.addToList(item);
    list.addToList(item2);
    list.removeFromList(item2.getDescription());
    list.addToList(item5);
    list.decreaseQty(item3);
    std::cout << "Test ShoppingList TotalItems Done" << std::endl << std::endl;
}
