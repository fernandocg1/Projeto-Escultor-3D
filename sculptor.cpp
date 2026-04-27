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
    for(int i = x0;i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
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

                if(x2 + y2 + z2 < (double)radius * radius){
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

// criando o arquivo .OFF

void Sculptor :: writeOFF(const char* filename){
    std::ofstream file;

    std::fixed(file);

    int NVertices = 0;
    int NFaces = 0;
    int NArestas = 0;
    file.open(filename);

    if(file.is_open()){
        std::cout << "O Arquivo foi aberto" << std :: endl;
    }else{
        std :: cout << "O Arquivo .OFF não foi aberto" << std :: endl;
        exit(1);
    }

    file << "OFF" << std :: endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){
                if(v[i][j][k].show == true){
                    NVertices = NVertices + 8;
                    NFaces = NFaces + 6;
                }
            }
        }
    }

    file << NVertices << " " << NFaces << " " << 0 << std :: endl;

    file << std::fixed;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){
                if(v[i][j][k].show == true){
                    file << i-0.5 << " " << j+0.5 << " " << k-0.5 << std :: endl;
                    file << i-0.5 << " " << j-0.5 << " " << k-0.5 << std :: endl;
                    file << i+0.5 << " " << j-0.5 << " " << k-0.5 << std :: endl;
                    file << i+0.5 << " " << j+0.5 << " " << k-0.5 << std :: endl;
                    file << i-0.5 << " " << j+0.5 << " " << k+0.5 << std :: endl;
                    file << i-0.5 << " " << j-0.5 << " " << k+0.5 << std :: endl;
                    file << i+0.5 << " " << j-0.5 << " " << k+0.5 << std :: endl;
                    file << i+0.5 << " " << j+0.5 << " " << k+0.5 << std :: endl;
                }
            }
        }
    }

    int aux = 0;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for( int k = 0; k < nz; k++){
                if(v[i][j][k].show == true){
                    file << 4 << " " << aux+0 << " " << aux+3 << " " << aux+2 << " " << aux+1 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std :: endl;

                    file << 4 << " " << aux+4 << " " << aux+5 << " " << aux+6 << " " << aux+7 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std :: endl;

                    file << 4 << " " << aux+0 << " " << aux+1 << " " << aux+5 << " " << aux+4 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std :: endl;

                    file << 4 << " " << aux+0 << " " << aux+4 << " " << aux+7 << " " << aux+3 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std :: endl;

                    file << 4 << " " << aux+3 << " " << aux+7 << " " << aux+6 << " " << aux+2 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std :: endl;

                    file << 4 << " " << aux+1 << " " << aux+2 << " " << aux+6 << " " << aux+5 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std :: endl;
                    aux=aux+8;
                }
            }
        }
    }

    if(file.is_open()){
        std :: cout << "Arquivo.OFF salvo!" << std :: endl;
    }
    file.close();
}































