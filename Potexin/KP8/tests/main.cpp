#include <iostream>
#include "../include/List.hpp"
#include "../src/benchmark.cpp"

int main() {

    benchmark();

    std::cout << std::endl << "-----------------------------------------" << std::endl;
    std::cout << "List interface test." << std::endl;

    List<std::string> a;
    for (int64_t i = 0; i < 10; ++i) {
        a.push_back(std::to_string(i));
    }

    std::cout << "a: " << a;

    a.pop_back();
    a.pop_front();
    a.push_front("146");
    a.push_front("-1");
    a.insert(a.begin() + 1, "1984");

    std::cout << "a: " << a;

    a.shift_cyclically();

    std::cout << "a: " << a;

    std::cout << "a: ";
    auto it = a.begin();
    for (int64_t i = 0; i < a.size() and it != a.end(); ++i, ++it) {
        *it += std::to_string(i * 2);
        std::cout << *it << "\t";
    }
    std::cout << std::endl;

    List<std::string> b = a;

    a.erase(a.begin(), a.end());
    a.push_back("133");

    std::cout << "a: " << a;
    std::cout << "b: " << b;

    return 0;
}
