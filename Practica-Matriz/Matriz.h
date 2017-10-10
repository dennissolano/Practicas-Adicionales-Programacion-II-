/* File : Matriz.h
 * Author : alan.calderon
 */

#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
public:
    // Construye una matriz de 5x5 inicializada con ceros.
    Matriz();

    // Construye una matriz de cf x cc inicializada con ceros.
    Matriz(int cf, int cc);

    // Consturye una copia de orig
    Matriz(const Matriz& orig);

    ~Matriz();

    /* OBTENEDORES */

    // REQ: 0 <= f < this->obtCntFilas() && 0 <= c < this->obtCntColumnas().
    // EFE: retorna el valor en la posición (f,c).
    int obtValor(int f, int c) const;

    // EFE: retorna la cantidad de filas de *this.
    int obtCntFilas() const;

    // EFE: retorna la cantidad de columnas de *this.
    int obtCntColumnas() const;

    /* ASIGNADORES */

    // REQ: 0 <= f < this->obtCntFilas() && 0 <= c < this->obtCntColumnas().
    // EFE: asigna v a la posición (f,c) de *this.
    void asgValor(int f, int c, int v);

    /* OPERADORES */

    // REQ: this->obtCntFilas() == x.obtCntFilas && this->obtCntColumnas() == x.obtCntColumnas
    // EFE: retorna una nueva matriz que representa la suma de *this y x.
    Matriz& operator+(const Matriz& x) const;

    // REQ: this->obtCntFilas() == x.obtCntFilas && this->obtCntColumnas() == x.obtCntColumnas
    // EFE: retorna una nueva matriz que representa la resta de *this y x.
    Matriz& operator-(const Matriz& x) const;

    // REQ: this->obtCntColumnas() == x.obtCntFilas.
    // EFE: retorna una nueva matriz que representa el producto matricial de *this y x.
    Matriz& operator*(const Matriz& x) const;

    // REQ: *this esté correctamente inicializada.
    // EFE: imprime en la salida estándar a *this.
    void imprimir() const;

private:
    int* matriz_ptr;
    int cntFilas;
    int cntColumnas;
};

#endif /* MATRIZ_H */

