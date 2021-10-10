#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long int lli;

void selection_sort(lli a[], lli n){

  for(lli i = 0; i < n - 1; i++){

    for(lli j = i + 1; j < n; j++){

      if(a[j]<a[i]){

        lli temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }
 
}

void bubble_sort(lli a[], lli n){

  lli counter = 1;
  while(counter < n){
    
    for(lli i = 0; i < n - counter; i++){

      if(a[i] > a[i+1]){

        lli temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
    counter++;
  }


}

int main(){
  printf("Enter the no. of elements of array: ");
  lli n;
  scanf("%lld",&n);
  
  lli a[n];
  
  for(lli i = 0; i < n; i++) a[i] = i+1;

  clock_t start_selection_sort, end_selection_sort, start_bubble_sort, end_bubble_sort;

  lli time_selection_sort, time_bubble_sort;

  start_selection_sort = clock();
  
  selection_sort(a, n);

  end_selection_sort = clock();

  time_selection_sort = end_selection_sort - start_selection_sort;

  printf("The time taken for selection sort: %f\n", (double) time_selection_sort/ (double) CLOCKS_PER_SEC);

  start_bubble_sort = clock();

  bubble_sort(a, n);

  end_bubble_sort = clock();

  time_bubble_sort = end_bubble_sort - start_bubble_sort;

  printf("The time taken for bubble sort: %f\n", (double) time_bubble_sort/ (double) CLOCKS_PER_SEC);

}
