class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        /*
        //Iteratin 1:
        [2,7,11,15], target = 9
         i       j
        sum = 15 + 2 = 17
        17(sum) > 9(tar) --> means sum jyada ho raah hai tho thoda chota number add kar:
        Therefore.. we move j to j --

        //Iteration 2:
        [2,7,11,15], target = 9
         i    j
        sum = 11 + 2 = 13
        13(sum) > 9(target) --> means abhi bhi mera sum jho hai wo mere target se badda hai --> mtlb merko or chota number add karna hoga!! 
        Or chota number right se ek kam jaane par milega --> means j = j--;

        //Iteration 3:
         [2,7,11,15], target = 9
          i j
        sum = 7 + 2 = 9
        9(sum) == 9 (target) --> return kardo
        */

        int n = arr.size();
        int i = 0;
        int j = n-1;

        while(i < j){

            int sum = arr[i] + arr[j];
            if(sum == target)   return {i+1, j+1};

            if(sum > target)    j--;
            else    i++;
        }
        return {};
    }
};