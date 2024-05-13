cmake_minimum_required(VERSION 3.25)

# 'lib' is the folder with Google Test sources
add_subdirectory(./lib) #aggiungo la sottocartella lib
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES RunAllTests.cpp TestShoppingList.cpp TestItem.cpp TestUser.cpp)
add_executable(Run_Google_Tests ${SOURCE_TEST_FILES})
# il nome dell'eseguibile è Run_Google_Tests, diverso dal nome del progetto
target_link_libraries(Run_Google_Tests gtest gtest_main core)