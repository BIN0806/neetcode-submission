// 1st solution

struct Node {
    Node* next; 
    char c; 
    bool isEnd;
    
    // member init list // data and next are auto default constuct
    // avoid double init => single step direcrtl from argument
    Node(char c) : next(nullptr), c(c), isEnd(false) {} 
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // construct graph, dealloc as we move onn
        if (strs.empty()) return "";

        Node* sentinel = new Node('0');
        Node* ptr = sentinel;
        for (char c: strs[0]) {
            ptr->next = new Node(c);
            ptr = ptr->next; 
        }

        for (size_t i = 1; i < strs.size(); ++i) {
            Node *ptr = sentinel; 
            for (char c: strs[i]) {
            if (!ptr->next || ptr->next->c != c) {
                    if (ptr->next) {
                        ptr->next = nullptr;
                    }
                    break;

                }   
                ptr = ptr->next;
            }
        
            if (ptr->next) {
                ptr->next = nullptr;
            }
        }


        string s = "";
        sentinel = sentinel->next;
        while (sentinel) {
            s += sentinel->c;
            sentinel = sentinel->next;   
        }
        return s;
    }
};

// 2nd solution (C++ Optimized)