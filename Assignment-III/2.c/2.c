#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX (int)1e4

void AvgCase(int n, int input[]) {
  for(int i=0; i<n; i++)
    input[i] = rand()%MAX;
}

void BestCase(int n, int input[]) {
  for(int i=0; i<n; i++)
    input[i] = i;
}

void WorstCase(int n, int input[]) {
  for(int i=0; i<n; i++)
    input[i] = n-i-1;
}

void InsertionSort(int n, int input[]) {
  int key, j;
  for (int i=1; i<n; i++){
    key = input[i];
    j = i-1;
    while (j>=0 && input[j]>key)
    {
        input[j+1] = input[j];
        j = j-1;
    }
    input[j+1] = key;
  }
}

int main() {

  srand(time(0));

  int n;
  printf("Enter size of input: ");
  scanf("%d", &n);

  int input[n];

  int k;
  printf("1. Average Case Input\n");
  printf("2. Best Case Input\n");
  printf("3. Worst Case Input\n");
  printf("Select the type of Input: ");
  scanf("%d", &k);

  switch(k) {
    case 1:
      AvgCase(n, input);
      break;

    case 2:
      BestCase(n, input);
      break;
    
    case 3:
      WorstCase(n, input);
      break;

    default:
      printf("Incorrect option\n");
      return 0;
      break;
  }

  clock_t start = clock();

  insertionSort(n, input);

  clock_t end = clock();
  printf("Total elapsed time : %f\n", (double)(end - start)/(double)CLOCKS_PER_SEC);

  return 0;
}
