#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

// 暴力求解
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

//O(n^2)
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

//动态规划
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

//分治
// O(NlgN)
int
max_sub3(const int a[], int start, int end){
  if(start == end){
      if(a[start] > 0)
          return a[start];
      else
          return 0;
  }
  //int mid = (end - start )/2 + start;
  int mid = (start + end)/2;
  int left, right;
  // 左面的最小子序列和和右面的最小子序列和
  left = max_sub3(a, start, mid);
  right = max_sub3(a, mid + 1, end);
  int left2,right2,tmp;
  left2 = right2 = 0;
  tmp = 0;
  for(int i = mid; i >= start; i--){
    tmp += a[i];
    if(tmp > left2)
    left2 = tmp;
  };
  tmp = 0;
  for(int i = mid + 1; i <= end; i++){
    tmp += a[i];
    if(tmp > right2)
    right2 = tmp;
  };
  int plus = left2 + right2;
  return left>right?(left>plus?left:plus):(right>plus?right:plus);
}

int
max_subsequence_sum3(const int a[], int n){
  return max_sub3(a, 0, n-1);
}

int
main(int argc, char const *argv[]) {
  /* code */
  int a[] ={1,-3,5,19,-5,10, 23,-14,9,1,20};
  for(int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
  size_t n = sizeof(a)/sizeof(int);
  printf("暴力法n^3: %i\n", max_subsequence_sum(a, n));
  printf("n^2: %i\n", max_subsequence_sum2(a, n));
  printf("动态规划: %i\n", max_subsequence_sum4(a, n));
  printf("分治: %i\n", max_subsequence_sum3(a, n));
  return 0;
}
