#!/bin/bash

PHP_VERSION=${PHP_VERSION:-8.2}

docker run -it --rm -v "$PWD":/usr/src/app -w /usr/src/app php:${PHP_VERSION}-cli bash -c "\
    apt-get update && \
    apt-get install -y \
        git \
        build-essential \
        autoconf && \
    phpize && \
    ./configure && \

    # Clean previous build and build
    make clean && make && \

    # Copy and enable extension
    cp ./.libs/daruma_framework.so \$(php-config --extension-dir) && \
        docker-php-ext-enable daruma_framework &&  \

    # Fix file permissions
    chown -R 1000:1000 . && \

    # run extension test
    php daruma_framework.php && make test < /dev/null
" | sed "s|/usr/src/app/||g"
