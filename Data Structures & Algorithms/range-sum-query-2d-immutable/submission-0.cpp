#include <vector>

using namespace std; 

class NumMatrix {

private: 
    int rows; 
    int cols;
    vector<vector<int>> prefix; 

public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        // (N + 1) X (M + 1) init to 0
        prefix.assign(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i+1][j+1] = matrix[i][j] 
                                    + prefix[i+1][j] // left rectangle
                                    + prefix[i][j+1] // top rectangle
                                    - prefix[i][j]; // exclude the topleft
            }
        }    
    }
    

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] 
            - prefix[row2+1][col1] // left rectangle
            - prefix[row1][col2+1] // top rectangle
            + prefix[row1][col1]; // exclude the topleft
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */