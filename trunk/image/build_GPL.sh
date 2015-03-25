ramdisk_size=7868
dest_dir="./rootfs_img"
jffs2_cfg="$dest_dir/jffs2_img"
squash_img="$dest_dir/squashfs_img"
initrd_img="$dest_dir/initrd_img"
tmp_initrd_img="$dest_dir/tmp_initrd_img"
initrd_mnt="$dest_dir/initrd_mnt"

umount -f $tmp_initrd_img 2> /dev/null
rm -f $tmp_initrd_img.gz
rm -rf $$initrd_mnt

mkdir -p $initrd_mnt

echo "Create RAMdisk size: $ramdisk_size"
dd if=/dev/zero of=$tmp_initrd_img bs=1k count=$ramdisk_size
mke2fs -F -m0 -i 2000 $tmp_initrd_img
mount -o loop -t ext2 $tmp_initrd_img $initrd_mnt

cp -a $initrd_img/* $initrd_mnt/
version=1.0.2.
beta_version=1
date_value_1=`date +%Y.%m.%d.%H%M`
date_value_2=`date +%Y/%m/%d`

echo "$version$beta_version""_""$date_value_1" > $initrd_mnt/etc/version.txt
echo "$version$beta_version""_""$date_value_1" > ./version.txt
echo "$date_value_2" >> ./version.txt

#create initrd
umount $initrd_mnt
gzip -9  $tmp_initrd_img 
./mkimage -A arm -O linux -T ramdisk -C gzip -a 0xb00000 -n Ramdisk -d $tmp_initrd_img.gz $dest_dir/uRamdisk

#create squash fs
rm $dest_dir/squash.img
./mksquashfs $dest_dir/squashfs_img/ $dest_dir/squash.img -all-root

#create jffs2
rm $dest_dir/jffs2.img
./mkfs.jffs2 -l --pad=1966080 -d $dest_dir/jffs2_img -o $dest_dir/jffs2.img


echo OUTPUT
echo "	$dest_dir/uRamdisk"
echo "	$dest_dir/squash.img"	
echo "	$dest_dir/jffs2.img"	
echo 
echo "build_rootfs.sh done!!"

cp -avf $dest_dir/squash.img ./squash.img
cp -avf $dest_dir/uRamdisk ./uRamdisk
cp -avf $dest_dir/jffs2.img ./jffs2.img
cp -avf $dest_dir/uRamdisk ./uInitrd

./merge_image

mv NAS-M25_firmware NAS-M25_firmware_$version$beta_version"_"$date_value_1".trx"

rm $dest_dir/squash.img ./squash.img  $dest_dir/uRamdisk ./uRamdisk $dest_dir/jffs2.img  ./jffs2.img
rm -rf $tmp_initrd_img.gz $initrd_mnt
