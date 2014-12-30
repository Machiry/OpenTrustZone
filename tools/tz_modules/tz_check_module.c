#include <linux/module.h>   
#include <linux/kernel.h>  
#include <linux/init.h>    

#define DRIVER_AUTHOR "Machiry, Aravind <makrvcs@gmail.com>"
#define DRIVER_DESC   "TZ Check"

#define ARM_SECURITY_EXTENSION_MASK	(0x30)
int has_security_extensions(void)
{
	int fea = 0;
	asm volatile(
			"mrc p15, 0, %[fea], cr0, cr1, 0" :
			[fea]"=r" (fea));

	printk(KERN_DEBUG "CPU Features: 0x%X", fea);
	/*
	* If the CPU features ID has 0 for security features then the CPU
	* doesn't support TrustZone at all!
	*/
	if ((fea & ARM_SECURITY_EXTENSION_MASK) == 0)
		return 0;

	return 1;
}

static int __init tz_check_init_module(void)
{
	if(has_security_extensions()) {
		printk(KERN_DEBUG "TRUSTZONE PRESENT!!!\n");
	} else{
		printk(KERN_DEBUG "TRUSTZONE NOT PRESENT!!!\n");
	}
    printk(KERN_DEBUG "Module Installed\n");
    return 0;
}

static void __exit tz_check_cleanup_module(void)
{
    printk(KERN_DEBUG "Removing Module\n");
}

module_init(tz_check_init_module);
module_exit(tz_check_cleanup_module);

MODULE_AUTHOR(DRIVER_AUTHOR);   
MODULE_DESCRIPTION(DRIVER_DESC); 
