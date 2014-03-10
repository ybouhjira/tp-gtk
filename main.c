#include "functions.h"
#include "structs.h"
#include "liste.h"

#include <string.h>
#include <stdlib.h>

void quitter()
{
  gtk_main_quit();
}

int main(int argc, char **argv)
{
  initialiser(&argc, &argv);

  Fenetre fen = struct_fenetre_init();

  // conteneur
  Conteneur conteneur = struct_conteneur_init();
  conteneur_creer(&conteneur);
  fen.conteneur = &conteneur;

  // titre
  strcpy(fen.titre, "Ma fenetre");

  // creeer la fenetre
  fenetre_creer(&fen);

  // Ajout de bouton

  // bouton
  Bouton bouton = struct_bouton_init();
  strcpy(bouton.text, "Bouton 1");
  bouton_creer(&bouton);
  conteneur_ajouter_bouton(conteneur, bouton);

  Bouton bouton2 = struct_bouton_init();
  strcpy(bouton2.text, "bouton 2");
  bouton_creer(&bouton2);
  conteneur_ajouter_bouton(conteneur, bouton2);

  Bouton bouton3 = struct_bouton_init();
  strcpy(bouton3.text, "quitter");
  bouton3.callback = quitter;
  bouton_creer(&bouton3);
  conteneur_ajouter_bouton(conteneur, bouton3);


  // menu
  Menu menu = struct_menu_init();
  menu_creer(&menu);

  liste_ajout_fin(&menu.elements, "Element 1");
  liste_ajout_fin(&menu.elements, "Element 2");
  liste_ajout_fin(&menu.elements, "Element 3");
  liste_ajout_fin(&menu.elements, "Element 4");

  menu_creer(&menu);

  conteneur_ajouter_menu(conteneur, menu);

  // checkbox
  CheckBox caseACocher = struct_checkbox_init();
  strcpy(caseACocher.text, "Case a cocher");
  checkbox_creer(&caseACocher);
  conteneur_ajouter_checkbox(conteneur, caseACocher);
  // fin ----------
  fenetre_afficher(fen);
  boucle_principale();
  return 0;
}

