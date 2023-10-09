#include "array.h"
#include <iostream>

int main() {
    DynamicArray arr;

    // Test add() method:
    for (int i = 1; i <= 100; i++) {
        arr.add(i);
    }
    std::cout << "After adding 100 numbers:\n";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr.get(i) << " ";
    }
    std::cout << "\n";

    // Test put() method:
    arr.put(0, 999);
    std::cout << "After updating the first element to 999:\n";
    std::cout << arr.get(0) << "\n";

    // Test remove() method:
    for (int i = 0; i < 10; i++) {
        arr.remove(0);
    }
    std::cout << "After removing the first element 10 times:\n";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr.get(i) << " ";
    }
    std::cout << "\n";

    return 0;
}
