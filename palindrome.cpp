#include<iostream>
using namespace std;

class Solution {
public:
    bool ispalindrome(int n) {
        int num=n;
        int rev=0;
        while(n!=0)
        {
            rev = rev * 10 + n%10 ;
            n = n/10;
        }
        if(rev==num)
            return true;
        
        return false;
    }
};

int main (){
    Solution s;
    int k = s.ispalindrome(121000);
    cout<<k;
    return 0;
}