#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTBL 1000000
// color1.c --- handle color struct.
struct color {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
struct ent {
  char *key;
  int val;
};
struct ent2 {
  char *key;
  char *val;
};

struct ent tbl[MAXTBL];
struct ent2 tbl2[MAXTBL];
int tblsize = 0;
int tblsize2 = 0;
