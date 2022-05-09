//
// Created by Ioana Ursu on 09/05/2022.
//

#ifndef LAB88888I_REPO_H
#define LAB88888I_REPO_H


#include "../Entity/Entity.h"
#include <iostream>
#include <vector>
using namespace std;

class Repo {
private:
    Entity entities[100];
    long long numberOfEntities;
public:
    Repo();
    ~Repo();
    void addItem(Entity &ent);
    int getSize() const;
    vector <Entity> getAll() const;
    void deleteItem(int id);
    void updateItem(Entity &entOld, Entity &entNew);
    Entity getById(int i);
    int getSizeRepo();
    void UndoR(vector <Entity> &v);
};



#endif //LAB88888I_REPO_H
