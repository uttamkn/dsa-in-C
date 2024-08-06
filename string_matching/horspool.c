#include <stdio.h>
#include <string.h>
#define SIZE 256

char table[SIZE];

void shiftTable(char *pattern) {
  int n = strlen(pattern);
  for (int i = 0; i < SIZE; i++) {
    table[i] = n;
  }

  for (int i = 0; i < n - 1; i++) {
    table[(unsigned char)pattern[i]] = n - i - 1;
  }
}

int horspools(char *source, char *pattern) {
  shiftTable(pattern);
  int n = strlen(source);
  int m = strlen(pattern);
  int i = m - 1;

  while (i < n) {
    int k = 0;
    while (k < m && pattern[m - 1 - k] == source[i - k]) {
      k++;
    }

    if (k == m) {
      return i - m + 1;
    } else {
      i += table[(unsigned char)source[i]];
    }
  }

  return -1;
}

int main() {
  char src[] = "ATCGGCTAAGCTTA";
  char pattern[] = "AAGC";

  int idx = horspools(src, pattern);

  if (idx == -1) {
    printf("not found\n");
  } else {
    printf("found at %d\n", idx);
  }
  return 0;
}
