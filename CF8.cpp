#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        int RGB(int n,string a)
        {
            int count=0;
            int i = 0;
            while(a[i+1]!='\0')
            {
                if(a[i]==a[i+1])
                {
                    count++;
                }
                i++;
            }
            return count;
        }
};

int main () {
    Solution s;
    int n;
    cin>>n;
    string a;
    cin>>a;
    cout<<s.RGB(n,a);
    return 0;
}