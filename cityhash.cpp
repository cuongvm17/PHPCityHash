// include the PHP API itself
#include <php.h>
// then include the header of your extension
#include "cityhash.h"
#include "city.h"
#include <string>

// register our function to the PHP API
// so that PHP knows, which functions are in this module
zend_function_entry CityHash_functions[] = {
    PHP_FE(CityHash64, NULL)
    PHP_FE(CityHash128, NULL)
    {NULL, NULL, NULL}
};

// some pieces of information about our module
zend_module_entry CityHash_module_entry = {
    STANDARD_MODULE_HEADER,
    CITYHASH_PHP_EXTNAME,
    CityHash_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    CITYHASH_PHP_VERSION,
    STANDARD_MODULE_PROPERTIES
};

// use a macro to output additional C code, to make ext dynamically loadable
ZEND_GET_MODULE(CityHash)

// Finally, we implement our "city hash" function
// this function will be made available to PHP
// and prints to PHP stdout using printf
PHP_FUNCTION(CityHash64) {
   char* input;
   size_t input_len;

   if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &input, &input_len) == FAILURE) {
       RETURN_NULL();
   }

   uint64 hash = CityHash64(input, input_len);
   std::string hash_str = std::to_string(hash);
   RETVAL_STRING(hash_str.c_str());
}

PHP_FUNCTION(CityHash128) {
   char* input;
   size_t input_len;

   if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &input, &input_len) == FAILURE) {
       RETURN_NULL();
   }

   uint128 hash = CityHash128(input, input_len);
   std::string hash_str = std::to_string(hash.first) + std::to_string(hash.second);
   RETVAL_STRING(hash_str.c_str());
}

