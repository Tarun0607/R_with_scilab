#include <stdlib.h>
#include <stdio.h>
 
#include <Rembedded.h>
#include <Rinternals.h>
#include <R_ext/Parse.h>



int kruskal_wallis(const char* str)
{
  int error;
  SEXP code, expr = R_NilValue;
  ParseStatus status;
 
  PROTECT(code = Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(code, 0, Rf_mkChar(str));
 
  expr = PROTECT(R_ParseVector(code, -1, &status, R_NilValue));
 
  switch (status) {
  case PARSE_OK:
    break;
  case PARSE_INCOMPLETE:
    fprintf(stderr, "Expression incomplete! Missing brackets?\n");
    UNPROTECT(2);
    return -1;
  case PARSE_ERROR:
    fprintf(stderr, "Syntax error!\n");
    UNPROTECT(2);
    return -1;
  default:
    UNPROTECT(2);
    return -1;
  }
   
  int i;
  for (i=0; i<LENGTH(expr); i++) {
    R_tryEval(VECTOR_ELT(expr, i), R_GlobalEnv, &error);
  }
 
  UNPROTECT(2);
 
  return error;
}

