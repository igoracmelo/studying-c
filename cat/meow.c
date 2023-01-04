// #include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // cat without args: pipe stdin to stdout
  if (argc == 1) {
    char buf[BUFSIZ];

    while (1) {
      int n = read(STDIN_FILENO, buf, BUFSIZ);
      if (n <= 0) {
        // TODO: handle errors
        break;
      }

      // TODO: handle errors
      write(STDOUT_FILENO, buf, n);
    }
  }

  // cat with args: print file(s) content(s)
  else {
    for (int i = 1; i < argc; i++) {
      int fd = open(argv[i], O_RDONLY, 0);
      if (fd == -1) {
        // TODO: handle errors
        break;
      }

      char buf[BUFSIZ];
      while (1) {
        int n = read(fd, buf, BUFSIZ);
        if (n <= 0) {
          // TODO: handle errors
          break;
        }

        // TODO: handle errors
        write(STDOUT_FILENO, buf, n);
      }
    }
  }
}
