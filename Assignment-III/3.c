#include <stdio.h>
#include <limits.h>

char PrimesArray[INT_MAX] = {0};

void SieveOfEratosthenes(int n) {
  for(int i=2; i*i<=n; i++) {
    if(PrimesArray[i]==0) {
      for(int j=2; j*i<=n; j++)
        PrimesArray[i*j] = 1;
    }
  }
}
void OutputPrimes(int n) {
  for(int i=2; i<=n; i++) {
    if(PrimesArray[i] == 0)
      printf("%d ", i);
  }
  printf("\n");
}
int main(){  
  int n;
  scanf("%d", &n);
  SieveOfEratosthenes(n);
  OutputPrimes(n);
  return 0;
}
