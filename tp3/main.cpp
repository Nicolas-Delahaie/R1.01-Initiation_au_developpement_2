/**
 * @file main.cpp
 * @author N.DELAHAIE
 * @brief Manipuler la recherche dichotomique
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "rechercheDick.h"

using namespace std;



int main()
{   
    const unsigned int nbCases = 10; 
    int tableau[nbCases] = {-53,-40,-35,-20,-5,8,13,18,19,40};
    int val;
    unsigned int pos;
    unsigned int nbBouclesRecherche;
    

    afficherTableau(tableau, nbCases);
    
    cout << "Valeur recherchee : ";
    cin >> val;

    if (rechercheDichotomique(tableau, val, nbCases, pos, nbBouclesRecherche))  {cout << "Position de " << val << " : " << pos << " en " << nbBouclesRecherche << " boucles" << endl;}
    else                                                                        {cout << "Valeur non presente." << endl;}



    return 911;
}