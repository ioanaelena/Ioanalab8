#include <iostream>
#include "Tests/tests.h"
#include "console/console.h"
#include <iostream>
using namespace std;
int main() {
    tests();
    Console console;
    console.runMenu();
    return 0;
}
