#include <iostream>
#include <string>

using namespace std;

class stack{
    private:
        int data[10000];
        int topIndex;
    public:
        stack(){
            topIndex = -1;
        }

        bool isEmpty(){
            return topIndex == -1;
        }

        void push(int x){
            data[++topIndex] = x;
        }

        void pop(){
            if(!isEmpty()){
                topIndex--;
            }
        }

        int top(){
            return data[topIndex];
        }
};

int main(){
    string input;
    
    getline(cin, input);

    stack s;
    bool isValid = true;

    for(char c : input){
        if(c == '('){
            s.push(c);
        }else if(c == ')'){
            if(s.isEmpty()){
                isValid = false;
                break;
            }
            s.pop();
        }
    }

    if(!s.isEmpty()){
        isValid = false;
    }

    if(isValid){
        cout << "Pass" << endl;
    }else{
        cout << "Error" << endl;
    }

    return 0;
}