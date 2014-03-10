#ifndef STRUCTS_H
#define STRUCTS_H

#include <gtk/gtk.h>

#include "liste.h"

typedef gboolean boolean;

/** Conteneur **/
typedef struct
{
  enum TypeConteneur{Horizontal, Vertical}  type;
  int espacement; // espace entre les widgets

  // privés
  GtkWidget *_widget;
} Conteneur;

/** Dimensions **/
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

  Conteneur *conteneur;           // Conteneur

  int padding;

  //! Membre privés
  GtkWidget *_widget;            // variable privée ne pas modifier
} Fenetre;

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
  void (*callback)(void); // Le callback appelée lorsque le bouton
                          // est cliqué

  char text[100]; // texte
  char image[100];  // image

  // privé
  GtkWidget *_widget;
} Bouton;


//// MENU /////////////////////////////////////////////////////////////////

typedef struct
{
  Liste *elements;

  // privé
  GtkWidget *_widget;
} Menu;


//// CHECKBUTTON /////////////////////////////////////////////////////////////////

typedef struct
{
  char text[100]; // texte

  GtkWidget *_widget;
} CheckBox;

#endif // STRUCTS_H
