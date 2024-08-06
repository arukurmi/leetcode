// 3016. Minimum Number of pushes to type word

// fairly easy problem. Simple logic.


class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(int i=0; i<word.length(); i++){
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<>());

        int res = 0;

        for(int i=0; i<8; i++){
            res+=freq[i];
        }
        for(int i=8; i<16; i++){
            res+=2*freq[i];
        }
        for(int i=16; i<24; i++){
            res+=3*freq[i];
        }
        for(int i=24; i<26; i++){
            res+=4*freq[i];
        }

        return res;
    }
};