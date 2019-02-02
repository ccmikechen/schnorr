#include "os_types.h"

typedef unsigned char digit;

typedef struct {
  digit* number;
  int length;
  int sign;
} bigint;

void bigint_init();

void bigint_new(bigint* dst);

void bigint_newf(bigint* dst, char* num);

void bigint_newb(bigint* dst, uint8_t* b, int size);

bigint* bigint_newc(char* num);

void bigint_copy(bigint* to, bigint* from);

void bigint_delete(bigint* a);

void bigint_add(bigint* dst, bigint* a, bigint* b);

void bigint_sub(bigint* dst, bigint* a, bigint* b);

void bigint_mul(bigint* dst, bigint* a, bigint* b);

void bigint_div(bigint* dst, bigint* a, bigint* b);

void bigint_mod(bigint* dst, bigint* a, bigint* b);

void bigint_pow(bigint* dst, bigint* a, int e);

void bigint_modpow(bigint* dst, bigint* a, bigint* e, bigint* m);

void bigint_neg(bigint* dst, bigint* a);

void bigint_abs(bigint* dst, bigint* a);

void bigint_str(bigint* a, char* s);

char* bigint_strc(bigint* a);

int bigint_compare(bigint* a, bigint* b);

int bigint_equal(bigint* a, bigint* b);
