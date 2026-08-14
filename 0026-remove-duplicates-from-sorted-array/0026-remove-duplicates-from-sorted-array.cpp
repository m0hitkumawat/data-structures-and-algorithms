class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // if(nums.size() == 1)
        //     return 1;

        int i = 0;
        // int j = 1;
        int n = nums.size();

        for(int j=1; j<n; j++){

            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};