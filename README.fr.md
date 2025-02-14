# CodeFr

[Version Française](README.fr.md) | [English Version](README.md)

## Introduction

CodeFr est un interpréteur éducatif visant à simplifier la programmation pour les débutants francophones. Il permet aux utilisateurs d'écrire et d'exécuter des algorithmes directement en français, offrant une approche plus intuitive pour les nouveaux venus dans l'apprentissage des concepts de programmation. CodeFr est construit en utilisant la puissance des technologies modernes d'interprétation, notamment Flex pour l'analyse lexicale, Bison pour l'analyse syntaxique, et C pour l'exécution, traduisant de manière transparente le pseudocode français en instructions exécutables.

- [Page d'accueil](https://nitoua-21.github.io/codefr_page/)

## Version

Version actuelle : 1.1

## Documentation du Langage

### Structure du Programme

Un programme CodeFr peut avoir l'une des structures suivantes :

1. Programme Simple :
```
// Déclarations (Variables, Constantes, Tableaux)
Debut
    // Instructions du programme
Fin
```

2. Programme avec Modules :
```
Module NomModule
    // Déclarations de fonctions
    // et autres éléments du module
FinModule
```

3. Programme avec Imports :
```
// Imports de modules
Importer Module1
Depuis Module2 Importer fonction1, fonction2

// Déclarations
Debut
    // Instructions du programme
Fin
```

Les déclarations doivent toujours précéder le bloc `Debut...Fin`, et les imports doivent précéder les déclarations.

#### Déclaration de Variables
```
Variable nom: Type
```

#### Types de Données Supportés
- `Entier`: Nombres entiers
- `Decimal`: Nombres décimaux
- `Chaine`: Chaînes de caractères
- `Logique`: Valeurs booléennes (Vrai/Faux)

#### Déclaration de Constantes
```
Constante PI: 3.14159
Constante MESSAGE: "Bonjour"
Constante ACTIVE: Vrai
```

### Tableaux

#### Tableaux à Une Dimension
Déclaration :
```
Tableau T[5]: Entier
```

Utilisation :
```
T[0] = 10
T[1] = 20
Ecrire(T[0])
```

#### Tableaux à Deux Dimensions
Déclaration :
```
Tableau M[3][2]: Entier
```

Utilisation :
```
M[0][0] = 10
M[1][1] = 20
Ecrire(M[0][0])
```

### Opérateurs

#### Opérateurs Arithmétiques
- `+` : Addition
- `-` : Soustraction
- `*` : Multiplication
- `/` : Division
- `Mod` : Modulo
- `^` : Puissance

#### Opérateurs de Comparaison
- `<` : Inférieur à
- `>` : Supérieur à
- `<=` : Inférieur ou égal à
- `>=` : Supérieur ou égal à
- `==` : Égal à
- `!=` : Différent de

#### Opérateurs Logiques
- `Et` : ET logique
- `Ou` : OU logique
- `Non` : NON logique
- `Oux` : OU exclusif

### Structures de Contrôle

#### Structure Conditionnelle
```
Si condition Alors
    // instructions
FinSi

Si condition Alors
    // instructions
Sinon
    // instructions
FinSi
```

#### Boucle TantQue
```
TantQue condition Faire
    // instructions
FinTantQue
```

#### Boucle Pour
```
Pour compteur De debut A fin Faire
    // instructions
FinPour
```

#### Structure Selon
```
Selon expression Faire
    Cas valeur1:
        // instructions
    Cas valeur2:
        // instructions
    Sinon
        // instructions par défaut
FinSelon
```

### Fonctions Utilisateur

Les fonctions peuvent être définies selon deux syntaxes différentes, selon qu'elles retournent ou non une valeur.

#### Fonction sans retour
```
Fonction NomFonction(arg1: type, arg2: type, ...)
    // Déclarations locales
    // Instructions
FinFonction
```

Exemple:
```
Fonction AfficherMessage(message: Chaine)
    Ecrire(message)
FinFonction
```

#### Fonction avec retour
```
Fonction NomFonction(arg1: type, arg2: type, ...): type
    // Déclarations locales
    // Instructions
    Retourner Expression
FinFonction
```

Exemple:
```
Fonction Somme(a: Entier, b: Entier): Entier
    Variable resultat: Entier
    resultat = a + b
    Retourner resultat
FinFonction
```

### Modules

Les modules permettent d'organiser et de réutiliser le code en le séparant dans différents fichiers. Le nom du module correspond au nom du fichier (sans l'extension `.cfr`).

#### Création d'un Module
Exemple de module `Calculs.cfr` :
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

#### Importation de Modules

##### Importer un Module Complet
```
Importer Calculs

resultat_addition = Calculs.addition(5, 3)
Ecrire(resultat_addition)

resultat_soustraction = Calculs.soustraction(10, 4)
Ecrire(resultat_soustraction)
```

##### Importer des Fonctions Spécifiques
```
Depuis Calculs Importer addition

resultat = addition(7, 2)
Ecrire(resultat)
```

#### Exécution de Programmes avec Modules
Pour exécuter un programme utilisant des modules, spécifiez tous les fichiers nécessaires :
```bash
./codefr calculs.cfr main.cfr
```

### Fonctions Mathématiques
- `Racine(x)` : Racine carrée
- `Sin(x)` : Sinus
- `Cos(x)` : Cosinus
- `Tan(x)` : Tangente
- `Log(x)` : Logarithme naturel
- `Log10(x)` : Logarithme base 10
- `Arrondi(x)` : Arrondi
- `Abs(x)` : Valeur absolue
- `Ent(x)` : Partie entière
- `Alea()` : Nombre aléatoire entre 0 et 1
- `Alea(min, max)` : Nombre aléatoire entre min et max

### Opérations sur les Chaînes
- `Longueur(str)` : Longueur de la chaîne
- `Concatener(str1, str2)` : Concaténation de chaînes
- `Comparer(str1, str2)` : Comparaison de chaînes
- `Recherche(str1, str2)` : Recherche de sous-chaîne
- `Copie(str, pos, n)` : Extraction de sous-chaîne

### Entrées/Sorties
```
Ecrire(expression)        // Sortie
Ecrire("Bonjour", x, y)  // Sortie multiple
Lire(variable)           // Entrée
```

## Prérequis

Pour compiler et exécuter le Compilateur CodeFr, vous avez besoin de :

- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Make

## Installation

1. Clonez le dépôt :

```bash
git clone clone https://github.com/nitoua-21/CodeFr
cd Codefr
```

2. Compilez le projet :

```bash
make
```

## Utilisation

1. Créez un fichier avec l'extension `.algo` contenant votre programme
2. Exécutez l'interpréteur :

```bash
./codefr programme.algo
```

## Exemples de Programmes

### Exemple 1 : Calculatrice Simple
```
Variable a: Entier
Variable b: Entier
Variable op: Chaine
Variable resultat: Decimal

Debut
    Ecrire("Entrez le premier nombre : ")
    Lire(a)
    Ecrire("Entrez l'opération (+,-,*,/) : ")
    Lire(op)
    Ecrire("Entrez le deuxième nombre : ")
    Lire(b)

    Si op == "+" Alors
        resultat = a + b
    SinonSi op == "-" Alors
        resultat = a - b
    SinonSi op == "*" Alors
        resultat = a * b
    SinonSi op == "/" Alors
        Si b == 0 Alors
            Ecrire("Erreur : Division par zéro!")
        Sinon
            resultat = a / b
        FinSi
    FinSi

    Ecrire("Résultat : ", resultat, "\n")
Fin
```

### Exemple 2 : Opérations sur Tableaux
```
Variable somme: Entier
Variable i: Entier
Tableau nombres[5]: Entier

Debut
    // Initialisation du tableau
    Pour i De 0 A 4 Faire
        nombres[i] = i * 2
    FinPour

    // Calcul de la somme
    somme = 0
    Pour i De 0 A 4 Faire
        somme = somme + nombres[i]
    FinPour

    Ecrire("Somme des éléments du tableau : ", somme, "\n")
Fin
```

## Structure du Projet

- `lexer.l` : Fichier Flex responsable de la décomposition du code source en jetons (analyse lexicale).
- `parser.y` : Fichier Bison qui analyse les jetons et génère l'arbre de syntaxe abstraite (analyse syntaxique).
- `main.c` : Point d'entrée principal de l'interpréteur.
- `Makefile` : Automatise le processus de compilation en utilisant gcc, flex et bison.
- `ast.c`, `expression.c` : Contient la logique d'évaluation de l'AST (exécution).
- `symbol.c` : Contient la logique de gestion de la Table des Symboles.
- `helpers` : Fonctions utilitaires

## Contribution

Les contributions sont les bienvenues ! Si vous souhaitez améliorer CodeFr, n'hésitez pas à soumettre une pull request. Certains domaines nécessitant des améliorations incluent l'ajout de structures de contrôle plus complexes, l'extension des types de données et l'amélioration de la gestion des erreurs.

## Auteurs

- Normich ITOUA - Travail initial | [Github](https://github.com/nitoua-21) / [Twitter](https://x.com/ItouaNormich) 


## Licence

Ce projet est open-source, public et libre d'utilisation, de modification et de distribution. Vous êtes libre d'utiliser CodeFr pour tout usage, y compris personnel, éducatif ou commercial.
