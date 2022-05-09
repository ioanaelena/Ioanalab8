//
// Created by Ioana Ursu on 09/05/2022.
//

#include "console.h"
#include <iostream>
#include "../Service/Service.h"
#include "cstring"
#include <algorithm>

using namespace std;

Console::Console() {

}

Console::~Console() {

}


void Options() {
    cout << endl << "1.Add an expense to the list of expense" << endl;
    cout << "2.Eliminate all expenses for a given apartment" << endl;
    cout << "3.Eliminate all expenses from apartment a to b" << endl;
    cout << "4.Eliminate all expenses for a given expense type" << endl;
    cout << "5.Replace the price of an expense  to a given apartment" << endl;
    cout << "6.List all of the expenses" << endl;
    cout << "7.List all expenses for a given apartment" << endl;
    cout << "8.List all the expenses with the price bigger than a given price" << endl;
    cout << "9.List all expenses equal to a given price" << endl;
    cout << "s.Calculates the sum of all expenses of the apartments for a given expense type" << endl;
    cout << "a.Shows the biggest expense of an apartment given by number." << endl;
    cout << "b.Sorts the list of expenses descending for a given expense" << endl;
    cout << "c.Filter for a given expense type" << endl;
    cout << "d.Filter for the expenses with a smaller price then a given number" << endl;
    cout << "u.Undo the last operation" << endl;
    cout << "x.Close app." << endl;
}




void Console::runMenu() {
    char option;
    bool ok = true;
    vector<Entity> v;
    while (ok) {
        Options();
        cout << "Give the option you want: ";
        cin >> option;
        switch (option) {
            case '1': {
                v = service.getAll();
                cout << "Give the id of the apartment" << endl;
                int id;
                cin >> id;
                cout << "Give the name of the expense" << endl;
                char name[50];
                cin >> name;
                int num;
                cout << "Give the number of the apartment" << endl;
                cin >> num;
                cout << "Give the price of the expense" << endl;
                int sum;
                cin >> sum;
                Entity e(id, name, num, sum);
                service.createEntity(e);

                break;
            }
            case '2': {
                v = service.getAll();
                int ap;
                cout << "Give the number of the apartment:";
                cin >> ap;
                service.elim_expense_by_app(ap);
                break;
            }
            case '3': {
                v = service.getAll();
                int ap1, ap2;
                cout << "Give the first apartment:" << endl;
                cin >> ap1;
                cout << "Give the first apartment:" << endl;
                cin >> ap2;
                service.elim_expenses_from_ap1_to_ap2(ap1, ap2);
                break;
            }
            case '4': {
                v = service.getAll();
                char name[50];
                cout << "Give the name of the expense" << endl;
                cin >> name;
                service.elim_all_expenses_for_a_given_type(name);
                break;
            }
            case '5': {
                v = service.getAll();
                cout << "Give the number of the apartment:" << endl;
                int ap, sum;
                cin >> ap;
                cout << "Give the new price of the expense:" << endl;
                cin >> sum;
                cout << "Give the expense type:" << endl;
                char name[50];
                cin >> name;
                service.replace_price_of_an_expense(name, sum, ap);
                break;
            }
            case '6': {
                service.list_all_apartments();
                break;
            }
            case '7': {
                cout << "Give the number of the apartment:" << endl;
                int ap;
                cin >> ap;
                service.list_all_expenses_for_a_given_ap(ap);
                break;
            }
            case '8': {
                cout << "Give the sum:" << endl;
                int sum;
                cin >> sum;
                service.list_all_expenses_bigger_than_a_given_sum(sum);
                break;
            }
            case '9': {
                cout << "Give the sum:" << endl;
                int sum;
                cin >> sum;
                service.list_all_expenses_equal_to_a_given_sum(sum);
                break;
            }
            case 's': {
                cout << "Give the type of the expense:" << endl;
                char name[50];
                cin >> name;
                cout << service.print_the_sum_of_all_expenses_by_a_given_type(name);
                break;
            }
            case 'a': {
                cout << "Give the number of the apartment:" << endl;
                int num;
                cin >> num;
                Entity e = service.print_the_biggest_type_of_expense_of_an_ap(num);
                cout << e;
                break;
            }
            case 'b': {
                cout << "Give the expense type you want:" << endl;
                char name[50];
                cin >> name;
                vector<Entity> v2;
                v2 = service.sort_all_expenses_by_a_given_type(name);
                for (auto &i: v2)
                    cout << i;
                break;
            }
            case 'c': {
                v = service.getAll();
                cout << "Give the expense type you want to filter by:" << endl;
                char name[50];
                cin >> name;
                service.filter_by_expense_type(name);
                break;
            }
            case 'd': {
                v = service.getAll();
                cout << "Give the sum you want to fitler by:" << endl;
                int sum;
                cin >> sum;
                service.filter_by_sum(sum);
                break;
            }
            case'u':{
                service.undoS(v);
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}
