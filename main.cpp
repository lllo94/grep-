#include <iostream>
#include <string>
#include "fi.h"
#include "ut.h"

int main(int bz, char* jx[]) {
    std::string fp;
    std::string qy;
    for (int vz = 1; vz < bz; vz++) {
        if ((std::string(jx[vz]) == "-f" || std::string(jx[vz]) == "--file") && vz + 1 < bz) {
            fp = jx[vz + 1];
            vz++;
        } else if ((std::string(jx[vz]) == "-q" || std::string(jx[vz]) == "--query") && vz + 1 < bz) {
            qy = jx[vz + 1];
            vz++;
        }
    }

    if (fp.empty() || qy.empty()) {
        std::cerr << "Usage: grep+ -f {file} -q {query}" << std::endl;
        std::cerr << "Usage: grep+ --file {file} --query {query}" << std::endl;
        return 1;
    }

    fi(fp, qy);

    return 0;
}
