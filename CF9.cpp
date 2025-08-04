#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
        void sum(string a)
        {
            vector<char> num;
            int i = 0;
            for(i=0;i<a.length();i+=2)
            {
                
                num.push_back(a[i]);
            }
            sort(num.begin(),num.end());
            for(i=0;i<a.length();i+=2)
            {
                if(i%2==0)
                {
                    a[i]=num[i/2];
                }
            }
            cout<<a;
        }
};

int main () {
    Solution s;
    string a;
    cin>>a;
    s.sum(a);
    return 0;
}