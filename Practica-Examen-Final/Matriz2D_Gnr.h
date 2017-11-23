#ifndef MATRIZ2D_GNR_H
#define MATRIZ2D_GNR_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template< typename V > // V: tipo de de dato.
class Matriz2D_Gnr
{
private:

    int cantidadFilas;
    int cantidadColumnas;
    vector< V > matriz;

public:

    /* Constructores */

    // Constructor estándar.
    Matriz2D_Gnr();

    // Constructor de copias.
    Matriz2D_Gnr(const Matriz2D_Gnr< V >& origen);

    // Construye una matriz con m filas y n columnas. Inicializada con ceros.
    Matriz2D_Gnr(int m, int n);

    // Destructor.
    ~Matriz2D_Gnr();

    /* Métodos Obtenedores */

    // REQ: *this haya sido correctamente inicializada.
    // EFE: retorna la cantidad de filas en *this.
    int obtCantidadFilas() const;

    // REQ: *this haya sido correctamente inicializada.
    // EFE: retorna la cantidad de columnas en *this.
    int obtCantidadColumnas() const;

    // REQ: 0 <= fila < cantidadFilas / 0 <= columna < cantidadColumnas.
    // EFE: retorna el elemento en la posición (fila, columna) de *this.
    V obtValor(int fila, int columna) const;

    // REQ: *this haya sido correctamente inicializada.
    // EFE: retorna la matriz transpuesta de *this.
    Matriz2D_Gnr< V >& transpuesta() const;

    /* Métodos Modificadores */

    // REQ: 0 <= fila < cantidadFilas / 0 <= columna < cantidadColumnas.
    // EFE: inserta en la posición (fila, columna) el valor v.
    // MOD: el valor del elemento contenido en la posición (fila, columna) de *this.
    void asgValor(int fila, int columna, V valor);

    // REQ:
    // EFE:
    // MOD:
    void llenarMatriz();

    /* Operadores */

    Matriz2D_Gnr<V>& operator=(const Matriz2D_Gnr< V >& origen);
    Matriz2D_Gnr< V >& operator+(const Matriz2D_Gnr< V >& origen) const;
    Matriz2D_Gnr< V >& operator*(const Matriz2D_Gnr< V >& origen) const;
    Matriz2D_Gnr< V >& operator%(V escalar) const; // El escalar es del mismo tipo que los elementos de la matriz.

    /* Otros */

    // REQ: *this haya sido correctamente inicializada.
    // EFE: imprime el contenido de *this.
    void imprimirMatriz()const;
};

template< typename V >
Matriz2D_Gnr< V >::Matriz2D_Gnr(int m, int n)
: cantidadFilas(m)
, cantidadColumnas(n)
{
    srand(time(NULL));
    matriz.resize(m*n, V());
}

template< typename V >
Matriz2D_Gnr< V >::Matriz2D_Gnr(const Matriz2D_Gnr<V>& origen)
: cantidadFilas(origen.cantidadFilas)
, cantidadColumnas(origen.cantidadColumnas)
, matriz(origen.matriz)
{
}

template< typename V >
Matriz2D_Gnr< V >::~Matriz2D_Gnr()
{
}

template< typename V >
int Matriz2D_Gnr< V >::obtCantidadFilas() const
{
    return cantidadFilas;
}

template< typename V >
int Matriz2D_Gnr< V >::obtCantidadColumnas() const
{
    return cantidadColumnas;
}

template< typename V >
V Matriz2D_Gnr< V >::obtValor(int fila, int columna) const
{
    return matriz[fila * cantidadColumnas + columna ];
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::transpuesta() const
{
}

template< typename V >
void Matriz2D_Gnr< V >::asgValor(int fila, int columna, V valor)
{
    matriz[fila * cantidadColumnas + columna ] = valor;
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator=(const Matriz2D_Gnr<V>& origen)
{
    // Evita que *this se copie a sí mismo.
    if (this != &origen)
    {
        cantidadFilas = origen.cantidadFilas;
        cantidadColumnas = origen.cantidadColumnas;
        matriz = origen.matriz;
    }
    return *this;
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator+(const Matriz2D_Gnr< V >& origen) const
{
    Matriz2D_Gnr< V >* matrizSuma = new Matriz2D_Gnr(cantidadFilas, cantidadColumnas);

    for (int fila = 0; fila < cantidadFilas; ++fila)
    {
        for (int columna = 0; columna < cantidadColumnas; ++columna)
        {

            V valor = this->obtValor(fila, columna) + origen.obtValor(fila, columna);
            matrizSuma->asgValor(fila, columna, valor);
        }
    }

    return *matrizSuma;
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator*(const Matriz2D_Gnr< V >& origen) const
{
    Matriz2D_Gnr< V >* matrizProducto = new Matriz2D_Gnr< V >(cantidadFilas, origen.cantidadColumnas);

    if (cantidadColumnas == origen.cantidadFilas)
    {
        for (int i = 0; i < cantidadFilas; ++i)
        {
            V sumatoriaEntradas = V();

            for (int j = 0; j < origen.cantidadColumnas; ++j)
            {
                for (int indiceVariable = 0; indiceVariable < cantidadFilas; ++indiceVariable)
                {
                    sumatoriaEntradas += obtValor(i, indiceVariable) + origen.obtValor(indiceVariable, j);
                }
                matrizProducto->asgValor(i, j, sumatoriaEntradas);
            }
        }
    }

    return *matrizProducto;
}

template< typename V >
Matriz2D_Gnr< V >& Matriz2D_Gnr< V >::operator%(V escalar) const
{
    Matriz2D_Gnr< V >* matrizEscalar = new Matriz2D_Gnr< V >(cantidadFilas, cantidadColumnas);
    *matrizEscalar = *this; // Operador de asignacion sobrecargado.

    for (int fila = 0; fila < cantidadFilas; ++fila)
    {
        for (int columna = 0; columna < cantidadColumnas; ++columna)
            matrizEscalar->asgValor(fila, columna, matrizEscalar->obtValor(fila, columna) * escalar);
        //matrizProductoEscalar->matriz[fila * cantidadColumnas + columna] *= escalar;
    }

    return *matrizEscalar;
}

template< typename V >
void Matriz2D_Gnr< V >::imprimirMatriz() const
{
    for (int i = 0; i < cantidadFilas; ++i)
    {
        for (int j = 0; j < cantidadColumnas; ++j)
        {
            cout << setw(10) << left << obtValor(i, j);
        }
        cout << endl;
    }
}

template< typename V >
void Matriz2D_Gnr< V >::llenarMatriz()
{
    for (int i = 0; i < cantidadFilas; ++i)
    {
        for (int j = 0; j < cantidadColumnas; ++j)
            asgValor(i, j, (rand() % 11));
    }
}

#endif /* MATRIZ2D_GNR_H */

