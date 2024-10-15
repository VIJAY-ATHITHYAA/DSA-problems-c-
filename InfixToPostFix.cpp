#include <iostream>
#include <string>
using namespace std;
class Stack{
    char arr[100];
    int top=0;
    public:
      void push(char);
      void pop();
      bool isEmpty();
      char top1();
};

void Stack::push(char ch){
    arr[top] = ch;
    top++;
}
void Stack::pop(){
    top--;
}
bool Stack::isEmpty(){
    if(top==0)
      return true;
    return false;
}

char Stack::top1(){
    return arr[top-1];
}

Stack st;

bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return true;
    }
    return false;
}

int precedence(char c){
    if(c=='+'||c=='-')
       return 1;
    if(c=='*'||c=='/')
       return 2;
    return 0;
}

string infixToPostfix(string infix){
    string post;
    for(int i=0;i<infix.length();i++){
        char ch = infix[i];
        if(ch>='a'&&ch<='z'||ch>='0'&&ch<='9')
            post+=ch;
        else if(isOperator(ch)){
            while(!st.isEmpty()&&precedence(ch)<=precedence(st.top1())){
                post+=st.top1();
                st.pop();
            }
            st.push(ch);
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.isEmpty()&&st.top1()!='('){
                post+=st.top1();
                st.pop();
            }
            st.pop();
        }
    }
    while(!st.isEmpty()){
        post+=st.top1();
        st.pop();
    }
    return post;
}

int main() {
    string in;
    cout<<"Enter the Expression: \n";
    cin>>in;
    string res = infixToPostfix(in);
    cout<<"Infix to PostFix Exp:\n";
    cout<<res;
    return 0;
}