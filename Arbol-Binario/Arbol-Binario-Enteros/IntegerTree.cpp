
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

            if( current->data == number )
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

void IntegerTree::toStr() const
{
    std::cout << '{';
    printTree( root );
    std::cout << '}' << std::endl;
}

void printTree(const std::shared_ptr<IntegerTree::Node> node)
{
    if( node )
    {
        printTree( node->leftChild );
        std::cout << node->data << ',';
        printTree( node->rightChild );
    }
}
