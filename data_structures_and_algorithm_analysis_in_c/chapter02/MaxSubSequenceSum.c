#include <stdio.h>
#include <stdlib.h>
// O(n^3)
int
max_subsequence_sum(const int a[], int n){
  int max=0;
  for(int i = 0; i < n; i++){
    for(int j=i; j < n; j++){
      int tmp=0;
      for(int k = i; k <= j; k++){
        tmp += a[k];
        if(tmp > max)
        max = tmp;
      }
    }
  }
  return max;
}

int
max_subsequence_sum2(const int a[], int n){
  int max=0;
  for(int i = 0; i < n; i++){
    int tmp=0;
    for(int j=i; j < n; j++){
      tmp += a[j];
      if(tmp > max)
      max = tmp;
    }
  }
  return max;
}

// O(n)
int
max_subsequence_sum4(const int a[], int n){
  int max = 0;
  int tmp = 0;
  for(int i = 0; i < n; i++){
    tmp += a[i];
    if (tmp > max)
    max = tmp;
    else if(tmp < 0)
    tmp = 0;
  }
  return max;
}

int
main(int argc, char const *argv[]) {
  /* code */
  int a[] ={1,-3,5,19,-5,10};
  printf("%i\n", max_subsequence_sum(a, 6));
  printf("%i\n", max_subsequence_sum2(a, 6));
  printf("%i\n", max_subsequence_sum4(a, 6));
  return 0;
}
