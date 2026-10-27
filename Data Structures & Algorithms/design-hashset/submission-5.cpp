#include <vector> 
using namespace std;

// Even more optimal given the constraints 

#include <array>
#include <cstdint>
class MyHashSet {
    private:
        alignas(64) std::array<uint64_t, 15626> bits {}; 

    public:
        constexpr MyHashSet() noexcept = default;

        inline void add(int key) noexcept {
            bits[key >> 6] |= (1ULL << (key & 63));
        }

        inline void remove(int key) noexcept {
            bits[key >> 6] &= ~(1ULL << (key & 63));
        }

        inline bool contains(int key) const noexcept {
            return (bits[key >> 6] & (1ULL << (key & 63))) != 0;
        }
}

// Optimal 
// struct Node {
//     public: 
//         int key; 
//         Node* next;
//         Node(int k, Node* n = nullptr) : key(k), next(n) {}
// };

// class MyHashSet {
//     private:
//         static constexpr int BUCKET_SIZE = 10007; // prime reduces collisions
//         vector<Node*> nodes;

//         int hash(int key) const {
//             return key % BUCKET_SIZE;
//         }

//     public:
//         MyHashSet() : nodes(BUCKET_SIZE, nullptr) {}
        
//        void add(int key) {
//             Node** cur = &nodes[hash(key)];
//             while (*cur) {
//                 if ((*cur)->key == key) return;
//                 cur = &((*cur)->next);
//             }
//             *cur = new Node(key); // directly attaches to bucket head or mem location of last nodes->next
//         }
        
//         void remove(int key) {
//             Node** cur = &nodes[hash(key)];
//             while (*cur) {
//                 if ((*cur)->key == key) {
//                     Node* toDelete = *cur;
//                     *cur = (*cur)->next; //
//                     delete toDelete; // free it's memory after disconnecting
//                     return;
//                 }
//                 cur = &((*cur)->next);
//             }
//         }
        
//         bool contains(int key) const {
//             Node* cur = nodes[hash(key)];

//             while (cur) {
//                 if (cur->key == key) {
//                     return true;
//                 }
//                 cur = cur->next;
//             }
//             return false;
//         }
// };



// // Naive:
// class Node {
//     public: 
//         int key; 
//         Node* next;

//         Node(int k) {
//             key = k;
//             next = nullptr;
//         }
// };

// class MyHashSet {
//     private:
//         vector<Node*> nodes;

//     public:
//         MyHashSet() {
//             nodes.resize(10000, nullptr);
//         }
        
//        void add(int key) {
//             int index = key % nodes.size();
//             Node* cur = nodes[index];
//             if (!cur) {
//                 nodes[index] = new Node(key);
//                 return;
//             }

//             while (cur) {
//                 if (cur->key == key) {
//                     return;
//                 }
//                 if (!cur->next) {
//                     break;
//                 }
//                 cur = cur->next;
//             }
//             cur->next = new Node(key);
//         }
        
//         void remove(int key) {
//             int index = key % nodes.size();
//             Node* cur = nodes[index];
//             Node* prev = nullptr;

//             while (cur) {
//                 if (cur->key == key) {
//                     if (prev) {
//                         prev->next = cur->next;
//                     } else {
//                         nodes[index] = cur->next;
//                     }

//                     delete cur; // free it's memory after disconnecting
//                     return;
//                 }

//                 prev = cur;
//                 cur = cur->next;
//             }
//         }
        
//         bool contains(int key) {
//             int index = key % nodes.size();
//             Node* cur = nodes[index];

//             while (cur) {
//                 if (cur->key == key) {
//                     return true;
//                 }
//                 cur = cur->next;
//             }
//             return false;
//         }
// };

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */