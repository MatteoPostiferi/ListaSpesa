cmake_minimum_required(VERSION 3.25)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Test)

set(SOURCE_FILES Item.cpp ShoppingList.cpp ItemsToBuyCounter.cpp TotalItemsCounter.cpp User.cpp)
add_executable(ListaSpesa ${SOURCE_FILES})
add_library(core ${SOURCE_FILES} NegativeQuantity.h User.h
        main.cpp)
target_link_libraries(ListaSpesa core)

