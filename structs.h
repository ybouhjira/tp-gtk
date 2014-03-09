#ifndef STRUCTS_H
#define STRUCTS_H

#include <gtk/gtk.h>

typedef gboolean boolean;

/* Dimensions*/
typedef struct
{
  int l; // longueur
  int L; // largeur
} Dimensions;

/* Fenetre */
typedef struct Fenetre
{
  char titre[100];
  boolean resizable;              // Redimonsionable

  boolean estPrincipale;          // Indique si la fenetre arrete le
                                  // le programme lorsque elle est fermée

  char icon[100];                 // Chemin de l'icone

  struct Fenetre *parent;         // fenetre mere

  Dimensions dimensions;          // longeur et largeur

  GtkWidget *_private;            // variable privée ne pas modifier
} Fenetre;

Fenetre struct_fenetre_init()
{
  Fenetre fen = {
    "", // titre
    TRUE, // resizable,
    TRUE, // true
    "", // icon
    NULL, // parent
    {200, 300}, // dimension
    NULL // _private
  };
  return fen;
}

/* Fond d'une fenetre */
typedef struct
{
  enum TypeFond{Image, Couleur} type;
  char valeur[100]; // code de la couleur ou chemin de l'image
} Fond;

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
