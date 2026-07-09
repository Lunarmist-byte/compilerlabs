Algorithm: Lexical Analyzer using C
Start the program.
Declare required variables, character buffer, keyword list, and a file pointer.
Open the input source program in read mode.
Read the input program character by character until the end of the file.
Ignore spaces, tabs, and newlines.
If the character is an operator, display it as an operator.
If the character is an alphabet or digit, store it in a buffer.
When a delimiter (space, newline, special character, etc.) is encountered:
Terminate the buffer with '\0'.
Compare the buffer with the list of keywords.
If it matches a keyword, display it as a Keyword.
Otherwise, display it as an Identifier.
Clear the buffer for the next token.
Repeat Steps 4–8 until the end of the file.
Close the input file.
Stop the program
