#include <iostream>
#include <string>

using namespace std;

class CustomStack {
private:
    char arr[1000];
    int topIndex;

public:
    CustomStack() {
        topIndex = -1;
    }

    void push(char x) {
        if (topIndex < 999) {
            topIndex++;
            arr[topIndex] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            topIndex--;
        }
    }

    char top() {
        if (!isEmpty()) {
            return arr[topIndex];
        }
        return '\0'; 
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

bool isValidParentheses(string s) {
    CustomStack st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (st.isEmpty()) {
                return false;
            }

            char topChar = st.top();
            st.pop();
            if (c == ')' && topChar != '(') return false;
            if (c == ']' && topChar != '[') return false;
            if (c == '}' && topChar != '{') return false;
        }
    }

    return st.isEmpty();
}

int main() {
    string input;
    if (cin >> input) {
        if (isValidParentheses(input)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}