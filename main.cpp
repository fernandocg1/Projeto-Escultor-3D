#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sculptor.h"


int main() {
    Sculptor draw(100,100,100);
    //torso
    draw.setColor(0.0, 0.0, 0.0, 1.0);
    draw.putBox(15, 35, 20, 40, 20, 30);

    //braços
    draw.setColor(0.0, 0.0, 0.0, 1.0);
    draw.putBox(36, 45, 20, 40, 20, 30);
    draw.putBox(5, 14, 20, 40, 20, 30);
    //mãos
    draw.setColor(1.0, 1.0, 1.0, 1.0);
    draw.putBox(36, 45, 20, 21, 20, 30);
    draw.putBox(5, 14, 20, 21, 20, 30);


    //pernas
    draw.setColor(0.0, 0.0, 0.0, 1.0);
    draw.putBox(15, 25, 0, 19, 20, 30);
    draw.putBox(16, 35, 0, 19, 20, 30);
    //pés
    draw.setColor(1.0, 1.0, 1.0, 1.0);
    draw.putBox(15, 25,0, 1, 20, 30);
    draw.putBox(16, 35, 0, 1, 20, 30);

    //cabeça
    draw.setColor(1.0, 1.0, 1.0, 1.0);
    draw.putEllipsoid(25, 48, 25, 8, 10, 8);

    //bone e corda
    draw.setColor(0.0, 0.0, 0.0, 1.0);
    draw.putBox(17, 33, 54, 57, 17, 33);
    draw.putVoxel(18, 53, 32);
    draw.putVoxel(18, 52, 32);
    draw.putVoxel(18, 51, 32);
    draw.putVoxel(18, 50, 32);
    draw.putVoxel(18, 49, 32);

    //boca
    draw.setColor(0.0, 0.0, 0.0, 1.0);
    draw.putVoxel(22, 45, 32);
    draw.putVoxel(23, 44, 32);
    draw.putVoxel(24, 44, 32);
    draw.putVoxel(25, 44, 32);
    draw.putVoxel(26, 44, 32);
    draw.putVoxel(27, 44, 32);
    draw.putVoxel(28, 45, 32);

    //olhos
    draw.setColor(0.0, 0.0, 0.0, 1.0);
    draw.putVoxel(27, 48, 32);
    draw.putVoxel(27, 49, 32);
    draw.putVoxel(23, 48, 32);
    draw.putVoxel(23, 49, 32);

    //jabô (parte branca da roupa)
    draw.setColor(1.0, 1.0, 1.0, 1.0);
    draw.putBox(17, 33, 36, 40, 30, 31);
    draw.putBox(20, 30, 33, 35, 30, 31);
    draw.putBox(23, 27, 32, 32, 30, 31);

    //faixa
    draw.setColor(0.0, 0.0, 1.0, 1.0);
    draw.putBox(15, 35, 20, 23, 20, 30);
    draw.putBox(15, 35, 20, 23, 30, 31);
    draw.putBox(15, 35, 20, 23, 19, 20);
    draw.putBox(30, 33, 10, 19, 30, 31);

    //canudo
    draw.setColor(0.0, 0.0, 1.0, 1.0);
    draw.putEllipsoid(41, 20, 25, 3, 3, 10);
    draw.putSphere(41, 20, 32, 3);
    draw.putSphere(41, 20, 18, 3);

    draw.setColor(1.0, 1.0, 0.0, 1.0);
    draw.putBox(39, 43, 18, 22, 32, 32);
    draw.putBox(39, 43, 18, 22, 18, 18);


    draw.writeOFF("Roblox.off");

    std::cout << "Arquivo gerado e abrindo o MeshLab..." << std::endl;

#ifdef _WIN32
    system("start meshlab Roblox.off");
#else
    system("meshlab Roblox.off &");
#endif

    return 0;
}