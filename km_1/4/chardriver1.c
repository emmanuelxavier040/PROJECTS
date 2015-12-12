#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
 
static dev_t first; // Global variable for the first device number
 
static int __init ofcd_init(void) /* Constructor */
{
    printk(KERN_INFO "Hello: ofcd registered\n");
    if (alloc_chrdev_region(&first, 0, 3, "Emmanuel") < 0)
    {
        return -1;
    }
    printk(KERN_INFO "<Major, Minor>: <%d, %d>\n", MAJOR(first), MINOR(first));
    return 0;
}
 
static void __exit ofcd_exit(void) /* Destructor */
{
    unregister_chrdev_region(first, 3);
    printk(KERN_INFO "Goodbye: ofcd unregistered\n");
}
 
module_init(ofcd_init);
module_exit(ofcd_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Emmanuel Xavier");
MODULE_DESCRIPTION("My Test Character Driver 1");