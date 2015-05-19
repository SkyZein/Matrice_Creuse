//
//  Matrice.h
//  Matrice_Creuse
//
//  Created by Despret Jean-Philippe on 19/05/2015.
//  Copyright (c) 2015 Despret Jean-Philippe. All rights reserved.
//

#ifndef __Matrice_Creuse__Matrice__
#define __Matrice_Creuse__Matrice__

#include <vector>
#include <iostream>
#include <map>

class Matrice
{
    std::map <int, std::vector <std::pair <int, int>>> _matrix;
    int Ligne, Colonne, zero;
    
    public :
    
    Matrice(int ligne, int colonne);
    std::vector < std::pair < int, int > > getCoordinates(int value);
    int getValue(int column, int line);
    void setValue(int column, int line);
    void Affichage();
    void Affichage(char * fileName);
    Matrice exponent(int n);
    Matrice transposed();
    Matrice inversed();
    Matrice& operator+=(Matrice second);
    Matrice& operator-=(Matrice second);
    Matrice& operator*=(Matrice second);
    Matrice& operator/=(Matrice second);
    Matrice& operator=(Matrice second);
    std::vector <std::pair <int, int>> operator[](int value);
};

Matrice operator+(Matrice const& first, Matrice const& second);
Matrice operator-(Matrice const& first, Matrice const& second);
Matrice operator*(Matrice const& first, Matrice const& second);
Matrice operator/(Matrice const& first, Matrice const& second);
bool operator==(Matrice first, Matrice second);
bool operator!=(Matrice first, Matrice second);
std::ostream& operator<<(std::ostream& flux, Matrice const& matrix);

#endif /* defined(__Matrice_Creuse__Matrice__) */
