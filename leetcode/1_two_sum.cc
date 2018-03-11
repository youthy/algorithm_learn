#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// time complexity O(n)
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    int size = nums.size();
    int j;
    vector<int> ret;
    for(int i = 0; i < size; i++)
    {
        int need_to_find = target - nums[i];
        if((j = map[need_to_find]))
        {
            ret.push_back(j - 1);
            ret.push_back(i);
            return ret;
        }
        else
            map[nums[i]] = i + 1;
    }
    return ret;
}

int main(void)
{
    vector<int> v{2,3,5,6,8};
    vector<int> r = twoSum(v, 5);
    for(int i = 0; i < r.size(); i++)
        cout << r[i] << endl;
    return 0;
}