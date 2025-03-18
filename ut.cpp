#include <iostream>
#include <chrono>
#include "ut.h"

void pr(const std::string& st) {
    std::cout << "\033[31m" << st << "\033[0m";
}

double gt() {
    auto tp = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(tp.time_since_epoch()).count();
}
