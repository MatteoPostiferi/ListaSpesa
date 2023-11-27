//
// Created by matte on 27/11/2023.
//

#ifndef LISTASPESA_TOTALITEMSCOUNTER_H
#define LISTASPESA_TOTALITEMSCOUNTER_H


#include "Observer.h"

class TotalItemsCounter : public Observer{
public:
    int update() override;

    ~TotalItemsCounter() override;

private:


};


#endif //LISTASPESA_TOTALITEMSCOUNTER_H
