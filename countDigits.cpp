#include<iostream>
using namespace std;

int main (){
    Solution s;
    int k = s.countDigit(2);
    cout<<k;
    return 0;
}

class Solution {
public:
    int countDigit(int n) {
        int count = 1;
        while(n/10 !=0)
        {
                n=n/10;
                count++;   
        }
        return count;
    }
};