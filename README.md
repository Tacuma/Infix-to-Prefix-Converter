
Prefix To Infix
===============


Data Structures/Concepts Used:
==============================
Uses 3 Stacks,each for:
(1)Input
(2)Operators
(3)Output


Description:
============
Please write a C++ source code/program that will  convert an expression in infix notation 
( e.g. 2 * 3 + (6 / 4) - 8 ) to the equivalent expression in prefix (polish) notation 
(e.g. - + * 2 3 / 6 4 8 ).

Algorithm for Converting infix to prefix
----------------------------------------
Pushes the contents of the string into the input stack
While the input stack is not empty...
-If it is operand, add it to output string.
-If it is Closing parenthesis, push it on stack.
-If it is an operator, then
	If stack is empty, push operator on operator stack.
	If the top of stack is closing parenthesis, push operator on stack.
	If it has same or higher priority than the top of stack, push operator on stack.
	Else pop the operator from the stack and add it to output string, repeat step 5.
-If it is a opening parenthesis, pop operators from stack and add them to output string 
	until a closing parenthesis is encountered. Pop and discard the closing parenthesis.
-If there is no more input, unstack the remaining operators and add them to output string.


Output:
=======
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

