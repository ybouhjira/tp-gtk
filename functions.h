#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

void fenetre_creer(Fenetre fenetre)
{
  // Creer la fenetre gtk
  fenetre._private = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Changer les propriétés de la fenêtre
  GtkWindow *win = GTK_WINDOW(fenetre._private);
  gtk_window_set_title(win, fenetre.titre);
  gtk_window_set_icon_from_file(win, fenetre.icon, NULL);
  gtk_window_set_resizable(win, fenetre.resizable);
  gtk_widget_set_parent(fenetre._private, fenetre.parent->_private);
}

void afficher_fenetre(Fenetre *fenetre)
{
  gtk_widget_show_all(fenetre->_private);
}

void maquer_fenetre(Fenetre *fenetre)
{
  gtk_widget_hide_all(fenetre->_private);
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
