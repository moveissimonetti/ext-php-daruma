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

    # Clean previous build, build, and enable extension
    make clean && make && \
    make install && docker-php-ext-enable daruma_framework && \

    # Fix file permissions
    chown -R 1000:1000 . && \

    # Test extension
    php daruma_framework.php && make test < /dev/null
" | sed "s|/usr/src/app/||g"
