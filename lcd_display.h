#ifndef __LCD__
#define __LCD__

#include <stdint.h>

void init_display(int ki);

void clear_display(int ki);

void print_message(uint32_t position, char message[]);



#endif
