#include<iostream>
using namespace std;

class Solution {
public:
    bool isamstrong(int n) {
        int num=n;
        int sum=0;
        while(n!=0)
        {
            sum += (n%10)*(n%10)*(n%10);
            n=n/10;
        }
        if(num==sum)
            return true;
        
        return false;
    }
};

int main (){
    Solution s;
    int k = s.isamstrong(370);
    cout<<k;
    return 0;
}