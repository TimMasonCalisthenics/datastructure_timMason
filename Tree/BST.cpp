
#include <iostream>
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

// เพิ่มข้อมูลใน BST
Node* add(Node* root, int v) {
    if (root == nullptr) {
        return new Node(v);
    }

    if (v < root->data) {
        root->left = add(root->left, v);
    }
    else if (v > root->data) {
        root->right = add(root->right, v);
    }

    // ถ้าค่าซ้ำ จะไม่ทำอะไร
    return root;
}

// หาค่าที่น้อยที่สุดใน subtree
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

// ลบข้อมูลใน BST
Node* removeNode(Node* root, int v) {
    if (root == nullptr) {
        return nullptr;
    }

    if (v < root->data) {
        root->left = removeNode(root->left, v);
    }
    else if (v > root->data) {
        root->right = removeNode(root->right, v);
    }
    else {
        // กรณีที่ 1: ไม่มีลูกซ้าย
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // กรณีที่ 2: ไม่มีลูกขวา
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // กรณีที่ 3: มีลูกทั้งสองข้าง
        Node* successor = findMin(root->right);

        root->data = successor->data;

        root->right = removeNode(root->right,
                                 successor->data);
    }

    return root;
}

// แสดงต้นไม้แบบ Level-order
void printTree(Node* root) {
    if (root == nullptr) {
        cout << "EMPTY\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            if (i > 0) cout << " ";
            cout << current->data;

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << '\n';
    }
}

// คืนหน่วยความจำของต้นไม้
void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int Q;
    cin >> Q;

    Node* root = nullptr;

    while (Q--) {
        string command;
        int v;

        cin >> command >> v;

        if (command == "add") {
            root = add(root, v);
        }
        else if (command == "remove") {
            root = removeNode(root, v);
        }

        printTree(root);
    }

    deleteTree(root);

    return 0;
}
