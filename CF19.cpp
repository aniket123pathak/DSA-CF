#include<iostream>
using namespace std;

class Solution {
    public:
        void abc()
        {
            string s;
            int n,i;
            cin>>n;
            cin>>s;

            int arr[150]={0};
            for(i=0;i<n;i++)
            {
                arr[s[i]]++;
            }
            
            for(i=1;i<n-1;i++)
            {
                if(arr[s[i]]>1)
                {
                    cout<<"Yes";
                    return ;
                }
            }
            cout<<"No";


        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc>0)
    {
        s.abc();
        cout<<endl;
        tc--;
    }
    return 0;
}

/*

3
aaa
3
aba
3
aab
4
abca
4
abba
4
aabb
5
abaca
5
abcda
5
abcba
6
abcbbf
6
abcdaa
3
abb
OutputCopy
Yes
No
Yes
No
Yes
Yes
Yes
No
Yes
Yes
Yes*/