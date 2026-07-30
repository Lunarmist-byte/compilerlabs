3. Operator Precedence Parser

Aim: To write a C program to parse a given arithmetic expression using operator precedence parsing.

Algorithm:

Construct the operator precedence table for the symbols + - * / ^ ( ) id $ based on standard precedence and associativity rules.
Initialize the stack with $ and read the input ending in $.
Compare the topmost terminal on the stack with the current input symbol using the precedence table:
If relation is < or =, shift the input symbol onto the stack.
If relation is >, reduce: pop symbols back to the last < marked symbol.
If no relation exists, report a syntax error.
Accept when the stack contains only $ and input is $.
