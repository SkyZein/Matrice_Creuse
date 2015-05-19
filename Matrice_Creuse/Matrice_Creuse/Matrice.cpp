//
//  Matrice.cpp
//  Matrice_Creuse
//
//  Created by Despret Jean-Philippe on 19/05/2015.
//  Copyright (c) 2015 Despret Jean-Philippe. All rights reserved.
//

#include "Matrice.h"
#include <map>
#include <iostream>
#include <tgmath.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

Matrice::Matrice(int ligne, int colonne)
{
    Ligne = ligne;
    Colonne = colonne;
    zero = (Ligne * Colonne) * 0.1;
    bool test = false ;
    srand(time(NULL));
    
    for (int i=0; i<10; i++)
    {
        vector < pair < int, int > > tableCoordinate;
        _matrix[i] = tableCoordinate;
    }
    for ( int i=0; i<=zero; i++)
    {
        int value = ceil(rand() % (1 - 11) +1);
        int column = ceil(rand() % (0 - Ligne));
        int line = ceil( rand() % (0 - Colonne));
        unsigned int j = _matrix[value].size();
        
        pair <int, vector <pair <int, int>>> pairValue;
        pair <int, int> pairCoordinate;
        vector <pair <int, int>> tableCoordinate;
        pairValue.first = value;
        pairCoordinate.first = column;
        pairCoordinate.second = line;
        while (j>0 && test == false)
        {
            if (_matrix[value][j-1].second == line)
            {
                if (_matrix[value][j-1].first == column)
                {
                    test = true ;
                }
            }
            j--;
        }
        if (test == false)
        {
            tableCoordinate.push_back(pairCoordinate);
            pairValue.second = tableCoordinate;
            _matrix[pairValue.first-1].push_back(pairCoordinate);
        }
        test = false ;
    }
    for (int i=0; i<Ligne; i++)
    {
        bool test = false ;
        for (int j=0; j<11; j++)
        {
            for (unsigned int k=0; k<_matrix[j].size(); k++)
            {
                if (_matrix[j][k].second == i)
                {
                    test = true;
                }
            }
        }
        if (test == false)
        {
            int value = ceil(rand() % (1 - 11) +1);
            int line = ceil(rand() % (0 - Colonne));
            
            pair <int, int>  pairCoordinate;
            pairCoordinate.first = i;
            pairCoordinate.second = line;
            _matrix[value].push_back(pairCoordinate);
        }
    }
}

void Matrice::Affichage()
{
    ofstream file("Matrice.txt", ios::out | ios::trunc);
    
    if(file)
    {
        file << "Ligne '\t' Colonne '\t' Valeur" << endl;
        
        for(int i=0; i<_matrix.size(); i++)
        {
            for (unsigned int j=0; j<_matrix[i].size(); j++)
            {
                file << _matrix[i][j].second << '\t' <<  _matrix[i][j].first << '\t' <<  i+1 << endl;
                file << "______________________________" << endl;
            }
            file << endl;
        }
        file << Ligne << " " << Colonne;
    }
    
    else
    {
        cout << "Impossible d'ecrire dans le fichier" << endl;
    }
    
    file.close();
}

void Matrice::Affichage(char * fileName)
{
    ofstream file(fileName, ios::out | ios::trunc);
    
    if(file)
    {
        file << "Ligne '\t' Colonne '\t' Valeur" << endl;
        
        for(int i=0; i<_matrix.size()-1; i++)
        {
            for (unsigned int j=0; j<_matrix[i].size(); j++)
            {
                file << _matrix[i][j].second << '\t' <<  _matrix[i][j].first << '\t' <<  i+1 << endl;
                file << "______________________________" << endl ;
            }
            file << endl;
        }
        file << Ligne << " " << Colonne;
    }
    
    else
    {
        cout << "Impossible d'ecrire dans le fichier" << endl;
    }
    file.close();
}

int Matrice::getValue(int column, int line)
{
    for (int i=0 ; i<this->Ligne; i++)
    {
        for (unsigned int j=0; j < this->_matrix[i].size(); j++)
        {
            if (this->_matrix[i][j].first == line && this->_matrix[i][j].second == column)
            {
                return i+1;
            }
        }
    }
    
    return 0;
}

vector <pair <int, int>> Matrice::getCoordinates(int value)
{
    return _matrix[value-1];
}

Matrice & Matrice::operator+= (Matrice second)
{
    std::map <int, std::vector <std::pair <int, int>>> tmp;
    pair <int, vector <pair <int, int>>> pairValue;
    pair <int, int>  pairCoordinate;
    vector <pair <int, int>> tableCoordinate;
    
    for(int i=0 ; i<this->Ligne; i++)
    {
        for (int j=0; j<this->Colonne; j++)
        {
            if(this->getValue(i,j) != 0 || second.getValue(i,j) != 0)
            {
                pairValue.first = this->getValue(i,j) + second.getValue(i,j);
                pairCoordinate.first = j;
                pairCoordinate.second = i;
                
                tableCoordinate.push_back(pairCoordinate);
                pairValue.second = tableCoordinate;
                tmp[pairValue.first - 1].push_back(pairCoordinate);
            }
        }
    }
    
    this->_matrix = tmp;
    return *this;
}