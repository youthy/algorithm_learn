#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
   unordered_map<int, int> map; 
   for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
   {
       if(++map[*iter] > 1)
            return true;
   }
   return false;
}

int main(void)
{
    vector<int> v = {1,2,3,4,5,5,6,7};
    printf("%d", containsDuplicate(v));
}