#include "php_cityhash.h"
#include "city.h"
#include <stdio.h>

PHP_FUNCTION(CityHash64)
{
  char *str;
  int len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", 
                   &str, &len) == FAILURE) 
  {
    RETURN_NULL();
  }

  uint64 hash = CityHash64(str, len);
  char *hash_str = (char *) malloc(21);
  sprintf(hash_str, "%llu", hash);
  RETVAL_STRING(hash_str);
}

PHP_FUNCTION(CityHash128)
{
  char *str;
  int len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", 
                   &str, &len) == FAILURE) 
  {
    RETURN_NULL();
  }

  uint128 hash = CityHash128(str, len);
  char *hash_str = (char *) malloc(43);
  sprintf(hash_str, "%llu%llu", hash.first, hash.second);
  RETVAL_STRING(hash_str);
}

static zend_function_entry php_cityhash_functions[] = {
  PHP_FE(CityHash64, NULL)
  PHP_FE(CityHash128, NULL) 
  { NULL, NULL, NULL }
};

zend_module_entry cityhash_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif

     PHP_CITYHASH_EXTNAME,
     php_cityhash_functions, /* Functions */
     NULL, /* MINIT */
     NULL, /* MSHUTDOWN */
     NULL, /* RINIT */
     NULL, /* RSHUTDOWN */
     NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
     PHP_CITYHASH_EXTVER,
#endif
     STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CITYHASH
ZEND_GET_MODULE(cityhash)
#endif
