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
    // there may be many file pointers and won't fit on the stack
    // so it is better to heap allocate
    FILE **fptrs = malloc(sizeof(FILE) * (argc - 1));

    for (int i = 1; i < argc; i++) {
      fptrs[i] = fopen(argv[i], "r");
      if (fptrs[i] == NULL) {
        fprintf(stderr, "Failed to open file %s.", argv[i]);
        exit(1);
      }

      while (1) {
        int ch = fgetc(fptrs[i]);
        if (ch == EOF) {
          break;
        }
        putc(ch, stdout);
      }
    }

    fflush(stdout);
  }
}
