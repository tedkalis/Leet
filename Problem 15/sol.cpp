class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //base case, less than 3 numbers in vector
        vector<vector<int>> output;
        if(nums.size() < 3){
            return output;
        }
        //sort, then for loop from 0 to size - 2
        std::sort(nums.begin(), nums.end());
        for(unsigned int i = 0 ; i < nums.size() - 2 ; ++i){
            if(nums[i] > 0){ //sum cannot be 0 if all 3 numbers are positive
                break;
            }
            if(i == 0 || nums[i] != nums[i-1]){ //skips duplicates
                int start = i + 1;
                int end = nums.size() - 1;
                int target = 0 - nums[i];
                while(start < end){
                    int curr = nums[start]+nums[end];
                    if(curr < target){
                        start++;
                    }
                    else if(curr > target){
                        end--;
                    }
                    else{
                        output.push_back(vector<int> {nums[i], nums[start++], nums[end--]});
                        while(nums[start] == nums[start-1] && start < end){
                            start++;
                        }
                        while(nums[end] == nums[end+1] && start < end){
                            end--;
                        }
                    }
                }
            }
        }
        return output;
    }
};