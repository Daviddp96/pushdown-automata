#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

stack<char> faStack;
int initialState = 0;
int currentState;

struct transition {
    int O;
    int F;
    char L;
    char E;
    string D;
};

struct state {
    vector<transition> transitions;
};

vector<state> states;
vector<string> inputStrings;

void printOutputStrings(vector<string> c) {
    for(int i = 0; i < c.size(); i++) {
        cout << "String " << i << ": " << c[i] << endl;
    }
}

void initfaStack(stack<char> &faStack) {
    char bottom = 'Z';
    faStack.push(bottom);
}

void stackSymbols(string Dstring) {
    for(int i = 0; i < Dstring.size(); i++) {
        if(Dstring[i] != '~') {
            char character = Dstring[i];
            faStack.push(character);
        }
    }
}

void printfaStack(stack<char> faStack) { 

    stack<char> aux = faStack;
    vector<char> faStackReversed;
    while(!aux.empty()) {
        faStackReversed.push_back(aux.top());
        aux.pop();
    }

    for(int j = faStackReversed.size() - 1; j >= 0; j--) {
        cout << faStackReversed[j];
    }

    cout << endl;
}

void emptyfaStack() {
    while(!faStack.empty()) {
        faStack.pop();
    }
}

bool definedTransition(state s, char c, char t, int &index) {
    for(int i = 0; i < s.transitions.size(); i++) {
        if(c == s.transitions[i].L && s.transitions[i].E == t) {
            index = i;
            return true;
        }
    }
    return false;
}

transition gettransition(state s, int index) {
    transition t = s.transitions[index];
    return t;
}

void applyTransition(int &currentState, transition t) {
    currentState = t.F;
    faStack.pop();
    stackSymbols(t.D);
    printfaStack(faStack);
}

bool testInputString(string inputString) {

    int index;

    currentState = initialState;

    char faStackTop = faStack.top();


    if(inputString.size() == 0) {
        return 0;
    }

    for(int i = 0; i < inputString.size(); i++) {

        if (definedTransition(states[currentState], inputString[i], faStackTop, index)) {
            transition t = gettransition(states[currentState], index);
            applyTransition(currentState, t);
            faStackTop = faStack.top();
            if(i == inputString.size() - 1) {
                 return 1;
            }
        } else {
            return 0;
        }
    }

    return 0;

}


int main() {

    int C;
    cin >> C;

    int N, T;
    cin >> N >> T;

    for(int i = 0; i < N; i++) {
        state state;
        states.push_back(state);
    }

    for(int i = 0; i < T; i++) {
        int o, f;
        char l, e;
        string d;
        cin >> o >> f >> l >> e >> d;
        
        transition t;
        t.O = o;
        t.F = f;
        t.L = l;
        t.E = e;
        t.D = d;

        states[o].transitions.push_back(t);

    }

    cin.ignore();

    for(int i = 0; i < C; i++) {
        string inputString;
        getline(cin, inputString);
        inputString+='~';
        inputStrings.push_back(inputString);
    }

    for(int i = 0; i < C; i++) {
        initfaStack(faStack);
        cout << "Case " << i+1 << ":" << endl;
        printfaStack(faStack);
        bool resultado = testInputString(inputStrings[i]);
        if(resultado) {
            cout << "ACCEPTED" << endl;
        } else {
            cout << "REJECTED" << endl;
        }
        cout << endl;
        emptyfaStack();
    }

    return 0;
}