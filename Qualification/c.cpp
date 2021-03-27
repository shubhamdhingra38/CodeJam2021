#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 2e9 + 100;
bool SolveFirst(vector<int> v, long long required) {
    long long cost = 0;
    int n = v.size();
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
        if (cost - 1 > required) {
            return false;
        }
    }
    return cost - 1 == required;
}

void Solve(int t) {
    int n, c;
    cin >> n >> c;
    // assert(n <= 7);
    bool possible = true;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    while (true) {
        if (SolveFirst(v, c)) {
            break;
        }
        bool hasNext = next_permutation(v.begin(), v.end());
        if (!hasNext) {
            possible = false;
            break;
        }
    }
    printf("Case #%d: ", t);
    if (possible) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", v[i]);
        }
        printf("\n");
    } else {
        printf("IMPOSSIBLE\n");
    }
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