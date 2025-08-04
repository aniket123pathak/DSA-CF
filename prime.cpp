#include<iostream>
using namespace std;

class Solution {
public:
    bool isprime(int n) {
        int i = 0;
        int count = 0;
        for(i = 1 ; i*i<=n ; i++)
        {
            if(n%i==0)
            {
                count++;
                if(n/i!=i)
                {
                    count++;
                }
            }
        }
        if(count==2)
            return true;
        else
            return false;
    }
};

int main (){
    Solution s;
    int k = s.isprime(121);
    cout<<k;
    return 0;
}