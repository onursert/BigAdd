# BigAdd
Lexical Analyzer and Interpreter for The BigAdd Language - 2019 (C)<br><br>

The BigAdd Language<br><br>

BigAdd language is a small programming language that has been designed in order to add and subtract big integers programmatically and display the result on the screen. BigAdd is an interpreted language.<br><br>

Lines of Code: Point (‘.’) is the end of line character. Lines can contain keywords, brackets, variables and constants. Any number of spaces or comments can be used between these elements. A program line can be divided between multiple text lines.<br>
A line of code is one of the following:<br>
A variable declaration.<br>
An assignment statement.<br>
An addition statement.<br>
A subtraction statement.<br>
An output statement.<br>
A loop statement.<br><br>

Comments: Comments are written between curly braces { }<br>
example: {this is a comment}{ and<br>
this is a comment too}<br><br>

Data Types: The only data type for variables is the integer. Integer is a signed whole number that is represented as a decimal data type. An integer can be as big as 100 decimal digits. Strings exist only as constants and are used in the out statements only.<br>
example: 123113, -5, 0, -314159 are valid integer representations.<br>
3.14159 is not a valid integer (it is a real number)<br>
3.0 is not a valid integer (decimal point should not be displayed)<br>
3. is not a valid integer (decimal point should not be displayed)<br>
- 5 is not a valid integer (there should be no blank between the minus sign and the first digit.<br>
--5 is not a valid integer (only one minus sign allowed)<br>
+5 is not a valid integer (plus sign is not allowed)<br><br>

Variables: All variables should be declared as an integer. Variables must be declared before they are used. All variables are global (and static).<br>
int <variable>.<br>
Variable names are case sensitive and have a maximum length of 20 characters. Variable names start with a letter (alphabetical character) and continue with alphanumeric characters or an underscore character.<br>
example: int myVar.<br>
All variables are initialized with the value 0 at the time of creation.<br><br>

Assignment Statement:<br>
move <int_value> to <variable>.<br>
example: move 25 to myVar. {assigns 25 to myVar}<br>
move myVar to yourVar. {assigns myVar to yourVar}<br><br>

Addition statement:<br>
add <int_value> to <variable>.<br>
Increments the variable by int_value.<br>
example: add 2 to sum . {The value of sum increases by 2}<br><br>

Subtraction statement:<br>
sub <int_value> from <variable>.<br>
example: sub t from total. {The value of total decreases by t}<br><br>

Output statement:<br>
out <out_list>.<br>
example: out “The result is:”,sum.<br><br>

An integer value is either a variable or a constant.<br>
<int_value>→<variable>|<int_const><br><br>

An output list is a list of strings and integer values separated by commas.<br>
<out_list>→<out_list>,<list_element>|<list_element><br>
<list_element>→<int_value>|<string><br>

Loop:<br>
loop <int_value> times <line><br>
{OR}<br>
loop <int_value> times <code_block><br><br>

A loop starts with the int_value and at each iteration decrements the value of int_value by one. If int_value is a variable, the value of the variable can be accessed and modified during the loop. After the loop the variable takes the value 0. The last iteration of the loop operates with the value 1.<br>
example:<br>
loop 10 times out “*”. {writes 10 stars on the screen}<br><br>
