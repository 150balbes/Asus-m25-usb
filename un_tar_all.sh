#!/bin/sh

cd toolchain
tar xfapv gcc-4.2.tar.bz2
tar xfapv gcc.tar.bz2
tar xfapv glibc-2.5.tar.bz2
cd ../trunk/bootcode
tar xfapv u-boot-3.4.9.tar.bz2
tar xfapv u-boot-3.5.9.tar.bz2
tar xfapv u-boot-3.6.9.tar.bz2
cd ../image
tar xfapv rootfs_img.tar.bz2
cd ../kernel
tar xfapv linux-2.6.22.18.tar.bz2
cd ../modules
tar xfapv include.tar.bz2
cd ../..
