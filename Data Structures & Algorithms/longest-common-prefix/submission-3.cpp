// 1st solution

// struct Node {
//     Node* next; 
//     char c; 
//     bool isEnd;
    
//     // member init list // data and next are auto default constuct
//     // avoid double init => single step direcrtl from argument
//     Node(char c) : next(nullptr), c(c), isEnd(false) {} 
// };

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         // construct graph, dealloc as we move onn
//         if (strs.empty()) return "";

//         // 1. Processes base string
//         Node* sentinel = new Node('0');
//         Node* ptr = sentinel;
//         for (char c: strs[0]) {
//             ptr->next = new Node(c);
//             ptr = ptr->next; 
//         }
        
//         // 2. Truncate on other strings based on size and mis-match
//         for (size_t i = 1; i < strs.size(); ++i) {
//             Node *ptr = sentinel; 
//             for (char c: strs[i]) {
//             if (!ptr->next || ptr->next->c != c) {
//                     if (ptr->next) {
//                         ptr->next = nullptr;
//                     }
//                     break;

//                 }   
//                 ptr = ptr->next;
//             }
//     // If the base string is longer than current stirng => cut it 
//             if (ptr->next) {
//                 ptr->next = nullptr;
//             }
//         }

//         // Output strings
//         string s = "";
//         sentinel = sentinel->next;
//         while (sentinel) {
//             s += sentinel->c;
//             sentinel = sentinel->next;   
//         }
//         return s;
//     }
// };

// 2nd solution (C++ Optimized)
#include <vector>
#include <string> 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (size_t i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];

            for (size_t j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }   
            }
        } 

        return strs[0];
    }
};