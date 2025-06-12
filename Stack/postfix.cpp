#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define MAXSIZE 100
// declaring the stack
struct stack{

    int stack[MAXSIZE];
    int Top;

};
typedef struct stack NODE;

void push(NODE *pu,int item){ // Function to add/insert element to the stack
    if(pu->Top==MAXSIZE){

        cout<<"\n the stack is full"<<endl;

    } else{
        pu->stack[++pu->Top]=item;
    } 
}

// this function will delete an element from top of the Stack
int pop(NODE *po){
    int item;

    if (po->Top==-1) cout<<"\nThe stack is empty,Invalid Infix expression"<<endl;
    else item=po->stack[po->Top--];
    return (item);

}

// this function will return the postfix of expression of an infix
int Postfix_Eval(char postfix[]){
    int a,b,temp,len;
    NODE *ps;

    ps->Top=-1;

    len=strlen(postfix);

    for(int i=0;i<len;i++){
        if (postfix[i]<='9' && postfix[i]>='0') push(ps,(postfix[i]-48));
        else {
            a=pop(ps);
            b=pop(ps);
            switch(postfix[i]){
                case '+':
                   temp=b+a; break;
                case '-':
                   temp=b-a; break;
                case '*':
                   temp=b*a; break;
                case '/':
                   temp=b/a; break;
                case '%':
                   temp=b & a; break;
                case '^':
                   temp=pow(b,a); break;
            }
            push(ps,temp);
        }
    }
    return (pop(ps));
}
int main(){
    char choice,postfix[MAXSIZE];
    do{
        cout<<"\nEnter the postfix expression="<<endl;
        fflush(stdin);
        gets(postfix);
        cout<<"\n\nThe Postfix evaluation is "<<Postfix_Eval(postfix)<<endl;
        cout<<"\n\nDo you want to continue(Y/y)="<<endl;
        fflush(stdin);
        cin>>choice;

    }while (choice=='Y' || choice=='y');
    return 0;
}