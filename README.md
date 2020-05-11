#A skeleton Linux kernel module template.

Usage

Clone into a directory named with the module name you want.
Uses the basename of the directory to define the module
being built.

Put include files in `include` subdirectory. The file `common_defs.h`
contains some useful defines and the signatures for the two main
procedures.

Defines

`__M__` The module name as a macro.
`__MSTR__` The module name as a string.
`STRINGIFY(s)` A macro that expands another macro to a quoted string.

Interface

Defined in main.c, to separate from module loading functionality.

`int main_init()` is called on module load.
`main_fini()` is called on module unload.




