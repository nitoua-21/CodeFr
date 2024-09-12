# CodeFr Compiler

## Description

CodeFr Compiler is an educational project aimed at simplifying programming for French-speaking beginners. It allows users to write and execute algorithms directly in French, reducing the learning curve associated with English-based programming languages.

This compiler translates French pseudocode into executable programs, bridging the gap between algorithmic thinking and practical programming skills.

## Version

Current version: 1.1

## Features

- Basic arithmetic operations
- Variable declaration and assignment
- Output functionality using `Ecrire`
- Support for integer data type

## Prerequisites

To build and run the CodeFr Compiler, you need:

- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Make

## Installation

1. Clone the repository:

```bash
git clone https://github.com/your-username/codefr-compiler.git
cd codefr-compiler
```

2. Build the project:

```bash
make
```

## Usage

1. Run the compiler:

```bash
./codefr
```

2. Enter CodeFr statements directly, or use a file:

```
./codefr file.fr
```

Example usage:

```plaintext
Variable x : Entier
x = 5
Variable y : Entier
y = 3
Ecrire(x + y)
x = x * 2
Ecrire(x)
```

## Project Structure

- `lexer.l`: Flex file for lexical analysis
- `parser.y`: Bison file for parsing
- `main.c`: Main entry point of the compiler
- `Makefile`: Build configuration

## Contributing

Contributions to the CodeFr Compiler are welcome! Please feel free to submit a Pull Request.


## Authors

- Normich ITOUA - Initial work

## Future Enhancements

- Support for additional data types (float, string, boolean)
- Implementation of control structures (if-else, loops)
- Function definitions and calls
- Error handling and informative error messages
- Standard library of basic French programming constructs
