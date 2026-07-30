class Solution {
public:

    vector<int> nextSmallest(vector<int>& arr){

        //vector creatio to store answer i.e. indexes
        vector<int>ans;

        // and then stack create krenge or usme -1 insert kr denge taaki compare kar sakke!
        stack<int>s;
        s.push(-1);

        for(int i=arr.size()-1; i>=0; i--){

            //kab tk loop chlega??
            //jab tk stack empty na ho ya fhir top ka element badda ho
            while(!s.empty() && s.top() != -1 && arr[s.top()] >= arr[i]){
                //pop krte jaana hai
                s.pop();
            }
            //ham yaha tak aaye hai mtlb ki top par uss se chota element hai..
            ans.push_back(s.top());

            //now stack me tho hamme curr insert krna hi hotahai...but kyu??
            //bcz ye maybe kissi or ka answer ho
            s.push(i);  //storing 'i' index!!
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> prevSmallest(vector<int>& arr){

        //vector creatio to store answer i.e. indexes
        vector<int>ans;

        // and then stack create krenge or usme -1 insert kr denge taaki compare kar sakke!
        stack<int>s;
        s.push(-1);

        for(int i=0; i<arr.size(); i++){

            //kab tk loop chlega??
            //jab tk stack empty na ho ya fhir top ka element badda ho
            while(!s.empty() && s.top() != -1 && arr[s.top()] > arr[i]){
                //pop krte jaana hai
                s.pop();
            }
            //ham yaha tak aaye hai mtlb ki top par uss se chota element hai..
            ans.push_back(s.top());


            //now stack me tho hamme curr insert krna hi hotahai...but kyu??
            //bcz ye maybe kissi or ka answer ho
            s.push(i);  //storing 'i' index!!
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        
        //creating next and prev vector to store indexes..
        //indexes of smallest elemt in array...so tham possible substring ban aaye
        vector<int>next = nextSmallest(arr);
        vector<int>prev = prevSmallest(arr);

        long long sum = 0;

       //iterate krna hai har ek elemt par
        for(int i=0; i<arr.size(); i++){

            //aab hamme ye dhekna hai ki har element kitni baar contribute krega!!
            int nexti = next[i] == -1 ? arr.size(): next[i];
            int previ = prev[i];

            //left and right me kitne element hai wo chek krna hai:
            int left = i - previ;
            int right = nexti - i;
            
            //aab check krenge kii kitni baar wo element min ban raha hoga:
            long long no_of_times = (left * right);

            //aab total sum calu krege:
            sum = (sum + no_of_times*arr[i]);
        }
        return sum;
    }

    vector<int> nextGreatest(vector<int>& arr){

        //vector creatio to store answer i.e. indexes
        vector<int>ans;

        // and then stack create krenge or usme -1 insert kr denge taaki compare kar sakke!
        stack<int>s;
        s.push(-1);

        for(int i=arr.size()-1; i>=0; i--){

            //kab tk loop chlega??
            //jab tk stack empty na ho ya fhir top ka element badda ho
            while(!s.empty() && s.top() != -1 && arr[s.top()] <= arr[i]){
                //pop krte jaana hai
                s.pop();
            }
            //ham yaha tak aaye hai mtlb ki top par uss se chota element hai..
            ans.push_back(s.top());

            //now stack me tho hamme curr insert krna hi hotahai...but kyu??
            //bcz ye maybe kissi or ka answer ho
            s.push(i);  //storing 'i' index!!
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> prevGreatest(vector<int>& arr){

        //vector creatio to store answer i.e. indexes
        vector<int>ans;

        // and then stack create krenge or usme -1 insert kr denge taaki compare kar sakke!
        stack<int>s;
        s.push(-1);

        for(int i=0; i<arr.size(); i++){

            //kab tk loop chlega??
            //jab tk stack empty na ho ya fhir top ka element badda ho
            while(!s.empty() && s.top() != -1 && arr[s.top()] < arr[i]){
                //pop krte jaana hai
                s.pop();
            }
            //ham yaha tak aaye hai mtlb ki top par uss se chota element hai..
            ans.push_back(s.top());


            //now stack me tho hamme curr insert krna hi hotahai...but kyu??
            //bcz ye maybe kissi or ka answer ho
            s.push(i);  //storing 'i' index!!
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        
        //creating next and prev vector to store indexes..
        //indexes of smallest elemt in array...so tham possible substring ban aaye
        vector<int>next = nextGreatest(arr);
        vector<int>prev = prevGreatest(arr);

        long long sum = 0;

       //iterate krna hai har ek elemt par
        for(int i=0; i<arr.size(); i++){

            //aab hamme ye dhekna hai ki har element kitni baar contribute krega!!
            int nexti = next[i] == -1 ? arr.size(): next[i];
            int previ = prev[i];

            //left and right me kitne element hai wo chek krna hai:
            int left = i - previ;
            int right = nexti - i;
            
            //aab check krenge kii kitni baar wo element min ban raha hoga:
            long long no_of_times = (left * right);

            //aab total sum calu krege:
            sum = (sum + no_of_times*arr[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        
        auto smallestSum = sumSubarrayMins(nums);
        auto largestSum = sumSubarrayMaxs(nums);

        return largestSum - smallestSum;
    }
};