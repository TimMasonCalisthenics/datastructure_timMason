#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        while (true) {
            vector<int> target(n);
            cin >> target[0];

            // ตรวจสอบเงื่อนไขจบ sub-testcase
            if (target[0] == 0) {
                cout << "\n";
                break;
            }

            for (int i = 1; i < n; ++i) {
                cin >> target[i];
            }

            stack<int> station;
            int current_incoming = 1;
            bool possible = true;

            for (int i = 0; i < n; ++i) {
                int required = target[i];

                // นำรถไฟเข้าสถานีเรื่อยๆ จนกว่าจะเจอคันที่ต้องการ
                while (current_incoming <= n && (station.empty() || station.top() != required)) {
                    station.push(current_incoming++);
                }

                // ตรวจสอบว่าคันบนสุดตรงกับที่ต้องการหรือไม่
                if (!station.empty() && station.top() == required) {
                    station.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    solve();
    return 0;
}