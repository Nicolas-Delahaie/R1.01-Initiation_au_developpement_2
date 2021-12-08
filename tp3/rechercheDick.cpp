/**
 * @file main.cpp
 * @author N.DELAHAIE
 * @brief Manipuler la recherche dichotomique
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "rechercheDick.h"

void afficherTableau (const int tab[], unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ", " ;

        };
        cout << tab[lgTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

void afficherAdresse (const Personne& personne)
{
    cout << "  {" << personne.nom << ", " << personne.prenom << ", { " ;
    cout <<        personne.adresse.numRue << ", " ;
    cout <<        personne.adresse.nomRue << ", ";
    cout <<        personne.adresse.codePostal << ", ";
    cout <<        personne.adresse.nomVille << " }";
    cout << "}";
}

bool rechercheDichotomique(int tab[], int val, unsigned int nbCases, unsigned int &pos, unsigned int &nbRep)
{
    unsigned short int bInf;
    unsigned int bSup;
    unsigned int milieu;

    //Initialisation
    nbRep = 0;
    bInf = 0;
    bSup = nbCases-1;

    //Effectuer la recherche
    while(true)
    {
        if (bInf > bSup)
        {
            return false;
        }
        nbRep++;

        //Calcul milieu
        milieu = (bSup + bInf)/2;

        if (tab[milieu] == val)
        {
            pos = milieu;
            return true;
        }
        
        //Progresser dans l'espace de recherche
        if (tab[milieu] > val)
        {
            bSup = milieu -1;
        }
        else
        {
            bInf = milieu +1;
        }
    }
}