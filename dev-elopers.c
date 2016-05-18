#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include "dev-elopers.h"

static ssize_t elopers_read(struct file *file, char *buf, size_t count, loff_t *ppos) {
	if (count < dev_elopers_mp3_len) {
		return -EINVAL;
	}

	if (*ppos != 0) {
		return 0;
	}

	if (copy_to_user(buf, dev_elopers_mp3, dev_elopers_mp3_len)) {
		return -EINVAL;
	}

	*ppos = dev_elopers_mp3_len;

	return dev_elopers_mp3_len;
}

static const struct file_operations elopers_fops = {
	.owner = THIS_MODULE,
	.read  = elopers_read
};

static struct miscdevice elopers_dev = {
	MISC_DYNAMIC_MINOR,
	"elopers",
	&elopers_fops
};

static int __init elopers_init(void) {
	int ret = 0;

	ret = misc_register(&elopers_dev);

	if (ret) {
		printk(KERN_ERR "Unable to register \"elopers\" misc device\n");
	}

	return ret;
}

module_init(elopers_init);

static void __exit elopers_exit(void) {
	misc_deregister(&elopers_dev);
}

module_exit(elopers_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Selwyn <kevinselwyn@gmail.com>");
MODULE_DESCRIPTION("Developers");
MODULE_VERSION("dev");