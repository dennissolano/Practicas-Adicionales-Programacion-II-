
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

    /*
     * temp1 = raiz, temp2(papá)
     * 
     * Si( El elemento en el nodo apuntado temp1 es igual al elemento a eliminar ) entonces
     * {
     *      temp2 = hijoDerecho de root;
     *      temp1 = hijoIzquierdo de root;
     * 
     *      Mientras( temp1 != nullptr )
     *      {
     *          Si( El hijoDerecho del temporal1 es un puntero nulo ) entonces
     *          {
     *              hijoDerecho de temp1 = temp2;
     *              temp1 = nullptr;       
     *          }
     *          Sino
     *              temp1 = hijoDerecho de temp1; // Mover temp1 hasta que encuentre el mayor de todos los números del subárbol derecho.
     *      }     
     * 
            temp3 = hijoIzquierdo de root;
            eliminar root
     *      root = temp3
     * }
     * 
     * Si( El elemento en el nodo apuntado por temp1 es igual al elemento a eliminar ) entonces
     * {
     * 
     *      Si( temp1 es nodo Hoja )
     *      {
     *          eliminar temp1;
     *      }
     *      Sino
     *      {    
     *          Si( El elemento en el nodo apuntado por temp1 es menor que el elemento en el nodo apuntado por temp2 ) entonces temp1 es hijo izquierdo de temp2
     *          {
     *              Si( temp1 tiene hijoIzquierdo e hijoDerecho )
     *              {
     *                  EL hijoIzquierdo del nodo papá temp2 = hijoIzquierdo de temp1;
     *                  El hijoDerecho del hijoIzquierdo de temp2 = hijoDerecho de temp1;
     *                  Eliminar temp1; // Revisar comportamiento esperado.
     *              }
     *              Sino
     *              {
     *                  Si( temp1 tiene solo hijoIzquierdo )
     *                  {
     *                      EL hijoIzquierdo del nodo papá temp2 = hijoIzquierdo de temp1;
     *                      Eliminar temp1; // Revisar comportamiento esperado.
     *                  }
     *                  Sino // temp1 tiene solo hijoDerecho
     *                  {
     *                      EL hijoIzquierdo del nodo papá temp2 = hijoDerecho de temp1;    
     *                  }            
     *              }    
     *          }
     *          Sino // temp1 es hijo derecho de temp2(nodo papá)
     *          {
     *              Si( temp1 tiene hijoIzquierdo e hijoDerecho )
     *              {
     *                  EL derecho del nodo papá temp2 = hijoIzquierdo de temp1;
     *                  El hijoDerecho del hijoDerecho de temp2 = hijoDerecho de temp1;
     *                  Eliminar temp1; // Revisar comportamiento esperado.
     *              }
     *              Sino
     *              {
     *                  Si( temp1 tiene solo hijoIzquierdo )
     *                  {
     *                      EL hijoDerecho del nodo papá temp2 = hijoIzquierdo de temp1;
     *                      Eliminar temp1; // Revisar comportamiento esperado.
     *                  }
     *                  Sino // temp1 tiene solo hijoDerecho
     *                  {
     *                      EL hijoDerecho del nodo papá temp2 = hijoDerecho de temp1;    
     *                  }            
     *              }    
     *   
     *          }
     * 
     *     }
     * 
     * }
     * Sino
     * {     
     * 
     *      Si( El elemento en el nodo apuntado por temp1 es menor que el elemento a eliminar ) entonces Visitar subárbol derecho.
     *      {
     *          temp2 = temp1; // Guarda un puntero al nodo papá.
     *          temp1 = hijoDerecho de temp1;
     *      }
     *      Sino
     *      {
     *          Visitar subárbol izquierdo
     *          temp2 = temp1; // Guarda un puntero al nodo papá.
     *          temp1 = hijoIzquierdo de temp1;
     *      }
     * }
     */
    if( root->data == number ) // Eliminar raíz.
    {
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
