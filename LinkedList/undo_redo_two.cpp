#include <iostream>
#include <string>

using namespace std;


struct Node {
    string text;
    Node* prev;
    Node* next;

    Node(string val) : text(val), prev(nullptr), next(nullptr) {}
};

void clearForward(Node* startNode) {
    Node* curr = startNode;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

int main() {
    // ปรับความเร็ว I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = nullptr;     
    Node* current = nullptr;  

    string input;
    while (cin >> input) {
        if (input == "END") {
            break;
        }
        if (input == "<<") {
            if (current != nullptr) {
                current = current->prev;
            }
        }
        else if (input == ">>") {
            if (current == nullptr) {
                if (head != nullptr) {
                    current = head;
                }
            } else {
                // ถ้ามีข้อความในอนาคตให้กู้คืน
                if (current->next != nullptr) {
                    current = current->next;
                }
            }
        }
        else {
            if (current != nullptr) {
                if (current->next != nullptr) {
                    clearForward(current->next); 
                    current->next = nullptr;
                }

                Node* newNode = new Node(input);
                current->next = newNode;
                newNode->prev = current;
                current = newNode; 
            } else {

                if (head != nullptr) {
                    clearForward(head);
                    head = nullptr;
                }

                Node* newNode = new Node(input);
                head = newNode;
                current = newNode;
            }
        }
    }

    if (current != nullptr) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->text << "\n";
            if (temp == current) {
                break; 
            }
            temp = temp->next;
        }
    }

    clearForward(head);

    return 0;
}