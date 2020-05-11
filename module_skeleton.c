#include <linux/module.h>  /* Needed by all kernel modules */
#include <linux/kernel.h>  /* Needed for loglevels (KERN_WARNING, KERN_EMERG, KERN_INFO, etc.) */
#include <linux/init.h>    /* Needed for __init and __exit macros. */
#include <linux/slab.h>    /* kmalloc */

#include "common_defs.h"	/* defines module specifics, like MNAME, common_init, common_fini */

// entry function
static int __init onload(void) {
	printk(KERN_INFO __MSTR__ " initialized\n"); // print to /var/log/syslog
	return common_init();
}

// exit function
static void __exit onunload(void) {
	common_fini();
	printk(KERN_INFO __MSTR__ " unloaded\n");
}

// register entry/exit point functions
module_init(onload);
module_exit(onunload);

// module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR(__MAUTHOR__);
MODULE_DESCRIPTION("Linux kernel module named " __MSTR__);

