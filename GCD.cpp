#include<iostream>
using namespace std;

class Solution {
public:
    int GCD(int n1,int n2) {
        int big,small,i;
        int gcd = 1 ;
        if(n1>n2)
        {
            big=n1;
            small=n2;
        }
        else{
            big=n2;
            small=n1;
        }
        
        for(i=small;i>=1;i--)
        {
            if(n1%i==0 && n2%i==0)
            {
                gcd=i;
                return gcd;
            }
        }
    }
};

int main() {
    Solution s;
    int gcd = s.GCD(100 , 200);
    cout<<gcd;
    return 0;
}
