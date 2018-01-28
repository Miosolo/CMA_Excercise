#include <stdbool.h>

#define TOTAL_STEP 26
#define LENGTH 10
#define BLANK '.'

extern char field[][LENGTH + 2];
extern int direction[];

bool random_walk(void);