#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long best_sum = a[1];
    int best_L = 1, best_R = 1;

    long long cur_sum = a[1];
    int cur_L = 1;

    for (int i = 2; i <= n; ++i) {
        if (cur_sum > 0) {
            cur_sum += a[i];
        } else {
            cur_sum = a[i];
            cur_L = i;
        }

        int cur_R = i;
        int cur_len = cur_R - cur_L + 1;
        int best_len = best_R - best_L + 1;
        
        if (cur_sum > best_sum) {
            best_sum = cur_sum;
            best_L = cur_L;
            best_R = cur_R;
        } else if (cur_sum == best_sum) {
            if (cur_len < best_len) {
                best_L = cur_L;
                best_R = cur_R;
            } else if (cur_len == best_len && cur_L < best_L) {
                best_L = cur_L;
                best_R = cur_R;
            }
        }
    }

    cout << best_sum << " " << best_L << " " << best_R << "\n";
    return 0;
}