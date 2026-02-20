#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> map = {};
        set<vector<int>> solution = {};

        // sort(nums.begin(), nums.end())

        for(int i = 0; i < (int)nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                map[nums[i]].push_back(i);
            }else{
                map.insert({nums[i], {i}});
            }
        }

        for(int i = 0; i < (int)nums.size(); i++){
            int x = nums[i];
            
            for(int j = i+1; j < (int) nums.size(); j++){

                int y = nums[j];
                int z = (-1)*(x+y);
                if(map.find(z) != map.end()){

                    vector<int> result = {x, y, z};
                    sort(result.begin(), result.end());
                    
                    if(z == x || z == y){
                        if(map[z].size() > 2){
                            //use unordered set with custom hash function for O(n^2) overall complexity
                            solution.insert(result); 
                        }
                    }else{
                        solution.insert(result);
                    }

                }


            }

        }
    
        
        return vector(solution.begin(), solution.end());
    }
};