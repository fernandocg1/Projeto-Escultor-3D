#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sculptor.h"

// adicionando construtor da classe

Sculptor :: Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = g = b = a = 1;


// alocação da matriz tridimencional

matriz = new Voxel**[nx];

    for(int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
    }
}