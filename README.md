# BigAdd Language
<p>Lexical Analyzer and Interpreter for BigAdd Language - 2019 (C)</p>

<p>BigAdd language is a small programming language that has been designed in order to add and subtract big integers programmatically and display the result on the screen. BigAdd is an interpreted language.</p>

<h3>End of Line:</h3>
<p>Point (".") is the end of line character. Lines can contain keywords, brackets, variables and constants. Any number of spaces or comments can be used between these elements. A program line can be divided between multiple text lines.</p>
<p>A line of code is one of the following:</p>
<ul>
  <li>A variable declaration.</li>
  <li>An assignment statement.</li>
  <li>An addition statement.</li>
  <li>A subtraction statement.</li>
  <li>An output statement.</li>
  <li>A loop statement.</li>
</ul>

<h3>Comments:</h3>
<p>Comments are written between curly braces { }</p>
<p>Example Code:</p>
  
```html
{this is a comment}{ and
this is a comment too}
```

<h3>Data Types:</h3>
<p>The only data type for variables is the integer. Integer is a signed whole number that is represented as a decimal data type. An integer can be as big as 100 decimal digits. Strings exist only as constants and are used in the out statements only.</p>
<p>Example:<p>
<ul>
  <li>123113, -5, 0, -314159 are valid integer representations.</li>
  <li>3.14159 is not a valid integer (it is a real number).</li>
  <li>3.0 is not a valid integer (decimal point should not be displayed).</li>
  <li>3. is not a valid integer (decimal point should not be displayed).</li>
  <li>- 5 is not a valid integer (there should be no blank between the minus sign and the first digit.</li>
  <li>--5 is not a valid integer (only one minus sign allowed).</li>
  <li>+5 is not a valid integer (plus sign is not allowed).</li>
</ul>

<h3>Variables:</h3>
<p>All variables should be declared as an integer. Variables must be declared before they are used. All variables are global (and static).</p>
<p>int [variable].</p>
<p>Variable names are case sensitive and have a maximum length of 20 characters. Variable names start with a letter (alphabetical character) and continue with alphanumeric characters or an underscore character. All variables are initialized with the value 0 at the time of creation.</p>
<p>Example Code:</p>

```html
int myVar.
```

<h3>Assignment Statement:</h3>
<p>move [int_value] to [variable].<p>
<p>Example Code:</p>

```html
move 25 to myVar. {assigns 25 to myVar}
move myVar to yourVar. {assigns myVar to yourVar}
```

<h3>Addition statement:</h3>
<p>add [int_value] to [variable].</p>
<p>Example Code:</p>

```html
add 2 to sum . {The value of sum increases by 2}
```

<h3>Subtraction statement:</h3>
<p>sub [int_value] from [variable].</p>
<p>Example Code:</p>

```html
sub t from total. {The value of total decreases by t}
```

<h3>Output statement:</h3>
<p>out [out_list].</p>
<p>Example Code:</p>

```html
out "The result is:",sum.
```

<p>An integer value is either a variable or a constant.</p>
<p>[int_value]→[variable]|[int_const]</p>

<p>An output list is a list of strings and integer values separated by commas.</p>
<p>[out_list]→[out_list],[list_element]|[list_element]</p>
<p>[list_element]→[int_value]|[string]</p>

<h3>Loop:</h3>
<p>loop [int_value] times [line] OR loop [int_value] times [code_block]</p>
<p>A loop starts with the int_value and at each iteration decrements the value of int_value by one. If int_value is a variable, the value of the variable can be accessed and modified during the loop. After the loop the variable takes the value 0. The last iteration of the loop operates with the value 1.</p>
<p>Example Code:</p>

```html
loop 10 times out "*". {writes 10 stars on the screen}
```
