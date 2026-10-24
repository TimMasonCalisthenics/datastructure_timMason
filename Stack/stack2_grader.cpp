#include <iostream>
#include <stack>

using namespace std;

void printStackBottomToTop(stack<int> s) {
    if (s.empty()) return;

    int val = s.top();
    s.pop();

    printStackBottomToTop(s);

    cout << val << " ";

    s.push(val);
}

void printStack(stack<int> s) {
    printStackBottomToTop(s);
    cout << endl;
}

int main() {
    stack<int> num;
    char cmd;
    int n;

    while (cin >> cmd) {
        if (cmd == 'X') {
            break;
        } else if (cmd == 'U') {
            cin >> n;
            num.push(n);
        } else if (cmd == 'O') {
            if (!num.empty()) {
                cout << num.top() << endl;
                num.pop();
            }
        } else if (cmd == 'T') {
            if (!num.empty()) {
                cout << num.top() << endl;
            }
        } else if (cmd == 'P') {
            printStack(num);
        } else if (cmd == 'N') {
            cout << num.size() << endl;
        }
    }

    return 0;
}