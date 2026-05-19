/* Host shim for FatFs ff.h — opaque stub so japi_base.h compiles on Linux.
   The simulator never uses FatFs internals; only the type size matters. */
#ifndef FF_SHIM_H
#define FF_SHIM_H
typedef struct { unsigned char _opaque[64]; } FIL;
#endif
