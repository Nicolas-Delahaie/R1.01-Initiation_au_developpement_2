/**
 * @file tris.h
 * @author N. DELAHAIE
 * @brief Regroupe les entêtes des sous-programmes de tris 
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TRIS_H
#define TRIS_H
#include <iostream>
using namespace std;

// Définition des types du module
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
 * @brief Affiche sur une ligne le contenu de l'enregistrement passé en paramètre
 * 
 * @param personne 
 */
void afficher(const Personne& personne);
/**
 * @brief affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments de type Personne si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')
 * 
 * @param tab 
 * @param lgTab 
 */
void afficher (const Personne tab[], unsigned short int lgTab);
/**
 * @brief affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments de type Personne si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')
 * 
 * @param tab 
 * @param lgTab 
 */
void afficher (const int tab[], unsigned short int lgTab);


/**
 * @brief Trie tab de taille nbTab par selection de place
 * 
 * @param tab 
 * @param nbTab 
 */
void triParSelectionDePlace (int tab [], unsigned int taille);


/**
 * @brief Trie tab de taille nbTab par tri à bulles
 * 
 * @param tab 
 * @param nbTab 
 */
void triBulle (int tab [], unsigned int taille);
/**
 * @brief 
 * 
 * @param Personne 
 * @param taille 
 */
void triBulle (Personne tab [], unsigned int taille);


/**
 * @brief 
 * 
 * @param tab 
 * @param nbTab 
 */
void triParInsertion (int tab [], unsigned int taille);



/* --------------------------------------------------
  Déclarations des sous-programmes utilisés dans main()
  -----------------------------------------------------*/
void testTriBulle_entiers();
// test du triBulle croissant d'un tableau d'entiers
void testTriBulle_personnes();
// test du triBulle croissant selon le champ .nom d'un tableau de Personnes
void testTriParInsertion_entiers();
// test du tri par Insertion croissant d'un tableau d'entiers
void testTriParSelectionDePlace_entiers();
// test du tri par Sélection de place croissant d'un tableau d'entiers




#endif
