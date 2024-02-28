cmake_minimum_required(VERSION 3.25)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Test) #dico al cmake di controllare se nella cartella Test c'è un file CMakeLists.txt per compilare un secondo programma
                       #Test ha il suo progetto cmake !!


set(SOURCE_FILES main.cpp Item.cpp ShoppingList.cpp Subject.cpp Observer.cpp ItemsListCounter.cpp ListGroup.cpp TotalItemsCounter.cpp ItemNotFound.h NegativeQuantity.h )
add_executable(ListaSpesa ${SOURCE_FILES}) #potevo aggiungere solo il main se includevo gli header?
add_library(core ${SOURCE_FILES}) #tratto i test come una libreria di nome core?
target_link_libraries(ListaSpesa core)

