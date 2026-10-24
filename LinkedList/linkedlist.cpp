#include <iostream>

using namespace std;

// โครงสร้าง Node สำหรับ Singly Linked List
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // คำสั่ง A: เพิ่มข้อมูลต่อท้าย Linked List (Append)
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // วนลูปหาโหนดตัวสุดท้าย
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // คำสั่ง I: แทรกข้อมูลหลังตำแหน่งที่กำหนด (1-based index)
    void insertAfter(int position, int value) {
        Node* curr = head;
        int count = 1;

        // วนลูปเดินไปให้ถึงโหนดตำแหน่งที่กำหนด
        while (curr != nullptr && count < position) {
            curr = curr->next;
            count++;
        }

        // หากเจอตำแหน่ง ให้แทรกโหนดใหม่คั่นกลาง
        if (curr != nullptr) {
            Node* newNode = new Node(value);
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    // คำสั่ง D: ลบข้อมูลออกจาก Linked List โดยอ้างอิงจากค่าของข้อมูล
    void deleteValue(int targetValue) {
        if (head == nullptr) return;

        // กรณีที่ 1: ข้อมูลที่ต้องการลบอยู่ที่ Head ตัวแรกสุด
        if (head->data == targetValue) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // กรณีที่ 2: วนหาโหนดก่อนหน้าตัวที่ต้องการลบ
        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != targetValue) {
            curr = curr->next;
        }

        // หากเจอ ให้ข้ามการชี้ไปยังตัวถัดไปแล้วลบโหนดนั้นทิ้ง
        if (curr->next != nullptr) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    // คำสั่ง P: แสดงข้อมูลทั้งหมดใน Singly Linked List
    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr) {
                cout << " ";
            }
            curr = curr->next;
        }
        cout << "\n";
    }

    // Destructor สำหรับคืน Memory ทั้งหมดเมื่อเลิกใช้งาน
    ~SinglyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

int main() {
    // ปรับความเร็ว I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SinglyLinkedList list;
    char cmd;

    while (cin >> cmd) {
        // คำสั่ง 0: สิ้นสุดการทำงาน
        if (cmd == '0') {
            break;
        }
        // คำสั่ง A: รับค่าตัวเลขแล้วเพิ่มต่อท้าย
        else if (cmd == 'A') {
            int val;
            cin >> val;
            list.append(val);
        }
        // คำสั่ง I: รับตำแหน่งและค่าตัวเลข แล้วแทรกหลังตำแหน่งนั้น
        else if (cmd == 'I') {
            int pos, val;
            cin >> pos >> val;
            list.insertAfter(pos, val);
        }
        // คำสั่ง D: รับค่าตัวเลขแล้วลบโหนดที่มีค่านั้น
        else if (cmd == 'D') {
            int val;
            cin >> val;
            list.deleteValue(val);
        }
        // คำสั่ง P: แสดงผลข้อมูลใน List
        else if (cmd == 'P') {
            list.printList();
        }
    }

    return 0;
}