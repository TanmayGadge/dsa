/*
Target Index Search
Given a sorted array of distinct integers and a target value, return the index of the target or -1 if not found.

Example 1

Input:
nums = [1, 2, 3, 4, 5]
target = 3

Output:
2

Explanation:
Initialize low = 0, high = 4. Compute mid = (0 + 4) // 2 = 2. nums[2] = 3 matches target, so return 2.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int binarySearch(vector<int> nums, int target) {
    int low = 0, high = nums.size() - 1;

    
    
    while(low <= high){
        int mid = floor((low + high)/2);

        if(nums[mid] == target){
            return mid;
        }

        if(target > nums[mid]){
            low = mid + 1;
        }
        if(target < nums[mid]){
            high = mid - 1;
        }
    }

    return -1;
}

int main(){

    vector<int> nums = {1, 2, 3, 4, 5};

    cout << binarySearch(nums, 9) << endl;

    return 0;
}