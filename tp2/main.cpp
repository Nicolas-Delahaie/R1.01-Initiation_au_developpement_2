/*
 But :  Manipuler des fractions
 Auteur : N. DELAHAIE
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
#include "fractions.h"
using namespace std;


int main (void)
{   
    //    ****************      D E C L A R A T I O N S      ***************
    //    V A R I A B L E S                    
    Fraction frac1;
    Fraction frac2;
    //    ****************      T R A I T E M E N T S       ****************   
    frac1 = inititalisation(3,4);
    //modifNumerateur(frac1, 4);
    //modifDenominateur(frac1, 7);

    //frac2 = saisieFrac();

    //afficheValExacte(frac1);
    //afficheValExacte(frac2);

    afficheValExacte(saisieFracEtOper());

    //afficheValExacte(division(frac1, frac2));
    //afficheArrondie(division(frac1, frac2));
    

    //if (fracEgales(frac1, frac2))  {cout << "Les 2 fractions sont egales" << endl;}
    //else                           {cout << "Les 2 fractions ne sont pas egales" << endl;}

    //afficheArrondie(frac2);
    
    //denomCommun(frac1, frac2);
    //afficheValExacte(frac1);
    //afficheValExacte(frac2);
    
    //afficheValExacte(saisieOper(frac1, frac2));

    //afficheValExacte(saisieOper(frac1, frac2));
    


    return 911;
}

