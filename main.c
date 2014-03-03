#include <gtk/gtk.h>

/* Type boolean*/
typedef enum {FAUX, VRAI} boolean;

/* Fond d'une fenetre */
typedef struct
{
  enum TypeFond{Image, Couleur} type;
  char valeur[100];
} Fond;

/* Dimensions*/
typedef struct
{
  int largeur, longueur;
} Dimensions;

/* Fenetre */
typedef struct
{
  struct Fenetre *parent;
  char titre[100];
  char icon[100]; // Chemin de l'icon
  boolean resizable; // Redimonsionable

  GtkWidget *__private; // variable privée ne pas modifier
} Fenetre;

/* Image */
typedef struct
{
  char chemin[100];
  Dimensions dimensions;
} Photo;

/* Texte */
typedef struct
{
  int taille;
  char police[100];
  char couleur[10]; // hex : #AABB23, ou nom : red, blue, ...
} Texte;



/* Bouton */
typedef struct
{
  enum TypeButton{Img, Text} type;
  void (*callback_click)(void);
} Button;


typedef struct
{
  enum TypeConteneur{Horizontal, Vertical}  type;
  int espacement; // espace entre les widgets
} Conteneur;

void fenetre_creer(Fenetre *fenetre)
{
  GtkWindow *win = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
  gtk_window_set_title(win, fenetre->titre);
  gtk_window_set_icon_from_file(win, fenetre->icon, NULL);

}

int main(void)
{

  return 0;
}

