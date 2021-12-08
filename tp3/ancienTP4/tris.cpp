/**
 * @file tris.h
 * @author N. DELAHAIE
 * @brief Regroupe les sous-programmes de tris 
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "tris.h"
#include <iostream>
using namespace std;

void afficher (const Personne& personne)
{
    cout << "  {" << personne.nom << ", " << personne.prenom << ", { " ;
    cout <<        personne.adresse.numRue << ", " ;
    cout <<        personne.adresse.nomRue << ", ";
    cout <<        personne.adresse.codePostal << ", ";
    cout <<        personne.adresse.nomVille << " }";
    cout << "}";
}
void afficher (const Personne tab[], unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{" << endl;
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            afficher(tab[i]) ;
            cout << ", "<< endl ;
        };
        afficher (tab[lgTab-1]);
        cout << endl <<  "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}
void afficher (const int tab[], unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ",  " ;
        };
        cout << tab[lgTab-1] <<  "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}


void faireMonterLaBulleIci (int tab[], unsigned int ici)
{
    int temp;
    for (unsigned int i = 0; i <= ici ; i++)
    {
        if (tab[i] >  tab[i+1])
        {
            temp = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = temp;
        }
    }
    
}
void triBulle (int tab [], unsigned int taille)
{
    for (unsigned int i = taille-1; i >= 1; i--)
    {
        faireMonterLaBulleIci(tab, i);
    }
}
void faireMonterLaBulleIci (Personne tab[], unsigned int ici)
{
    Personne temp;
    for (unsigned int i = 0; i <= ici ; i++)
    {
        if (tab[i].nom >  tab[i+1].nom)
        {
            temp = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = temp;
        }
    }
    
}
void triBulle (Personne tab [], unsigned int taille)
{
    for (unsigned int i = taille-1; i > 1; i--)
    {
        faireMonterLaBulleIci(tab, i);
    }
}


unsigned int determinerPlace (int tab[], unsigned int placeInititale)
{
    unsigned int nouvellePlace;
    nouvellePlace = placeInititale;
    while (true)
    {
        if (tab[nouvellePlace-1] >= tab[nouvellePlace])
        {
            break;
        }
        nouvellePlace = nouvellePlace -1;
    }
    return nouvellePlace;
}
void insererValeur (int tab[], unsigned int depart, unsigned int arrivee)
{
    int val;
    val = tab[depart];
    for (unsigned int i = depart-1 ; i > arrivee ; i--)
    {
        tab[i+1] = tab[i];
    }
}
void triParInsertion (int tab [], unsigned int taille)
{
    unsigned int arrivee;

    for (unsigned int i = 1; i < taille; i++)
    {
        arrivee = determinerPlace(tab, i);
        insererValeur(tab, i, arrivee);
    }
}



/* --------------------------------------------------
  Corps des sous-programmes utilisés dans main()
  -----------------------------------------------------*/

void testTriBulle_entiers()
{
    
    const unsigned int TAILLE = 10 ;

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
   int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
   int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
   int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

   cout << " ------------------   TRI BULLE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;

}

void testTriBulle_personnes()
{
    const unsigned short int TAILLE = 10;
    Personne tableau1[TAILLE] =   {                                             // à l'envers
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Lopisteguy", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Etcheverry", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},                               
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}}
                                }; 

        Personne tableau2[TAILLE] =   {                                                 // en désordre quelconque, avec doublons
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Marquesuzaa", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},       
        {"Marquesuzaa", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},        
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}}                              
        };                                                                              // remarquer l'ordre des 3 Marquesuzaa

    cout << " ------------------   TRI BULLE croissant - tableau de PERSONNES --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // le tri Bulle est stable : 
    // - AVANT le tri, les 3 Marquesuzaa etaient dans un certain ordre : Philippe, Christophe, Christophe
    // - APRES le tri, les 3 Marquesuzaa sont dans le même ordre --> le triBulle respecte l'ordre initial des doublons 
}

void testTriParInsertion_entiers()
{
    
    const unsigned int TAILLE = 10 ;

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
   int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
   int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
   int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

   cout << " ------------------   TRI par INSERTION croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tripar INSERTION  croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;
}

void testTriParSelectionDePlace_entiers()
{
    /*
    const unsigned int TAILLE = 10 ;

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
   int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
   int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
   int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

   cout << " ------------------   TRI par SELECTION de PLACE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tripar SELECTION de PLACE  croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;
    */
}

