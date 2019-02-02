#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bigint.h"

void test_bigint_add() {
  bigint a, b, ans;

  printf("test_bigint_add():\n");
  
  bigint_newf(&a, "111");
  bigint_newf(&b, "222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("333")));

  bigint_newf(&a, "-111");
  bigint_newf(&b, "-222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-333")));

  bigint_newf(&a, "111");
  bigint_newf(&b, "-222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-111")));

  bigint_newf(&a, "-111");
  bigint_newf(&b, "222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("111")));

  bigint_newf(&a, "11111111111111111111111111111111111111111111");
  bigint_newf(&b, "22222222222222222222222222222222222222222222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("33333333333333333333333333333333333333333333")));
                                         
  bigint_newf(&a, "-11111111111111111111111111111111111111111111");
  bigint_newf(&b, "-22222222222222222222222222222222222222222222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-33333333333333333333333333333333333333333333")));

  bigint_newf(&a, "11111111111111111111111111111111111111111111");
  bigint_newf(&b, "-22222222222222222222222222222222222222222222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-11111111111111111111111111111111111111111111")));

  bigint_newf(&a, "-11111111111111111111111111111111111111111111");
  bigint_newf(&b, "22222222222222222222222222222222222222222222");
  bigint_add(&ans, &a, &b);
  printf("%s + %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("11111111111111111111111111111111111111111111")));
}

void test_bigint_sub() {
  bigint a, b, ans;

  printf("test_bigint_sub():\n");
  
  bigint_newf(&a, "111");
  bigint_newf(&b, "222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-111")));

  bigint_newf(&a, "-111");
  bigint_newf(&b, "-222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("111")));

  bigint_newf(&a, "111");
  bigint_newf(&b, "-222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("333")));

  bigint_newf(&a, "-111");
  bigint_newf(&b, "222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-333")));

  bigint_newf(&a, "11111111111111111111111111111111111111111111");
  bigint_newf(&b, "22222222222222222222222222222222222222222222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-11111111111111111111111111111111111111111111")));
                                         
  bigint_newf(&a, "-11111111111111111111111111111111111111111111");
  bigint_newf(&b, "-22222222222222222222222222222222222222222222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("11111111111111111111111111111111111111111111")));

  bigint_newf(&a, "11111111111111111111111111111111111111111111");
  bigint_newf(&b, "-22222222222222222222222222222222222222222222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("33333333333333333333333333333333333333333333")));

  bigint_newf(&a, "-11111111111111111111111111111111111111111111");
  bigint_newf(&b, "22222222222222222222222222222222222222222222");
  bigint_sub(&ans, &a, &b);
  printf("%s - %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-33333333333333333333333333333333333333333333")));
}

void test_bigint_mul() {
  printf("test_bigint_mul():\n");
  bigint a, b, ans;

  bigint_newf(&a, "2");
  bigint_newf(&b, "3");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("6")));
  
  bigint_newf(&a, "-2");
  bigint_newf(&b, "3");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-6")));
  
  bigint_newf(&a, "2");
  bigint_newf(&b, "-3");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-6")));
  
  bigint_newf(&a, "-2");
  bigint_newf(&b, "-3");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("6")));
  
  bigint_newf(&a, "0");
  bigint_newf(&b, "3");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));
  
  bigint_newf(&a, "2");
  bigint_newf(&b, "0");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));
  
  bigint_newf(&a, "20");
  bigint_newf(&b, "123");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("2460")));
  
  bigint_newf(&a, "-123");
  bigint_newf(&b, "20");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-2460")));
  
  bigint_newf(&a, "123456789");
  bigint_newf(&b, "9876543210987654321");
  bigint_mul(&ans, &a, &b);
  printf("%s * %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1219326311248285321112635269")));
}

void test_bigint_div() {
  printf("test_bigint_div():\n");
  bigint a, b, ans;

  bigint_newf(&a, "0");
  bigint_newf(&b, "3");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));
  
  bigint_newf(&a, "2");
  bigint_newf(&b, "3");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));

  bigint_newf(&a, "3");
  bigint_newf(&b, "2");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1")));

  bigint_newf(&a, "-2");
  bigint_newf(&b, "3");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));
  
  bigint_newf(&a, "-3");
  bigint_newf(&b, "2");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-1")));

  bigint_newf(&a, "2");
  bigint_newf(&b, "-3");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));
  
  bigint_newf(&a, "3");
  bigint_newf(&b, "-2");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-1")));

  bigint_newf(&a, "123456789");
  bigint_newf(&b, "9876");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("12500")));

  bigint_newf(&a, "-12345678909876543211234567890987654321");
  bigint_newf(&b, "9876543211234567890");
  bigint_div(&ans, &a, &b);
  printf("%s / %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-1249999989453125003")));
}

void test_bigint_mod() {
  printf("test_bigint_mod():\n");
  bigint a, b, ans;

  bigint_newf(&a, "0");
  bigint_newf(&b, "3");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));
  
  bigint_newf(&a, "2");
  bigint_newf(&b, "3");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("2")));

  bigint_newf(&a, "3");
  bigint_newf(&b, "2");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1")));

  bigint_newf(&a, "-2");
  bigint_newf(&b, "3");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-2")));
  
  bigint_newf(&a, "-3");
  bigint_newf(&b, "2");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-1")));

  bigint_newf(&a, "2");
  bigint_newf(&b, "-3");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("2")));
  
  bigint_newf(&a, "3");
  bigint_newf(&b, "-2");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1")));

  bigint_newf(&a, "123456789");
  bigint_newf(&b, "9876");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("6789")));

  bigint_newf(&a, "-12345678909876543211234567890987654321");
  bigint_newf(&b, "9876543211234567890");
  bigint_mod(&ans, &a, &b);
  printf("%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&b), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-94521472127700651")));
}

void test_bigint_pow() {
  printf("test_bigint_pow():\n");
  bigint a, ans;
  int e;
  
  bigint_newf(&a, "0");
  e = 3;
  bigint_pow(&ans, &a, e);
  printf("%s^%d = %s\n", bigint_strc(&a), e, bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));

  bigint_newf(&a, "3");
  e = 0;
  bigint_pow(&ans, &a, e);
  printf("%s^%d = %s\n", bigint_strc(&a), e, bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1")));

  bigint_newf(&a, "2");
  e = 3;
  bigint_pow(&ans, &a, e);
  printf("%s^%d = %s\n", bigint_strc(&a), e, bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("8")));

  bigint_newf(&a, "-2");
  e = 3;
  bigint_pow(&ans, &a, e);
  printf("%s^%d = %s\n", bigint_strc(&a), e, bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-8")));

  bigint_newf(&a, "2");
  e = 100;
  bigint_pow(&ans, &a, e);
  printf("%s^%d = %s\n", bigint_strc(&a), e, bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1267650600228229401496703205376")));
  
  bigint_newf(&a, "-2");
  e = 999;
  bigint_pow(&ans, &a, e);
  printf("%s^%d = %s\n", bigint_strc(&a), e, bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("-5357543035931336604742125245300009052807024058527668037218751941851755255624680612465991894078479290637973364587765734125935726428461570217992288787349287401967283887412115492710537302531185570938977091076523237491790970633699383779582771973038531457285598238843271083830214915826312193418602834034688")));
  
}

void test_bigint_modpow() {
  printf("test_bigint_modpow():\n");
  bigint a, e, m, ans;
  
  bigint_newf(&a, "0");
  bigint_newf(&e, "100");
  bigint_newf(&m, "10");
  bigint_modpow(&ans, &a, &e, &m);
  printf("%s^%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&e), bigint_strc(&m),
	 bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("0")));

  bigint_newf(&a, "1");
  bigint_newf(&e, "100");
  bigint_newf(&m, "10");
  bigint_modpow(&ans, &a, &e, &m);
  printf("%s^%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&e), bigint_strc(&m),
	 bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("1")));

  
  bigint_newf(&a, "2");
  bigint_newf(&e, "100000000000000000000000000000");
  bigint_newf(&m, "30000000000000000000000000000000000000000000000");
  bigint_modpow(&ans, &a, &e, &m);
  printf("%s^%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&e), bigint_strc(&m), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("17150757490199091893380022607743740081787109376")));

  bigint_newf(&a, "17");
  bigint_newf(&e, "99999999999999999999999999999999999999999999999");
  bigint_newf(&m, "123456789");
  bigint_modpow(&ans, &a, &e, &m);
  printf("%s^%s mod %s = %s\n", bigint_strc(&a), bigint_strc(&e), bigint_strc(&m), bigint_strc(&ans));
  assert(bigint_equal(&ans, bigint_newc("57163418")));
}

int main() {
  bigint_init();
  
  test_bigint_add();
  test_bigint_sub();
  test_bigint_mul();
  test_bigint_div();
  test_bigint_mod();
  test_bigint_pow();
  test_bigint_modpow();
  
  return 0;
}
