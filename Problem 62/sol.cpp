class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> memo(n, 1); //memo vector, with row size
        for(int i = 1; i < m ; ++i){ //for all spaces in the rectangle except the first row/column
            for(int j = 1; j < n ; ++j){
                memo[j] += memo[j-1]; //update the memoization value to be the above value + the left value (Figure 2)
            }
        }
        return memo[n-1]; //return the last value calculated aka #of ways to reach bottom right space
    }
};