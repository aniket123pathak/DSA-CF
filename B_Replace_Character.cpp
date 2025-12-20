#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
    public:
        void solve()
        {
            int n;
            cin >> n;
            string s;
            cin >> s;
            
            vector<int> count(26, 0);
            for(char c : s){
                count[c - 'a']++;
            }
            
            vector<pair<int, int>> v;
            for(int i = 0; i < 26; i++){
                if(count[i] > 0){
                    v.push_back({count[i], i});
                }
            }
            
            sort(v.begin(), v.end());
            
            char min_char = (char)('a' + v[0].second);
            char max_char = (char)('a' + v.back().second);
            
            for(int i = 0; i < n; i++){
                if(s[i] == min_char){
                    s[i] = max_char;
                    break; 
                }
            }
            
            cout << s << endl;
        }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    int tc;
    cin >> tc;
    while(tc-- > 0)
    {
        s.solve();
    }
    return 0;
}