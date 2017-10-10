/* 
 * File:   main.cpp
 * Author: alan.calderon
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Matriz.h"

int main(int argc, char** argv)
{
    srand( time( NULL ) );

    Matriz cinco; // Crea una matriz de 5x5.
    Matriz nueve( 9, 9 ); // Crea una matriz de 9x9.
    Matriz cincoBis;
    Matriz nueveBis( 9, 9 );

    // Llena las matrices con datos válidos:
    // prográmelo usted...

    for( int indiceFila = 0; indiceFila < 5; ++indiceFila )
    {
        for( int indiceColumna = 0; indiceColumna < 5; ++indiceColumna )
        {
            cinco.asgValor( indiceFila, indiceColumna, rand( ) % 10 );
            cincoBis.asgValor( indiceFila, indiceColumna, rand( ) % 10 );
        }
    }

    std::cout << "Matriz A" << std::endl << std::endl;
    cinco.imprimir( );

    std::cout << "Matriz B" << std::endl << std::endl;
    cincoBis.imprimir( );


    // Realiza operaciones con las matrices semejantes:

    std::cout << "Producto de matrices: AXB" << std::endl << std::endl;
    Matriz cincoProducto = cinco * cincoBis;
    cincoProducto.imprimir( );

    std::cout << "Suma de matrices: A+B" << std::endl << std::endl;
    Matriz cincoSuma = cinco + cincoBis;
    cincoSuma.imprimir( );

    std::cout << "Resta de matrices: A-B" << std::endl << std::endl;
    Matriz cincoResta = cinco - cincoBis;
    cincoResta.imprimir( );

    // Programe otras operaciones...

    return 0;
}

