#include "mrubyc_src/mrubyc.h"

#include <stdio.h>
#include <stdlib.h>

// #include "src/models/[replace with your file].c"
// #include "src/loops/[replace with your file].c"

#define MEMORY_SIZE (1024*40)
static uint8_t my_memory_pool[MEMORY_SIZE];

//================================================================
/*! DEBUG PRINT
*/
static void c_debugprint(struct VM *vm, mrbc_value v[], int argc){
  for( int i = 0; i < 79; i++ ) { console_putchar('='); }
  console_putchar('\n');
  int total, used, free, fragment;
  mrbc_alloc_statistics( &total, &used, &free, &fragment );
  console_printf("Memory total:%d, used:%d, free:%d, fragment:%d\n", total, used, free, fragment );
  unsigned char *key = GET_STRING_ARG(1);
  unsigned char *value = GET_STRING_ARG(2);
  console_printf("%s:%s\n", key, value );
  for( int i = 0; i < 79; i++ ) { console_putchar('='); }
  console_putchar('\n');
}

int main(void) {
  mrbc_init(my_memory_pool, MEMORY_SIZE);

  mrbc_define_method(0, mrbc_class_object, "debugprint", c_debugprint);

//  mrbc_create_task( [replace with your task], 0 );
  mrbc_run();

  return 0;
}

