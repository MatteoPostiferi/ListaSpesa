cmake_minimum_required(VERSION 3.25)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListaSpesa main.cpp Item.cpp Item.h ShoppingList.cpp ShoppingList.h Subject.cpp Subject.h Observer.cpp Observer.h ItemsListCounter.cpp ItemsListCounter.h ListGroup.cpp ListGroup.h)
