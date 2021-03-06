/*
 Programme : Hanoi - itératif - avec Tableau de piles et sous-programmes 
 But :  Résolution des tours de Hanoi - version itérative - pour 3 à 9 disques
 Date de dernière modification : 04-12-2021
 Auteur : Pantxika Dagorret
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - TD n°4
*/
#include <iostream>
#include <stdlib.h>
#include "pile.h"
using namespace std;


const unsigned int NB_TOURS = 3;     // CONSTANTE dite 'GLOBALE' : 
                                            // portée = tous les Sous-programmes
                                            // présents dans ce fichier

/* ---------- Observateurs
   ------------------------------------------------------------------*/

bool estDeplacable(const UnePile tourOrigine, const UnePile tourDestination);
//But : indiquer si la tour d'origine peut déplacer son dernier disque vers la tour de destination.


/* ---------- Primitives modifiant 1 tour
   ------------------------------------------------------------------*/

void deplacerDisque(UnePile &tourOrigine, UnePile &tourDestination);
// But : déplace un disque d'une tour à une autre
// pré-condition : estDeplacable(tourOrigine, tourDestination) est VRAI
//                 c'est à dire :
//
//                 estVide(tourOrigine)  = FAUX
//                 et  (
//                        (estVide(tourDestination) = VRAI ) 
//                         OU 
//                        ( estVide(tourDestination)  = FAUX
//                          et
//                          sommet(tourOrigine) < sommet(tourDestination)
//                         )
//                     )

void remplirTour(UnePile &tourARemplir , const unsigned int nbDisques);
// But remplit la tourARemplir avec nbDisques, du plus grand (en bas) au plus 
// petit (au sommet) de la tour

/* ---------- Primitives modifiant plusieurs tours
   ------------------------------------------------------------------*/

void initialiserTours(UnePile lesTours[]);
// But : initialise les NB_TOURS tours du tableau lesTours

/* ---------- Affichages
   ------------------------------------------------------------------*/

void afficherTour(UnePile tour);
// Affiche le contenu de la tour passée en paramètre

void afficherTours(const UnePile lesTours[]);
// Affiche le contenu des tours passées en paramètre 



/* ---------- Algorithmes de résolution du problème des tours de Hanoi
   --------------------------------------------------------------------*/

void resoudreToursHanoiManuel(unsigned int nbDisques); 
// Buts : 1- faire résoudre les tours de Hanoi avec nbDisques au joueur
//        2-pour tester les primitives 
//        - initialiserTours()
//        - remplirTour()
//        - afficherTour()
//        - afficherTours()
//        - deplacerDisque()


/* ---------- Boîte à outils pour resolutionToursHanoiManuel ()
   -------------------------------------------------------------------*/

   void saisieVerifDeplacementDemande(bool& reponseOk, unsigned int& origine, unsigned int& destination);
   // saisie du choix des tours prenant part au déplacement d'un disque :
   // 12 pour deplacement d'un disque de la tour 1 vers la tour 2
   // 13 pour deplacement d'un disque de la tour 1 vers la tour 3
   // 31 pour deplacement d'un disque de la tour 3 vers la tour 1
   // ...
   // 0 si aucun deplacement demandé

   int carToChiffre (char car);
   // convertit un caractère en chiffre



/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
   -------------------------------------------------------------------*/


// ======================================================================
int main()
{
    const unsigned int NB_MINIMUM_DISQUES = 3;   // nbre minimum autoris� de disques
    const unsigned int NB_MAXIMUM_DISQUES = 9;   // nbre maximum autoris� de disques
    unsigned int nbDisques;                     // nbre de disques à déplacer
    
    // (clavier), NB_MINIMUM_DISQUES, NB_MINIMUM_DISQUES >> saisie du nbre de disques >> nbDisques
    do
    {
        cout << "Entrer le nbre de disques de la tour de Hanoi (entre " << NB_MINIMUM_DISQUES << " et " << NB_MAXIMUM_DISQUES << ") : ";
        cin >> nbDisques;
    }
    while (!((nbDisques >=NB_MINIMUM_DISQUES) && (nbDisques <= NB_MAXIMUM_DISQUES)));


    // nbDisques >>  résoudre Hanoi manuellement pour le nb de disques entré >> ()
    resoudreToursHanoiManuel(nbDisques);
        
    /*
    unsigned short int origine;
    unsigned short int destination;
    unsigned short int NOMBRE_DISQUES = 3;
    UnePile lesTours[3];

    
    initialiserTours(lesTours);
    remplirTour(lesTours[0], NOMBRE_DISQUES);
    afficherTours(lesTours);

    while(true)
    {
        cout << "Origine :";
        cin >> origine;
        cout << "Destination :";
        cin >> destination;
        
        origine --;
        destination--;

        if (estDeplacable(lesTours[origine], lesTours[destination]) == false)
        {
            cout << "Eh fdp" << endl;
        }
        else
        {
            deplacerDisque(lesTours[origine], lesTours[destination]);
        }
        afficherTours(lesTours);
    }
    */




    return 0;
}

// ======================================================================


// ---------- Observateurs
bool estDeplacable(const UnePile tourOrigine, const UnePile tourDestination)
{

    if (estVide(tourOrigine))
    {
        return false;
    }
    else 
    {
        if (estVide(tourDestination))
        {
            return true;
        }
        else
        {
            if (sommet(tourOrigine) < sommet(tourDestination))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

// ---------- Primitives modifiant 1 tour
void deplacerDisque(UnePile &tourOrigine, UnePile &tourDestination)
{
    UnElement disque;
    depiler(tourOrigine, disque);
    empiler(tourDestination, disque);
}

void remplirTour(UnePile &tourARemplir , const unsigned int nbDisques)
{
    for (unsigned int i = nbDisques ; i > 0 ; i--)
    {
        empiler(tourARemplir, i);
    }
}

// ---------- Primitives modifiant plusieurs tours
void initialiserTours(UnePile lesTours[])
{
    for (unsigned int i = 0; i < 3; i++)
    {
        initialiser(lesTours[i]);
    }
    
}


// ---------- Affichages
void afficherTour(UnePile tour)
// paramètre passé par valeur
{
    UnElement disque;
    cout << "{ ";
    while (!estVide(tour))
    {
        depiler(tour, disque);
        cout << disque << ". ";
    }
    cout << " }";
}

void afficherTours(const UnePile lesTours[])
{
    for (unsigned int i = 0 ; i < 3 ; i++)
    {
        cout << "t" << i + 1 << " = ";
        afficherTour(lesTours[i]);
        cout << "      ";
    }
    cout << endl;
}

// ---------- Algorithme de résolution du problème des tours de Hanoi
void resoudreToursHanoiManuel(unsigned int nbDisques)
{
    UnePile lesTours[3];

    unsigned int tourOrigine;       // tour origine du déplacement
    unsigned int tourDestination;   // tour destination du déplacement
    bool deplacementDemande;        // = vrai si, mors de la saisie, un déplacement est demandé, 
                                    // = faux si pas de déplacement demandé

    //Initialiser tours et éléments de la réussite
    initialiserTours(lesTours);
    remplirTour(lesTours[0], nbDisques);
    afficherTours(lesTours); cout << endl;
       
    // faire des déplacements manuels jusqu'à gagner
    do
    {
        // saisie - verif
        saisieVerifDeplacementDemande(deplacementDemande, tourOrigine, tourDestination);
        if (deplacementDemande)
        {
            if (estDeplacable(lesTours[tourOrigine], lesTours[tourDestination]))
            {
                system ("CLS");
                // faire le déplacement demandé
                deplacerDisque (lesTours[tourOrigine], lesTours[tourDestination]);
                afficherTours(lesTours);
            }
            else
            {
                cout << "Deplacement impossible" << endl;
            }
        }
    } while (!(estVide(lesTours[0]) && estVide(lesTours[1])));
}


/* ---------- Boîte à outils pour Hanoi Manuel 
   -------------------------------------------------------------------*/

   void saisieVerifDeplacementDemande(bool& deplacement, unsigned int& origine, unsigned int& destination)
   {
        string demandeSaisie    ;  // la demande de déplacement saisie
        bool reponseOk ;            // indicateur de validité de la réponse saisie : "12", "21", .... "31", ou "0xx"
        
        
        deplacement = false;   // = faux si l'utilisateur saisit "0" (pas de déplacement), vrai s'il saisit une des autres combinaisons autorisées
        cout << endl << "Instruction (12 pour deplacer le disque de la tour 1 a 2) : " ;

        do
        {
            // saisie 
            cout << " : " ;
            cin >> demandeSaisie;

        } while (!((demandeSaisie[0] == '0') ||
                 ((demandeSaisie[0] >= '1') && (demandeSaisie[0] <= '3') && 
                  (demandeSaisie[1] >= '1') && (demandeSaisie[1] <= '3'))));

        // demandeSaisie >> Analyse de la réponse correcte >>  >> deplacement, [origine, destination] 
        if (demandeSaisie[0] != '0')
        {
            origine = carToChiffre(demandeSaisie[0]) - 1;
            destination = carToChiffre(demandeSaisie[1]) - 1;
            deplacement = true;
        }
   }

      int carToChiffre (char car)
      {
          int chiffre;
          chiffre = int(car-int('0'));
          return chiffre;
      }

      
/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
   -------------------------------------------------------------------*/