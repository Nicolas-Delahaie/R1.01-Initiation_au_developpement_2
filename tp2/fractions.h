/**
 * @file fractions.h
 * @author N. DELAHAIE
 * @brief Entête du module fractions.cpp
 * @date 2021-11-17 
 */

#ifndef FRACTIONS_H
#define FRACTIONS_H

struct Fraction
{
    int num;
    int denom;
};

const Fraction FRACTION_NULLE = {0, 1}; 

// -- CONSTRUCTEURS --
/**
 * @brief Renvoit une Fraction avec pour numerateur num et denominateur denom. Une fraction peut avoir un dénominateur égal à 0
 * 
 * @param numerateur 
 * @param denominateur 
 * @return Fraction 
 */
Fraction inititalisation(int numerateur, int denominateur);


// -- SAISIE --
/**
 * @brief Renvoit une fraction définie par la saisie du numérateur et du dénominateur à l'utilisateur
 * 
 * @return Fraction 
 */
Fraction saisieFrac();

/**
 * @brief Renvoit le resultat de frac1 et frac2 par l'opérateur saisie entre +, -, *, /
 * 
 * @param frac1 
 * @param frac2 
 * @return Fraction 
 */
Fraction saisieOper(Fraction frac1, Fraction frac2);

/**
 * @brief Renvoit le résultat d'un calcul de deux fractions saisies
 * 
 * @return Fraction 
 */
Fraction saisieFracEtOper();



// -- MODIFICATEURS --
/**
 * @brief Remplace le dénominateur de frac par denom
 * 
 * @param frac 
 * @param numerateur 
 */
void modifNumerateur(Fraction &frac, int numerateur);

/**
 * @brief Remplace le numérateur de frac par num
 * 
 * @param frac 
 * @param denominateur 
 */
void modifDenominateur(Fraction &frac, int denominateur);



// -- CONVERTEURS --
/**
 * @brief Transforme frac sous forme irreductible
 * 
 * @param frac 
 */
void conversionIrreductible (Fraction &frac);

/**
 * @brief Met frac1 et frac2 sur le même denominateur
 * 
 * @param frac1 
 * @param frac2 
 */
void denomCommun(Fraction &frac1, Fraction &frac2);



// -- OBSERVATEURS --
/**
 * @brief Indique si la fraction est réduite ou non
 * 
 * @param frac 
 * @return true 
 * @return false 
 */
bool estReduite (Fraction frac);

/**
 * @brief Indique si la fraction n'a pas un denominsateur égal à 0
 * 
 * @param frac 
 * @return true 
 * @return false 
 */
bool denomNegalAZero(Fraction frac);

/**
 * @brief Indique si les 2 fractions sont égales ou non
 * 
 * @param frac1 
 * @param frac2 
 * @return true 
 * @return false 
 */
bool fracEgales(Fraction frac1, Fraction frac2);



// -- OPERATEURS --
/**
 * @brief Renvoit l'addition de frac1 et frac2
 * 
 * @param frac1 
 * @param frac2 
 * @return Fraction 
 */
Fraction addition(Fraction frac1, Fraction frac2);

/**
 * @brief Renvoit la soustraction de frac1 et frac2
 * 
 * @param frac1 
 * @param frac2 
 * @return Fraction 
 */
Fraction soustraction(Fraction frac1, Fraction frac2);

/**
 * @brief Renvoit la multiplication de frac1 et frac2
 * 
 * @param frac1 
 * @param frac2 
 * @return Fraction 
 */
Fraction multiplication(Fraction frac1, Fraction frac2);

/**
 * @brief Renvoit la division de frac1 et frac2
 * 
 * @param frac1 
 * @param frac2 
 * @return Fraction 
 */
Fraction division(Fraction frac1, Fraction frac2);



// -- SORTIES --
/**
 * @brief Affiche la valeur exacte de frac de la forme "9 / 2"
 * 
 * @param frac 
 */
void afficheValExacte(Fraction frac);

/**
 * @brief Affiche la valeur arrondie de frac de la forme "4,5"
 * 
 * @param frac 
 */
void afficheArrondie(Fraction frac);



// -- AUTRES --
/**
 * @brief Renvoit le pgcd de 2 nombres entiers positifs
 * 
 * @param a 
 * @param b 
 * @return unsigned int 
 */
unsigned int pgcd(unsigned int a,unsigned int b);

/**
 * @brief Renvoit le ppcm de 2 nombres entiers positifs
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int ppcm(unsigned int x, unsigned int y);


#endif