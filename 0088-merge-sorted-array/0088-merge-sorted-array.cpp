class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> ans;
        int i=0;
        int j=0;

        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
            
        }
        while(m>i)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(n>j)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        for(int i=0; i<ans.size(); i++)
            nums1[i]=ans[i];
    }   
};