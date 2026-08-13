Start the parser.
Initialize an empty stack and read the input string.
Add $ at the bottom of the stack and at the end of the input.
Read the input from left to right.
Shift: Move the next input symbol onto the stack.
Check whether the top of the stack matches the right-hand side of any production.
Reduce: Replace the matched RHS with the corresponding non-terminal E.
Continue shifting and reducing until the entire input is processed.
If the stack becomes $E$, accept the input.
Otherwise, reject the input.
Stop.
