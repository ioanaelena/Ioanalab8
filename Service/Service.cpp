//
// Created by Ioana Ursu on 09/05/2022.
//

#include "Service.h"

Service::Service() = default;

Service::Service(Repo &r) {
    this->repo = r;
}

void Service::createEntity(Entity ent) {
    repo.addItem(ent);
}

void Service::updateEntity(Entity oldEnt, Entity newEntity) {
    repo.updateItem(oldEnt, newEntity);
}

void Service::deleteEntity(Entity ent) {
    repo.deleteItem(ent.getId());
}

void Service::readEntity(Repo r) {
    r.getAll();
}

Entity Service::getByID(int i) {
    return repo.getById(i);
}

vector<Entity> Service::getAll() {
    vector<Entity> entities = this->repo.getAll();
    return entities;
}

int Service::getSize() {
    return repo.getSize();
}

Service::~Service() = default;

void Service::undoS(vector<Entity> &vec) {
    repo.UndoR(vec);

}

void Service::elim_expense_by_app(int ap) {
    for (auto &ent: getAll())
        if (ent.getNumber() == ap)
            deleteEntity(ent);
}

void Service::list_all_apartments() {
    for (auto &ent: getAll())
        cout << ent;

}

void Service::elim_expenses_from_ap1_to_ap2(int ap1, int ap2) {
    for (auto &ent: getAll())
        if (ent.getNumber() >= ap1 and ent.getNumber() <= ap2)
            deleteEntity(ent);
}

void Service::elim_all_expenses_for_a_given_type(const char *name) {
    for (auto &ent: getAll())
        if (strcmp(ent.getName(), name) == 0)
            deleteEntity(ent);
}

void Service::replace_price_of_an_expense(const char *name, int sum_new, int ap) {
    for (auto &ent: getAll()) {
        if (ent.getNumber() == ap && strcmp(ent.getName(), name) == 0) {
            Entity ent_new(ent.getId(), name, ap, sum_new);
            updateEntity(ent, ent_new);
        }
    }
}

void Service::list_all_expenses_for_a_given_ap(int ap) {
    for (auto &ent: getAll())
        if (ent.getNumber() == ap)
            cout << ent;

}

void Service::list_all_expenses_bigger_than_a_given_sum(int sum) {
    for (auto &ent: getAll())
        if (ent.getSum() >= sum)
            cout << ent;
}

void Service::list_all_expenses_equal_to_a_given_sum(int sum) {
    for (auto &ent: getAll())
        if (ent.getSum() == sum)
            cout << ent;
}

int Service::print_the_sum_of_all_expenses_by_a_given_type(const char *name) {
    int sum = 0;
    for (auto &ent: getAll())
        if (strcmp(ent.getName(), name) == 0)
            sum = sum + ent.getSum();
    return sum;
}

Entity Service::print_the_biggest_type_of_expense_of_an_ap(int ap) {
    Entity e;
    int max_sum = 0;
    for (auto &ent: getAll())
        if (ent.getNumber() == ap)
            if (ent.getSum() >= max_sum) {
                e = ent;
                max_sum = ent.getSum();
            }
    return e;
}

vector<Entity> Service::sort_all_expenses_by_a_given_type(const char *name) {
    vector<Entity> v;
    for (auto &ent: getAll())
        if (strcmp(ent.getName(), name) == 0)
            v.push_back(ent);

    //sort(v.end(),v.begin());
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i; j < v.size(); j++)
            if (v[i].getSum() > v[j].getSum()) {
                Entity aux;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    return v;


}

void Service::filter_by_expense_type(const char *name) {
    for (auto &ent: getAll())
        if (strcmp(ent.getName(), name) < 0 or strcmp(ent.getName(), name) > 0)
            deleteEntity(ent);

}

void Service::filter_by_sum(int sum) {
    for (auto &ent: getAll())
        if (ent.getSum() <= sum)
            deleteEntity(ent);
}
