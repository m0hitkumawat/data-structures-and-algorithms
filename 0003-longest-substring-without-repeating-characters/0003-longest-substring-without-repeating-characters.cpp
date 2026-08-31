class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longest = 0;
        int n = s.length();
        vector<bool> visited(256,false);

        int l = 0;
        int r = 0;

        while(r<n){

            //checking: if I'm visited to this char or not?
            while(visited[s[r]]){
                visited[s[l]] = false;
                l++;
            }
            
            visited[s[r]] = true;
            longest = max(r-l+1, longest); 
            r++;
        }
        return longest;
    }
};