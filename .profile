# ~/.profile: executed by Bourne-compatible login shells.

if [ "$BASH" ]; then
  if [ -f ~/.bashrc ]; then
    . ~/.bashrc
  fi
fi

mesg n

PROJECT_ROOT=/home/almirus/Asus-m25-usb/trunk
echo "PROJECT_ROOT: $PROJECT_ROOT"

export PROJECT_ROOT
export LINUX_SRC=${PROJECT_ROOT}/kernel/linux-2.6.22.18
export MODULE_DIR=${PROJECT_ROOT}/modules
export ROOT_FS=${PROJECT_ROOT}/image/rootfs

export TOOLCHAIN=${PROJECT_ROOT}/../toolchain/gcc
export TOOLCHAIN_FS=${TOOLCHAIN}/arm-none-linux-gnueabi
export TARGET_HOST=arm-none-linux-gnueabi

PATH=${TOOLCHAIN}/bin:"$PATH"
echo "PATH: $PATH"
export PATH

export CROSS_COMPILE=arm-none-linux-gnueabi-
CC=${CROSS_COMPILE}gcc
AS=${CROSS_COMPILE}as
LD=${CROSS_COMPILE}ld
AR=${CROSS_COMPILE}ar
RANLIB=${CROSS_COMPILE}ranlib
CPP=${CROSS_COMPILE}cpp
CXX=${CROSS_COMPILE}g++
NM=${CROSS_COMPILE}nm
STRIP=${CROSS_COMPILE}strip
export CC AS LD AR RANLIB CPP CXX NM STRIP
export LDFLAGS=-L${TOOLCHAIN_FS}/lib

# NAS_MODEL
# DNS-3461
# NAS-2302
# HDL-VR3
# NAS-M254
export NAS_MODEL=4

export LVM_ENABLED=0
export SNAPSHOT_ENABLED=0
export ENCRYPT_ENABLED=0
export MIRROR_ENABLED=0
export ALPHA_CUSTOMIZE=1
