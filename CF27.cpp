#include <iostream>
using namespace std;

const int MAXLEN = 100005;

struct State {
    int len, link;
    map<char, int> next;
};

State st[2 * MAXLEN];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;

    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;

            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }

            st[q].link = st[cur].link = clone;
        }
    }

    last = cur;
}

int count_distinct_substrings(const string& s) {
    sa_init();
    for (char c : s) {
        sa_extend(c);
    }

    long long total = 0;
    for (int i = 1; i < sz; ++i) {
        total += (st[i].len - st[st[i].link].len);
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        bool found = false;

        if (s.length() == 1) {
            cout << -1 << '\n';
            continue;
        }

        // Try substrings of size 2 to 5
        for (int i = 0; i < (int)s.length() && !found; ++i) {
            for (int len = 2; len <= 5 && i + len <= (int)s.length(); ++len) {
                string sub = s.substr(i, len);

                int count = count_distinct_substrings(sub);
                if (count % 2 == 0) {
                    cout << sub << '\n';
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }

    return 0;
}