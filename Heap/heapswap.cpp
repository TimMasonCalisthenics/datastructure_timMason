
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ตรวจสอบว่า a ดีกว่า b ตามชนิดของ Heap หรือไม่
bool better(int a, int b, string type) {
    if (type == "max") {
        return a > b;
    }
    return a < b; // min-heap
}

// วิธีที่ 1: Insert ทีละตัว (Sift-up)
int insertHeap(vector<int> data, string type) {
    vector<int> heap;
    int swaps = 0;

    for (int value : data) {
        // เพิ่มข้อมูลใหม่ไว้ท้าย Heap
        heap.push_back(value);

        int child = (int)heap.size() - 1;

        // ดันค่าขึ้นไปหาพ่อ
        while (child > 0) {
            int parent = (child - 1) / 2;

            if (better(heap[child], heap[parent], type)) {
                swap(heap[child], heap[parent]);
                swaps++;
                child = parent;
            } else {
                break;
            }
        }
    }

    return swaps;
}

// วิธีที่ 2: Heapify แบบ Bottom-up
int heapify(vector<int> data, string type) {
    int n = (int)data.size();
    int swaps = 0;

    // เริ่มจากโหนดสุดท้ายที่มีลูก
    for (int i = n / 2 - 1; i >= 0; i--) {
        int parent = i;

        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int bestChild = parent;

            // ตรวจสอบลูกซ้าย
            if (left < n &&
                better(data[left], data[bestChild], type)) {
                bestChild = left;
            }

            // ตรวจสอบลูกขวา
            // หากลูกซ้ายและขวาดีเท่ากัน จะคงเลือกลูกซ้าย
            if (right < n &&
                better(data[right], data[bestChild], type)) {
                bestChild = right;
            }

            // ถ้าพ่อยังเป็นค่าที่ดีที่สุด ให้หยุด
            if (bestChild == parent) {
                break;
            }

            swap(data[parent], data[bestChild]);
            swaps++;

            // ดันค่าต่อจากตำแหน่งใหม่
            parent = bestChild;
        }
    }

    return swaps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string type;
    int N;

    cin >> type;
    cin >> N;

    vector<int> data(N);

    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    cout << insertHeap(data, type) << '\n';
    cout << heapify(data, type) << '\n';

    return 0;
}
