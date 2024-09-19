# CodeFr

## Introduction

CodeFr is an educational interpreter aimed at simplifying programming for French-speaking beginners. It allows users to write and execute algorithms directly in French, providing a more intuitive way for newcomers to grasp programming concepts. CodeFr is built using the power of modern interpreter technologies, including Flex for lexical analysis, Bison for syntax parsing, and C for execution, seamlessly translating French pseudocode into executable instructions.

The aim is to bridge the gap between algorithmic thinking and practical programming, helping users develop foundational skills without the overhead of learning English programming syntax.

- [Landing Page](https://nitoua-21.github.io/codefr_page/)
- [Blog post]()

## Version

Current version: 1.1

## Features

- __Arithmetic operations__: Supports basic operations like addition, subtraction, multiplication, and division.
- __Variable declaration and assignment__: Variables can be declared and assigned values with support for integers, decimals, booleans, and strings.
- __Conditional statements__: Implement `Si`, `Sinon`, and `FinSi` (if, else, endif) structures.
- Input and output:   
    - `Ecrire`: Outputs values to the screen.
    - `Lire`: Reads input from the user.    
- __Data types__: Supports integers (`Entier`), decimals (`Decimal`), booleans (`Logique`), and strings (`Chaine`).

- __Comments__: Supports single-line (`//`) and multi-line (`/* ... */`) comments.


## How Does It Work?

CodeFr integrates several core technologies to interpret French pseudocode into executable programs. Here's a breakdown of how the different tools work together:

1. Lexical Analysis (Flex):
- Flex is responsible for scanning the input source code and breaking it down into tokens. Tokens are individual elements of the language, such as keywords (`Algorithme`, `Si`, `TantQue`), variables, operators, and symbols.
- The `lexer.l` file defines patterns to recognize these tokens and generates a token stream for the parser to process.

2. Parsing and Syntax Analysis (Bison):   
- Bison processes the token stream provided by Flex and constructs a hierarchical structure, known as the abstract syntax tree (AST).
- The `parser.y` file defines the grammar of the NI+ language, specifying how different statements (like conditionals, loops, and expressions) are structured.
For example, the rule for parsing a TantQue loop looks like this
```plaintext
SI expression ALORS statement_list FINSI { $$ = new_if($2, $4, NULL); }
```
- The parser then builds a representation of the program using nodes like loops, conditionals, and expressions.

3. Abstract Syntax Tree (AST):
- The AST is a data structure that represents the entire program in a tree format. Each node represents an operation (e.g., an assignment, a loop, or a condition).
- Nodes are generated through helper functions in ast.c, such as `new_print()` for print or `new_if()` for conditionals.

4.  Evaluation (C Code):
- The AST is then passed to an evaluator, which recursively traverses the tree, executing statements and evaluating expressions in the correct order.
- The main logic for executing the program is implemented in C, specifically in files like ast.c, which contains functions that evaluate various constructs like `Si` (if), `TantQue` (while), assignments, arithmetic operations, and more.

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

1. Run the interpreter:

```
./codefr file.fr
```

### Conditional Example:

```c
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

## Project Structure

- `lexer.l`: The Flex file responsible for breaking the source code into tokens (lexical analysis).
- `parser.y`: The Bison file that parses the tokens and generates the abstract syntax tree (syntax analysis).
- `main.c`: The main entry point of the interpreter.
- `Makefile`:Automates the build process using gcc, flex, and bison.
- `ast.c`, `expression.c`: Contains the logic for evaluating the program's AST (execution).
- `symbol.c`: Contains the logic for managing the Symbol Table.
- `helpers`: Helper functions

## Contributing

Contributions are welcome! If you'd like to improve CodeFr, feel free to submit a pull request. Some areas that need enhancement include adding more complex control structures, expanding data types, and improving error handling.


## Authors

- Normich ITOUA - Initial work | [Github](https://github.com/nitoua-21) / [Twitter](https://x.com/ItouaNormich) 

## Future Enhancements

- Support for arrays: Allow users to declare and manipulate arrays.
- Functions: Enable users to define and call functions.
- Error handling: Provide detailed and helpful error messages during lexical, syntactic, and runtime analysis.
- Standard library: Implement a set of utility functions for string manipulation, mathematical operations, and more.

## Related Projects

- __AlgoBox__: A free, educational software designed to introduce beginners to algorithmic thinking. It allows users to write pseudocode and execute algorithms in a structured, easy-to-learn environment.
    - [Website](https://www.xm1math.net/algobox/)

## Licencing:

This project is open-source, public, and free to use, modify, and distribute. You are welcome to use CodeFr for any purpose, including personal, educational, or commercial projects.
