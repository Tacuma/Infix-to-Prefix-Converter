//Tacuma Solomon
//Computer Science III
//Infix to Prefix Converter

//Please write a C++ source code/program that will  convert an expression in infix notation 
//( e.g. 2 * 3 + (6 / 4) - 8 ) to the equivalent expression in prefix (polish) notation 
//(e.g. - + * 2 3 / 6 4 8 ).


#include<iostream>
#include<string>
#include "StackType.h"
using namespace std;

int priority(char);
void Footer();

int main(){

	string infix; // the infix expression read from the line
	StackType input; // stack for input string
	StackType operators; // stack for operators
	StackType output;  // stack for output
	char temp,again='y';
	cout << "-Infix to Prefix Converter-" << endl;
	
	while (again!='n')
	{
		cout << endl << "Please enter a Mathematical Expression" << endl;
		cin >> infix;
		//Pushes the contents of the string into the input stack
		for (int i=0;i<infix.length();i++){
			input.Push(infix[i]);
		}
		// While the input stack is not empty...
		while(!input.IsEmpty()){
			temp=input.Top();
			input.Pop();
			//If it is operand, add it to output string.
			if (isdigit(temp))  
				output.Push(temp);
			//If it is Closing parenthesis, push it on stack.
			if (temp==')')
				operators.Push(temp);
			//If it is an operator, then
			if ((temp=='+') || (temp=='/') || (temp =='-') || (temp=='*')) {
				bool pushed = false;
				while(!pushed){
					//If stack is empty, push operator on stack.
					if(operators.IsEmpty()){
						operators.Push(temp);
						pushed=true;
					}
					//If the top of stack is closing parenthesis, push operator on stack.
					else if (operators.Top()==')'){
						operators.Push(temp);
						pushed=true;
					}
					//If it has same or higher priority than the top of stack, push operator on stack.
					else if ((priority(temp)>priority(operators.Top())) || (priority(temp)==priority(operators.Top()))){
						operators.Push(temp);
						pushed=true;
					}
					//Else pop the operator from the stack and add it to output string, repeat step 5.
					else {
						output.Push(operators.Top());
						operators.Pop();
					}	
				}
			}
			//If it is a opening parenthesis, pop operators from stack and add them to output string 
			//until a closing parenthesis is encountered. Pop and discard the closing parenthesis.
			if (temp=='('){
				while (operators.Top()!=')')
				{
					output.Push(operators.Top());
					operators.Pop();
				}
				operators.Pop(); // ')' is popped and discarded
			}
		}
		//If there is no more input, unstack the remaining operators and add them to output string.
		while(!operators.IsEmpty()){
			output.Push(operators.Top());
			operators.Pop();
		}

		while(!output.IsEmpty()){
			cout << output.Top();
			output.Pop();
		}

		cout << endl;
		cout << "Would  you like to convert another expression? (y/n)";
		cin >> again;
	}
	cout << endl;
	Footer();
	system("pause");
	return 0;
}

//Determines the priority of an operator
int priority(char op){
	if (op =='+')
		return 1;
	if (op =='-')
		return 1;
	if (op =='/')
		return 2;
	if (op =='*')
		return 2;
}

void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}



/*
-Infix to Prefix Converter-

Please enter a Mathematical Expression
(2*3+(6/4)-8)
-+*23/648
Would  you like to convert another expression? (y/n)y

Please enter a Mathematical Expression
2*3/(2-1)+5*(4-1)
+/*23-21*5-41
Would  you like to convert another expression? (y/n)n



() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/