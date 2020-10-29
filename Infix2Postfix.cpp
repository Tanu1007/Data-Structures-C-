#include <iostream>
#include <stack>

using namespace std;

int precedence(char c){
	if(c == '^') return 3;
	else if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	else return -1;
}

string InfixTopostfix(stack <char> s, string infix){
	string postfix;
	for(int i=0;i<infix.length();i++){
		if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) postfix+=infix[i];
		else if(infix[i]=='(') s.push(infix[i]);
		else if(infix[i]==')'){
			while((s.top()!='(') && (!s.empty())){
				//char x=s.top();
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){
			if(s.empty()) s.push(infix[i]);
			else{
				if(precedence(infix[i])>precedence(s.top())) s.push(infix[i]);
				else if(precedence(infix[i])==precedence(s.top()) && (infix[i]=='^')) s.push(infix[i]);
				else{
					while(!s.empty() && precedence(infix[i]) <= precedence(s.top())){
						//char x = s.top();
						postfix+=s.top();
						s.pop();						
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty()){
		postfix+=s.top();
		s.pop();
	}
	return postfix;
}

int main(){
	string infix,postfix;
	cin >> infix;
	stack <char> s;
	cout << "INFIX EXPRESSION: " << infix << endl;
	postfix = InfixTopostfix(s,infix);
	cout << "POSTFIX EXPRESSION: " << postfix << endl;
}
