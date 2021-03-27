#include <bits/stdc++.h>
using namespace std;

int t, n, q;
map<pair<pair<int, int>, int>, int> cache;

int AskQuery(int a, int b, int c) {
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);
    if (cache[{{arr[0], arr[1]}, arr[2]}] != 0) {
        return cache[{{arr[0], arr[1]}, arr[2]}];
    }

    cout << a << " " << b << " " << c << endl;
    int ans;
    cin >> ans;
    // if (ans == -1) {
    //     exit(0);
    // }
    return cache[{{arr[0], arr[1]}, arr[2]}] = ans;
}

void PrintDeque(deque<int>& d) {
    for (int ele : d) {
        cout << ele << " ";
    }
    cout << endl;
}

void Solve() {
    cache.clear();
    deque<int> result;

    for (int i = 1; i <= n; ++i) {
        result.push_back(i);
    }

    int start = 0;
    int end = n - 1;

    bool f = false;
    while (start < end) {
        int index = start + 1;
        while (index < end) {
            int front = result.at(start);
            int back = result.at(end);
            if (result.at(index) == back) {
                continue;
            }
            int element = result.at(index);
            int ans = AskQuery(front, element, back);
            if (ans == front) {
                result.erase(result.begin() + index);
                result.insert(result.begin() + start,
                              element);  //[index, front, back]
                index++;
            } else if (ans == element) {
                index++;
            } else {
                result.erase(result.begin() + index);
                result.insert(result.begin() + end,
                              element);  //[front, back, index]
            }
            // PrintDeque(result);
        }

        int front = result.at(start);
        int back = result.at(end);

        if (!f) {
            f = true;
        } else {
            int ffront = result.at(start - 1);
            int ans = AskQuery(ffront, front, back);
            if (ans == front) {
            } else if (ans == back) {
                result.erase(result.begin() + start);
                result.insert(result.begin() + start, back);
                result.erase(result.begin() + end);
                result.insert(result.begin() + end, front);
            } else {
            }
        }

        start++;
        end--;
    }
    PrintDeque(result);
    cout.flush();
    int correct;
    cin >> correct;
    if (!correct) {
        exit(1);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> t >> n >> q;
    // t = 1;
    for (int i = 1; i <= t; ++i) {
        Solve();
    }
}