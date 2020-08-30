#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMPLATE_START "COMEÇA JAJÁ: ("
#define TEMPLATE_END ")\n"

struct Banner {
  int x;
  int y;
  int xModifier;
  int yModifier;
  int width;
  int height;
  char *title;
};

struct Banner* initBanner(char *time) {
  struct Banner* banner = malloc(sizeof(struct Banner));

  if(banner == NULL) {
    warning("Failed to alloc banner memory");
    exit(1);

  } else {
    int bannerWidth = strlen(time) + strlen(TEMPLATE_START) + strlen(TEMPLATE_END) + 1;

    banner->title = NULL;
    banner->x = 5;
    banner->y = 5;
    banner->xModifier = 1;
    banner->yModifier = 1;
    banner->height = 1;
    banner->width = bannerWidth;

    banner->title = calloc(sizeof(char), bannerWidth);

    if(banner->title == NULL) {
      free(banner);
      banner = NULL;
      warning("Failed to allocate memory for banner->title");
      exit(1);
    }

    sprintf(banner->title, "%s%s%s", TEMPLATE_START, time, TEMPLATE_END);

    return banner;
  }
}

void animateBanner(struct Banner *banner) {
  if(banner == NULL) {
    warning("Banner is null on animateBanner");
    exit(1);
  }

  if(((banner->x + banner->xModifier + banner->width) >= SCREEN_WIDTH)
      || ((banner->x + banner->xModifier) <= 0)) {
    banner->xModifier *= -1;
  }

  if(((banner->y + banner->yModifier + banner->height) >= SCREEN_HEIGHT)
      || ((banner->y + banner->yModifier) <= 0)) {
    banner->yModifier *= -1;
  }

  banner->x += banner->xModifier;
  banner->y += banner->yModifier;
}

void printBanner(struct Banner *banner) {
  if(banner == NULL) {
    warning("Banner is null on printBanner");
    exit(1);
  }

  if(banner->title == NULL) {
    warning("Banner->title is null on printBanner");
    exit(1);
  }

  int i = 0;
  int j = 0;

  system("clear");

  for(j = 0; j < banner->y; j++) {
    printf("\n");
  }

  for(i = 0; i < banner->x; i++) {
    printf(" ");
  }

  printf("%s", banner->title);

  for(i = banner->y; i < SCREEN_HEIGHT; i++) {
    printf("\n");
  }
}

void destroyBanner(struct Banner* banner) {
  free(banner->title);
  banner->title = NULL;

  free(banner);
  banner = NULL;
}

