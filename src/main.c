#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_HEIGHT 20
#define SCREEN_WIDTH 80

#include "./helpers.h"
#include "./Banner.h"

int main() {
  char time[6];
  struct Banner *banner = NULL;

  printf("Digite o horário que você vai aparecer no formato hh:mm\n");

  scanf("%s", time);

  banner = initBanner(time);

  system("clear");

  while(1) {
    animateBanner(banner);
    printBanner(banner);
    usleep(150000);
  }

  destroyBanner(banner);

  return(0);
}
