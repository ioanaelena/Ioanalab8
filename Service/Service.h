//
// Created by Ioana Ursu on 09/05/2022.
//

#ifndef LAB88888I_SERVICE_H
#define LAB88888I_SERVICE_H


#include "../Repo/Repo.h"
#include "../Entity/Entity.h"
#include <vector>

class Service {
private:
    Repo repo;
public:
    Service();
    explicit Service(Repo& r);
    ~Service();
    void createEntity(Entity ent);
    void updateEntity(Entity oldEnt, Entity newEntity);
    void deleteEntity(Entity ent);
    void readEntity(Repo r);
    Entity getByID(int i);
    vector<Entity>getAll();
    int getSize();
    void undoS(vector <Entity> &vec);
    void elim_expense_by_app(int ap);
    void list_all_apartments();
    void elim_expenses_from_ap1_to_ap2(int ap1,int ap2);
    void elim_all_expenses_for_a_given_type(const char* name);
    void replace_price_of_an_expense(const char* name,int sum_new,int ap);
    void list_all_expenses_for_a_given_ap(int ap);
    void list_all_expenses_bigger_than_a_given_sum(int sum);
    void list_all_expenses_equal_to_a_given_sum(int sum);
    int print_the_sum_of_all_expenses_by_a_given_type(const char* name);
    Entity print_the_biggest_type_of_expense_of_an_ap(int ap);
    vector<Entity> sort_all_expenses_by_a_given_type(const char* name);
    void filter_by_expense_type(const char*name);
    void filter_by_sum(int sum);

};


#endif //LAB88888I_SERVICE_H
