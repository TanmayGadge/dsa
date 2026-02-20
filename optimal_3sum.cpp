#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{

    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            
            vector<vector<int>> ans = {};
            sort(nums.begin(), nums.end());

            int n = (int)nums.size();

            for(int i = 0; i < n; i++){
                int j = i + 1;
                int k = n - 1;

                if(i != 0){
                    if(nums[i] == nums[i-1]) continue;
                }

                while(j < k){

                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){ 
                        ans.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;

                        if(j >= k) break;
                        
                        
                        while(nums[j] == nums[j - 1]){
                            if(j == k) break;
                            j++;
                        }
                        

                        if(k <= j) break;

                        if(k != n - 1){
                            while(nums[k] == nums[k + 1]){
                               k--;
                            }
                        }

                    }else{
                        if(sum < 0){
                            j++;
                        }else{
                            k--;
                        }
                    }
                    
                }
            }

            return ans;
        }
};



