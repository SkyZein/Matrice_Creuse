//
//  main.cpp
//  Matrice_Creuse
//
//  Created by Despret Jean-Philippe on 19/05/2015.
//  Copyright (c) 2015 Despret Jean-Philippe. All rights reserved.
//

#include <iostream>
#include "Matrice.h"

using namespace std;

int main()
{
    cout << "Projet Matrice" << endl;
    
    Matrice matrice1(100,100); // nombre ligne et colonne première matrice
    Matrice matrice2(100,100); // idem avec la deuxième matrice
    
    matrice1.Affichage(); // affichage de la première matrice
    matrice2.Affichage("MATRICE.txt"); // affichage de la seconde matrice et stockage dans un fichier texte
    
    for (int i=0; i<120; i++)
    {
        cout << i << "   " << matrice1.getValue(i,2) << endl; //
    }
    
    matrice1 += matrice2;// opération entre la matrice 1 et la matrice 2
    matrice1.Affichage("MATRICE_ADD.txt"); // résultat sotcké dans un autre fichier texte
    
    return 0;
}
