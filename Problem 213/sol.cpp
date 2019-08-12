class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){ //base case of size 0, no houses to rob, return 0
            return 0;
        }
        if(nums.size() == 1){ //1 house to rob, return that house's monetary value
            return nums[0];
        }
        else{ //for more than 1 house
            int lootcount1 = 0; //initialize lootcounts
            int lootcount2 = 0;
            for(unsigned int i = 0; i < nums.size() - 1; ++i){ //look at every house except the last 1
                int temp = lootcount1; //make the old max loot equal to temp
                lootcount1 = lootcount2 + nums[i] > lootcount1 ? lootcount2+nums[i] : lootcount1; //set lootcount1 to new max loot
                lootcount2 = temp; //store old max loot in lootcount2
            }
            int max1 = lootcount1; //max loot of houses 0 to N-1 is now equal to max 1
            lootcount1 = 0; //reset lootcount 1 and 2
            lootcount2 = 0;
            for(unsigned int i = 1; i < nums.size(); ++i){ //same algorithm for every house except the first 1
                int temp = lootcount1; 
                lootcount1 = lootcount2 + nums[i] > lootcount1 ? lootcount2+nums[i] : lootcount1;
                lootcount2 = temp;
            }
            return max1 > lootcount1 ? max1 : lootcount1; //return which of the two runthroughs had the most loot
        }
    }
};