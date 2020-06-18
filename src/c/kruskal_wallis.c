#include <stdlib.h>
#include <stdio.h>
#include "kruskal_wallis.h"
#include <Rembedded.h>
#include <Rinternals.h>
#include <R_ext/Parse.h>
 
 
 
 
 
int main()
{
  char *argv[] = {"exec_r", "--quiet"};
  int argc = 2;
   
  Rf_initEmbeddedR(argc, argv);
 
  kruskal_wallis("my_data <- PlantGrowth ; print(kruskal.test(weight ~ group ,data = my_data))");
   
  Rf_endEmbeddedR(0);
   
  return 0;
}
