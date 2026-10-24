#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node * next;
};

void insert(Node*& head, Node*& tail, int value){
    Node* newNode = new Node{value, nullptr};

    if(head == nullptr){
        head = tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
}

void rearrange(Node*& head){
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* current = head;

    while(current != nullptr){
        Node* nextNode = current -> next;
        current -> next = nullptr;

        if(current -> data % 2 == 0){
            if(evenHead == nullptr){
                evenHead = evenTail = current;
            }else{
                evenTail -> next = current;
                evenTail = current;
            }
        }else{
            if (oddHead == nullptr) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = nextNode;
    }
    if (evenHead == nullptr) {
        head = oddHead;
    } else {
        head = evenHead;
        evenTail->next = oddHead;
    }
}

void display(Node* head){
    if(head == nullptr){
        cout << "EMPTY";
        return;
    }
    while(head != nullptr){
        cout << head -> data;
        if(head -> next != nullptr){
            cout << " ";
        }
        head = head -> next;
    }
    cout << '\n';
}

int main(){
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0;i < n;i++){
        int x ;
        cin >> x;
        insert(head,tail,x);
    }

    rearrange(head);
    display(head);
    return 0;
}