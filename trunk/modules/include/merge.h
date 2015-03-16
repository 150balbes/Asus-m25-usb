#define	DBG			1

#define KERNEL_FILE		    "uImage"
#define RAMDISK_FILE	    "uRamdisk"
#define SQUASH_FILE		    "squash.img"
#define BOOT_FILE		    "u-boot-db88f6281abp_400db_nand.bin"
#define SCRIPT_FILE		    "fwUpdate.sh"
#define SCRIPT_FILE_b	    "fwUpdateb.sh"
#define SCRIPT_FILE_TMP	    "fwUpdate.tmp.sh"
#define uP_FILE			    "hdl-vr.hex"
#define TMP_SCRIPT_FILE	    "/tmp/fwUpdate.sh"
#define TMP_uP_FILE		    "/tmp/hdl-vr.hex"
#define MERGED_FILE		    "NAS-M25_firmware"


#define	BOOT_SIZE		    0x100000
#define KERNEL_SIZE		    0x300000
#define	RAMDISK_SIZE 	    0x200000
#define	SQUASHFS_SIZE	    0x3700000 /*Matt change size to 55MB*/
#define	FIS_SIZE            0x0
#define CONFIG_SIZE		    0x200000

#define BLOCK_SIZE		    0x10000

#define PRODUCT_ID  0
#define CUSTOM_ID   0
#define MODEL_ID    0

//the sting is "0x55 0xaa GENERIC - 0x55 0xaa"
unsigned char GENERIC_MAGIC_NUM[12] =
                {0x55, 0xaa, 0x47, 0x45, 0x4E, 0x45, 0x52, 0x49, 0x43, 0x2d, 0x55, 0xaa};

//TBD: the sting is "0x55 0xaa NAS-M25 - 0x55 0xaa" 
unsigned char CUSTOM_MAGIC_NUM[12] =
                {0x55, 0xaa, 0x4e, 0x41, 0x53, 0x2d, 0x4d, 0x32, 0x35, 0x2d, 0x55, 0xaa};

#define fnm_convert_ul_endian(x)						\
	((unsigned long)((((unsigned long)(x)) >> 24) + ((((unsigned long)(x)) & 0x00ff0000) >> 8) +		\
		 ((((unsigned long)(x)) & 0x0000ff00) << 8) + (((unsigned long)(x)) << 24)))


typedef struct _CONTROL_HEADER_
{
	unsigned long 	kernel_offset;
	unsigned long 	kernel_size;
	unsigned long 	uRamdisk_offset;
	unsigned long 	uRamdisk_size;
	unsigned long 	squashfs_offset;
	unsigned long 	squashfs_size;
	unsigned long 	uboot_offset;
	unsigned long 	uboot_size;
	unsigned long 	script_offset;
	unsigned long 	script_size;
	unsigned long 	kernel_checksum;		
	unsigned long   uRamdisk_checksum;
	unsigned long 	squashfs_checksum;
	unsigned long 	uboot_checksum;
	unsigned long 	script_checksum;
	unsigned char 	magic_num[12];
	unsigned char 	product_id;
	unsigned char 	custom_id;
	unsigned char 	model_id;
	unsigned char 	sub_id;
	unsigned char 	NewVersion;
	char    update_kernel;
	char    update_uRamdisk;
	char    update_squashfs;
	char    update_uboot;
	char    script_flag;
	char	build_date[25];
	unsigned long 	uP_offset;
	unsigned long 	uP_size;
	unsigned long 	uP_checksum;
	char		update_uP;
	char 		up_version[30];
	char 		bootldr_ver[8];
	unsigned long 	Next_offset;
}*CONTROL_HEADER_ID, CONTROL_HEADER;


typedef struct _EXTEND_HEADER_
{
	char 		Directory[32];
	char		FileName[32];

	unsigned short	chmod;
	unsigned char	execute;
	unsigned char	reserved[13];

	unsigned long 	offset;
	unsigned long 	len;
	unsigned long 	checksum;
	unsigned long 	Next_offset;
}*EXTEND_HEADER_ID, EXTEND_HEADER;

static struct {
	char *Directory;
	char *FileName;
} *PEXTEND_ELEMENTS, EXTEND_ELEMENTS[] = {
	{NULL, NULL}
};

