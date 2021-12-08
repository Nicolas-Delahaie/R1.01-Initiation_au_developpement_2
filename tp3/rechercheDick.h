/**
 * @file main.cpp
 * @author N.DELAHAIE
 * @brief Manipuler la recherche dichotomique
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef RECHERCHE_DICK_H
#define RECHERCHE_DICK_H
#include <iostream>
using namespace std;

struct Adresse 
{
    string numRue; 
    string nomRue;
    unsigned short int codePostal;
    string nomVille; 
};

struct Personne
{
    string nom;
    string prenom;
    Adresse adresse;
};


/**
 * @brief 
 * 
 * @param tab 
 * @param lgTab 
 */
void afficherTableau (const int tab[], unsigned short int lgTab);

/**
 * @brief Affiche l'adresse  d'une personne
 * 
 * @param personne 
 */
void afficherAdresse(const Personne& personne);

/**
 * @brief  Effectue une recherche dichotomique de val dans tab de taille nbCases et retourne s'il a été trouvé ou non avec sa position si c'est le cas
 * 
 * @param tab 
 * @param val 
 * @param nbCases 
 * @param pos 
 * @return true 
 * @return false 
 */
bool rechercheDichotomique(int tab[], int val, unsigned int nbCases, unsigned int &pos, unsigned int &nbRep);


#endif