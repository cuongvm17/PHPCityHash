### Google's CityHash extension for PHP.
- Source: https://github.com/google/cityhash

### Installation
#### Install Google's CityHash
```
RUN apt-get update \
    && apt-get install -y --no-install-recommends git \
    && cd /tmp \
    && git clone https://github.com/google/cityhash.git \
    && cd cityhash \
    && ./configure \
    && make all check CXXFLAGS="-g -O3" \
    && make install
```

#### install PHP extension
````
RUN apt-get update \
    && apt-get install -y --no-install-recommends git \
    && cd /tmp \
    && git clone https://github.com/cuongvm17/PHPCityHash.git \
    && cd PHPCityHash \
    && phpize \
    && ./configure --with-cityhash \
    && make \
    && make install
    
RUN rm -rf /tmp/cityhash \
    && rm -rf /tmp/PHPCityHash \
    && apt-get purge \
        -y --auto-remove \
        -o APT::AutoRemove::RecommendsImportant=false
````


##### Full file
```
RUN apt-get update \
    && apt-get install -y --no-install-recommends git \
    && cd /tmp \
    && git clone https://github.com/google/cityhash.git \
    && cd cityhash \
    && ./configure \
    && make all check CXXFLAGS="-g -O3" \
    && make install \
    && cd /tmp \
    && git clone https://github.com/cuongvm17/PHPCityHash.git \
    && cd PHPCityHash \
    && phpize \
    && ./configure --with-cityhash \
    && make \
    && make install \
    && rm -rf /tmp/cityhash \
    && rm -rf /tmp/PHPCityHash \
    && apt-get purge \
        -y --auto-remove \
        -o APT::AutoRemove::RecommendsImportant=false
```

#### Add PHP cityhash extention
``` 
extension=cityhash.so
```

#### Usage
````
  CityHash64('hash');
````
