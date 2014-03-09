#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"
#include <string.h>

void fenetre_creer(Fenetre *fen)
{
  // Creer la fenetre gtk
  fen->_private = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Changer les propriétés de la fenêtre
  GtkWindow *win = GTK_WINDOW(fen->_private);
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
    gtk_widget_set_parent(fen->_private, fen->parent->_private);
}

void fenetre_afficher(Fenetre fenetre)
{
  gtk_widget_show_all(fenetre._private);
}

void maquer_fenetre(Fenetre fenetre)
{
  gtk_widget_hide_all(fenetre._private);
}

void initialiser(int *argc, char ***argv)
{
  gtk_init(argc, argv);
}

void boucle_principale()
{
  gtk_main();
}

#endif // FUNCTIONS_H
