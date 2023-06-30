// Intuition
// Two pointer

// Approach
// Use Two pointer one that will say what number it need and another will fill according to it

// Complexity
// Time complexity: O(N)
// Space complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        // we only need to use 1 or 2 so 1 or 2 can come either together or single
        // 1 , 11, 22,
        // if we need 2 at second string then we need to add 2 came char but not same with last index 
        // and if we need 1 at second string then we will add 1 diff char then previous one in 
        if(n < 4) return 1;
        vector<char> s(n+1,'1');
        s[1] = s[2] = '2';
        int ans = 0;
        int need = 2, cur = 3;
        while(cur < n){
            if(s[need] == '2'){
                s[cur] = s[cur+1] = (s[cur-1] == '2' ) ? '1' : '2';
                cur += 2; 
            }else{
                s[cur] = (s[cur-1] == '2' ) ? '1' : '2';
                cur++;
            }
            need++;
        }
        for(int i=0;i<n;i++) if(s[i] == '1') ans++;
        return ans;
    }
};