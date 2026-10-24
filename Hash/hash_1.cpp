#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> inventory;
    string cmd, item;
        while (cin >> cmd && cmd != "End") {
        cin >> item; 
        
        if (cmd == "ADD") {
            inventory[item]++;
        } 
        else if (cmd == "CHECK") {
            cout << inventory[item] << endl;
        }
    }
    
    return 0;
}