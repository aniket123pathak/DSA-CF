#include<iostream>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        int rev=0;
        int rem=0;
        while(n!=0)
        {
            rem = n%10;
            rev = rev * 10 + rem ;
            n = n/10;
        }
        return rev;
    }
};

int main (){
    Solution s;
    int k = s.reverseNumber(30100);
    cout<<k;
    return 0;
}

