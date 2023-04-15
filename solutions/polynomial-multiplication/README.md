### Polynomial Multiplication
- Given two polynomials, present an algorithm to multiplicate them. Since input is n+1 coefficients of each polynomial of n degree, as well as output is 2n + 1 coefficients from resulted polynomial.
- Develop a solution using:
    - trivial multiplication
    - divide and conquer
    - Fast Fourier Transform

- **Input**:
````bash
        n
        i0 i1 ... in
        j0 j2 ... jn
````

- **Output**:
````bash
        Trivial
        result

        Divide-n-Conquer
        result

        Fast Fourier Transform
        result
````

- [Solution](algorithms.c)

#### Running
- Compiling:
````bash
    $ make
````

- Running an instance:
````bash
    ./polymul "path_instance"
````

- Example: running an instance "input_simple1.dat":
````bash
    ./polymul instances/input_simple1.dat
````