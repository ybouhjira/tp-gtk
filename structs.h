#ifndef STRUCTS_H
#define STRUCTS_H

#include <gtk/gtk.h>

typedef gboolean boolean;

/* Fenetre */
typedef struct Fenetre
{
  char titre[100];
  boolean resizable; // Redimonsionable
  char icon[100]; // Chemin de l'icon
  struct Fenetre *parent;

  GtkWidget *_private; // variable privée ne pas modifier
} Fenetre;

/* Fond d'une fenetre */
typedef struct
{
  enum TypeFond{Image, Couleur} type;
  char valeur[100]; // code de la couleur ou chemin de l'image
} Fond;

/* Dimensions*/
typedef struct
{
  int largeur, longueur;
} Dimensions;

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

#endif // STRUCTS_H
