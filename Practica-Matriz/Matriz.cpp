/* 
 * File:   Matriz.cpp
 * Author: alan.calderon
 */

#include <stddef.h>
#include <iostream>

#include "Matriz.h"

Matriz::Matriz()
{
    this->cntFilas = 5;
    this->cntColumnas = 5;
    this->matriz_ptr = new int[25];

    // Inicializa la matriz con ceros.
    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            //( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] = 0;
            *( ( this->matriz_ptr + indiceFila * this->cntColumnas ) + indiceColumna ) = 0;
        }
    }

    /*for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] << std::endl;
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
    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            //( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] = 0;
            *( ( this->matriz_ptr + indiceFila * this->cntColumnas ) + indiceColumna ) = 0;
        }
    }

    /*for( int indiceFila = 0; indiceFila <  this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas ; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( this->matriz_ptr + indiceFila * this->cntColumnas  )[indiceColumna] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }*/
}

Matriz::Matriz(const Matriz& orig)
{
    this->cntFilas = orig.cntFilas;
    this->cntColumnas = orig.cntColumnas;
    this->matriz_ptr = new int[this->cntFilas * this->cntColumnas];

    // Copia el elemento en la fila i columna j de la matriz de origen en la fila i columna j de *this.
    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            //( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] = ( orig.matriz_ptr + indiceFila * orig.cntColumnas )[indiceColumna];
            *( ( this->matriz_ptr + indiceFila * this->cntColumnas ) + indiceColumna ) = *( ( orig.matriz_ptr + indiceFila * orig.cntColumnas ) + indiceColumna );
        }
    }

    /*
     std::cout << "Matriz Original" << std::endl;
    for( int indiceFila = 0; indiceFila < orig.cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < orig.cntColumnas; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( orig.matriz_ptr + indiceFila * orig.cntColumnas )[indiceColumna] << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
     * 
     * 
     *  
    std::cout << "Matriz Copia" << std::endl << std::endl;
    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << ( this->matriz_ptr + indiceFila * this->cntColumnas )[indiceColumna] << std::endl;
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
    //return(this->matriz_ptr + f * this->cntColumnas )[c];
    return *( ( this->matriz_ptr + f * this->cntColumnas ) + c );
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
    //( this->matriz_ptr + f * this->cntColumnas )[c] = v;
    *( ( this->matriz_ptr + f * this->cntColumnas ) + c ) = v;

    /*for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            std::cout << "Fila: " << indiceFila << "  Columna: " << indiceColumna << "  Valor: " << *( ( this->matriz_ptr + indiceFila * this->cntColumnas ) + indiceColumna ) << std::endl;
        }
        std::cout << std::endl << std::endl;
    }*/
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

void Matriz::imprimir() const
{
    for( int indiceFila = 0; indiceFila < this->cntFilas; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < this->cntColumnas; ++indiceColumna )
        {
            std::cout << this->matriz_ptr[indiceFila * this->cntColumnas + indiceColumna] << "  ";
        }
        std::cout << std::endl;
    }
}