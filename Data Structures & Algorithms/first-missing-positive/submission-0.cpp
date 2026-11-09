#include <vector>
#include <unordered_set> 
using namespace std; 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // UF them 
        // go through key in sorted order (nlogn); not sufficient 


        // obseravtion output range: (1, len(nums) + 1)
        // the length is 10**6 
        // but b-search solution, needs sorted which is nlogn, bc arr isn't sorted 
        
        // for i in range(1, len + 2): 
        // on the set(nums) => O(N)

        // idea: use extra memory to O(1) using input as extra memoery 
        // how to use an arr as an hashset? 
        // arr[indx] -> to values 
        // each of values has an index to input arr 
        
        // value - 1 = idx of location
        // at this negatives indicate true 
        // but negative numbers in the arr! 
            // => it doesn't matter, get rid of it! (i.e. change it to 0, so it doesnt' affect postivie and negative to indicate)


        // 1st iteration
            // mark negatives as 0 
        // 2nd iteration

        // 3rd iteration
        

    }
};