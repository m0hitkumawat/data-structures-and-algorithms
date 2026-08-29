class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int lsum = 0;
        int rsum = 0;
        int n = nums.size()-1;

        int maxSum = 0;

        // first ka size ka window bana liya
        for(int i=0; i<k; i++)
            lsum += nums[i];

        maxSum = lsum;

        for(int i=k-1; i>=0; i--){

            lsum -= nums[i];
            rsum += nums[n--];

            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};