#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigint.h"

#define CHAR_ZERO 48
#define MAX(X, Y) (X > Y ? X : Y)

static bigint* ZERO;
static bigint* ONE;
static bigint* TWO;

void bigint_init() {
  ZERO = bigint_newc("0");
  ONE = bigint_newc("1");
  TWO = bigint_newc("2");
}

static int bigint_is_zero(bigint* a) {
  int i;
  for (i = 0; i < a->length; i++) {
    if (a->number[i] > 0) {
      return 0;
    }
  }
  return 1;
}

static void bigint_mul10n(bigint* dst, bigint* a, int n) {
  if (bigint_is_zero(a)) {
    bigint_copy(dst, a);
    return;
  }

  bigint* out = (bigint*)malloc(sizeof(bigint));
  int len = a->length + n; 
  out->length = len;
  out->sign = a->sign;
  out->number = (digit*)malloc(len);

  int i;
  for (i = 0; i < a->length; i++) {
    out->number[i] = a->number[i];
  }
  for (; i < len; i++) {
    out->number[i] = 0;
  }
  bigint_copy(dst, out);
}

void bigint_new(bigint* dst) {
  dst->number = (digit*)malloc(1);
  dst->number[0] = 0;
  dst->length = 1;
  dst->sign = 1;
}

void bigint_newf(bigint* dst, char* num) {
  int len = strlen(num);
  int p = 0;
  dst->sign = 1;
  if (num[0] == '-') {
    dst->sign = -1;
    len--;
    p++;
  }

  int i;
  for (i = 0; i < len; i++) {
    if (num[i + p] > CHAR_ZERO) {
      break;
    }
  }
  if (i == len) {
    dst->number = (digit*)malloc(1);
    dst->number[0] = 0;
    dst->length = 1;
    return;
  }

  dst->length = len - i;
  dst->number = (digit*)malloc(len - i);
  
  int j;
  for (j = 0; i < len; i++, j++) {
    dst->number[j] = num[i + p] - CHAR_ZERO;
  }
}

bigint* bigint_newc(char* num) {
  bigint* out = (bigint*)malloc(sizeof(bigint));
  bigint_newf(out, num);
  return out;
}

void bigint_copy(bigint* to, bigint* from) {
  if (bigint_is_zero(from)) {
    bigint_newf(to, "0");
    return;
  }
  to->sign = from->sign;
  to->length = from->length;
  to->number = (digit*)malloc(from->length);
  int i = 0;
  while (i < from->length) {
    to->number[i] = from->number[i];
    i++;
  }
  
  while (to->number[0] == 0) {
    to->number++;
    to->length--;
  }
}

void bigint_delete(bigint* a) {
  //  free(a->number);
  free(a);
}

void bigint_add(bigint* dst, bigint* a, bigint* b) {
  if (a->sign > b->sign) {
    bigint tmp;
    bigint_neg(&tmp, b);
    bigint_sub(dst, a, &tmp);
    return;
  }
  if (a->sign < b->sign) {
    bigint tmp;
    bigint_neg(&tmp, a);
    bigint_sub(dst, b, &tmp);
    return;
  }
  bigint* out = (bigint*)malloc(sizeof(bigint));
  int len = MAX(a->length, b->length) + 1;
  
  out->length = len;
  out->sign = a->sign;
  out->number = (digit*)malloc(len);
  
  int i;
  char t = 0;
  for (i = 1; i <= len; i++) {
    t /= 10;
    if (i <= a->length) {
      t += a->number[a->length - i];
    }
    if (i <= b->length) {
      t += b->number[b->length - i];
    }
    out->number[len - i] = t % 10;
  }
  if (out->length > 1 && out->number[0] == 0) {
    out->number++;
    out->length--;
  }
  bigint_copy(dst, out);
}

void bigint_sub(bigint* dst, bigint* a, bigint* b) {
  if (a->sign > b->sign) {
    bigint tmp;
    bigint_neg(&tmp, b);
    bigint_add(dst, a, &tmp);
    return;
  }
  if (a->sign < b->sign) {
    bigint tmp;
    bigint_neg(&tmp, b);
    bigint_add(dst, a, &tmp);
    return;
  }
  if ((bigint_compare(a, b) * a->sign) == -1) {
    bigint_sub(dst, b, a);
    dst->sign = a->sign * -1;
    return;
  }
  bigint* out = (bigint*)malloc(sizeof(bigint));
  int len = a->length;
  out->length = len;
  out->sign = a->sign;
  out->number = (digit*)malloc(len);

  int i;  
  char t = 0;
  for (i = 1; i <= len; i++) {
    t = t < 0 ? -1 : 0;
    if (i <= a->length) {
      t += a->number[a->length - i];
    }
    if (i <= b->length) {
      t -= b->number[b->length - i];
    }
    out->number[len - i] = (t + 10) % 10;
  }
  bigint_copy(dst, out);
}


void bigint_mul(bigint* dst, bigint* a, bigint* b) {
  if (a->length < b->length) {
    bigint_mul(dst, b, a);
    return;
  }

  bigint* out = bigint_newc("0");

  bigint tmp;
  int i;
  for (i = 0; i < b->length; i++) {
    int n = b->number[b->length - i - 1];

    bigint_newf(&tmp, "0");
    while (n > 0) {
      bigint_add(&tmp, &tmp, a);
      n--;
    }

    bigint_mul10n(&tmp, &tmp, i);
    bigint_add(out, out, &tmp);
  }
  out->sign = a->sign * b->sign;
  bigint_copy(dst, out);
}



static void bigint_div_and_mod(bigint* a, bigint* b, bigint* ans, bigint* mod) {
  if (bigint_is_zero(b)) {
    fprintf(stderr, "bigint error: Divide by zero\n");
    exit(1);
  }
  bigint c;
  bigint_abs(&c, b);
  bigint* ans_tmp = (bigint*)malloc(sizeof(bigint));
  bigint tmp;
  bigint_newf(&tmp, "0");

  ans_tmp->number = (digit*)malloc(a->length);
  ans_tmp->length = a->length;

  int i;
  char j;
  for (i = 0; i < a->length; i++) {
    bigint_mul10n(&tmp, &tmp, 1);
    tmp.number[tmp.length - 1] = a->number[i];
    j = 0;
    while (bigint_compare(&tmp, &c) >= 0) {
      bigint_sub(&tmp, &tmp, &c);
      j++;
    }
    ans_tmp->number[i] = j;
  }
  
  ans_tmp->sign = a->sign * b->sign;
  tmp.sign = a->sign;

  bigint_copy(ans, ans_tmp);
  bigint_copy(mod, &tmp);
}

void bigint_div(bigint* dst, bigint* a, bigint* b) {
  bigint tmp;
  bigint_div_and_mod(a, b, dst, &tmp);
}

void bigint_mod(bigint* dst, bigint* a, bigint* b) {
  bigint tmp;
  bigint_div_and_mod(a, b, &tmp, dst);
}

void bigint_pow(bigint* dst, bigint* a, int e) {
  bigint_newf(dst, "1");
  while (e-- > 0) {
    bigint_mul(dst, dst, a);
  }
}

void bigint_modpow(bigint* dst, bigint* a, bigint* e, bigint* m) {
  bigint r;
  bigint mod;
  bigint exp;
  bigint_copy(&exp, e);
  bigint n;
  bigint_copy(&n, a);

  // tmp
  bigint ta;
  bigint tb;
  bigint tm;
  bigint* out = bigint_newc("1");

  do {
    bigint_mod(&n, &n, m);
    bigint_div_and_mod(&exp, TWO, &exp, &mod);

    if (bigint_equal(&mod, ONE)) {
      bigint_mul(&tm, out, &n);
      bigint_mod(out, &tm, m);
    }

    bigint_mul(&n, &n, &n);
  } while (bigint_compare(&exp, ZERO) == 1);
  bigint_copy(dst, out);
}

void bigint_neg(bigint* dst, bigint* a) {
  bigint_copy(dst, a);
  dst->sign *= -1;
}


void bigint_abs(bigint* dst, bigint* a) {
  bigint_copy(dst, a);
  if (a->sign == -1) {
    dst->sign = 1;
  }
}

void bigint_str(bigint* a, char* s) {  
  char* out = (char*)malloc(a->length + 1);
  int i;
  for (i = 0; i < a->length; i++) {
    out[i] = a->number[i] + CHAR_ZERO;
  }
  out[i] = '\0';
  if (a->sign == -1 && !(a->length == 1 && a->number[0] == 0)) {
    strcpy(s, "-");
  }
  strcat(s, out);
}

char* bigint_strc(bigint* a) {
  int len = a->length;
  if (a->sign == -1) {
    len++;
  }
  char* s = (char*)malloc(len);
  bigint_str(a, s);
  return s;
}

int bigint_compare(bigint* a, bigint* b) {
  if (a->length == 1 && a->number[0] == 0 &&
      b->length == 1 && b->number[0] == 0) {
    return 0;
  }
  if (a->sign > b->sign) {
    return 1;
  }
  if (a->sign < b->sign) {
    return -1;
  }
  if (a->length > b->length) {
    return a->sign;
  }
  if (a->length < b->length) {
    return -a->sign;
  }
  int i;
  for (i = 0; i < a->length; i++) {
    if (a->number[i] > b->number[i]) {
      return a->sign;
    }
    if (a->number[i] < b->number[i]) {
      return -a->sign;
    }
  }
  return 0;
}

int bigint_equal(bigint* a, bigint* b) {
  return bigint_compare(a, b) == 0;
}
