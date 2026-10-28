#include <vector>
using namespace std; 

struct Node {
    public:
        int key; 
        int value;
        Node* next;

        Node(int k, int v, Node* n = nullptr): key(k), value(v), next(n) {};
};

class MyHashMap {

    private: 
        int BUCKET_SIZE = 10007;
        vector<Node*> nodes;

        int hash(int key) const {
            return key % BUCKET_SIZE; 
        } 
        
    public:
        MyHashMap() : nodes(BUCKET_SIZE, nullptr) {};
        
        void put(int key, int value) {
            Node** cur = &nodes[hash(key)];
            while (*cur) {
                if ((*cur)->key == key) {
                    (*cur)->value = value;
                    return; 
                }
                cur = &((*cur)->next);
            }
            (*cur) = new Node(key, value);
        }
        
        int get(int key) {
            Node** cur = &nodes[hash(key)];
            while (*cur) {
                if ((*cur)->key == key) {
                    return (*cur)->value; 
                }
                cur = &((*cur)->next);
            }
            return -1;
        }
        
        void remove(int key) {
            Node** cur = &nodes[hash(key)];
            while (*cur) {
                if ((*cur)->key == key) {                    
                    Node* toDelete = (*cur);
                    (*cur) = (*cur)->next;

                    delete toDelete;
                    return; 
                }
                cur = &((*cur)->next);
            }
        }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */