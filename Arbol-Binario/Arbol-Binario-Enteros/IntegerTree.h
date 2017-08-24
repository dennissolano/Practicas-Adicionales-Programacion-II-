
#ifndef INTEGERTREE_H
#define INTEGERTREE_H

#include <iostream>
#include <sstream>
#include <memory>
#include <string>

class IntegerTree
{
private:

    struct Node
    {
        int data;
        std::shared_ptr<Node> rightChild;
        std::shared_ptr<Node> leftChild;

        Node(int number)
        : data{ number }
        , rightChild{nullptr }
        , leftChild{nullptr }
        {
        }

        ~Node()
        {
            std::cout << "Borrando: " << data << std::endl;
        }
    };

    std::shared_ptr<Node> root;

public:

    // EFE: Construye un nuevo conjunto de enteros vacío.
    IntegerTree();

    // EFE: Construye una copia idéntica e independiente de "other".
    IntegerTree(const IntegerTree& other);

    ~IntegerTree();

    // MOD: *this.
    // EFE: Si "number" no pertenece a *this, lo agrega preservando el orden y retorna verdadero,
    // en caso contrario no tiene efecto y retorna falso.
    bool insert(int number);

    // MOD: *this.
    // EFE: Si "number" pertenece a *this, entonces lo elimina preservando el orden y retorna verdadero,
    // en caso contrario no tiene efecto y retorna falso.
    bool remove(int number);

    // EFE: Si "number" pertenece a *this, entonces retorna verdadero, en caso contrario retorna falso.
    bool search(int number) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la unión de *this con "other".
    IntegerTree& operator+(const IntegerTree& other) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la diferencia de *this con "other".
    IntegerTree& operator-(const IntegerTree& other) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la intersección de *this con "other".
    IntegerTree& operator*(const IntegerTree& other) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la diferencia simétrica de *this con "other".
    IntegerTree& operator/(const IntegerTree& other) const;

    // EFE: Retorna una hilera que representa a *this.
    void toStr() const;

    // EFE: Imprime recursivamente en orden, el conjunto de números almacenado en el árbol binario.
    void printTree(const std::shared_ptr<Node> node)const;
};

#endif /* INTEGERTREE_H */

