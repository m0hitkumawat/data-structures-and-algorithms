class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();

        //left and right ax ke liye array bnaya hai
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        //leftMax waala array complete krna:
        for(int i=1; i<n; i++){
            left[i] = max(arr[i-1], left[i-1]);
        }

        //similalry, rightMax fill krna hai
        for(int i=n-2; i>=0; i--){
            right[i] = max(arr[i+1], right[i+1]);
        }

        //aab meko count dhekna hai har index par jaake
        // or building minus krna hai!!
        int count = 0;
        for(int i=1; i<n-1; i++){

            //kitna store hoga or uska cond kya hoga:
            if(left[i] > arr[i] && right[i] > arr[i]){
                count += min(left[i], right[i]) - arr[i];
            }
        }
        return count;
    }
};