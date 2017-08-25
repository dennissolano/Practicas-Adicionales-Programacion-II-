
#include <algorithm>

#include "IntegerTree.h"

IntegerTree::IntegerTree()
{

}

IntegerTree::IntegerTree(const IntegerTree& other)
{

}

IntegerTree::~IntegerTree()
{

}

bool IntegerTree::insert(int number)
{
    bool result = false;
    std::shared_ptr<Node> current = root;

    if( !current ) // Conjunto vacío.
    {
        root = std::shared_ptr<Node>( new Node( number ) );
        result = true;
    }
    else
    {
        while( current )

            if( current->data == number ) // Elemento repetido.
            {
                current = nullptr;
            }
            else
            {
                if( current->data < number ) // Insertar en subárbol derecho.
                {
                    if( !current->rightChild )
                    {
                        result = true;
                        current->rightChild = std::shared_ptr<Node>( new Node( number ) );
                        current = nullptr;
                    }
                    else
                    {
                        current = current->rightChild;
                    }
                }
                else // Insertar en subárbol izquierdo.
                {
                    if( !current->leftChild )
                    {
                        result = true;
                        current->leftChild = std::shared_ptr<Node>( new Node( number ) );
                        current = nullptr;
                    }
                    else
                    {
                        current = current->leftChild;
                    }
                }
            }
    }

    return result;
}

bool IntegerTree::remove(int number)
{
    bool result = false;
    std::shared_ptr<Node> temp1 = root;
    std::shared_ptr<Node> temp2 = nullptr;
    std::shared_ptr<Node> temp3 = nullptr;

    if( temp1 ) // El árbol tiene elementos.
    {
        if( temp1->data == number ) // Caso A: Eliminar raíz.
        {
            if( temp1->rightChild && temp1->leftChild ) // Caso 1: La raíz tiene hijo izquierdo e hijo derecho.
            {
                temp2 = temp1->rightChild; // Guarda puntero a subárbol derecho de la raíz.
                temp1 = temp1->leftChild;

                while( temp1 ) // Buscar el mayor de los elementos del subárbol izquierdo de la ráiz.
                {
                    if( !temp1->rightChild ) // Una vez que lo encuentra el mayor de los elementos, liga su hijo derecho que es nulo con el subárbol derecho de la raíz.
                    {
                        temp1->rightChild = temp2;
                        temp1 = nullptr;
                    }
                    else
                    {
                        temp1 = temp1->rightChild;
                    }
                }

                temp3 = root->leftChild;
                root = nullptr; // Elimina raíz original.
                root = temp3; // Establece nueva raíz.
                result = true;
            }
            else
            {
                if( temp1->rightChild ) // Caso 2: La raíz tiene solo hijo derecho.
                {
                    temp1 = temp1->rightChild;
                    root = nullptr;
                    root = temp1;
                    result = true;
                }
                else
                {
                    if( temp1->leftChild ) // Caso 3: La raíz tiene solo hijo izquierdo.
                    {
                        temp1 = temp1->leftChild;
                        root = nullptr;
                        root = temp1;
                        result = true;
                    }
                    else // Caso 4: EL árbol tiene solo un elemento la raíz.
                    {
                        root = nullptr;
                        result = true;
                    }
                }
            }
        }
        else
        {
            if( temp1->data < number ) // Visitar subárbol derecho.
            {
                temp2 = temp1;
                temp1 = temp1->rightChild;
            }
            else // Visitar subárbol izquierdo.
            {
                temp2 = temp1;
                temp1 = temp1->leftChild;
            }

            while( temp1 )
            {
                if( temp1->data == number )
                {
                    if( temp1->data < temp2->data ) // temp1 es hijo izquierdo de temp2.
                    {

                    }
                    else
                    {

                    }
                }
                else
                {
                    if( temp1->data < number ) // Visitar subárbol derecho.
                    {
                        temp2 = temp1;
                        temp1 = temp1->rightChild;
                    }
                    else // Visitar subárbol izquierdo.
                    {
                        temp2 = temp1;
                        temp1 = temp1->leftChild;
                    }
                }
            }
        }
    }

    return result;
}

bool IntegerTree::search(int number) const
{
    bool result = false;
    std::shared_ptr<Node> current = root;

    while( current )
    {
        if( current->data == number )
        {
            result = true;
            current = nullptr;
        }
        else
        {
            if( current->data < number )
            {
                current = current->rightChild;
            }
            else
            {
                current = current->leftChild;
            }
        }
    }

    return result;
}

std::string IntegerTree::toStr() const
{
    std::stringstream buffer;

    buffer << '{';
    printTree( root, buffer );
    buffer << '}';

    return buffer.str( );
}

void IntegerTree::printTree(const std::shared_ptr<Node> node, std::stringstream& buffer)const
{
    if( node )
    {
        printTree( node->leftChild, buffer );
        buffer << node->data << ',';
        printTree( node->rightChild, buffer );
    }
}
