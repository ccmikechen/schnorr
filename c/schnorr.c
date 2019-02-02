#include <string.h>
#include <stdlib.h>

#include "bigint.h"
#include "schnorr.h"
#include "os_types.h"
#include "sha1.h"


int schnorr_verify(char* msg, char* key_c, char* p_c, char* r_c, char* e_c) {
  bigint_init();
  // require
  bigint key, p, r, e;

  // calculate
  bigint h, tmp, result;
  
  // key
  bigint_newf(&key, key_c);
  bigint_newf(&p, p_c);

  // signature
  bigint_newf(&r, r_c);
  bigint_newf(&e, e_c);
  
  // hash
  char* sr = bigint_strc(&r);
  uint8_t digest[20];
  
  SHA1_CTX context;
  SHA1_Init(&context);
  SHA1_Update(&context, (uint8_t *) msg, strlen(msg));
  SHA1_Update(&context, (uint8_t *) sr, strlen(sr));
  SHA1_Final(&context, digest);

  bigint_newb(&h, digest, 20);
  //  printf("hash = %s\n", bigint_strc(&h));

  // verify
  bigint_modpow(&tmp, &key, &h, &p);
  bigint_mul(&tmp, &tmp, &r);
  bigint_mod(&result, &tmp, &p);
  //  printf("result = %s\n", bigint_strc(&result));

  return bigint_equal(&e, &result);
}
