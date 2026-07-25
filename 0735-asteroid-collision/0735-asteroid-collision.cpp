class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> stk;

        for(auto num: asteroids){

            while(!stk.empty() && num<0 && stk.top()>0){

                int sum = num + stk.top();
                if(sum<0){
                    stk.pop();
                }
                else if(sum > 0)
                    num = 0;
                else{
                    stk.pop();
                    num = 0;
                }
            }

            if(num != 0){
                stk.push(num);
            }
        }
        int s = stk.size();
        vector<int> result(s);

        int i = s-1;
        while(!stk.empty()){
            result[i] = stk.top();
            stk.pop();
            i--;
        }
        return result;
    }
};