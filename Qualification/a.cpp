#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 2e9 + 100;
void Solve(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    long long cost = 0;
    for (int i = 0; i < n; ++i) {
        int mn = INF;
        int index = i;
        for (int j = i; j < n; ++j) {
            if (v[j] < mn) {
                mn = v[j];
                index = j;
            }
        }

        reverse(v.begin() + i, v.begin() + index + 1);

        cost += index - i + 1;
    }
    printf("Case #%d: %lld\n", t, cost - 1);
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