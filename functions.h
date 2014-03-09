#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"
#include <string.h>

//// FONCTIONS PRINCIPALE /////////////////////////////////////////////////
void initialiser(int *argc, char ***argv)
{
  gtk_init(argc, argv);
}

void boucle_principale()
{
  gtk_main();
}

//// FENETRE //////////////////////////////////////////////////////////////
/**
 * Initialise la structure fenetre
 */
Fenetre struct_fenetre_init()
{
   return (Fenetre) {
      "",         // titre
      TRUE,       // resizable,
      TRUE,       // true
      "",         // icon
      NULL,       // parent
      {200, 300}, // dimension
      NULL,       // _private
      NULL,       // _layout
    };
}

void fenetre_creer(Fenetre *fen)
{
  // Creer la fenetre gtk
  fen->_widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Changer les propriétés de la fenêtre
  GtkWindow *win = GTK_WINDOW(fen->_widget);
  //// Titre
  gtk_window_set_title(win, fen->titre);

  //// Icon
  if(strlen(fen->icon) > 0)
    gtk_window_set_icon_from_file(win, fen->icon, NULL);

  //// Dimensions
  gtk_window_set_default_size(win, fen->dimensions.l, fen->dimensions.L );

  //// Redimonsionable
  gtk_window_set_resizable(win, fen->resizable);

  //// Fenetre mere
  if(fen->parent)
    gtk_widget_set_parent(fen->_widget, fen->parent->_widget);

  //// Fermer le programme lors de la femeture
  if(fen->estPrincipale)
  gtk_signal_connect(GTK_OBJECT(fen->_widget), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

  ////  Layout
  if(fen->_layout)
    gtk_container_add(GTK_CONTAINER(fen->_widget), fen->_layout);
}

void fenetre_afficher(Fenetre fenetre)
{
  gtk_widget_show_all(fenetre._widget);
}

void maquer_fenetre(Fenetre fenetre)
{
  gtk_widget_hide_all(fenetre._widget);
}

//// CONTENEUR ////////////////////////////////////////////////////////////
Conteneur struct_conteneur_init()
{
  return (Conteneur) {
      Vertical,  // type
      5,         // espacement
      NULL
    };
}

void conteneur_creer(Conteneur *conteneur)
{
  switch (conteneur->type)
    {
    case Horizontal:
      conteneur->_widget = gtk_hbox_new(TRUE, conteneur->espacement);
      break;
    default:
      conteneur->_widget = gtk_vbox_new(TRUE, conteneur->espacement);
    }
}

void conteneur_ajouter_conteneur(Conteneur c1, Conteneur c2)
{
  gtk_container_add(GTK_CONTAINER(c1._widget), c2._widget);
}

#endif // FUNCTIONS_H
