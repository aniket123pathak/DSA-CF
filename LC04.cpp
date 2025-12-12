#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.00000;
        }
        if(n<0){
            x=1.00000/x;
            n=abs(n);
        }
        
        long double ans = myPow(x,n/2);
        long double finalAns = ans * ans;

        if(n%2!=0){
            return x*finalAns;
        }
        return finalAns;
    }
};
