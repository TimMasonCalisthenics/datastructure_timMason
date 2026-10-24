#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int data;
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class linkedlist{
    private:
        Node* head;
    public:
        linkedlist() : head(NULL) {}
};

int main(){
    return 0;
}