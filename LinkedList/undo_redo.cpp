#include <iostream>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }   
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList():head(NULL),tail(NULL){}

        ~DoublyLinkedList(){
            Node* current = head;
            while(current != NULL){
                Node* nextNode = current -> next;
                delete current;
                current = nextNode;
            }
        }

        void insert_end(int x){
            Node* newNode = new Node(x);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }

        void PrintList(){
            Node* current = head;
            cout << " ";
            while(current != NULL){
                cout << current -> data << " ";
                current = current -> next;
            }
            cout << "NULL" << endl;
        }
};