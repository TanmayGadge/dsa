/*
Subarrays with Given Sum and Bounded Maximum
Given an integer array nums and integers k and M, count the number of contiguous subarrays whose sum equals k
and whose maximum element is at most M.

Example

Input:

nums = [2, -1, 2, 1, -2, 3]
k = 3
M = 2

Output:
2

Explanation:
We need subarrays with sum = 3 and all elements ≤ 2. 
Also, any subarray containing 3 is invalid because 3 > M. 

Check all starts:
- From index 0: [2, -1, 2] → sum = 3, max = 2 → valid (count = 1).
- From index 2: [2, 1] → sum = 3, max = 2 → valid (count = 2). No other subarray qualifies. Thus the total count is 2.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> slice(vector<int> array, size_t start, size_t end){
    
    vector<int> sub_array = {};
    if(!end){
        end = array.size();
    }

    for(size_t i = start; i < end; i++){
        sub_array.push_back(array[i]);
    }

    return sub_array;
}

// long countSubarraysWithSumAndMaxAtMost(vector<int> nums, long k, long M) {

//     long count = 0;
//     size_t starting_index = 0;
    
//     while(starting_index < nums.size()){
//         size_t subArraySize = 1;
//         while(subArraySize < nums.size()){

//             vector<int> subArray = slice(nums, starting_index, subArraySize);
    
//             long sum = 0;
            
//             for(size_t i = 0; i < subArray.size(); i++){
//                 if(subArray[i] >= M){
//                     break;
//                 }
//                 sum += subArray[i];
//             }
//             if(sum == k){
//                 count ++;
//             }
            
//             subArraySize++;
//         }
//         starting_index++;
//     }

//     return count;
// }

long countSubarraysWithSumAndMaxAtMost(vector<int> nums, long k, long M) {

    long count = 0;

    for(size_t i = 0; i < nums.size(); i++){
        long sum = 0;
        long max_value = nums[0];
        for(size_t j = i; j < nums.size(); j++){
            
            if(nums[j] > max_value){
                max_value = nums[j];
            }
            if(max_value > M){
                break;
            }
            sum += nums[j];
            
            if(sum == k){
                count++;
            }

        }
    }

    return count;
}

int main(){

    vector<int> test_array = {5};

    vector<int> sub_array = slice(test_array, 0, 2);

    long count = countSubarraysWithSumAndMaxAtMost(test_array, 5, 5);

    cout << count << endl;

    // for(int x: sub_array){
    //     cout << x << ", ";
    // }

    return 0;
}