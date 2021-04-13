#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>

void gcrypt_init(void);

void progress_handler (void *cb_data, const char *what,
        int printchar, int current, int total);


#endif
