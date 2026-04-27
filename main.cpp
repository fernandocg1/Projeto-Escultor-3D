#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sculptor.h"


int main() {
    Sculptor draw(75,75,75);

    //torso
    draw.setColor(0.0, 0.0, 1.0, 1.0);
    draw.putBox(15, 35, 20, 40, 20, 30);

    //braços
    draw.setColor(1.0, 1.0, 0.0, 1.0);
    draw.putBox(36, 45, 20, 40, 20, 30);
    draw.putBox(5, 14, 20, 40, 20, 30);

    //pernas
    draw.setColor(0.0, 1.0, 0.0, 1.0);
    draw.putBox(15, 25, 0, 19, 20, 30);
    draw.putBox(16, 35, 0, 19, 20, 30);

    //cabeça
    draw.setColor(1.0, 1.0, 0.0, 1.0);
    draw.putEllipsoid(25, 50, 25, 8, 10, 8);


    draw.writeOFF("Roblox.off");

    std::cout << "Arquivo gerado! Abrindo o MeshLab..." << std::endl;

    #ifdef _WIN32
        system("start meshlab Roblox.off");
    #else
        system("meshlab Roblox.off &");
    #endif

    return 0;
}