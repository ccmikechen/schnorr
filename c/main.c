#include <stdio.h>
#include "schnorr.h"

int main() {

  char* key = "258991358871459";

  char* msg = "Hello Man";
  
  char* p = "1809223843192979";
  char* r = "586882903039785";
  char* e = "258991358871459";
  
  int result = schnorr_verify(msg, key, p, r, e);
  
  if (result) {
    printf("successed\n");
  } else {
    printf("failed\n");
  }
  
  return 0;
  
}
