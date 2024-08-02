// 2134. Minimum Swaps to Group All 1's Together II

// used hints to solve. but got it by myself.

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // count 1 and 0
        int one_count = 0;
        int zero_count = 0; // zero count is always minimum number of swaps.

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1) one_count++;
        }

        for(int j=0; j<one_count; j++){
            if(nums[j] == 0) zero_count++;
        }

        // if 0 and 1 are not adjacent, return -1
        int res = zero_count;
        nums.insert(nums.begin(), nums.begin(), nums.end()); // to remove circular condition

        for(int i=0; i<nums.size()-one_count; i++){
            if((nums[i] == 0 && nums[i+one_count] == 0) || (nums[i] == 1 && nums[i+one_count] == 1)) {
                continue;
            }
            else if(nums[i] == 0 && nums[i+one_count] == 1) { // if 0 is going out of our window
                zero_count--;
            }
            else { // if 0 is going into our window
                zero_count++;
            }
            res = min(res, zero_count); // res will be minimum of zero_count. 
        }

        return res;
    }
};


