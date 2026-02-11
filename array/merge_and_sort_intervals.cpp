/*
Merge and Sort Intervals
Given an array of intervals [startTime, endTime], merge all overlapping intervals
and return a sorted array of non-overlapping intervals.


Example:-

Input:
intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]

Output: [[1, 6], [8, 10], [15, 18]]

Explanation:
- Step 1: Sort intervals by start time (already sorted). 
- Step 2: Initialize merged list with first interval [1,3]. 
- Step 3: Compare [2,6] with last merged [1,3]. They overlap (2 ≤ 3), so merge into [1,6]. 
- Step 4: Compare [8,10] with last merged [1,6]. No overlap (8 > 6), append [8,10]. 
- Step 5: Compare [15,18] with last merged [8,10]. No overlap (15 > 10), append [15,18]. 

Result: [[1,6],[8,10],[15,18]].
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

void printIntervals(vector<vector<int>> intervals){
    cout << "[";
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < intervals[i].size(); j++)
        {
            cout << intervals[i][j]  << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}


//Main Solution
vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
    
    if(intervals.empty()){
        return {};
    }
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);


    for(size_t i = 1; i < intervals.size(); ++i){
        if(intervals[i][0] <= result.back()[1]){
            //There is an overlap
            if(intervals[i][1] > result.back()[1]){
                result.back()[1] = intervals[i][1];
            }
        }else{
            //There is NOT an overlap
            result.push_back(intervals[i]);
        }
    }


    return result;

}



int main()
{

//  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals = {{1,10}, {2,3}, {4,5}, {6,7}};

    vector<vector<int>> result = mergeHighDefinitionIntervals(intervals);


    printIntervals(result);

    return 0;

}