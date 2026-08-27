class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
    int longest = 0;
    set<int> set;

    for(auto num: nums){
        set.insert(num);
    }

    for(int x: set){

        if(set.find(x-1) == set.end()){

            int currNum = x;
            int currLen = 1;

            while(set.find(currNum+1) != set.end()){
                currNum++;
                currLen++;
            }
            longest = max(longest, currLen);
        }
    }
        return longest;
    }
};