#include <iostream>
#include <memory>
using namespace std;

#include "Matriz2D_Gnr.h"

int main()
{
    // Matrices de int:
    Matriz2D_Gnr< int > m_int1( 3, 4 ), m_int2( 3, 4 ), m_int_suma( 3, 4 ); // Suponemos que quedan inicializadas.
    m_int1.llenarMatriz( );
    m_int2.llenarMatriz( );

    Matriz2D_Gnr< int > m_int3( 4, 3 );
    m_int3.llenarMatriz( );

    Matriz2D_Gnr< int > m_int_multi( 3, 3 ); // para multiplicar una de 3x4 con otra de 4x3 o dos de 3x3.
    Matriz2D_Gnr< int > m_int_trns( 3, 4 );

    m_int_suma = m_int1 + m_int2;
    m_int_suma = m_int_suma % 7;
    m_int_multi = m_int1 * m_int3; // OJO: sólo se permite multiplicar si son "compatible

    m_int3.imprimirMatriz( );
    cout << endl;

    m_int_trns = m_int3.transpuesta( );

    std::cout << "Matriz Transpuesta  de m_int3 \n\n";
    m_int_trns.imprimirMatriz( );

    // Matrices de double:
    Matriz2D_Gnr< int > m_double( 3, 4 ), m_double1( 3, 4 ), m_double2( 3, 4 ), m_double_suma( 3, 4 ); // Suponemos que quedan inicializadas.
    Matriz2D_Gnr< int > m_double3( 4, 3 );
    Matriz2D_Gnr< int > m_double_multi( 3, 3 ); // para multiplicar una de 3x4 con otra de 4x3 o dos de 3x3.
    Matriz2D_Gnr< int > m_double_trns( 3, 4 );

    m_double_suma = m_double1 + m_double2;
    m_double_suma = m_double_suma % 7;
    m_double_multi = m_double * m_double3; // OJO: sólo se permite multiplicar si son "compatibles".
    m_double_trns = m_double3.transpuesta( );

    return 0;
}