//
// Created by Ioana Ursu on 09/05/2022.
//

#include <cassert>
#include <cstring>
#include "tests.h"
#include "../Entity/Entity.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include "../console/console.h"

void testConstructor() {
    Entity ent;
    assert(ent.getName() == nullptr);
    assert(ent.getSum() == 0);
    assert(ent.getNumber() == 0);
}

void testSetterAndGetter() {
    Entity ent;
    ent.setId(1);
    ent.setSum(100);
    ent.setNumber(25);
    ent.setName("gaz");
    assert(strcmp(ent.getName(), "gaz") == 0);
    assert(ent.getNumber() == 25);
    assert(ent.getSum() == 100);
    assert(ent.getId() == 1);
}

void testRepo() {
    Repo repo;
    Entity ent0, ent1, ent2;
    const char *s2 = "curent";
    const char *s1 = "apa";
    const char *s0 = "gaz";
    ent0.setSum(100);
    ent0.setNumber(25);
    ent0.setName(const_cast<char *>(s0));
    ent1.setSum(100);
    ent1.setNumber(25);
    ent1.setName(const_cast<char *>(s1));
    ent2.setSum(100);
    ent2.setNumber(25);
    ent2.setName(const_cast<char *>(s2));
    repo.addItem(ent0);
    repo.addItem(ent1);
    repo.addItem(ent2);
    assert(repo.getSize() == 3);
}

void testDeleteEntities() {
    Repo repo;
    char s2[7] = "curent";
    char s1[4] = "apa";
    char s0[4] = "gaz";
    char s3[14] = "electricitate";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 24, 90);
    Entity ent3(3, s1, 23, 76);
    Entity ent4(4, s3, 22, 100);
    repo.addItem(ent1);
    repo.addItem(ent2);
    repo.addItem(ent3);
    repo.addItem(ent4);
    repo.deleteItem(3);
    assert(repo.getSize() == 3);
}

void testUpdateItem() {
    Repo repo;
    const char *s2 = "curent";
    const char *s1 = "apa";
    const char *s0 = "gaz";
    const char *s3 = "electricitate";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 24, 90);
    Entity ent3(3, s1, 23, 76);
    Entity ent4(4, s3, 22, 100);
    repo.addItem(ent1);
    repo.addItem(ent2);
    repo.addItem(ent3);
    repo.updateItem(ent1, ent4);
    assert(repo.getById(2) == ent2);
    assert(repo.getById(4) == ent4);
}

void testCreateService() {
    const char *s0 = "gaz";
    Entity ent(1, s0, 25, 200);
    Repo r;
    Service s;
    s.createEntity(ent);
    assert(s.getAll().size() == 1);
}

void testUpdateService() {
    Repo r;
    Service s;
    const char *s2 = "curent";
    const char *s1 = "apa";
    const char *s0 = "gaz";
    const char *s3 = "electricitate";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 24, 90);
    Entity ent3(3, s1, 23, 76);
    Entity ent4(4, s3, 22, 100);

    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.updateEntity(ent1, ent4);
    assert(s.getByID(4) == ent4);
}

void testDeleteService() {
    Service s;
    const char *s2 = "curent";
    const char *s1 = "apa";
    const char *s0 = "gaz";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 24, 90);
    Entity ent3(3, s1, 23, 76);

    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.deleteEntity(ent1);
    assert(s.getAll().size() == 2);
}

void test_elim_expense_by_app() {
    Service s;
    const char *s2 = "curent";
    const char *s1 = "apa";
    const char *s0 = "gaz";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 24, 90);
    Entity ent3(3, s1, 23, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    assert(s.getAll().size() == 3);
    s.elim_expense_by_app(24);
    assert(s.getAll().size() == 2);
    s.elim_expense_by_app(23);
    assert(s.getAll().size() == 1);

}

void test_elim_expenses_from_ap1_to_ap2() {
    Service s;
    const char *s0 = "curent";
    const char *s1 = "apa";
    const char *s2 = "gaz";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s1, 24, 90);
    Entity ent3(3, s2, 23, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    assert(s.getAll().size() == 3);
    s.elim_expenses_from_ap1_to_ap2(23, 24);
    assert(s.getAll().size() == 1);
}

void test_elim_all_expenses_for_a_given_type() {
    Service s;
    const char *s2 = "curent";
    const char *s1 = "gaz";
    const char *s0 = "gaz";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 24, 90);
    Entity ent3(3, s1, 23, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.elim_all_expenses_for_a_given_type("gaz");
    assert(s.getAll().size() == 1);
}

void test_replace_price_of_an_expense() {
    Service s;
    const char *s1 = "curent";
    Entity ent1(1, s1, 25, 150);
    s.createEntity(ent1);
    s.replace_price_of_an_expense("curent", 90, 25);
    assert(ent1.getSum() == 150);

}

void test_print_the_sum_of_all_expenses_by_a_given_type() {
    Service s;
    const char *s0 = "curent";
    const char *s1 = "gaz";
    const char *s2 = "gaz";
    Entity ent1(1, s0, 25, 90);
    Entity ent2(2, s1, 24, 150);
    Entity ent3(3, s2, 23, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    int sum;
    sum = s.print_the_sum_of_all_expenses_by_a_given_type("gaz");
    assert(sum == 150 + 76);

}

void test_print_the_biggest_type_of_expense_of_an_ap() {
    Service s;
    const char *s2 = "curent";
    const char *s1 = "gaz";
    const char *s0 = "intretinere";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 25, 90);
    Entity ent3(3, s1, 25, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    assert(s.print_the_biggest_type_of_expense_of_an_ap(25) == s.getByID(1));
}

void test_sort_all_expenses_by_a_given_type() {
    Service s;
    const char *s0 = "gaz";
    const char *s1 = "gaz";
    const char *s2 = "gaz";
    Entity ent1(1, s0, 25, 85);
    Entity ent2(2, s1, 24, 90);
    Entity ent3(3, s2, 23, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    vector<Entity> v;
    v = s.sort_all_expenses_by_a_given_type("gaz");
    vector<Entity> sort;
    sort.push_back(ent3) ;
    sort.push_back(ent1) ;
    sort.push_back(ent2) ;
    assert(v[0] == sort[0]);
    assert(v[1] == sort[1]);
    assert(v[2] == sort[2]);
}

void test_filter_by_expense_type() {
    Service s;
    const char *s2 = "curent";
    const char *s1 = "gaz";
    const char *s0 = "intretinere";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 25, 90);
    Entity ent3(3, s1, 25, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.filter_by_expense_type("gaz");
    assert(s.getAll().size() == 1);
}

void test_filter_by_sum() {
    Service s;
    const char *s2 = "curent";
    const char *s1 = "gaz";
    const char *s0 = "intretinere";
    Entity ent1(1, s0, 25, 150);
    Entity ent2(2, s2, 25, 90);
    Entity ent3(3, s1, 25, 76);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.filter_by_sum(100);
    assert(s.getAll().size() == 1);
}

void tests() {
    testConstructor();
    testSetterAndGetter();
    testRepo();
    testDeleteEntities();
    testUpdateItem();
    testUpdateService();
    testCreateService();
    testDeleteService();

    test_elim_expense_by_app();
    test_elim_expenses_from_ap1_to_ap2();
    test_elim_all_expenses_for_a_given_type();
    test_replace_price_of_an_expense();
    test_print_the_sum_of_all_expenses_by_a_given_type();
    test_print_the_biggest_type_of_expense_of_an_ap();
    test_sort_all_expenses_by_a_given_type();
    test_filter_by_expense_type();
    test_filter_by_sum();


}
