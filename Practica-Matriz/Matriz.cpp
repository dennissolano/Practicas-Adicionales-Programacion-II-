/* 
 * File:   Matriz.cpp
 * Author: alan.calderon
 */

#include <stddef.h>
#include <iostream>

#include "Matriz.h"

Matriz::Matriz()
{
    this->cntColumnas = 5;
    this->cntFilas = 5;
    this->matriz_ptr = new int[25];

    // Inicializa la matriz con ceros.
    for( int indiceFila = 0; indiceFila < 5; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < 5; ++indiceColumna )
        {
            ( this->matriz_ptr + indiceFila * 5 )[indiceColumna] = 0;
        }
    }

    /*for( int indiceFila = 0; indiceFila < 5; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < 5; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( matriz_ptr + indiceFila * 5 )[indiceColumna] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }*/
}

Matriz::Matriz(int cf, int cc)
{
    this->cntFilas = cf;
    this->cntColumnas = cc;
    this->matriz_ptr = new int[cntFilas * cntColumnas];

    // Inicializa la matriz con ceros.
    /*for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            ( this->matriz_ptr + indiceFila * cc )[indiceColumna] = 0;
        }
    }*/

    /*for( int indiceFila = 0; indiceFila < cf; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < cc; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( matriz_ptr + indiceFila * cc )[indiceColumna] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }*/
}

Matriz::Matriz(const Matriz& orig)
{
    this->cntFilas = orig.cntFilas;
    this->cntColumnas = orig.cntColumnas;

    this->matriz_ptr = new int[this->cntFilas * this->cntColumnas];

    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            ( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] = ( orig.matriz_ptr + indiceFila * orig.cntColumnas )[indiceColumna];
        }
    }

    /*std::cout << "Matriz Copia" << std::endl << std::endl;
    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    std::cout << "Matriz Original" << std::endl;
    for( int indiceFila = 0; indiceFila < orig.cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < orig.cntColumnas; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( orig.matriz_ptr + indiceFila * orig.cntColumnas )[indiceColumna] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }*/
}

Matriz::~Matriz()
{
    delete[] this->matriz_ptr;
}

int Matriz::obtValor(int f, int c) const
{
}

int Matriz::obtCntFilas() const
{
    return this->cntFilas;
}

int Matriz::obtCntColumnas() const
{
    return this->cntColumnas;
}

void Matriz::asgValor(int f, int c, int v)
{
}

Matriz& Matriz::operator*(const Matriz& x ) const
{
}

Matriz& Matriz::operator+(const Matriz& x ) const
{
}

Matriz& Matriz::operator-(const Matriz& x ) const
{
}