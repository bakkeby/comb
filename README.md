# `comb`: A combination generator

`comb` is a simple tool that generates combinations from the possible values given the specified
sample size and prints the results to standard out.

The first argument is the sample size; it is the number of values to pick per combination.

This would be the r in the nCr formula for computing combinations with n being the number of values.

The remaining arguments are the values to pick from.

If an argument contains multiple values separated by space then these will be treated as individual
but non-combinable values.

This program does not read from standard in.

Example usage:
```
$ comb 4 A B C D E
A B C D
A B C E
A B D E
A C D E
B C D E
```
```
$ comb 3 A B C "D E"
A B C
A B D
A B E
A C D
A C E
B C D
B C E
```

## Installation

```
$ git clone https://github.com/bakkeby/comb.git
$ cd comb
$ sudo make install
$ comb
```

## License

`comb` is available under an MIT license. See the `LICENSE` file.
