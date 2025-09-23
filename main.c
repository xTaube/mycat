

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_MAX 8192

typedef enum { FLAG_NONE = 0x0, FLAG_N = 0x1 } FLAGS;

void _cat_with_line_number(FILE *fp, char buffer[BUFF_MAX],
                           size_t *line_number) {
  while (fgets(buffer, BUFF_MAX, fp)) {
    fprintf(stdout, "%6zu %s", *line_number, buffer);
    (*line_number)++;
  }
}

void cat(FILE *fp, unsigned int flags, size_t *line_number) {

  char buffer[BUFF_MAX];

  if (flags & FLAG_N) {
    _cat_with_line_number(fp, buffer, line_number);
  } else {
    size_t n = 0;
    while ((n = fread(buffer, 1, BUFF_MAX, fp)) > 0) {
      if (fwrite(buffer, 1, n, stdout) != n) {
        perror("Cannot write to stdout:");
        exit(EXIT_FAILURE);
      }
    }
  }

  while (fgets(buffer, BUFF_MAX, fp)) {
    if (flags & FLAG_N) {
      fprintf(stdout, "%6zu %s", *line_number, buffer);
    } else {
      fprintf(stdout, "%s", buffer);
    }
    (*line_number)++;
  }
}

int main(int argc, const char *argv[argc + 1]) {
  unsigned int flags = FLAG_NONE;

  size_t line_number = 1;

  int arg_idx = 1;
  for (; arg_idx < argc; arg_idx++) {
    if (strncmp(argv[arg_idx], "-", 1) != 0) {
      break;
    }
    if (strcmp(argv[arg_idx], "-n") == 0)
      flags |= FLAG_N;
  }

  if (arg_idx == argc) {
    cat(stdin, flags, &line_number);
    return EXIT_SUCCESS;
  }

  for (; arg_idx < argc; arg_idx++) {
    FILE *fp = fopen(argv[arg_idx], "rb");
    if (!fp) {
      fprintf(stderr, "Cannot open %s: ", argv[arg_idx]);
      perror(NULL);
      continue;
    }
    cat(fp, flags, &line_number);
    fclose(fp);
  }

  return EXIT_SUCCESS;
}
