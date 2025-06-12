#include<iostream>
#include<stack>
using namespace std;
// undo / redo in Text Editor 
class TextEditor {
    stack<string> undoStack,redoStack;

    public:
     void type(string text){
        undoStack.push(text);
        while (!redoStack.empty()) {
            redoStack.pop();

        }
      
     }
     void undo(){
        if (!undoStack.empty()) {

            redoStack.push(undoStack.top());
            undoStack.pop();

        }
     }
     void redo(){
        if ( !redoStack.empty()){

        undoStack.push(redoStack.top());
        redoStack.pop();

        }
     }
     void display(){

        if (!undoStack.empty()) cout<<"Current text: "<< undoStack.top()<<endl;
        else cout<<"No text available.\n ";

     }

};
int main(){

    TextEditor editor;
    editor.type("Hello World!");
    editor.display();
    editor.undo();
    editor.display();
    editor.type("Mr.Computer,I am your master,Jitin.");
    editor.redo();
    editor.display();

    return 0;

}