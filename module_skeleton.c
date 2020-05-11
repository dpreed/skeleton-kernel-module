#include <linux/module.h>  /* Needed by all kernel modules */
#include <linux/kernel.h>  /* Needed for loglevels (KERN_WARNING, KERN_EMERG, KERN_INFO, etc.) */
#include <linux/init.h>    /* Needed for __init and __exit macros. */
#include <linux/slab.h>    /* kmalloc */

#include "common_defs.h"	/* defines module specifics, like MNAME, common_init, common_fini */

// entry function
static int __init onload(void) {
	printk(KERN_INFO MSTR " initialized\n"); // print to /var/log/syslog
	return MPRE(_init)();
}

// exit function
static void __exit onunload(void) {
	MPRE(_fini)();
	printk(KERN_INFO MSTR " unloaded\n");
}

// register entry/exit point functions
module_init(onload);
module_exit(onunload);

// module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("David P. Reed <dpreed@deeplum.com>");
MODULE_DESCRIPTION("A simple skeleton for a loadable Linux kernel module");

