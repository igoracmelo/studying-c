#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int exit_status = 0;

  if (argc == 1) {
    while (1) {
      int ch = getc(stdin);
      if (ch == EOF)
        break;
      putc(ch, stdout);
    }
  } else {
    for (int i = 1; i < argc; i++) {
      FILE *file = fopen(argv[i], "r");

      if (file == NULL) {
        fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
        exit_status = errno;
        continue;
      }

      while (1) {
        int ch = getc(file);
        if (ch == EOF)
          break;
        putc(ch, stdout);
      }

      fclose(file);
    }
  }

  return exit_status;
}