/*
Max Unique Substring Length in a Session
Given a string of lowercase letters with sessions separated by '' characters, find the maximum length of a substring with all distinct letters within any single session.

Example

Input:
sessionString = abcabcbb

Output:
3

Explanation:
- There is only one session: "abcabcbb". 
- Scanning with a sliding window for distinct letters, the longest substrings without repeats are "abc", "bca" and so on, each of length 3. 
- Therefore, the result is 3.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int maxDistinctSubstringLengthInSessions(string sessionString) {

    int start = 0;
    int window_size = sessionString.size();
    int end = start + window_size;

    
    // vector<char> letters = {};
    
    // while( (start < end) & (end < sessionString.size()) ){

    //     bool contains_flag = false;
        
    //     //Check if the letter has repeated
    //     if(!letters.empty()){

    //         for(char x: letters){
    //             if(sessionString[end] == x){
    //                 end--;
    //                 continue;
    //                 // start++;
    //                 // contains_flag = true;
    //                 // break;
    //             }
    //             letters.push_back(sessionString[end]);
    //         }
            
    //     }else{
    //         letters.push_back(sessionString[end]);
    //         end--;
    //     }
    // }

/*
    while(window_size > 0){
        string sub_string = sessionString.substr(window_size);

        int i = 0; 
        bool repeated_letters = false;

        while(i < sub_string.size()){
            
            int j = i + 1;
            while(j < window_size){

                if(sub_string[i] == sub_string[j]){
                    repeated_letters = true;
                    break;
                }else{
                    j++;
                }

            }

            if(repeated_letters){
                window_size--;
                break;
            }
            i++;
        }

    }

*/

    vector<int> freq(26, 0);
    int left = 0, right = 0;
    int maxLen = 0;

    while(right < sessionString.size()){
        char c = sessionString[right];
        freq[c - 'a']++;

        while(freq[c - 'a'] > 1){
            freq[sessionString[left] - 'a']-- ;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
    
}

int main(){

   string sessionString = "abcabcbb";
   int length = maxDistinctSubstringLengthInSessions(sessionString);

   cout << length << endl;

    return 0;
}