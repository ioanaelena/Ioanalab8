//
// Created by Ioana Ursu on 09/05/2022.
//

#include "Entity.h"
#include <string.h>
#include <vector>

using namespace std;

const char *Entity::getName() {
    return name;
}

void Entity::setName(const char *n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

int Entity::getNumber() {
    return number;
}

void Entity::setNumber(int num) {
    this->number = num;
}

int Entity::getSum() {
    return sum;
}

void Entity::setSum(int s) {
    this->sum = s;
}

Entity::Entity() {
    this->name = nullptr;
    this->number = 0;
    this->sum = 0;
    this->id = 0;
}

Entity::Entity(const Entity &ent) {
    this->name = new char[strlen(ent.name) + 1];
    this->number = ent.number;
    this->sum = ent.sum;
    this->id = ent.id;
    strcpy_s(this->name, sizeof(this->name), ent.name);

}

Entity::Entity(int i, const char *name1, int num, int s) {
    this->name = new char[strlen(name1) + 1];
    strcpy_s(this->name, sizeof(this->name), name1);
    this->id = i;
    this->number = num;
    this->sum = s;

}

Entity::~Entity() {
    delete[] this->name;
}

Entity &Entity::operator=(const Entity &ent) {
    this->setName(ent.name);
    this->setNumber(ent.number);
    this->setSum(ent.sum);
    this->setId(ent.id);
    return *this;
}


void Entity::setId(int i) {
    this->id = i;
}

int Entity::getId() {
    return id;
}

bool Entity::operator==(const Entity &ent) {
    return this->sum == ent.sum && this->number == ent.number && this->id == ent.id &&
           strcmp(this->name, ent.name) == 0;
}

ostream &operator<<(ostream &out, Entity &e) {
    out << "id:" << e.id << " ";
    out << "name: " << e.name << " ";
    out << "number : " << e.number << " ";
    out << "sum : " << e.sum << " ";
    out << endl;
    return out;
}

bool Entity::operator<=(const Entity &ent1) {
    if (this->sum <= ent1.sum)
        return true;
    return false;
}

bool Entity::operator<(const Entity &ent1) {
    if (this->sum < ent1.sum)
        return true;
    return false;
}

bool Entity::operator>=(const Entity &ent1) {
    if (this->sum >= ent1.sum)
        return true;
    return false;
}

bool Entity::operator>(const Entity &ent1) {
    if (this->sum > ent1.sum)
        return true;
    return false;

}
