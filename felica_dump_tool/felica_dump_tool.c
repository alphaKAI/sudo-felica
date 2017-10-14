#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <libpafe/libpafe.h>

int main() {
  pasori *p;
  felica *f;
  time_t      start_time;
  start_time = time(NULL);
  bool timeout = true;


  p = pasori_open();
  if (!p) {
    fprintf(stderr, "Failed to open Pasori\n");
    exit(-1);
  }
  pasori_init(p);

  printf("Please touch your Felica card on Pasori\n");

  while (difftime(time(NULL), start_time) < 5) {
    f = felica_polling(p, FELICA_POLLING_ANY, 0, 0);
    if (f) {
      printf("IDm : ");
      for (size_t idx = 0; idx < 8; idx++) {
        printf("%x", f->IDm[idx]);
      }
      printf("\n");
      printf("PMm : ");
      for (size_t idx = 0; idx < 8; idx++) {
        printf("%x", f->PMm[idx]);
      }
      printf("\n");

      timeout = false;
      break;
    }
  }

  if (timeout == true) {
    fprintf(stderr, "Timeout\n");
  }

  free(f);
  pasori_close(p);

  return 0;
}
