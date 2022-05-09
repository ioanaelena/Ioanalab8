//
// Created by Ioana Ursu on 09/05/2022.
//

#ifndef LAB88888I_ENTITY_H
#define LAB88888I_ENTITY_H


#include <vector>
#include <cstring>
#include <iostream>
using namespace std;


class Entity {
private:
    char* name;
    int number;
    int sum,id;
    const vector<const char*> possible_entities = {"apa", "curent", "gaz", "electricitate", "caldura","internet","altele"};
public:
    Entity();
    Entity(const Entity &ent);
    Entity(int i, const char *name1, int num, int s);
    const char *getName();
    void setName(const char *n);
    void setId(int i);
    int getId();
    int getNumber();
    void setNumber(int num);
    int getSum();
    void setSum(int s);
    Entity &operator=(const Entity &ent);
    bool operator==(const Entity &ent);
    friend ostream &operator<<(ostream &out, Entity &e);
    bool operator <=(const Entity &ent1);
    bool operator <(const Entity &ent1);
    bool operator >=(const Entity &ent1);
    bool operator >(const Entity &ent1);
    ~Entity();

};


#endif //LAB88888I_ENTITY_H
