//
// Created by Matteo Postiferi on 20/02/2024.
//

#ifndef LISTASPESA_ITEMNOTFOUND_H
#define LISTASPESA_ITEMNOTFOUND_H

#include <exception>

class ItemNotFound : public std::exception {
public:
    const char *what() const noexcept override {
        return ": articolo non presente nella lista";
    };
};

#endif //LISTASPESA_ITEMNOTFOUND_H
