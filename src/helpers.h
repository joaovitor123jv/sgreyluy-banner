#include<stdio.h>
#include<stdlib.h>

void warning(char *message) {
  printf("WARNING: %s\n", message);
}

void err(char *message) {
  printf("ERROR: %s\n", message);
  exit(1);
}
