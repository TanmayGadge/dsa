/*
Find the Smallest Missing Positive Integer
Given an unsorted array of integers, find the smallest positive integer not present in the array in O(n) time and O(1) extra space.

Example

Input

orderNumbers = [3, 4, -1, 1]
Output

2
Explanation

We want the smallest positive missing integer.

Start with [3, 4, -1, 1]
- i=0: value 3 ⇒ swap with index 2 ⇒ [-1, 4, 3, 1]
- i=0: value -1 is out of range ⇒ move on
- i=1: value 4 ⇒ swap with index 3 ⇒ [-1, 1, 3, 4]
- i=1: value 1 ⇒ swap with index 0 ⇒ [1, -1, 3, 4]
- now 1 at index 0, 3 at 2, 4 at 3; -1 remains at index 1

Scan from index 0:
index 0 has 1 (correct), index 1 has -1 (not 2) ⇒ missing positive is 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& element1, int& element2){
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

int findSmallestMissingPositive(vector<int> orderNumbers) {

    int i = 0;
    if(orderNumbers.empty()){
        return 1;
    }

    while(i < int(orderNumbers.size())){
        // cout << "i = " << i << "value = " << orderNumbers[i] << endl;
        if(orderNumbers[i] > int(orderNumbers.size()) || orderNumbers[i] <= 0){ //Out of range condition
            i++;
        }
        else if(orderNumbers[i] != i+1){

            if(orderNumbers[orderNumbers[i] - 1] != orderNumbers[i]){
                swap(orderNumbers[orderNumbers[i] - 1], orderNumbers[i]);
                continue;
            }
            else{
                i++;
            }
        }
        else{
            i++;
        }
    }

    for(size_t j = 0; j < orderNumbers.size(); j++){
        if(orderNumbers[j] != j+1){
            return j+1;
        }
    }


    return orderNumbers[orderNumbers.size() - 1] + 1;
}

int main(){

    vector<int> array = {};
    
    int answer = findSmallestMissingPositive(array);
    cout << answer << endl;

    return 0;
}