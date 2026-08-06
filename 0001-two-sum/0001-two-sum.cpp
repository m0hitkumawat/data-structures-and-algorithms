class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        int n = arr.size();
        unordered_map<int, int> map;

        //map banaya me..
        //key   :   value
        //actual no : index
        for(int i=0; i<n; i++){
            map[arr[i]] = i;
        }

        for(int i=0; i<n; i++){

            int com = target - arr[i];
            if(map.count(com) && map[com] != i){
                return {i, map[com]};
            }
        }
        return {};
    }
};