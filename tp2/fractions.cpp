/**
 * @file fractions.cpp
 * @author N. DELAHAIE
 * @brief Module servant à manipuler des fractions
 * @date 2021-11-18
 * 
 */

#include "fractions.h"
#include <iostream>
#include <math.h>
using namespace std;

// -- CONSTRUCTEURS --
Fraction inititalisation(int numerateur, int denominateur)
{
    Fraction frac;
    frac.num = numerateur;
    frac.denom = denominateur;
    if (denominateur < 0)
    {
        frac.num = -numerateur;
        frac.denom = -denominateur;
    }

    return frac;
}


// -- SAISIE --
Fraction saisieFrac()
{
    Fraction frac;
    cout << "Numerateur : ";
    cin >> frac.num;
    cout << "Denominateur : ";
    cin >> frac.denom;
    return frac;
}

Fraction saisieOper(Fraction frac1, Fraction frac2)
{
    char operateur;
    Fraction resultat;

    cout << "Operateur : ";
    cin >> operateur;
    switch (operateur)
    {
    case '+': resultat = addition(frac1, frac2); break;
    case '-': resultat = soustraction(frac1, frac2); break;
    case '*': resultat = multiplication(frac1, frac2); break;
    case '/': resultat = division(frac1, frac2); break;
    default: cout << "Mauvaise saisie d'oerateur"; break;
    }

    return resultat;
}

Fraction saisieFracEtOper()
{
    return saisieOper(saisieFrac(), saisieFrac());
}


// -- MODIFICATEURS --
void modifNumerateur(Fraction &frac, int numerateur)
{
    frac.num = numerateur;
}

void modifDenominateur(Fraction &frac, int denominateur)
{
    frac.denom = denominateur;
}


// -- CONVERTEURS --
void conversionIrreductible (Fraction &frac)
{
    unsigned int plusPetitDiviseurCommun;
    plusPetitDiviseurCommun = pgcd(frac.num, frac.denom);
    frac.num /= plusPetitDiviseurCommun;
    frac.denom /= plusPetitDiviseurCommun;
}

void denomCommun(Fraction &frac1, Fraction &frac2)
{
    unsigned int ppcmDenom;

    if (frac1.denom != frac2.denom)
    {
        ppcmDenom = ppcm(frac1.denom, frac2.denom);

        frac1.num *= ppcmDenom / frac1.denom;
        frac2.num *= ppcmDenom / frac2.denom;

        frac1.denom = ppcmDenom;
        frac2.denom = ppcmDenom;
    }
}


// -- OBSERVATEURS --
bool estReduite (Fraction frac)
{
    if (pgcd(frac.num, frac.denom) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool denomNegalAZero(Fraction frac)
{
    if (frac.denom == 0)    {return false;}
    else                    {return true;}
}

bool fracEgales(Fraction frac1, Fraction frac2)
{
    if ((frac1.num == frac2.num) && (frac1.denom == frac2.denom))
    {
        return true;
    }
    else
    {
        return false;
    }
}


// -- OPERATEURS --

Fraction addition(Fraction frac1, Fraction frac2)
{
    if (denomNegalAZero(frac1) && denomNegalAZero(frac2))
    {
        Fraction resultat;
        denomCommun(frac1, frac2);
        resultat.num = frac1.num + frac2.num;
        resultat.denom = frac1.denom;
        conversionIrreductible(resultat);

        return resultat;
    }
    else
    {
        cout << "Division par 0 impossible" << endl;
        return FRACTION_NULLE;
    }
}

Fraction soustraction(Fraction frac1, Fraction frac2)
{
    if (denomNegalAZero(frac1) && denomNegalAZero(frac2))
    {
        Fraction resultat;
        denomCommun(frac1, frac2);
        resultat.num = frac1.num - frac2.num;
        resultat.denom = frac1.denom;
        conversionIrreductible(resultat);

        return resultat;
    }
    else
    {
        cout << "Division par 0 impossible" << endl;
        return FRACTION_NULLE;
    }
}

Fraction multiplication(Fraction frac1, Fraction frac2)
{
    if (denomNegalAZero(frac1) && denomNegalAZero(frac2))
    {
        Fraction resultat;
        resultat.num = frac1.num * frac2.num;
        resultat.denom = frac1.denom * frac2.denom;
        conversionIrreductible(resultat);

        return resultat;
    }
    else
    {
        cout << "Division par 0 impossible" << endl;
        return FRACTION_NULLE;
    }
}

Fraction division(Fraction frac1, Fraction frac2)
{
    if (denomNegalAZero(frac1) && denomNegalAZero(frac2))
    {
        Fraction resultat;
        int temp;

        temp = frac2.num;
        frac2.num = frac2.denom;
        frac2.denom = temp;

        resultat.num = frac1.num * frac2.num;
        resultat.denom = frac1.denom * frac2.denom;
        conversionIrreductible(resultat);

        return resultat;
    }
    else
    {
        cout << "Division par 0 impossible" << endl;
        return FRACTION_NULLE;
    }
}


// -- SORTIES --
void afficheValExacte(Fraction frac)
{
    if (frac.num == frac.denom)     {cout << 1 << endl;}
    else if (frac.num == 0)         {cout << 0 << endl;}
    else                            {cout << frac.num << " / " << frac.denom << endl;}
}

void afficheArrondie(Fraction frac)
{
    double fracArrondie;

    if (denomNegalAZero(frac))
    {
        fracArrondie = int((double(frac.num) / double(frac.denom)) * 100.0) /100.0;
        cout << fracArrondie << endl;
    }
    else
    {
        cout << "Division impossible" << endl;
    }
}



// -- AUTRES --
unsigned int pgcd(unsigned int a,unsigned int b)
{
    return b ?  pgcd(b,a%b) : a;
}

int ppcm(unsigned int x, unsigned int y)
{
  int A=x;
  int B=y;
  while (A!=B)
  {
    while (A>B) 
    {
        B=B+y;
    }
    while (A<B) 
    {
        A=A+x;
    }
  }
  return A;
}
