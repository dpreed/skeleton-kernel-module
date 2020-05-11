#define _STRINGIFY(name) #name
#define STRINGIFY(name) _STRINGIFY(name)

#define __MSTR__ STRINGIFY(__M__)
#define __MAUTHOR__ "David P. Reed <dpreed@deepplum.com>"

int common_init(void);
void common_fini(void);
