#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *sieve(int maxlimit, int *primeCount) {
  int sq = sqrt((double)maxlimit) + 1;
  int *flags = (int *)malloc(sizeof(int) * (maxlimit + 1));
  memset(flags, 0, maxlimit + 1); // memset to any non-zero value does not work
  // memset sets byte to (1) and not the integer
  // 1 int = 4 bytes
  // therefore memset result is
  // 01010101 (base 16) =  16843009 (base 10)
  flags[0] = 1;
  flags[1] = 1;
  flags[2] = 0;

  int i = 0, j = 0;
  for (i = 2; i < sq; i++) {
    if (flags[i] == 0) {
      for (j = 2; i * j < maxlimit + 1; j++) {
        flags[i * j] = 1;
      }
    }
  }

  int num_primes = 0;
  for (i = 0; i < maxlimit + 1; i++) {
    if (flags[i] == 0) {
      num_primes++;
    }
  }

  int *primes = (int *)malloc(sizeof(int) * num_primes);
  *primeCount = num_primes;
  num_primes = 0;
  for (i = 0; i < maxlimit + 1; i++) {
    if (flags[i] == 0) {
      primes[num_primes] = i;
      num_primes++;
    }
  }
  return primes;
}

void display(int *arr, int numElems) {
  int i = 0;
  for (i = 0; i < numElems; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main() {
  int maxlimit = 1000000;
  int primeCount = 0;
  int *primes = sieve(maxlimit, &primeCount);
  display(primes, primeCount);
}