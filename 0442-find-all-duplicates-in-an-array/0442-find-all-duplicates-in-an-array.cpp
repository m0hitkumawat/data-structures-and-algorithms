class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        
        map<int, int> map;
        vector<int> ans;
        for(auto i: arr)
            map[i]++;
        
        for(auto mp: map){
            if(mp.second == 2){
                ans.push_back(mp.first);
            }
        }
        return ans;
    }
};