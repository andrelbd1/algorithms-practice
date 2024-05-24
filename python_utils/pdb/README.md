### Debugging With [Pdb](https://docs.python.org/3/library/pdb.html)
- Pdb is part of Python’s standard library, so it’s always there and available for use.
- Insert the following code at the location where you want to break into the debugger:
````bash
    import pdb; pdb.set_trace() 
````

- When the line above is executed, Python stops and waits for you to tell it what to do next.
- Starting in Python 3.7, there’s another way to enter the debugger. [PEP 553](https://peps.python.org/pep-0553/) describes the built-in function breakpoint(), which makes entering the debugger easy and consistent:
````bash
    breakpoint()
````

- By default, breakpoint() will import pdb and call pdb.set_trace(), as shown above. However, using breakpoint() is more flexible and allows you to control debugging behavior via its API and use of the environment variable PYTHONBREAKPOINT. For example, setting PYTHONBREAKPOINT=0 in your environment will completely disable breakpoint(), thus disabling debugging.

- You can also invoke pdb from the command line to debug other scripts. For example:
````bash
    python -m pdb myscript.py
````

#### Example 1 - Printing a Variable’s Value
- Let’s use the p command to print a variable’s value. Enter p variable_name at the (Pdb) prompt to print its value. Let’s look at the example. Here’s the example1.py source:
- [example1.py](example1.py)

- Run this from your shell:
````bash
    ./example1.py
````

- Now enter p filename. You should see file name.
````bash
    p filename
````

#### Example 2 - Printing Expressions
- Let’s print some expressions to look at the current state of the application. Here’s the example2.py source:
- [example2.py](example2.py)

- Run this from your shell:
````bash
    ./example2.py
````

- Now use the command ll (longlist) initially to list the function’s source.
````bash
    ll
````

#### Example 3 - Stepping Through Code
- There are two commands you can use to step through code when debugging:
    - n (next): Continue execution until the next line in the current function is reached or it returns.
    - s (step): Execute the current line and stop at the first possible occasion (either in a function that is called or in the current function).

- Let’s look at an example using both commands. Here’s the example3.py source:
- [example3.py](example3.py)

- If you run this from your shell and enter n, you should get the output:
````bash
    $ ./example3.py 
    > /pdb/example3.py(14)<module>()
    -> filename_path = get_path(filename)
````

````bash
    (Pdb) n
    > /pdb/example3.py(15)<module>()
    -> print(f'path = {filename_path}')
````

- Let’s try s:
````bash
    $ ./example3.py 
    > /pdb/example3.py(14)<module>()
    -> filename_path = get_path(filename)
````

````bash
    (Pdb) s
    --Call--
    > /pdb/example3.py(6)get_path()
    -> def get_path(filename):
````

#### Example 4 - Using Breakpoints
- Use the command b (break) to set a breakpoint. You can specify a line number or a function name where execution is stopped. The syntax for break is:
````bash
    b(reak) [ ([filename:]lineno | function) [, condition] ]
````

- In this example, there’s a utility module util.py. Let’s set a breakpoint to stop execution in the function get_path().
- Here’s the source for the main script example4.py:
- [example4.py](example4.py)

- Here’s the source for the utility module util.py:
- [util.py](util.py)

- Let’s set a breakpoint using the source filename and line number:
````bash
    $ ./example4.py 
    > /pdb/example4.py(7)<module>()
    -> filename_path = util.get_path(filename)
````

````bash
    (Pdb) b util:5
    Breakpoint 1 at /pdb/util.py:5
````

- The command c (continue) continues execution until a breakpoint is found.
````bash
    (Pdb) c
    > /pdb/util.py(5)get_path()
    -> return head
````

- Next, let’s set a breakpoint using the function name:
````bash
    $ ./example4.py 
    > /pdb/example4.py(7)<module>()
    -> filename_path = util.get_path(filename)
````

````bash
    (Pdb) b util.get_path
    Breakpoint 1 at /pdb/util.py:1
````

````bash
    (Pdb) c
    > /pdb/util.py(3)get_path()
    -> import os
````

- Enter b with no arguments to see a list of all breakpoints:
````bash
    (Pdb) b
    Num Type         Disp Enb   Where
    1   breakpoint   keep yes   at /pdb/util.py:1
            breakpoint already hit 1 time
````

- You can disable and re-enable breakpoints using the command disable bpnumber and enable bpnumber. bpnumber is the breakpoint number from the breakpoints list’s 1st column Num. Notice the Enb column’s value change:
````bash
    (Pdb) disable 1
    Disabled breakpoint 1 at /pdb/util.py:1
````

````bash
    (Pdb) b
    Num Type         Disp Enb   Where
    1   breakpoint   keep no    at /pdb/util.py:1
            breakpoint already hit 1 time
````

- To delete a breakpoint, use the command cl (clear):
````bash
    cl(ear) filename:lineno
    cl(ear) [bpnumber [bpnumber...]]
````

- Now let’s use a Python expression to set a breakpoint. Imagine a situation where you wanted to break only if your troubled function received a certain input. In this example scenario, the get_path() function is failing when it receives a relative path, i.e. the file’s path doesn’t start with /. I’ll create an expression that evaluates to true in this case and pass it to b as the 2nd argument:
````bash
    $ ./example4.py
    > /pdb/example4.py(7)<module>()
    -> filename_path = util.get_path(filename)
````

````bash
    (Pdb) b util.get_path, not filename.startswith('/')
    Breakpoint 1 at /pdb/util.py:1
````

- After you create the breakpoint above and enter c to continue execution, pdb stops when the expression evaluates to true.
````bash
    (Pdb) c
    > /pdb/util.py(3)get_path()
    -> import os
````

- The command a (args) prints the argument list of the current function.
````bash
    (Pdb) a
    filename = './example4.py' 
````

- If you need to break using an expression with a variable name located inside a function, i.e. a variable name not in the function’s argument list, specify the line number:
````bash
    $ ./example4.py 
    > /pdb/example4.py(7)<module>()
    -> filename_path = util.get_path(filename)
````

````bash
    (Pdb) b util:5, not head.startswith('/')
    Breakpoint 1 at /pdb/util.py:5
````

````bash
    (Pdb) c
    > /code/util.py(5)get_path()
    -> return head
````

````bash
    (Pdb) p head
    '.'
````

````bash
    (Pdb) a
    filename = './example4.py'
````

- You can also set a temporary breakpoint using the command tbreak. It’s removed automatically when it’s first hit. It uses the same arguments as b.

#### Example 5 - Displaying Expressions
- Similar to printing expressions with p and pp, you can use the command display [expression] to tell pdb to automatically display the value of an expression, if it changed, when execution stops. Use the command undisplay [expression] to clear a display expression.

- Below is an example, example5.py, demonstrating its use with a loop:
- [example5.py](example5.py)

````bash
    $ ./example5.py 
    > /pdb/example5.py(9)get_path()
    -> head, tail = os.path.split(fname)
````

````bash
    (Pdb) ll
    6     def get_path(fname):
    7         """Return file's path or empty string if no path."""
    8         breakpoint()
    9  ->     head, tail = os.path.split(fname)
    10         for char in tail:
    11             pass  # Check filename char
    12         return head
````

````bash
    (Pdb) b 11
    Breakpoint 1 at /pdb/example5.py:11
````

````bash
    (Pdb) c
    > /pdb/example5.py(11)get_path()
    -> pass  # Check filename char
````

- You can enter display multiple times to build a watch list of expressions. This can be easier to use than p. 
````bash
    (Pdb) display char
    display char: 'e'
````

````bash
    (Pdb) c
    > /pdb/example5.py(11)get_path()
    -> pass  # Check filename char
    display char: 'x'  [old: 'e']
````

````bash
    (Pdb) 
    > /pdb/example5.py(11)get_path()
    -> pass  # Check filename char
    display char: 'a'  [old: 'x']
````

````bash
    (Pdb) 
    > /pdb/example5.py(11)get_path()
    -> pass  # Check filename char
    display char: 'm'  [old: 'a']
````

#### Example 6 - Stack Trace
- In this scenario, imagine there’s a large code base with a function in a utility module, get_path(), that’s being called with invalid input. However, it’s being called from many places in different packages. Use the command w (where) to print a stack trace, with the most recent frame at the bottom:

- Below is an example, example6.py, demonstrating its use:
- [example6.py](example6.py)

- Use the command w (where) to print a stack trace, with the most recent frame at the bottom:
````bash
    $ ./example6.py 
    > /pdb/fileutil.py(5)get_path()
    -> head, tail = os.path.split(fname)
````

````bash
    (Pdb) w
    /pdb/example6.py(12)<module>()
    -> filename_path = get_file_info(filename)
    /pdb/example6.py(7)get_file_info()
    -> file_path = fileutil.get_path(full_fname)
    > /pdb/fileutil.py(5)get_path()
    -> head, tail = os.path.split(fname)
````

- You can use the two commands u (up) and d (down) to change the current frame. Combined with p, this allows you to inspect variables and state in your application at any point along the call stack in any frame. Here’s the syntax and description for both commands:
````bash
    u(p) [count]: Move the current frame count (default one) levels up in the stack trace (to an older frame).
    d(own) [count]: Move the current frame count (default one) levels down in the stack trace (to a newer frame).
````

- Let’s look at an example using the u and d commands. The call to breakpoint() is in fileutil.py in the function get_path(), so the current frame is initially set there. You can see it in the 1st line of output above:
````bash
    $ ./example6.py 
    > /pdb/fileutil.py(5)get_path()
    -> head, tail = os.path.split(fname)
````

````bash
    (Pdb) w
    /pdb/example6.py(12)<module>()
    -> filename_path = get_file_info(filename)
    /pdb/example6.py(7)get_file_info()
    -> file_path = fileutil.get_path(full_fname)
    > /pdb/fileutil.py(5)get_path()
    -> head, tail = os.path.split(fname)
````

- To access and print the local variable full_fname in the function get_file_info() in example6.py, the command u was used to move up one level:
````bash
    (Pdb) u
    > /pdb/example6.py(7)get_file_info()
    -> file_path = fileutil.get_path(full_fname)
````

````bash
    (Pdb) p full_fname
    './example6.py'
````

````bash
    (Pdb) d
    > /pdb/fileutil.py(5)get_path()
    -> head, tail = os.path.split(fname)
````

````bash
    (Pdb) p fname
    './example6.py'
````

#### Essential commands
- Just enter h or help <topic> to get a list of all commands or help for a specific command or topic. For quick reference, here’s a list of essential commands:

````bash
    p	Print the value of an expression.
    pp	Pretty-print the value of an expression.
````
````bash
    c	Continue execution and only stop when a breakpoint is encountered.
    n	Continue execution until the next line in the current function is reached or it returns.
    s	Execute the current line and stop at the first possible occasion (either in a function that is called or in the current function).
````
````bash
    l	List source code for the current file.
    ll	List the whole source code for the current function or frame.
````
````bash
    b	With no arguments, list all breaks. With a line number argument, set a breakpoint at this line in the current file.
````
````bash
    w	Print a stack trace, with the most recent frame at the bottom.
    u	Move the current frame count (default one) levels up in the stack trace (to an older frame).
    d	Move the current frame count (default one) levels down in the stack trace (to a newer frame).
````
````bash
    h	See a list of available commands.
    h <topic>	Show help for a command or topic.
    h pdb	Show the full pdb documentation.
````
````bash
    q	Quit the debugger and exit.
````

### [Back](../../README.md)