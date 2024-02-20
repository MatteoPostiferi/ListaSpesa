//
// Created by Matteo Postiferi on 20/02/2024.
//

#ifndef LISTASPESA_NEGATIVEQUANTITY_H
#define LISTASPESA_NEGATIVEQUANTITY_H

#include <exception>

class NegativeQuantity : public std::exception {
public:
    const char *what() const noexcept override {
        return "Quantità negativa";
    };
};

#endif //LISTASPESA_NEGATIVEQUANTITY_H
