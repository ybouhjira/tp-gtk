#include "functions.h"
#include "structs.h"

int main(int argc, char **argv)
{
  initialiser(&argc, &argv);

  Fenetre fenetre = {"Ma fenetre", FALSE};
  fenetre_creer(fenetre);

  boucle_principale();
  return 0;
}

