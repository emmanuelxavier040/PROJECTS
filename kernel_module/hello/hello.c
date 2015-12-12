
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kmod.h>



static int start_userhelper( void )
{
	char *argv[] =  { "/bin/bash", "-c", "/usr/bin/joysti", NULL};
	static char *envp[]={ "HOME=/", "TERM=linux", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL};
	call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
 	return 0;
}

static int stop_userhelper( void )
{
	char *argv[] =  { "/bin/bash", "-c", "killall /usr/bin/joysti", NULL};
	static char *envp[]={ "HOME=/", "TERM=linux", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL};
	call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
 	return 0;
}


static int __init hello1_init(void)
{
	printk(KERN_DEBUG "Hello World!\n");	
	return  start_userhelper();
	
}

static void __exit hello1_exit(void)
{
	//printk(KERN_INFO "Module removed.....Goodbye world 1.\n");
	stop_userhelper();
}


module_init(hello1_init);
module_exit(hello1_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Emmanuel Xavier");
MODULE_DESCRIPTION("Test module hello1");

