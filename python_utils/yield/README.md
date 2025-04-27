### Yield
- Yield is a fairly simple statement. Its primary job is to control the flow of a generator function in a way that’s similar to return statements.
- When you call a generator function or use a generator expression, you return a special iterator called a generator. You can assign this generator to a variable in order to use it. When you call special methods on the generator, such as `next()`, the code within the function is executed up to yield.
- When the Python yield statement is hit, the program suspends function execution and returns the yielded value to the caller. When a function is suspended, the state of that function is saved. This includes any variable bindings local to the generator, the instruction pointer, the internal stack, and any exception handling.


#### Examples
- [Code 1](example_1.py)
- [Code 2](example_2.py)


### [Back](../../README.md)