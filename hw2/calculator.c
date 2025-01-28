#include <stdio.h>
#include <stdlib.h>

void remove_newline(char *s, int maxsize) {
  for (int i = 0; i < maxsize && s[i]; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  const int BUFSIZE = 80;
  char buffer[BUFSIZE];
  FILE *infile = NULL;

  if (argc != 2) {
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1;
  }

  infile = fopen(argv[1], "r");
  if (!infile) {
    fprintf(stderr, "input file %s not found\n", argv[1]);
    return 1;
  }

  long current_total;
  char operator= 0;
  int is_first = 1;

  while (fgets(buffer, BUFSIZE, infile)) {
    remove_newline(buffer, BUFSIZE);

    if (is_first) {
      current_total = strtol(buffer, NULL, 10);
      is_first = 0;
    } else if (operator== 0) {
      operator= buffer[0];
    } else {
      long num = strtol(buffer, NULL, 10);
      if (operator== '/' && num == 0) {
        printf("ERROR\n");
        fclose(infile);
        return 0;
      }
      if (operator== '+') {
        current_total += num;
      }

      else if (operator== '-') {
        current_total -= num;
      } else if (operator== '*') {
        current_total *= num;
      }

      else if (operator== '/') {
        current_total /= num;
      }

      operator= 0;
    }
  }

  printf("%ld\n", current_total);
  fclose(infile);
  return 0;
}
