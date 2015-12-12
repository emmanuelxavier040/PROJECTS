#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

//probe function
//called on device insertion if and only if no other driver has beat us to the punch
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO "[*] OS Project USB Device (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
	return 0; //return 0 indicates we will manage this device
}

//disconnect

static void pen_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "[*] OS Project USB Device removed\n");

}



//usb_device_id
static struct usb_device_id pen_table[] = {
	//046d:c21d
	{ USB_DEVICE(0x046d, 0xc21d) },	//information is obtained using "lsbusb" at the command line
	{}	/* Terminating entry	*/
};
MODULE_DEVICE_TABLE(usb, pen_table);



//usb_driver
static struct usb_driver pen_driver=
{
	.name = "OS Project USB Driver",
	.id_table = pen_table, // usb_device_id
	.probe = pen_probe,
	.disconnect = pen_disconnect,
};

static int __init pen_init(void)
{
	
	int ret = -1;
	printk(KERN_INFO "[*] OS Project USB Device Driver Constructor\n");
	printk(KERN_INFO "\tRegistering Driver with Kernel\n");
	ret = usb_register_driver(&pen_driver);
	printk(KERN_INFO "\tRegistration is Complete\n");
	return ret;
}

static void __exit pen_exit(void)
{
	//deregister
	printk(KERN_INFO "[*] OS Project USB Device Driver Destructor\n");
	usb_deregister_driver(&pen_driver);
	printk(KERN_INFO "\tUnregistration is Complete\n");
}

module_init(pen_init);
module_exit(pen_exit);