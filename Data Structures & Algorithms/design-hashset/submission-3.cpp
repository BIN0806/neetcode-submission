#include <vector> 

using namespace std;
class Node {
    public: 
        int key; 
        Node* next;

        Node(int k) {
            key = k;
            next = nullptr;
        }
};

class MyHashSet {
    private:
        vector<Node*> nodes;

    public:
        MyHashSet() {
            nodes.resize(10000, nullptr);
        }
        
       void add(int key) {
            int index = key % nodes.size();
            Node* cur = nodes[index];
            if (!cur) {
                nodes[index] = new Node(key);
                return;
            }

            while (cur) {
                if (cur->key == key) {
                    return;
                }
                if (!cur->next) {
                    break;
                }
                cur = cur->next;
            }
            cur->next = new Node(key);
        }
        
        void remove(int key) {
            int index = key % nodes.size();
            Node* cur = nodes[index];
            Node* prev = nullptr;

            while (cur) {
                if (cur->key == key) {
                    if (prev) {
                        prev->next = cur->next;
                    } else {
                        nodes[index] = cur->next;
                    }

                    delete cur; // free it's memory after disconnecting
                    return;
                }

                prev = cur;
                cur = cur->next;
            }
        }
        
        bool contains(int key) {
            int index = key % nodes.size();
            Node* cur = nodes[index];

            while (cur) {
                if (cur->key == key) {
                    return true;
                }
                cur = cur->next;
            }
            return false;
        }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */