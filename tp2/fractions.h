/*
Fonctions permetttant de manipuler des fractions
De : N. DELAHAIE
*/


#ifndef FONCTIONS_H
#define FONCTIONS_H

struct Fraction
{
    int num;
    int denom;
};

const Fraction FRACTION_NULLE = {0, 4}; 

// -- CONSTRUCTEURS --
Fraction inititalisation(int numerateur, int denominateur);
/*Renvoit une Fraction avec pour numerateur num et denominateur denom.
  une fraction peut avoir un dénominateur égal à 0*/


// -- SAISIE --
Fraction saisieFrac();
/*Renvoit une fraction définie par la saisie du numérateur et du dénominateur à l'utilisateur*/
Fraction saisieOper(Fraction frac1, Fraction frac2);
/*Renvoit le resultat de frac1 et frac2 par l'opérateur saisie entre +, -, *, /*/
Fraction saisieFracEtOper();
/*Renvoit le résultat d'un calcul de deux fractions saisies*/


// -- MODIFICATEURS --
void modifNumerateur(Fraction &frac, int numerateur);
/*Remplace le dénominateur de frac par denom*/
void modifDenominateur(Fraction &frac, int denominateur);
/*Remplace le numérateur de frac par num*/


// -- CONVERTEURS --
void conversionIrreductible (Fraction &frac);
/*Transforme frac sous forme irreductible*/
void denomCommun(Fraction &frac1, Fraction &frac2);
/*Met frac1 et frac2 sur le même denominateur*/


// -- OBSERVATEURS --
bool denomNegalAZero(Fraction frac);
/*Renvoit vrai si la fraction n'a pas un denominsateur égal à 0*/
bool fracEgales(Fraction frac1, Fraction frac2);
/*Indique si les 2 fractions sont égales ou non*/


// -- OPERATEURS --
Fraction addition(Fraction frac1, Fraction frac2);
/*Renvoit l'addition de frac1 et frac2*/
Fraction soustraction(Fraction frac1, Fraction frac2);
/*Renvoit la soustraction de frac1 et frac2*/
Fraction multiplication(Fraction frac1, Fraction frac2);
/*Renvoit la multiplication de frac1 et frac2*/
Fraction division(Fraction frac1, Fraction frac2);
/*Renvoit la division de frac1 et frac2*/


// -- SORTIES --
void afficheValExacte(Fraction frac);
/*Affiche la valeur exacte de frac de la forme "9 / 2"*/
void afficheArrondie(Fraction frac);
/*Affiche la valeur arrondie de frac de la forme "4,5"*/



// -- AUTRES --
unsigned int pgcd(unsigned int a,unsigned int b);
/*Renvoit le pgcd de 2 nombres entiers positifs*/
int ppcm(unsigned int x, unsigned int y);
/*Renvoit le ppcm de 2 nombres entiers positifs*/

























#endif