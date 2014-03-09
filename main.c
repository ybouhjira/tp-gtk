#include "functions.h"
#include "structs.h"
#include <string.h>

int main(int argc, char **argv)
{
  initialiser(&argc, &argv);

  Fenetre fen = struct_fenetre_init();
  strcpy(fen.titre, "Ma fenetre");
  fenetre_creer(&fen);

  fenetre_afficher(fen);

  boucle_principale();
  return 0;
}

