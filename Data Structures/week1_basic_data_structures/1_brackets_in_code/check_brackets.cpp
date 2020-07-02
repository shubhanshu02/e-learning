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
            opening_brackets_stack.push(Bracket(next, position +1));
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()) {
                cout << position + 1 << endl;
                return 0;
            }
            Bracket b = opening_brackets_stack.top();
            if (!b.Matchc(next)) {
                cout << position + 1 << endl;
                return 0;
            }
            opening_brackets_stack.pop();
        }
    }
    if (!opening_brackets_stack.empty()) {
        Bracket top = opening_brackets_stack.top();
        while (!opening_brackets_stack.empty()) {
            top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
        }
        cout << top.position << endl;
        return 0;
    }
    cout << "Success"<<endl;
    // Printing answer, write your code here

    return 0;
}
