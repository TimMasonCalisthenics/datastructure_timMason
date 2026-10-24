#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    
    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] < heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else break;
        }
    }
    void siftDown(int idx) {
        int n = heap.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right; 
            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                idx = largest;
            } else break;
        }
    }
public:
    void add(int v) {
        heap.push_back(v);
        siftUp(heap.size() - 1);
    }
    int extractMax() {
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
        return maxVal;
    }
    bool isEmpty() const { return heap.empty(); }
    void print() const {
        if (heap.empty()) {
            cout << "EMPTY" << endl;
        } else {
            for (size_t i = 0; i < heap.size(); ++i) {
                if (i) cout << " ";
                cout << heap[i];
            }
            cout << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> Q;
    MaxHeap h;
    while (Q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int v; cin >> v;
            h.add(v);
            h.print();
        } else if (cmd == "delete") {
            if (!h.isEmpty()) h.extractMax();
            h.print();
        } else if (cmd == "topk") {
            int k; cin >> k;
            vector<int> popped;
            while (k-- && !h.isEmpty())
                popped.push_back(h.extractMax());
            if (popped.empty()) cout << "EMPTY" << endl;
            else {
                for (size_t i = 0; i < popped.size(); ++i) {
                    if (i) cout << " ";
                    cout << popped[i];
                }
                cout << endl;
            }
            h.print();
        }
    }
    return 0;
}