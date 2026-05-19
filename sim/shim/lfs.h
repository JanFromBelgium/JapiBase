/* Host shim for littlefs lfs.h — opaque stub so japi_base.h compiles on Linux.
   The simulator never uses littlefs internals; only the type size matters. */
#ifndef LFS_SHIM_H
#define LFS_SHIM_H
typedef struct { unsigned char _opaque[64]; } lfs_file_t;
#endif
