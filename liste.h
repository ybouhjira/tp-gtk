#ifndef LISTE_H
#define LISTE_H

#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Liste
{
  struct Liste *suiv;
  char val[100];
} Liste;

Liste* liste_creer()
{
  Liste *liste = calloc(1, sizeof(Liste));
  return liste;
}

void liste_ajout_fin(Liste **liste, char *val)
{
  assert(val);

  Liste *nouv = calloc(1, sizeof(Liste));
  strcpy(nouv->val, val);
  if(!(*liste))
      *liste = nouv;
  else
    {
      Liste *courant;
      for(courant = *liste; courant->suiv; courant = courant->suiv);
      courant->suiv = nouv;
    }
}

#endif // LISTE_H
