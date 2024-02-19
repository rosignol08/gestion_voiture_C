#include <stdio.h>
#include <string.h>

// creation de la structure date
typedef struct date {
  int jours;
  enum mois {janvier,fevrier,mars,avril,mai,juin,juillet,aout,septembre,octobre,novembre,decembre} mois_selectionne;
} date;
//on cree une date defaut pour reinitialiser les reservations annulees
date defaut = {0, janvier};
int duree;

// creation des voitures
typedef struct voiture {
  char type;
  date date_reservation;
  int occupee;
} voiture;

voiture voiture1 = {'A', 0, 0};
voiture voiture2 = {'B', 0, 0};
voiture voiture3 = {'C', 0, 0};
voiture voiture4 = {'D', 0, 0};
voiture voiture5 = {'E', 0, 0};
voiture voiture6 = {'F', 0, 0};
voiture voiture7 = {'G', 0, 0};

// selection de la date
date saisie(void) {
  date t;
  int jours_par_mois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  do {
    printf("jours?\n");
    scanf("%i", &t.jours);
    printf("quel mois ? (0 janvier,1 fevrier,2 mars,3 avril,4 mai,5 juin,6 "
           "juillet,7 aout,8 septembre,9 octobre,10 novembre 11 decembre)\n");
    scanf("%d", &t.mois_selectionne);
  } while (t.mois_selectionne < 0 || t.mois_selectionne > 11);
  // ajustement du nombre de jours en fonction du mois
  if (t.jours < 1 || t.jours > jours_par_mois[t.mois_selectionne]) {
    printf("Le mois saisi ne possède pas autant de jours. Veuillez ressaisir "
           "la date.\n");
    return saisie(); // appel récursif de la fonction pour redemander une saisie
                     // valide
  }

  return t;
}
//pour calculer les dates et les comparer
int jours_ecoules(date t) {
    int jours_par_mois[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int temps_ecoule = t.jours;
    for (int i = 0; i < t.mois_selectionne; i++){
        temps_ecoule = temps_ecoule + jours_par_mois[i];
    }
    return temps_ecoule;
}
// pour l'affichage de la date
const char *mois_nom[] = {"janvier",   "fevrier", "mars",     "avril",
                          "mai",       "juin",    "juillet",  "aout",
                          "septembre", "octobre", "novembre", "decembre"};

void affichage(date t) {
  printf("La date entree est : %i %s\n", t.jours, mois_nom[t.mois_selectionne]);
}

// réservation d'une voiture
void reservation(voiture *v) {
  if (v->occupee == 0) {
    v->occupee = 1;
    v->date_reservation = saisie();
    printf("Voiture %c reservee avec succes jusqu'au %d %s.\n", v->type,
           v->date_reservation.jours,
           mois_nom[v->date_reservation.mois_selectionne]);
  } else {
    printf("La voiture %c est deja reservee jusqu'au %d %s.\n", v->type,
           v->date_reservation.jours,
           mois_nom[v->date_reservation.mois_selectionne]);
  }
}

// annulation d'une réservation
void annulation(voiture *v) {
  if (v != NULL && v->occupee == 1) {
    v->occupee = 0;
    v->date_reservation = defaut;
    printf("Reservation de la voiture %c annulee avec succes.\n", v->type);
  } else {
    printf("La voiture n'est pas reservee ou n'existe pas.\n");
  }
}

// affichage des voitures disponibles à une date donnée

//fonction d'un precedent tp qui compare les dates
int comparaison(date un, date t){
  int premier = jours_ecoules(un);
  int deuxieme = jours_ecoules(t);
  if (premier < deuxieme){
    return 1;
  }
  else{
    return 2;
  }
}

void disponibilite(date t) {
  printf("Voitures disponibles le %i %s :\n", t.jours, mois_nom[t.mois_selectionne]);
    if (comparaison(voiture1.date_reservation, t)==1) {
        printf("- Voiture MERCEDES\n");
    }
    if (comparaison(voiture2.date_reservation, t)==1) {
        printf("- Voiture LAMBORGHINI\n");
    }
    if (comparaison(voiture3.date_reservation, t)==1 ) {
        printf("- Voiture MITSUBISHI\n");
    }
    if (comparaison(voiture4.date_reservation, t)==1 ) {
        printf("- Voiture PEUGEOT\n");
    }
    if (comparaison(voiture5.date_reservation, t)==1 ) {
        printf("- Voiture JEEP\n");
    }
    if (comparaison(voiture6.date_reservation, t)==1 ) {
        printf("- Voiture ROLLS-ROYCE\n");
    }
    if (comparaison(voiture7.date_reservation, t)==1 ) {
        printf("- Voiture FERRARI\n");
    }
}
void menu() {
  int choix;
  char fini[5] = "fini";
  char reponse[10];

  do {
    printf("1: faire une reservation, 2: supprimer une reservation et 3: voir "
           "les voitures disponibles a une date donnee (ou tapez 'fini' pour "
           "quitter) : \n");
    scanf("%s", reponse);
    if (strcmp(reponse, fini) == 0) {
      printf("Programme terminé.\n");
      break;
    }

    choix = atoi(reponse);

    if (choix >= 1 && choix <= 3) {
      switch (choix) {
        // consommer les caractères restants dans le flux d'entrée
        while (getchar() != '\n')
          ;
      }
      switch (choix) {

      case 1:
        printf("Vous avez choisi l'option 1.\n");
        printf("Veuillez choisir une voiture (A:MERCEDES, B:LAMBORGHINI, C:MITSUBISHI, D:PEUGEOT, E:JEEP, F:ROLLS-ROYCE, G:FERRARI) : ");
        char voitureChoisie;
        scanf(" %c", &voitureChoisie);
        switch (voitureChoisie) {
        case 'A':
          reservation(&voiture1);
          break;
        case 'B':
          reservation(&voiture2);
          break;
        case 'C':
          reservation(&voiture3);
          break;
        case 'D':
          reservation(&voiture4);
          break;
        case 'E':
          reservation(&voiture5);
          break;
        case 'F':
          reservation(&voiture6);
          break;
        case 'G':
          reservation(&voiture7);
          break;
        default:
          printf("Erreur : Veuillez entrer une voiture valide (A:MERCEDES, B:LAMBORGHINI, C:MITSUBISHI, D:PEUGEOT, E:JEEP, F:ROLLS-ROYCE, G:FERRARI).\n");
          break;
        }
        break;

      case 2:
        printf("Vous avez choisi l'option 2.\n");
        printf("Veuillez choisir une voiture (A:MERCEDES, B:LAMBORGHINI, C:MITSUBISHI, D:PEUGEOT, E:JEEP, F:ROLLS-ROYCE, G:FERRARI) : ");
        char voitureLiberee;
        scanf(" %c", &voitureLiberee);
        switch (voitureLiberee) {
        case 'A':
          annulation(&voiture1);
          break;
        case 'B':
          annulation(&voiture2);
          break;
        case 'C':
          annulation(&voiture3);
          break;
        case 'D':
          annulation(&voiture4);
          break;
        case 'E':
          annulation(&voiture5);
          break;
        case 'F':
          annulation(&voiture6);
          break;
        case 'G':
          annulation(&voiture7);
          break;
        }
        break;
      case 3:
        printf("Vous avez choisi l'option 3.\n");
        date t = saisie();
        affichage(t);
        disponibilite(t);
      }
    }
  } while (strcmp(reponse, fini) != 0);
}

int main() {
  menu();
  return 0;
}
