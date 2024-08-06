// 2053. Kth Distinct String in an Array
// Very simple yet I got stuck. thought of faltu ka complex logic!

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;

        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(string str:arr){
            if(mp[str] == 1){
                k--;
            }
            if(k==0){
                return str;
            }
        }

        return "";
    }
};