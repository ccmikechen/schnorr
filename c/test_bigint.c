#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "bigint.h"

int main() {

  bigint* a;
  bigint* b;
  bigint* c;

  a = (bigint*)malloc(sizeof(bigint));
  bigint_new(a);
  b = (bigint*)malloc(sizeof(bigint));
  bigint_newf(b, "0");
  assert(bigint_compare(a, b) == 0);

  a = bigint_newc("0000000000000001");
  b = bigint_newc("1");
  printf("%s\n", bigint_strc(a));
  assert(bigint_compare(a, b) == 0);
  
  a = bigint_newc("111111111111111111111111111111111111111111111111");
  b = bigint_newc("222222222222222222222222222222222222222222222222");
  assert(bigint_compare(a, b) == -1);
  assert(bigint_compare(b, a) == 1);

  a = bigint_newc("-11111111111111111111111111111111111111111111111");
  b = bigint_newc("-22222222222222222222222222222222222222222222222");
  assert(bigint_compare(a, b) == 1);
  assert(bigint_compare(b, a) == -1);

  a = bigint_newc("123");
  b = bigint_newc("123");
  assert(bigint_equal(a, b));

  a = bigint_newc("-123");
  b = bigint_newc("-123");
  assert(bigint_equal(a, b));
  
  return 0;
}
