#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // cat without args: pipe stdin to stdout
  if (argc == 1) {
    while (1) {
      int ch = getc(stdin);
      if (ch == EOF) {
        fflush(stdout);
        break;
      }
      putc(ch, stdout);
    }
  }

  // cat with args: print file(s) content(s)
  else {
    for (int i = 1; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r");

      if (fp == NULL) {
        fprintf(stderr, "Failed to open file %s.", argv[i]);
        exit(1);
      }

      while (1) {
        int ch = fgetc(fp);
        if (ch == EOF) {
          break;
        }
        putc(ch, stdout);
      }

      fclose(fp);
    }

    fflush(stdout);
  }
}
