// 273. Integer to English Words

// Mostly it's implementation based question. Hard problem but did it all by myself.
// Should also do it on your own. will get to know so many edge cases but 
// at the end when it get's fully subbmitted then it's very satisfying.

class Solution {
public:

    int getLT(int num){
        int one = num % 10;
        int ten = (num / 10) % 10;
        int hun = (num / 100) % 10;

        return hun*100+ten*10+one;
    }

    string recur(int num, vector<string> ones, vector<string> tens, vector<string> scale, int scaleV){

        if(num <= 0) return "";

        int lastThree = getLT(num);
        
        string res = "";
        string hunString = "";
        int hun;

        if(lastThree/100 > 0){
            hun = lastThree/100;
            hunString = ones[hun] + " Hundred";
        }

        int one = lastThree % 10;
        // lastThree/=10;
        int ten = (lastThree / 10) % 10;
        int lastTwo = ten*10+one;
        string lastTwoString = "";

        if(ten != 1 && ten != 0){
            // cout<< ten<< " one: " <<one;
            lastTwoString = one == 0 ? tens[ten] : tens[ten] + " " + ones[one];
        } else {
            lastTwoString = ones[lastTwo];
        }

        res = (hunString == "") ? (lastTwoString) : (lastTwoString == "" ? hunString : hunString + " " + lastTwoString);
        // cout<< lastThree << "   hun: " << hunString << " last " << lastTwoString;

        num/=1000;

        string withScale = scaleV == 0 ? res : (res == "" ? res : res + " " + scale[scaleV]);
        string pre = recur(num, ones, tens, scale, scaleV + 1);
        return pre != "" ? (withScale == "" ? pre : pre + " " + withScale) : withScale;
    }


    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> scale = {"", "Thousand", "Million", "Billion", "Trillion" };

        string res = recur(num, ones, tens, scale, 0);

        return res;
    }
};