
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<long long> c(m);
    vector<long long> d(m);

    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }

    for (int k = 0; k < n; k++) {
        long long W;
        cin >> W;

        priority_queue<long long> pq;

        long long selectedSum = 0;
        int closed = 0;
        bool possible = true;

        for (int i = 0; i < m; i++) {
            // ประตูเมืองนี้เป็นตัวเลือกใหม่
            pq.push(d[i]);

            // ปริมาณน้ำที่ต้องระบายออกอย่างน้อย
            long long need = W - c[i];

            // เลือกปิดประตูเพิ่มจนกว่าเมืองจะปลอดภัย
            while (selectedSum < need) {
                if (pq.empty()) {
                    possible = false;
                    break;
                }

                selectedSum += pq.top();
                pq.pop();

                closed++;
            }

            if (!possible) {
                break;
            }
        }

        if (possible) {
            cout << closed << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
