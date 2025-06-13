//Maze Solver
#include<iostream>
#include<stack>
using namespace std;

struct Position{int x,y;};
void SolveMaze(){
    stack<Position> path;
    path.push({0,0});

    while(!path.empty()){
        Position current = path.top();
        path.pop();
        cout<<"Visiting : ("<<current.x<<","<<current.y<<")\n";
        if (current.x == 10 && current.y == 10) {

            cout<<"Maze Solved!\n";
            return;
        }
        path.push({current.x + 1,current.y + 1});
    }
}

int main(){
    SolveMaze();
    return 0;
}

