./build_gz.sh
rm build_rootfs.sh
rm build_gz.sh
rm build.log
rm build_image.sh
rm rootfs_list
rm rootfs_list.tmp
rm -rvf rootfs
rm -rvf gz
rm -rvf *.tgz
cp merge/setting.txt ./
cp merge/u-boot-db88f6281abp_400db_nand.bin ./
cp merge/uImage ./
cp merge/merge ./merge_image
