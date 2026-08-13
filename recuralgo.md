Start the program.
Read the input expression as a string.
Initialize the input pointer i to 0.
Call the function E().
E() calls T() followed by Eprime().
T() calls F() followed by Tprime().
F() checks:
If the current character is (, consume it, call E(), and check for the corresponding ).
If the current character is an alphabetic character, treat it as an identifier and consume it.
Otherwise, report the expression as invalid.
Tprime() checks for *. If found, consume it, call F(), and repeat.
Eprime() checks for +. If found, consume it, call T(), and repeat.
After E() finishes, check whether the entire input has been consumed.
If input[i] == '\0', print Valid Expression.
Otherwise, print Invalid Expression.
Stop.
