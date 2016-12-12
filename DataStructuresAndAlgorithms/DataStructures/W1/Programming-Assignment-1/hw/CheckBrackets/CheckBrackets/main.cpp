//
//  main.cpp
//  CheckBrackets
//
//  Created by Garrett Wang on 12/12/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
    type(type),
    position(position)
    {}
    
    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    
    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        
        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position));
        }
        
        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()){
                cout << position + 1 << endl;
                exit(0);
            }
            else{
                Bracket last = opening_brackets_stack.top();
                if(last.Matchc(next)){
                    opening_brackets_stack.pop();
                }
                else{
                    cout << position + 1 << endl;
                    exit(0);
                }
            }
        }
    }
    if(opening_brackets_stack.empty()){
        cout << "Success" << endl;
    }
    else{
        int size = opening_brackets_stack.size();
        while(--size){
            opening_brackets_stack.pop();
        }
        cout << opening_brackets_stack.top().position+1 << endl;
        
    }
    
    return 0;
}
