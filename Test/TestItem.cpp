#include "../Item.h"
#include <gtest/gtest.h>

TEST(ItemTest, Constructor) {
    std::cout << "Test Item Constructor" << std::endl << std::endl;
    std::cout << " Description : Petto di pollo" << std::endl;
    std::cout << "Category : Carne" << std::endl;
    std::cout << "Quantity : 2" << std::endl;
    std::cout << "Bought : false" << std::endl;

    Item item("Petto di pollo", "Carne", 2);
    EXPECT_EQ(item.getDescription(), "Petto di pollo");
    EXPECT_EQ(item.getCategory(), "Carne");
    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_FALSE(item.isBought());
    std::cout << "Oggetto creato correttamente" << std::endl << std::endl;

    std::cout << " Description : Petto di pollo" << std::endl;
    std::cout << "Category : Carne" << std::endl;
    std::cout << "Quantity : -4" << std::endl;
    std::cout << "Bought : false" << std::endl;

    EXPECT_THROW(Item("Petto di pollo", "Carne", -4), NegativeQuantity);
    std::cout << "Eccezione lanciata correttamente" << std::endl << std::endl;

    std::cout << "Test Item Constructor done " << std::endl << std::endl;

}