class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(!root){ //if root doesn't exist, then return an empty 2-d vector
            return ret;
        }
        vector<int> currNums; //create variables for current numbers in the current path
        vector<TreeNode*> currPath; //current path
        currPath.push_back(root); //root is always in the current path
        currNums.push_back(root->val); //root's value is in every path
        std::stack<TreeNode*> dfs; //create a stack for the DFS
        if(root->left){ //if root's left child exists, add to DFS
            dfs.push(root->left);  
        }
        if(root->right){ //if root's right child exists, add to DFS
            dfs.push(root->right);
        }
        if(dfs.empty() && sum == root->val){ //if there's nothing in the stack, AKA the root has no children, if root->val = sum return that
            ret.push_back(currNums); //this means the root is also a leaf since there's no children
            return ret;
        }
        while(!dfs.empty()){ //while the dfs is not empty, which means we haven't looked at all paths yet
            TreeNode* curr = dfs.top(); //obtain the top of the stack
            dfs.pop(); //pop the top off the stack
            while(currPath[currPath.size() - 1]->left != curr && currPath[currPath.size() - 1]->right != curr){
                currPath.pop_back(); //if the top of stack is not part of the current path, remove the last element
                currNums.pop_back(); //of the current paths until we obtain a valid path (Look at figures for clearer explanation)
            }
            currPath.push_back(curr); //add current val to path
            currNums.push_back(curr->val);
            if(!curr->left && !curr->right && sum == pSum(currNums)){ //if our path is complete (root to leaf) and it equals the sum
                ret.push_back(currNums); //add to output, remove last element from path
                currPath.pop_back();
                currNums.pop_back();
            }
            else if(!curr->left && !curr->right){
                currPath.pop_back(); //if we have a root to leaf complete path but the sum does not equal the target
                currNums.pop_back(); //just remove last element
            }
            else if(!curr->left){ //here we add to the stack, if left doesn't exist, push the right
                dfs.push(curr->right);
            }
            else if(!curr->right){ //if right doesn't exist, push left
                dfs.push(curr->left);
            }
            else{       //push both if we make it here, they both exist
                dfs.push(curr->left);
                dfs.push(curr->right);

            }
            
        }
        return ret; //return the output vector of paths
    }
    
    int pSum(vector<int>& nums){ //function to obtain sum of the current path vector
        int s = 0;
        for(auto i : nums){
            s+=i;
        }
        return s;
    }
    
};