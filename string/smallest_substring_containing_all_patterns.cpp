/*
Given a string S and an array of patterns, find the smallest substring window [l, r] such that each pattern appears at least once within S[l..r]. Return the pair of indices or [-1, -1] if no such window exists.

Example

Input:
S = xyzabcabczyx
patterns = ['abc', 'zyx']

Output:
[6,11]

Explanation:
- Identify occurrences of 'abc' at indices [3..5] and [6..8], and 'zyx' at [9..11]. 
- Combining the second 'abc' ([6..8]) with 'zyx' ([9..11]) yields the window [6,11] of length 6, which is shorter than the alternative 
[3,11], so the result is [6,11].
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> findSmallestSubstringWindow(vector<string> patterns, string S) {
    
    vector<vector<int>> intervals = {};
    
    for(int i = 0; i < (int)patterns.size(); i++){

        int window_size = patterns[i].length();

        int start = 0;
        int end = start + (window_size - 1);

        while(end < (int)S.length()){

            string sub_string = S.substr(start, window_size);
    
            if(sub_string == patterns[i]){
                intervals.push_back({start, end, i});
            }

            start++;
            end++;

        }
        
    }
    
    sort(intervals.begin(), intervals.end());

    int start = intervals.size() - 1;
    int end = start - 1; //window size is 2

    if(intervals[0][0] == 0 && intervals[0][1] == 0 && intervals.size() == 1){
        return {0,0};
    }


    while(end >= 0){
        if(intervals[start][2] != intervals[end][2]){
            return {intervals[end][0], intervals[start][1]};
        }
        end--;
        start--;
    }
    
    return {-1, -1};
}


int main(){

    string S = "xyzabcabczyx";
    vector<string> patterns = {"abc", "zyx"};

    vector<int> result = findSmallestSubstringWindow(patterns, S);
    for(int x: result){
        cout << x << " ";
    }

    return 0;
}