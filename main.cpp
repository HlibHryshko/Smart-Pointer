//
// Created by glebg on 04.12.2021.
//
#include <iostream>
#include "unique_ptr.h"

int main(){
    auto str = make_unique<std::string>("Alice");
    std::cout << *str << '\n';  // Alice
    auto number = make_unique<int>(21);
    auto answer = 2 * (*number);
    std::cout << answer << '\n';  // 42
}

