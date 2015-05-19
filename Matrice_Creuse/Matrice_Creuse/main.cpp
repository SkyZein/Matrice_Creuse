//
//  main.cpp
//  Matrice_Creuse
//
//  Created by Despret Jean-Philippe on 19/05/2015.
//  Copyright (c) 2015 Despret Jean-Philippe. All rights reserved.
//

#include <iostream>
//#include "Matrice.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    
    Matrix Une(15,15);
    Matrix Deux(15,15);
    
    
    Une.display();
    
    Deux.display("Matrice2.txt");
    
    for (int i = 0 ; i < 20 ; i++ )
    {
        cout << i << " " << Une.getValue(i,2) << endl;
    }
    
    //    vector < pair < int, int > > coordinate ;
    //    coordinate = Une.getCoordinates(1) ;
    //    for ( int i = 0 ; i < coordinate.size() ; i++ )
    //    {
    //        cout << "Ligne : " << coordinate[i].second << "    Colonne : " << coordinate[i].first << endl ;
    //    }
    //    cout << coordinate.size() ;
    
    Une += Deux ;
    
    Une.display("MatriceAdd.txt");
    
    
    
    return 0;
}
