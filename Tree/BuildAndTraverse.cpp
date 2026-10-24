
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// สร้าง Binary Tree จากข้อมูล Level-order
Node* buildTree(vector<int>& a) {
    if (a.empty() || a[0] == -1) {
        return nullptr;
    }

    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < (int)a.size()) {
        Node* current = q.front();
        q.pop();

        // สร้างลูกซ้าย
        if (i < (int)a.size()) {
            if (a[i] != -1) {
                current->left = new Node(a[i]);
                q.push(current->left);
            }
            i++;
        }

        // สร้างลูกขวา
        if (i < (int)a.size()) {
            if (a[i] != -1) {
                current->right = new Node(a[i]);
                q.push(current->right);
            }
            i++;
        }
    }

    return root;
}

// Preorder: Root -> Left -> Right
void preorder(Node* root, vector<int>& result) {
    if (root == nullptr) return;

    result.push_back(root->data);
    preorder(root->left, result);
    preorder(root->right, result);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root, vector<int>& result) {
    if (root == nullptr) return;

    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root, vector<int>& result) {
    if (root == nullptr) return;

    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->data);
}

// แสดงผลลัพธ์
void printResult(vector<int>& result) {
    if (result.empty()) {
        cout << "EMPTY\n";
        return;
    }

    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }

    cout << '\n';
}

// คืนหน่วยความจำของต้นไม้
void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int K;
    cin >> K;

    vector<int> a(K);

    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }

    Node* root = buildTree(a);

    int Q;
    cin >> Q;

    while (Q--) {
        string command;
        cin >> command;

        vector<int> result;

        if (command == "preorder") {
            preorder(root, result);
        }
        else if (command == "inorder") {
            inorder(root, result);
        }
        else if (command == "postorder") {
            postorder(root, result);
        }

        printResult(result);
    }

    deleteTree(root);

    return 0;
}
