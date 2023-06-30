// Complexity
// Time complexity:Depends on the number of factors of 5 in n.

// Space complexity:O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        while(n){
            n/=5;
            cnt+=n;
        }
        return cnt;
    }
};