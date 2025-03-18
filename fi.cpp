#include <iostream>
#include <fstream>
#include <regex>
#include "fi.h"
#include "ut.h"

void fi(const std::string& fn, const std::string& qy) {
    auto st = gt();
    
    std::ifstream fs(fn);
    
    if (!fs.is_open()) {
        std::cerr << "Err: Can't open " << fn << std::endl;
        return;
    }

    std::string ln;
    std::regex rg(qy);
    
    while (std::getline(fs, ln)) {
        if (std::regex_search(ln, rg)) {
            size_t idx = 0;
            while ((idx = ln.find(qy, idx)) != std::string::npos) {
                std::cout << ln.substr(0, idx);
                pr(ln.substr(idx, qy.length()));
                idx += qy.length();
            }
            std::cout << ln.substr(ln.find(qy) + qy.length()) << std::endl;
        }
    }

    fs.close();

    auto et = gt();
    std::cout << "\nTime taken: " << et - st << " seconds." << std::endl;
}
