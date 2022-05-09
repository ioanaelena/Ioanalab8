//
// Created by Ioana Ursu on 09/05/2022.
//

#ifndef LAB88888I_CONSOLE_H
#define LAB88888I_CONSOLE_H


#include "../Repo/Repo.h"
#include "../Service/Service.h"
class Console{
private:
    Service service;
public:
    Console();
    ~Console();
    void runMenu();

};

#endif //LAB88888I_CONSOLE_H
