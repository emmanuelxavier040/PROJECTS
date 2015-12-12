#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/types.h>   // for dev_t typedef
#include <linux/kdev_t.h>  // for format_dev_t
#include <linux/fs.h>      // for alloc_chrdev_region()
#include <linux/cdev.h>     // for "struct cdev"
#include <asm/uaccess.h>    // for user/kernel space copy routines




struct cdev my_cdev;



static dev_t mydev;             // (major,minor) value
static char buffer[64];         // optional, for debugging




static char output[] = "Victory is mine!\n";

ssize_t my_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    printk(KERN_INFO "In chardrv read routine.\n");
    printk(KERN_INFO "Count field is %lu.\n", count);
    //printk(KERN_INFO "Offset is %lu.\n", *f_pos);

    if (output[*f_pos] == '\0') {
        printk(KERN_INFO "End of string, returning zero.\n");
        return 0;
    }
    
    if (copy_to_user(buf, &output[*f_pos], 1) > 0) {
    	return -EFAULT;
	}

    *f_pos += 1;
    return 1;  // returned a single character
}

struct file_operations my_fops = {
    .owner = THIS_MODULE,
    .read = my_read,
};

static int __init chardrv_in(void)
{
    printk(KERN_INFO "module chardrv being loaded.\n");

    alloc_chrdev_region(&mydev, 0, 1, "rday");
    printk(KERN_INFO "%s\n", format_dev_t(buffer, mydev));

    cdev_init(&my_cdev, &my_fops);
    my_cdev.owner = THIS_MODULE;
    cdev_add(&my_cdev, mydev, 1);

    return 0;
}


static void __exit chardrv_out(void)
{
    printk(KERN_INFO "module chardrv being unloaded.\n");

    cdev_del(&my_cdev);
    unregister_chrdev_region(mydev, 1);
}


module_init(chardrv_in);
module_exit(chardrv_out);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("GPL");

