#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> customer;
    

    while(n--){
        string cmd;
        cin >> cmd;

        if(cmd == "ARRIVE"){
            int x;
            cin >> x;

            customer.push(x);
        }
        else if(cmd == "SERVE"){
            if(customer.empty()){
                cout << "EMPTY" << endl;
            }else{
                cout << customer.front() << endl;
                customer.pop();
            }
        }
        else if(cmd == "FRONT"){
            if(customer.empty()){
                cout << "EMPTY" << endl;
            }else{
                cout << customer.front() << endl;
            }
        }
    }
    return 0;
}