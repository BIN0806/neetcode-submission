#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std; 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = board.size();
        int M = board[0].size();

        map<pair<int, int>, unordered_set<char>> square_map_to_set;
        unordered_map<int, unordered_set<char>> col_map_to_set;
        unordered_map<int, unordered_set<char>> rol_map_to_set;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (board[i][j] == '.') {continue;}

                if (rol_map_to_set[i].contains(board[i][j])) {return false;}    
                rol_map_to_set[i].insert(board[i][j]);

                if (col_map_to_set[j].contains(board[i][j])) {return false;}    
                col_map_to_set[j].insert(board[i][j]);    
     
                int box_row = i / 3;
                int box_col = j / 3;
                if (square_map_to_set[{box_row, box_col}].contains(board[i][j])) {return false;}    
                square_map_to_set[{box_row, box_col}].insert(board[i][j]);                
            }
        }
        return true;
    }
};
