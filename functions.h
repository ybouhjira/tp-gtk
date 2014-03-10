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
      NULL,       // conteneur
      NULL,       // _private
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

  //// Layout
  if(fen->conteneur)
    gtk_container_add(GTK_CONTAINER(fen->_widget),
                      fen->conteneur->_widget);
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

void conteneur_ajouter_bouton(Conteneur conteneur, Bouton bouton)
{
  gtk_container_add(GTK_CONTAINER(conteneur._widget), bouton._wiget);
}

//// BOUTTON //////////////////////////////////////////////////////////////

Bouton struct_bouton_init()
{
  return (Bouton) {
      NULL,                 // callback
      "",                   // texte
      "",                   // image
      NULL                  // _widget
    };
}

void bouton_creer(Bouton *bouton)
{
  bouton->_wiget = gtk_button_new_with_label(bouton->text);
  gtk_button_set_image(GTK_BUTTON(bouton->_wiget),
                       gtk_image_new_from_file(bouton->image));

  if(bouton->callback)
    gtk_signal_connect(GTK_OBJECT(bouton->_wiget), "clicked",
                      G_CALLBACK(bouton->callback), NULL);
}

#endif // FUNCTIONS_H
