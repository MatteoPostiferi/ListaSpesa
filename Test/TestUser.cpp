//
// Created by matte on 07/05/2024.
//

#include "gtest/gtest.h"
#include "../User.h"


TEST(User, constructor){
    std::cout << "Test User Constructor" << std::endl << std::endl;
    std::cout << "Name : Matteo" << std::endl;
    User user("Matteo");
    EXPECT_EQ(user.getName(), "Matteo");
    std::cout << "User successfully created" << std::endl << std::endl;
    std::cout << "Test User Constructor done" << std::endl << std::endl;

}

TEST(User, addList) {
    std::cout << "Test User addList" << std::endl << std::endl;
    User user("Matteo");
    ShoppingList list("List1");
    user.addList(&list);
    EXPECT_EQ(user.getLists().size(),
              1);                         //controllo che la lista già creata in precedenza sia stata aggiunta
    EXPECT_EQ(user.getLists().at("List1"), &list);
    user.addList("List2");                                        //aggiungo una lista creandola
    EXPECT_EQ(user.getLists().size(), 2);                         //controllo che la lista sia stata aggiunta
    EXPECT_EQ(user.getLists().at("List2")->getListName(), "List2");
    user.printLists();
    std::cout << std::endl<< "Test User addList done" << std::endl << std::endl;
}

TEST(User, removeList) {
    std::cout << "Test User removeList" << std::endl << std::endl;
    User user("Matteo");
    ShoppingList list("List1");
    user.addList(&list);
    user.removeList("List2");
    user.removeList("List1");
    EXPECT_EQ(user.getLists().size(), 0);                         //controllo che la lista sia stata rimossa
    EXPECT_THROW(user.getLists().at("List1"), std::out_of_range); //controllo che la lista non sia più presente
    std::cout << std::endl<< "Test User removeList done" << std::endl << std::endl;
}

TEST(User, changeName) {
    std::cout << "Test User changeName" << std::endl << std::endl;
    User user("Matteo");
    user.changeName("Matte");
    EXPECT_EQ(user.getName(), "Matte");
    std::cout << "Test User changeName done" << std::endl << std::endl;
}