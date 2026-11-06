#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std; 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> box_map;
        unordered_map<int, unordered_set<char>> col_map;
        unordered_map<int, unordered_set<char>> row_map;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {continue;}

                int box_id = (i / 3) * 3 + (j / 3);
                if (!row_map[i].insert(c).second ||       !col_map[j].insert(c).second || 
                    !box_map[box_id].insert(c).second) {
                    return false;    
                }
            }
        }
        return true;
    }
};
