### Map function
- For an alternative approach that’s based in functional programming, you can use `map()`. You pass in a function and an iterable, and `map()` will create an object. This object contains the result that you’d get from running each iterable element through the supplied function. The `map()` function will return an iterator that yields the results. This can allow for some very concise code because a `map()` statement can often take the place of an explicit loop.

````bash
    map(<f>, <iterable>)
    map(<f>, <iterable₁>, <iterable₂>, ..., <iterableₙ>)
````

#### Examples
- [Code](example_1.py)
- [Code](example_2.py)
- [Code](example_3.py)


### [Back](../../README.md)