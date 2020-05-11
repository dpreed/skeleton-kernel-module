/* define MNAME in make file to be module name */
#define MSTR2(n) #n
#define MSTR1(n) MSTR2(n)
#define MSTR MSTR1(MNAME)
#define MPRE2(n,s) n ## s
#define MPRE1(n, s) MPRE2(n, s)
#define MPRE(s) MPRE1(MNAME, s)
int MPRE(_init)(void);
void MPRE(_fini)(void);
