#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e3 + 100;
constexpr int INF = 2e9 + 100;
long long dp[MAX][2];

void Solve(int t) {
    int x, y;
    string s;
    cin >> x >> y;
    cin >> s;
    int sz = s.size();

    for (int i = 0; i < sz; ++i) {
        dp[i][0] = dp[i][1] = INF;
    }

    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i < sz; ++i) {
        char c = s[i];
        char last = s[i - 1];
        if (c == '?') {
            if (last == 'C') {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][0] + x;
            } else if (last == 'J') {
                dp[i][0] = dp[i - 1][1] + y;
                dp[i][1] = dp[i - 1][1];
            } else {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
            }

        } else if (c == 'C') {
            if (last == '?') {
                dp[i][0] = dp[i][1] =
                    min(dp[i - 1][0], dp[i - 1][1] + y);  //(CC, JC)
            } else if (last == 'J') {
                dp[i][0] = dp[i][1] = dp[i - 1][1] + y;  // JC
            } else {
                dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            }
        } else {
            if (last == '?') {
                dp[i][0] = dp[i][1] =
                    min(dp[i - 1][0] + x, dp[i - 1][1]);  //(CJ, JJ)
            } else if (last == 'C') {
                dp[i][0] = dp[i][1] = dp[i - 1][0] + x;  // CJ
            } else {
                dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
    }
    printf("Case #%d: %lld\n", t, min(dp[sz - 1][0], dp[sz - 1][1]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    // t = 1;
    for (int i = 1; i <= t; ++i) {
        Solve(i);
    }
}