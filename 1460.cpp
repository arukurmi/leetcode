// 1460. Make Two Arrays Equal by Reversing Subarrays

// Fairly easy problem. Simple logic

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());
        return arr == target;
    }
};