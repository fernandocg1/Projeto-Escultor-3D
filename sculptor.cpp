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

v = new Voxel**[nx];

    for(int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
    }
    for(int i = 0;i < nx; i++){
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0;i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].show = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

//destrutor da classe

Sculptor :: ~Sculptor(){

// liberação da memoria alocada

    for(int i = 0;i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
    }

    for(int i = 0; i < nx; i++){
        delete[] v[i];
    }

    delete[] v;
    nx = ny = nz = 0;

}

// Escolha das cores

void Sculptor :: setColor(float mr, float mg, float mb, float ma){
    r = mr;
    g = mg;
    b = mb;
    a = ma;
}

// ativação do voxel

void Sculptor :: putVoxel(int mx, int my, int mz){
    v[mx][my][mz].show = true;
    v[mx][my][mz].r = r;
    v[mx][my][mz].g = g;
    v[mx][my][mz].b = b;
    v[mx][my][mz].a = a;
}

//desativação do voxel de uma posição

void Sculptor :: cutVoxel(int mx, int my, int mz){
    v[mx][my][mz].show = false;
}

// implementação de um cubo

void Sculptor :: putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = 0;i < x1; i++){
        for(int j = 0; j < y1; j++){
            for(int k = 0; k < z1; k++){
                v[i][j][k].show = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

// remoção de um cubo

void Sculptor :: cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int i = 0;i < x1; i++){
        for(int j = 0; j < y1; j++){
            for(int k = 0; k < z1; k++){
                v[i][j][k].show = false;
            }
        }
    }
}

// implementação da esfera

void Sculptor :: putSphere(int xcenter, int ycenter, int zcenter, int radius){
    double x2, y2, z2;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){

                x2 = (double)(i-xcenter) * (double)(i-xcenter);
                y2 = (double)(j-ycenter) * (double)(j-ycenter);
                z2 = (double)(k-zcenter) * (double)(k-zcenter);

                if(x2 + y2 + z2 < (r*r)){
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

// remoção da esfera

void Sculptor :: cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    double x2, y2, z2;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){

                x2 = (double)(i-xcenter) * (double)(i-xcenter);
                y2 = (double)(j-ycenter) * (double)(j-ycenter);
                z2 = (double)(k-zcenter) * (double)(k-zcenter);

                if(x2 + y2 + z2 < (r*r)){
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

// implementação da elipsoide

void Sculptor :: putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    double x3, y3, z3;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){

                x3 = ((double)(i-xcenter) * (double)(i-xcenter))/(rx * rx);
                y3 = ((double)(j-ycenter) * (double)(j-ycenter))/(ry * ry);
                z3 = ((double)(k-zcenter) * (double)(k-zcenter))/(rz * rz);

                if((x3 + y3 + z3) < 1){
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

// remoção da elipsoide

void Sculptor :: cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    double x3, y3, z3;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){

                x3 = ((double)(i-xcenter) * (double)(i-xcenter))/(rx * rx);
                y3 = ((double)(j-ycenter) * (double)(j-ycenter))/(ry * ry);
                z3 = ((double)(k-zcenter) * (double)(k-zcenter))/(rz * rz);

                if((x3 + y3 + z3) < 1){
                    v[i][j][k].show = false;
                }
            }
        }
    }
}






























