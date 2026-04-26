#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sculptor.h"


int main() {
    Sculptor draw(50,50,50);

    draw.setColor(1.0, 0.0, 0.0, 1.0);
    draw.putBox(15, 35, 20, 40, 20, 30);

    draw.writeOFF("Roblox.off");

    std::cout << "Arquivo gerado! Abrindo o MeshLab..." << std::endl;

    #ifdef _WIN32
        system("start meshlab Roblox.off");
    #else
        system("meshlab Roblox.off &");
    #endif

    return 0;
}