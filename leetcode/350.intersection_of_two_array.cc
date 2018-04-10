#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ret;
    int size1 = nums1.size();
    int size2 = nums2.size();
    int minSize = min(size1, size2);
    if(minSize < 1) return ret;  // 等于0直接返回
    vector<int> &minv = size1 > size2 ? nums2 : nums1;
    vector<int> &maxv = size1 > size2 ? nums1 : nums2;
    int retSize = 0;
    unordered_map<int, int> times;
    for (auto i : minv)
    {
        times[i]++;
    }
    for(auto i: maxv)
    {
        if(times[i] > 0)
        {
            ret.push_back(i);
            times[i]--;
            retSize++;
        }
        if(retSize >= minSize) return ret;
    }
    return ret;
}