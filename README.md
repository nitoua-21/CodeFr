# CodeFr

## Description

CodeFr is an educational project aimed at simplifying programming for French-speaking beginners. It allows users to write and execute algorithms directly in French, reducing the learning curve associated with English-based programming languages.

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

```
./codefr file.fr
```

### Conditional Example:

```plaintext
Algorithme Signe_numbre

Variable n : Entier

Debut
    Ecrire("Enter an integer: ")
    Lire(n)

    // Check if the number is positive
    Si n > 0 Alors
        Ecrire("You entered a positive number: ", n, "\n")
    FinSi
Fin

```

### Loops example

```
Algorithme Boucle

Variable i : Entier

Debut
    i = 0
    TantQue i < 5 Faire
        Ecrire(i, "\n")
        i = i + 1
    FinTanQue
Fin
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
