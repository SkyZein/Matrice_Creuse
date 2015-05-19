//
//  Matrice.cpp
//  Matrice_Creuse
//
//  Created by Despret Jean-Philippe on 19/05/2015.
//  Copyright (c) 2015 Despret Jean-Philippe. All rights reserved.
//

#include "Matrice.h"
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <tgmath.h>
#include <fstream>

using namespace std ;

Matrice::Matrice(int width, int height)
{
    _width = width ;
    _height = height ;
    _nbNotZeros = ( _width * _height ) * 0.1;
    
    bool test = false ;
    
    
    srand(time(NULL)) ;
    
    for ( int i = 0 ; i < 9 ; i ++ )
    {
        vector < pair < int, int > > tableCoordinate ;
        _Matrice[i] = tableCoordinate ;
    }
    for ( int i = 0 ; i <= _nbNotZeros ; i++ )
    {
        int value = ceil( rand() % ( 1 - 11 ) +1 ) ;
        int column = ceil( rand() % ( 0 - _width ) ) ;
        int line = ceil( rand() % ( 0 - _height ) ) ;
        unsigned int j = _Matrice[value].size() ;
        
        pair < int, vector < pair < int, int > > > pairValue ;
        pair < int, int >  pairCoordinate ;
        vector < pair < int, int > > tableCoordinate ;
        pairValue.first = value ;
        pairCoordinate.first = column ;
        pairCoordinate.second = line ;
        while ( j > 0 && test == false )
        {
            if ( _Matrice[value][j-1].second == line )
            {
                if ( _Matrice[value][j-1].first == column )
                {
                    test = true ;
                }
            }
            j-- ;
        }
        if ( test == false )
        {
            tableCoordinate.push_back(pairCoordinate) ;
            pairValue.second = tableCoordinate ;
            _Matrice[pairValue.first-1].push_back(pairCoordinate) ;
        }
        test = false ;
    }
    for ( int i = 0 ; i < _width ; i++ )
    {
        bool test = false ;
        for ( int j = 0 ; j < 10 ; j++ )
        {
            for ( unsigned int k = 0 ; k < _Matrice[j].size() ; k++ )
            {
                if ( _Matrice[j][k].second == i )
                {
                    test = true ;
                }
            }
        }
        if ( test == false )
        {
            int value = ceil( rand() % ( 1 - 11 ) +1 ) ;
            int line = ceil( rand() % ( 0 - _height ) ) ;
            
            pair < int, int >  pairCoordinate ;
            pairCoordinate.first = i ;
            pairCoordinate.second = line ;
            _Matrice[value].push_back(pairCoordinate) ;
        }
    }
}

void Matrice :: display()
{
    
    ofstream file("Matrice.txt", ios::out | ios::trunc);
    
    if(file)
    {
        file << "Ligne '\t' Colonne '\t' Valeur" << endl ;
        
        for(int i = 0 ; i < _Matrice.size() ; i++)
        {
            for ( unsigned int j = 0 ; j < _Matrice[i].size() ; j++)
            {
                file << _Matrice[i][j].second << '\t' <<  _Matrice[i][j].first << '\t' <<  i+1 << endl ;
                file << "______________________________" << endl ;
            }
            file << endl ;
        }
        file << _width << " " << _height ;
    }
    
    else
    {
        cout << "Impossible d'ecrire dans le fichier" << endl ;
    }
    
    file.close();
}

void Matrice :: display(char * fileName)
{
    
    ofstream file(fileName, ios::out | ios::trunc);
    
    if(file)
    {
        file << "Ligne '\t' Colonne '\t' Valeur" << endl ;
        
        for(int i = 0 ; i < _Matrice.size()-1 ; i++)
        {
            for ( unsigned int j = 0 ; j < _Matrice[i].size() ; j++)
            {
                file << _Matrice[i][j].second << '\t' <<  _Matrice[i][j].first << '\t' <<  i+1 << endl ;
                file << "______________________________" << endl ;
            }
            file << endl ;
        }
        file << _width << " " << _height ;
    }
    
    else
    {
        cout << "Impossible d'ecrire dans le fichier" << endl ;
    }
    
    file.close();
}


int Matrice :: getValue(int column, int line)
{
    for (int i = 0 ; i < this->_width ; i++)
    {
        for (unsigned int j = 0 ; j < this->_Matrice[i].size() ; j++)
        {
            if (this->_Matrice[i][j].first == line && this->_Matrice[i][j].second == column )
            {
                return i+1 ;
            }
        }
        
    }
    
    return 0 ;
}

vector < pair < int, int > > Matrice::getCoordinates(int value)
{
    return _Matrice[value-1] ;
}

Matrice & Matrice :: operator+= (Matrice second)
{
    std::map < int, std::vector < std::pair < int, int > > > tmp ;
    
    pair < int, vector < pair < int, int > > > pairValue ;
    pair < int, int >  pairCoordinate ;
    vector < pair < int, int > > tableCoordinate ;
    
    for(int i = 0 ; i < this->_width ; i++)
    {
        for (int j = 0 ; j < this->_height ; j++)
        {
            
            if(this->getValue(i,j) != 0 || second.getValue(i,j) != 0)
            {
                pairValue.first = this->getValue(i,j) + second.getValue(i,j);
                pairCoordinate.first = j ;
                pairCoordinate.second = i ;
                
                
                tableCoordinate.push_back(pairCoordinate) ;
                pairValue.second = tableCoordinate ;
                tmp[pairValue.first-1].push_back(pairCoordinate) ;
                
            }
        }
        
    }
    
    this->_Matrice = tmp ;
    
    return *this ;
}