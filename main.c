/*
 * Main program for this kernel module
 */
#include "common_defs.h"

/* called at module load time */
int common_init(void)
{
	return 0;
}

/* called at module unload time */
void common_fini(void)
{
}
