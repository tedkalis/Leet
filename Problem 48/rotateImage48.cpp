class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int maxRot = matrix.size()/2;
        int rotations = 0;
        while(rotations <= maxRot){
            for(unsigned int i = rotations ; i < matrix[i].size() - rotations - 1 ; ++i){
                if(i == rotations){ //for corners of squares
                    int temp = matrix[rotations][matrix[i].size() - 1 - rotations];
                    matrix[rotations][matrix[i].size() - 1 - rotations] = matrix[rotations][rotations];
                    int temp2 = matrix[matrix.size() - 1 - rotations][matrix.size() - 1 - rotations];
                    matrix[matrix.size() - 1 - rotations][matrix.size() - 1 - rotations] = temp;
                    temp = matrix[matrix.size() - 1 - rotations][rotations];
                    matrix[matrix.size() - 1 - rotations][rotations] = temp2;
                    matrix[rotations][rotations] = temp;
                }
                else{ //non corners
                    int temp = matrix[i][matrix[i].size() - 1 - rotations];
                    matrix[i][matrix[i].size() - 1 - rotations] = matrix[rotations][i];
                    int temp2 = matrix[matrix[i].size() - 1 - rotations][matrix[i].size() - 1 - i];
                    matrix[matrix[i].size() - 1 - rotations][matrix[i].size() - 1 - i] = temp;
                    temp = matrix[matrix.size() - 1 - i][rotations];
                    matrix[matrix.size() - 1 - i][rotations] = temp2;
                    matrix[rotations][i] = temp;
                }
            }       
            rotations++;
        }
    }
};