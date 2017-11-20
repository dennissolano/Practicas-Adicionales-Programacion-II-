#ifndef MATRIZ2D_GNR_H
#define MATRIZ2D_GNR_H

#include <memory>
#include <vector>
using namespace std;

template< typename V > // V: tipod de dato.
class Matriz2D_Gnr
{
private:

    int cantidadFilas;
    int cantidadColumnas;
    shared_ptr< vector< V > > matrizPtr;

public:

    /* Constructores */

    // Constructor estándar.
    Matriz2D_Gnr( );

    // Constructor de copias.
    Matriz2D_Gnr( const Matriz2D_Gnr< V >& origen );

    // Construye una matriz con m filas y n columnas. Inicializada con ceros.
    Matriz2D_Gnr( int m, int n );

    // Destructor.
    ~Matriz2D_Gnr( );

    /* Métodos Obtenedores */

    // REQ: *this haya sido correctamente inicializada.
    // EFE: retorna la cantidad de filas en *this.
    int obtCantidadFilas( ) const;

    // REQ: *this haya sido correctamente inicializada.
    // EFE: retorna la cantidad de columnas en *this.
    int obtCantidadColumnas( ) const;

    // REQ: 0 <= fila < cantidadFilas / 0 <= columna < cantidadColumnas.
    // EFE: retorna el elemento en la posición (fila, columna) de *this.
    V obtValor( int fila, int columna ) const;

    // REQ: *this haya sido correctamente inicializada.
    // EFE: retorna la matriz transpuesta de *this.
    Matriz2D_Gnr< V >& transpuesta( ) const;

    /* Métodos Modificadores */

    // REQ: 0 <= fila < cantidadFilas / 0 <= columna < cantidadColumnas.
    // EFE: inserta en la posición (fila, columna) el valor v.
    // MOD: el valor del elemento contenido en la posición (fila, columna) de *this.
    void asgValor( int fila, int columna, V valor );

    /* Operadores */

    Matriz2D_Gnr<V>& operator=( const Matriz2D_Gnr< V >& origen );
    Matriz2D_Gnr< V >& operator+( const Matriz2D_Gnr< V >& origen ) const;
    Matriz2D_Gnr< V >& operator*( const Matriz2D_Gnr< V >& origen ) const;
    Matriz2D_Gnr< V >& operator%( int escalar ) const;
};

template< typename V >
Matriz2D_Gnr< V >::Matriz2D_Gnr( int m, int n )
: cantidadFilas( m )
, cantidadColumnas( n )
, matrizPtr( shared_ptr< vector< V > >( new vector< V >( m*n, 0 ) ) )
{
}

template< typename V >
Matriz2D_Gnr< V >::Matriz2D_Gnr( const Matriz2D_Gnr<V>& origen )
: cantidadFilas( origen.cantidadFilas )
, cantidadColumnas( origen.cantidadColumnas )
, matrizPtr( origen.matrizPtr )
{
}

template< typename V >
int Matriz2D_Gnr< V >::obtCantidadFilas( ) const
{
    return cantidadFilas;
}

template< typename V >
int Matriz2D_Gnr< V >::obtCantidadColumnas( ) const
{
    return cantidadColumnas;
}

template< typename V >
V Matriz2D_Gnr< V >::obtValor( int fila, int columna ) const
{
    return matrizPtr[fila * cantidadColumnas + columna];
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::transpuesta( ) const
{
}

template< typename V >
void Matriz2D_Gnr< V >::asgValor( int fila, int columna, V valor )
{
    matrizPtr[fila * cantidadColumnas + columna] = valor;
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator=( const Matriz2D_Gnr<V>& origen )
{
    // Evita que *this se copie a sí mismo.
    if ( this != &origen )
    {

        cantidadFilas = origen.cantidadFilas;
        cantidadColumnas = origen.cantidadColumnas;
        matrizPtr = origen.matrizPtr;
    }
    return *this;
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator+( const Matriz2D_Gnr< V >& origen ) const
{
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator*( const Matriz2D_Gnr< V >& origen ) const
{
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator%( int escalar ) const
{
}

#endif /* MATRIZ2D_GNR_H */

