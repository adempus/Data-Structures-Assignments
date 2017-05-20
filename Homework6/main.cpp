#include <iostream>
#include "MyMap.h"

using namespace std;

int main() {
    std::cout << "MyMap test" << std::endl;
    string first("first");
    MyMap<string, int> testMap(first, 21, 5);
    testMap.insert(first, 55);

    return 0;
}