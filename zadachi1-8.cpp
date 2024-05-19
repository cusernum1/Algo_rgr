#include <iostream>
#include <vector>
#include <map>

using namespace std;

pair<int, int> findLongestSubs(const vector<int>& nums) {
    map<int, int> lastIdx; 
    int maxLength = 0; 
    int startIndex = 0; 
    int left = 0; 

    for (int right = 0; right < nums.size(); ++right) {
        if (lastIdx.find(nums[right]) != lastIdx.end() && lastIdx[nums[right]] >= left) {
            left = lastIdx[nums[right]] + 1;
        }
        
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            startIndex = left;
        }

        lastIdx[nums[right]] = right;
    }

    return {maxLength, startIndex};
}
