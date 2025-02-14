# CodeFr

[Version Française](README.fr.md) | [English Version](README.md)

## Introduction

CodeFr is an educational interpreter aimed at simplifying programming for French-speaking beginners. It allows users to write and execute algorithms directly in French, providing a more intuitive way for newcomers to grasp programming concepts. CodeFr is built using the power of modern interpreter technologies, including Flex for lexical analysis, Bison for syntax parsing, and C for execution, seamlessly translating French pseudocode into executable instructions.

The aim is to bridge the gap between algorithmic thinking and practical programming, helping users develop foundational skills without the overhead of learning English programming syntax.

- [Landing Page](https://nitoua-21.github.io/codefr_page/)

## Version

Current version: 1.0

## Language Documentation

### Program Structure

A CodeFr program can have one of the following structures:

1. Simple Program:
```
// Declarations (Variables, Constants, Arrays)
Debut
    // Program statements
Fin
```

2. Program with Modules:
```
Module ModuleName
    // Function declarations
    // and other module elements
FinModule
```

3. Program with Imports:
```
// Module imports
Importer Module1
Depuis Module2 Importer function1, function2

// Declarations
Debut
    // Program statements
Fin
```

Declarations must always precede the `Debut...Fin` block, and imports must precede declarations.

#### Supported Data Types
- `Entier`: Integer numbers
- `Decimal`: Floating-point numbers
- `Chaine`: String values
- `Logique`: Boolean values (Vrai/Faux)

#### Constants Declaration
```
Constante PI: 3.14159
Constante MESSAGE: "Hello"
Constante ENABLED: Vrai
```

### Arrays

#### Single Dimension Arrays
Declaration:
```
Tableau T[5]: Entier
```

Usage:
```
T[0] = 10
T[1] = 20
Ecrire(T[0])
```

#### Two-Dimensional Arrays
Declaration:
```
Tableau M[3][2]: Entier
```

Usage:
```
M[0][0] = 10
M[1][1] = 20
Ecrire(M[0][0])
```

### Operators

#### Arithmetic Operators
- `+` : Addition
- `-` : Subtraction
- `*` : Multiplication
- `/` : Division
- `Mod` : Modulo
- `^` : Power

#### Comparison Operators
- `<` : Less than
- `>` : Greater than
- `<=` : Less than or equal
- `>=` : Greater than or equal
- `==` : Equal to
- `!=` : Not equal to

#### Logical Operators
- `Et` : Logical AND
- `Ou` : Logical OR
- `Non` : Logical NOT
- `Oux` : Logical XOR

### Control Structures

#### If Statement
```
Si condition Alors
    // statements
FinSi

Si condition Alors
    // statements
Sinon
    // statements
FinSi
```

#### While Loop
```
TantQue condition Faire
    // statements
FinTantQue
```

#### For Loop
```
Pour counter De start A end Faire
    // statements
FinPour
```

#### Switch Statement
```
Selon expression Faire
    Cas value1:
        // statements
    Cas value2:
        // statements
    Sinon
        // default statements
FinSelon
```

### User-Defined Functions

Functions can be defined using two different syntaxes, depending on whether they return a value or not.

#### Function without return value
```
Fonction FunctionName(arg1: type, arg2: type, ...)
    // Local declarations
    // Statements
FinFonction
```

Example:
```
Fonction DisplayMessage(message: Chaine)
    Ecrire(message)
FinFonction
```

#### Function with return value
```
Fonction FunctionName(arg1: type, arg2: type, ...): type
    // Local declarations
    // Statements
    Retourner Expression
FinFonction
```

Example:
```
Fonction Sum(a: Entier, b: Entier): Entier
    Variable result: Entier
    result = a + b
    Retourner result
FinFonction
```

### Modules

Modules allow you to organize and reuse code by separating it into different files. The module name corresponds to the file name (without the `.cfr` extension).

#### Creating a Module
Example module `Calculs.cfr`:
```
Fonction addition(a, b)
    Retourner a + b
FinFonction

Fonction soustraction(a, b)
    Retourner a - b
FinFonction

Fonction multiplication(a, b)
    Retourner a * b
FinFonction
```

#### Importing Modules

##### Import an Entire Module
```
Importer Calculs

resultat_addition = Calculs.addition(5, 3)
Ecrire(resultat_addition)

resultat_soustraction = Calculs.soustraction(10, 4)
Ecrire(resultat_soustraction)
```

##### Import Specific Functions
```
Depuis Calculs Importer addition

resultat = addition(7, 2)
Ecrire(resultat)
```

#### Running Programs with Modules
To run a program using modules, specify all the necessary files:
```bash
./codefr calculs.cfr main.cfr
```

### Mathematical Functions
- `Racine(x)`: Square root
- `Sin(x)`: Sine
- `Cos(x)`: Cosine
- `Tan(x)`: Tangent
- `Log(x)`: Natural logarithm
- `Log10(x)`: Base-10 logarithm
- `Arrondi(x)`: Round
- `Abs(x)`: Absolute value
- `Ent(x)`: Integer part
- `Alea()`: Random number between 0 and 1
- `Alea(min, max)`: Random number between min and max

### String Operations
- `Longueur(str)`: String length
- `Concatener(str1, str2)`: String concatenation
- `Comparer(str1, str2)`: String comparison
- `Recherche(str1, str2)`: Search substring
- `Copie(str, pos, n)`: Extract substring

### Input/Output
```
Ecrire(expression)        // Output
Ecrire("Hello", x, y)    // Multiple values output
Lire(variable)           // Input
```

## Prerequisites

To build and run the CodeFr Compiler, you need:

- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Make

## Installation option 1: using the prebuilt `.deb` package

To install the CodeFr Interpreter using the prebuilt `.deb` package, follow these steps:

1. Download the `.deb` package:
```bash
   wget https://github.com/nitoua-21/CodeFr/builds/codefr-interpreter_1.0_amd64.deb
```

2. Install the package using dpkg:

```bash
   sudo dpkg -i codefr-interpreter_1.0_amd64.deb
```

## Installation option 2: compiling the code

1. Clone the repository:

```bash
git clone https://github.com/nitoua-21/CodeFr
cd Codefr
```

2. Build the project:

```bash
make
```

## Usage

1. Create a file with `.cfr` extension containing your program
2. Run the interpreter:

```bash
./codefr program.cfr
```

## Example Programs

### Example 1: Basic Calculator
```
Variable a: Entier
Variable b: Entier
Variable op: Chaine
Variable resultat: Decimal

Debut
    Ecrire("Enter first number: ")
    Lire(a)
    Ecrire("Enter operation (+,-,*,/): ")
    Lire(op)
    Ecrire("Enter second number: ")
    Lire(b)

    Si op == "+" Alors
        result = a + b
    SinonSi op == "-" Alors
        result = a - b
    SinonSi op == "*" Alors
        result = a * b
    SinonSi op == "/" Alors
        Si b == 0 Alors
            Ecrire("Error: Division by zero!")
        Sinon
            result = a / b
        FinSi
    FinSi

    Ecrire("Result: ", result, "\n")
Fin
```

### Example 2: Array Operations
```
Variable sum: Entier
Variable i: Entier
Tableau numbers[5]: Entier

Debut
    // Initialize array
    Pour i De 0 A 4 Faire
        numbers[i] = i * 2
    FinPour

    // Calculate sum
    sum = 0
    Pour i De 0 A 4 Faire
        sum = sum + numbers[i]
    FinPour

    Ecrire("Sum of array elements: ", sum, "\n")
Fin
```

## Project Structure

- `lexer.l`: The Flex file responsible for breaking the source code into tokens (lexical analysis).
- `parser.y`: The Bison file that parses the tokens and generates the abstract syntax tree (syntax analysis).
- `main.c`: The main entry point of the interpreter.
- `Makefile`: Automates the build process using gcc, flex, and bison.
- `ast.c`, `expression.c`: Contains the logic for evaluating the program's AST (execution).
- `symbol.c`: Contains the logic for managing the Symbol Table.
- `helpers`: Helper functions

## Contributing

Contributions are welcome! If you'd like to improve CodeFr, feel free to submit a pull request. Some areas that need enhancement include adding more complex control structures, expanding data types, and improving error handling.

## Authors

- Normich ITOUA - Initial work | [Github](https://github.com/nitoua-21) / [Twitter](https://x.com/ItouaNormich) 


## License

This project is open-source, public, and free to use, modify, and distribute. You are welcome to use CodeFr for any purpose, including personal, educational, or commercial projects.