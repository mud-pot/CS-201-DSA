#include<stdio.h>
#define MAX 100

int main(){
  
  int size, arr1D[MAX];
  printf("Enter the size of the 1D array: ");
  scanf("%d",&size);

  printf("Enter the elements of the 1D array: ");
  for(int i=0;i<size;i++){
    scanf("%d", arr1D[i]);
  }

  int n, m;
  printf("Enter the no. of rows and columns of the 2D array: ");
  scanf("%d %d", &n, &m);

  if(n*m != size){
    printf("Invalid Input");
  }
  else{
    
    int arr2D[n][m];
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        arr2D[i][j] = arr1D[i*m+j];
      }
    }

    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        printf("%d   ",arr2D[i][j]);        
      }
      printf("\n");
    }
  }
  return 0;
}
