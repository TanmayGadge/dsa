/*
Check Palindrome by Filtering Non-Letters
Given a string containing letters, digits, and symbols, determine if it reads the same forwards and backwards when considering only alphabetic characters (case-insensitive).

Example

Input:
code = A1b2B!a

Output:
1

Explanation
- Step 1: Extract only letters → ['A','b','B','a'] 
- Step 2: Convert to lowercase → ['a','b','b','a'] 
- Step 3: Compare sequence forward and backward: 'abba' == 'abba' → true
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool isAlphabeticPalindrome(string code) {

    vector<char> letters = {};
    bool is_palindrome = true;

    //Extract Letters
    for(int i = 0; i < code.size(); i++){
        if(isalpha(code[i])){
            letters.push_back(tolower(code[i]));
        }
    }


    int i = 0, j = letters.size() - 1;

    while(i < j){
        if(letters[i] != letters[j]){
            is_palindrome = false;  
            break; 
        }
        i++;
        j--;
    }

    return is_palindrome;

}

int main(){

    string code = "A1b2B!a";

    cout << isAlphabeticPalindrome(code) << endl;

    return 0;
}