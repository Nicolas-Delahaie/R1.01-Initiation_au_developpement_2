/**
 * @file tris.h
 * @author N. DELAHAIE
 * @brief Manipule les algorithes de tri
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "tris.h"
#include <iostream>
using namespace std;


int main (void)
{
    unsigned const int tailleListe = 6;
    //int liste[6] = {0,5,10,15,20,9};
    int liste[6] = {85,6,4,77,95,1};
    //triParInsertion(liste, tailleListe);
    triBulle(liste, tailleListe);

    afficher(liste, tailleListe);
    
    //testTriBulle_entiers();
    //testTriBulle_personnes();
    testTriParInsertion_entiers();
    //testTriParSelectionDePlace_entiers();

    return 911;
}
