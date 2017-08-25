/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dennis
 *
 * Created on 23 de agosto de 2017, 06:14 PM
 */

#include <cstdlib>
#include "IntegerTree.h"

int main(int argc, char** argv)
{
    IntegerTree setA;

    setA.insert( 13 );
    setA.insert( 7 );
    setA.insert( 3 );
    setA.insert( 11 );
    setA.insert( 15 );
    setA.insert( 22 );
    setA.insert( 19 );

    std::cout << "Conjunto Original:" << setA.toStr( ) << std::endl;

    setA.remove( 13 );
    std::cout << "A:" << setA.toStr( ) << std::endl;

    setA.remove( 7 );
    std::cout << "A:" << setA.toStr( ) << std::endl;

    setA.remove( 3 );
    std::cout << "A:" << setA.toStr( ) << std::endl;
}

