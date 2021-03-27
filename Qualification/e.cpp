#include <bits/stdc++.h>
using namespace std;

constexpr int MX_STU = 100;
constexpr int MX_Q = 10000;

void Solve(int t) {
    vector<int> score(MX_STU, 0);
    string s;
    for (int i = 0; i < MX_STU; ++i) {
        cin >> s;
        for (int j = 0; j < MX_Q; ++j) {
            score[i] += (int)s[j];
        }
    }
    int maxScore, index;
    maxScore = 0;
    index = -1;
    for (int i = 0; i < MX_STU; ++i) {
        if (score[i] > maxScore) {
            maxScore = score[i];
            index = i;
        }
    }
    printf("Case #%d: %d\n", t, index + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int p;
    cin >> p;
    // t = 1;
    for (int i = 1; i <= t; ++i) {
        Solve(i);
    }
}