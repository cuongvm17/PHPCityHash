PHP_ARG_ENABLE(cityhash, Whether to enable the CityHashPHP extension, [ --enable-cityhash Enable CityHashPHP])

if test "$PHP_CITYHASH" != "no"; then
    source_file="cityhash/src/city.cc \
    cityhash.cpp"

    PHP_REQUIRE_CXX()
    PHP_ADD_INCLUDE(./cityhash/)

    PHP_SUBST(CITYHASH_SHARED_LIBADD)
    PHP_NEW_EXTENSION(cityhash, $source_file, $ext_shared)
fi