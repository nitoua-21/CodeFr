# CodeFR - Un langage de programmation en français

## Table des matières

1. [Introduction](#introduction)
2. [Pour qui est CodeFR ?](#pour-qui-est-codefr)
3. [Documentation du langage](#documentation-du-langage)
   * [Types et variables](#types-et-variables)
      * [Types de données supportés](#types-de-données-supportés)
      * [Déclaration de variables](#déclaration-de-variables)
      * [Déclaration de constantes](#déclaration-de-constantes)
   * [Entrées/Sorties](#entrées-sorties)
      * [Affichage (Ecrire)](#affichage-ecrire)
      * [Lecture (Lire)](#lecture-lire)
   * [Opérateurs](#opérateurs)
      * [Opérateurs arithmétiques](#opérateurs-arithmétiques)
      * [Opérateurs logiques](#opérateurs-logiques)
      * [Opérateurs de comparaison](#opérateurs-de-comparaison)
   * [Structures de contrôle](#structures-de-contrôle)
      * [Conditions](#conditions)
         * [Si-Alors-FinSi](#si-alors-finsi)
         * [Si-Alors-Sinon-FinSi](#si-alors-sinon-finsi)
         * [Si-SinonSi-Sinon-FinSi](#si-sinonsi-sinon-finsi)
         * [Selon-Cas-FinSelon](#selon-cas-finselon)
      * [Boucles](#boucles)
         * [TantQue-Faire-FinTantQue](#tantque-faire-fintantque)
         * [Pour-Faire-FinPour](#pour-faire-finpour)
   * [Tableaux](#tableaux)
      * [Tableaux à Une Dimension](#tableaux-à-une-dimension)
      * [Tableaux à Deux Dimensions](#tableaux-à-deux-dimensions)
   * [Fonctions](#fonctions)
      * [Fonctions intégrées](#fonctions-intégrées)
         * [Fonctions Mathématiques](#fonctions-mathématiques)
         * [Opérations sur les Chaînes](#opérations-sur-les-chaînes)
      * [Fonctions Utilisateur](#fonctions-utilisateur)
         * [Fonction sans retour](#fonction-sans-retour)
         * [Fonction avec retour](#fonction-avec-retour)
   * [Modules](#modules)
      * [Création d'un module](#création-dun-module)
      * [Utilisation d'un module](#utilisation-dun-module)
   * [Commentaires](#commentaires)
      * [Commentaire sur une ligne](#commentaire-sur-une-ligne)
      * [Commentaire multi-lignes](#commentaire-multi-lignes)
4. [Guide d'installation et d'utilisation](#guide-dinstallation-et-dutilisation)
   * [Installation](#installation)
   * [Compilation et exécution](#compilation-et-exécution)
   * [Commandes utiles](#commandes-utiles)

## Introduction

CodeFR est un langage de programmation conçu pour faciliter l'apprentissage de l'algorithmique et de la programmation dans les pays francophones. Il vise à éliminer la barrière de la langue anglaise souvent rencontrée par les débutants, en permettant l'écriture de code directement en français. CodeFR est particulièrement adapté aux étudiants, aux enseignants et aux tuteurs en programmation.

## Pour qui est CodeFR ?

* 🧑🎓 **Étudiants** : Ils peuvent écrire des algorithmes simples en pseudocode français et voir leur logique prendre vie sans la barrière de la langue.
* 👩🏫 **Professeurs de sciences** : Ils peuvent démontrer comment le pseudocode se traduit en véritables programmes, rendant la pensée algorithmique et la programmation plus claires.
* 📚 **Tuteurs en programmation** : Ils peuvent identifier et expliquer les erreurs de compilation en pseudocode français, aidant ainsi les élèves à comprendre et corriger leurs erreurs plus facilement.
* 👨💻 **Développeurs** : Ils peuvent concevoir une série d'exercices de programmation en français, qui peuvent être compilés et exécutés, offrant ainsi un apprentissage interactif aux étudiants francophones.


## Documentation du langage

### Structure du programme

Un programme CodeFR peut avoir plusieurs structures différentes :

#### Programme Simple

```
// Déclarations (Variables, Constantes, Tableaux)

Debut

// Instructions du programme

Fin
```

**Exemple - Hello World :**

```
Debut

    Ecrire("Hello World\n")

Fin
```

**Exemple - Programme avec variables :**

```
Variable rayon: Entier

Variable surf: Decimal

Constante PI = 3.14159

Debut

    rayon = 5

    surf = PI * rayon ^ 2

    Ecrire(surf, "\n")

Fin
```


#### Programme avec Fonction

```
Fonction Ajouter(a: Entier, b: Entier): Entier

Retourner a + b

FinFonction

Variables x, y, resultat: Entier

Debut

    x = 5

    y = 10

    resultat = Ajouter(x, y)

    Ecrire(resultat)

Fin
```


#### Programme avec Imports

```
// Imports de modules

Importer Module1

Depuis Module1 Importer fonction1, fonction2

// Déclarations

Debut

// Instructions du programme

Fin
```
### Types de Données, Variables et Constantes

CodeFR offre une variété de types de données pour représenter différentes sortes d'informations, ainsi que des mécanismes pour déclarer des variables et des constantes.

#### Types de Données Supportés

CodeFR prend en charge les types de données suivants :

* `Entier` : Nombres entiers (ex : 1, -5, 100).
* `Decimal` : Nombres décimaux (ex : 3.14, -0.5, 2.0).
* `Chaine` : Chaînes de caractères (ex : "Bonjour", "CodeFR").
* `Logique` : Valeurs booléennes, qui peuvent être `Vrai` ou `Faux`.


#### Déclaration de Variables

Les variables sont des emplacements de mémoire nommés qui peuvent contenir des valeurs qui peuvent changer pendant l'exécution du programme.

**Syntaxe :**

```
Variable nom: Type
```

ou pour déclarer plusieurs variables du même type en une seule ligne :

```
Variables nom1, nom2, nom3: Type
```

Où :

* `Variable` est le mot-clé pour déclarer une variable.
* `nom` (ou `nom1`, `nom2`, etc.) est le nom de la variable.
* `Type` est le type de données de la variable (Entier, Decimal, Chaine, Logique).

**Exemples :**

```codefr
Variable age: Entier
Variable nom: Chaine
Variable prix: Decimal
Variable estActif: Logique

Debut
    age = 25
    nom = "Jean Dupont"
    prix = 19.99
    estActif = Vrai

    Ecrire(nom, " a ", age, " ans et le prix est de ", prix, ".\n")
Fin
```


#### Déclaration et Affectation de Variables

Il est possible de déclarer et d'affecter une valeur à une variable en deux étapes distinctes, comme montré dans l'exemple précédent. Vous pouvez aussi faire l'affectation plus tard dans le programme.

```codefr
Variable x: Decimal
Variables a, b, c: Entier

Debut
    a = 5
    b = 10
    c = a + b
    x = 3.14

    Ecrire("La somme de ", a, " et ", b, " est ", c, ".\n")
Fin
```


#### Déclaration de Constantes

Les constantes sont des valeurs qui ne peuvent pas être modifiées une fois qu'elles ont été définies. Elles sont utiles pour représenter des valeurs fixes, comme la valeur de Pi ou un message qui ne doit pas changer.

**Syntaxe :**

```
Constante NOM_CONSTANTE = valeur
```

Où :

* `Constante` est le mot-clé pour déclarer une constante.
* `NOM_CONSTANTE` est le nom de la constante (par convention, en majuscules).
* `valeur` est la valeur de la constante.

**Exemples :**

```codefr
Constante PI = 3.14159
Constante MESSAGE = "Bonjour tout le monde !"
Constante ACTIVE = Vrai

Debut
    Ecrire(MESSAGE, "\n")
    Ecrire("La valeur de PI est : ", PI, "\n")
    Si ACTIVE Alors
        Ecrire("Le programme est actif.\n")
    FinSi
Fin
```

**Points importants :**

* **Noms de variables et de constantes :** Les noms doivent commencer par une lettre et peuvent contenir des lettres, des chiffres et des underscores (\_).
* **Type de données :** Assurez-vous que la valeur affectée à une variable ou une constante correspond au type de données déclaré.
* **Constantes :** Une fois qu'une constante est déclarée, sa valeur ne peut plus être modifiée.



### Entrées/Sorties

CodeFR fournit des instructions simples pour interagir avec l'utilisateur, permettant d'afficher des messages à l'écran (sortie) et de lire des données saisies par l'utilisateur (entrée).

**Sortie :**

L'instruction `Ecrire(expression)` permet d'afficher la valeur d'une expression à la console.

* `Ecrire(expression)` : Affiche la valeur de l'expression. L'expression peut être une variable, une constante, une opération, ou une chaîne de caractères.
* `Ecrire("Bonjour", x, y)` : Permet d'afficher plusieurs valeurs à la suite. Les valeurs peuvent être un mélange de chaînes de caractères et de variables.

**Exemples :**

```
Variable nom: Chaine
Variable age: Entier

Debut
    nom = "Normich"
    age = 25

    Ecrire("Bonjour ", nom, ", vous avez ", age, " ans.\n") // Sortie multiple
    Ecrire(age * 2) // Affiche le double de l'âge
Fin
```

**Entrée :**

L'instruction `Lire(variable)` permet de lire une valeur saisie par l'utilisateur et de l'assigner à une variable.

* `Lire(variable)` : Lit une valeur depuis l'entrée standard (généralement le clavier) et l'assigne à la variable. Le type de la valeur saisie doit correspondre au type de la variable.

**Exemples :**

```
Variable nom: Chaine
Variable age: Entier

Debut
    Ecrire("Entrez votre nom : ")
    Lire(nom)
    Ecrire("Entrez votre âge : ")
    Lire(age)

    Ecrire("Bonjour ", nom, ", vous avez ", age, " ans.\n")
Fin
```

**Explication :**

Dans cet exemple, le programme demande à l'utilisateur d'entrer son nom et son âge. Les valeurs saisies sont stockées dans les variables `nom` et `age`, puis un message de salutation est affiché.

**Note importante :**

* Lors de l'utilisation de `Lire(variable)`, assurez-vous que l'utilisateur entre une valeur du type attendu par la variable. Par exemple, si `variable` est de type `Entier`, l'utilisateur doit entrer un nombre entier. Si l'utilisateur entre une valeur d'un type incorrect, le comportement du programme peut être imprévisible (généralement une erreur d'exécution).
* En CodeFR, il n'existe pas de contrôle de type intégré lors de la lecture de l'entrée utilisateur. Il est donc important d'informer clairement l'utilisateur du type de données attendu et, si nécessaire, de mettre en place des mécanismes de validation pour s'assurer que l'entrée est correcte.


### Opérateurs

Les opérateurs sont des symboles spéciaux qui effectuent des opérations sur des variables et des valeurs. CodeFR prend en charge différents types d'opérateurs, notamment les opérateurs arithmétiques, logiques et de comparaison.

#### Opérateurs Arithmétiques

Les opérateurs arithmétiques sont utilisés pour effectuer des opérations mathématiques.

* `+` : Addition (ex : `a + b`)
* `-` : Soustraction (ex : `a - b`)
* `*` : Multiplication (ex : `a * b`)
* `/` : Division (ex : `a / b`)
* `Mod` : Modulo (reste de la division entière) (ex : `a Mod b`)
* `^` : Puissance (ex : `a ^ b`, a élevé à la puissance b)

**Exemple :**

```codefr
Variable x, y, somme, produit: Entier
Debut
    x = 10
    y = 5
    somme = x + y
    produit = x * y
    Ecrire("Somme : ", somme, "\n")
    Ecrire("Produit : ", produit, "\n")
    Ecrire("10 Mod 3 :", 10 Mod 3) // affiche 1
Fin
```


#### Opérateurs Logiques

Les opérateurs logiques sont utilisés pour combiner des expressions booléennes (Logique).

* `Et` : ET logique (ex : `(a > 0) Et (a < 10)`)
* `Ou` : OU logique (ex : `(a < 0) Ou (a > 10)`)
* `Non` : NON logique (ex : `Non (a == 0)`)
* `Oux` : OU exclusif (XOR) (ex : `(a Vrai) Oux (b Faux)`)

**Exemple :**

```codefr
Variable a, b: Logique
Debut
    a = Vrai
    b = Faux
    Ecrire("a Et b : ", a Et b, "\n")
    Ecrire("a Ou b : ", a Ou b, "\n")
    Ecrire("Non a : ", Non a, "\n")
    Ecrire("a Oux b :", a Oux b, "\n")
Fin
```


#### Opérateurs de Comparaison

Les opérateurs de comparaison sont utilisés pour comparer deux valeurs. Ils renvoient une valeur booléenne (`Vrai` ou `Faux`).

* `<` : Inférieur à (ex : `a < b`)
* `>` : Supérieur à (ex : `a > b`)
* `<=` : Inférieur ou égal à (ex : `a <= b`)
* `>=` : Supérieur ou égal à (ex : `a >= b`)
* `==` : Égal à (ex : `a == b`)
* `!=` : Différent de (ex : `a != b`)

**Exemple :**

```codefr
Variable x, y: Entier
Variable egal: Logique
Debut
    x = 5
    y = 10
    egal = (x == y)
    Ecrire("x == y : ", egal, "\n")
    Ecrire("x < y : ", x < y, "\n")
Fin
```


### Structures de contrôle

## Structures Conditionnelles en CodeFR

CodeFR offre plusieurs façons d'implémenter des conditions pour contrôler le flux d'exécution d'un programme. Voici les trois structures principales :

### 1. `Si-FinSi` (Condition Simple)

Cette structure permet d'exécuter un bloc d'instructions uniquement si une condition est vraie.

**Syntaxe :**

```
Si condition Alors
    // Instructions à exécuter si la condition est vraie
FinSi
```

**Exemple :**

```
Variable age: Entier

Debut
    age = 18
    Si age >= 18 Alors
        Ecrire("Vous êtes majeur.\n")
    FinSi
Fin
```

**Explication :**

Dans cet exemple, le message "Vous êtes majeur." est affiché seulement si la variable `age` est supérieure ou égale à 18.

### 2. `Si-Sinon-FinSi` (Condition Alternative)

Cette structure permet d'exécuter un bloc d'instructions si une condition est vraie, et un autre bloc si la condition est fausse.

**Syntaxe :**

```
Si condition Alors
    // Instructions à exécuter si la condition est vraie
Sinon
    // Instructions à exécuter si la condition est fausse
FinSi
```

**Exemple :**

```
Variable nombre: Entier

Debut
    nombre = 7
    Si nombre Mod 2 == 0 Alors
        Ecrire(nombre, " est un nombre pair.\n")
    Sinon
        Ecrire(nombre, " est un nombre impair.\n")
    FinSi
Fin
```

**Explication :**

Ici, si le `nombre` est divisible par 2 (c'est-à-dire, est pair), le premier message est affiché. Sinon, le second message est affiché.

### 3. `Si-SinonSi-Sinon-FinSi` (Conditions Multiples)

Cette structure permet de tester plusieurs conditions en séquence. Si la première condition est fausse, la condition suivante est évaluée, et ainsi de suite. Un bloc `Sinon` final peut être inclus pour exécuter des instructions si aucune des conditions précédentes n'est vraie.

**Syntaxe :**

```
Si condition1 Alors
    // Instructions à exécuter si condition1 est vraie
SinonSi condition2 Alors
    // Instructions à exécuter si condition1 est fausse et condition2 est vraie
Sinon
    // Instructions à exécuter si toutes les conditions précédentes sont fausses
FinSi
```

**Exemple :**

```
Variable note: Entier

Debut
    note = 75
    Si note >= 90 Alors
        Ecrire("Excellent!\n")
    SinonSi note >= 80 Alors
        Ecrire("Très bien.\n")
    SinonSi note >= 70 Alors
        Ecrire("Bien.\n")
    Sinon
        Ecrire("Vous devez travailler davantage.\n")
    FinSi
Fin
```

### 4. Condition Selon (Switch)

La structure `Selon` permet d'exécuter différents blocs d'instructions en fonction de la valeur d'une expression. Elle est similaire à un switch-case dans d'autres langages.

**Syntaxe :**

```
Selon expression Faire
    Cas valeur1:
        // Instructions à exécuter si l'expression vaut valeur1
    Cas valeur2:
        // Instructions à exécuter si l'expression vaut valeur2
    // ...
    Sinon:
        // Instructions à exécuter si aucune autre condition n'est vraie
FinSelon
```

**Exemple :**

```codefr
Variable jour: Entier

Debut
    jour = 3
    Selon jour Faire
        Cas 1:
            Ecrire("Lundi\n")
        Cas 2:
            Ecrire("Mardi\n")
        Cas 3:
            Ecrire("Mercredi\n")
        Sinon:
            Ecrire("Jour inconnu.\n")
    FinSelon
Fin
```

**Explication :**

Dans cet exemple, le programme affiche le nom du jour de la semaine correspondant au numéro stocké dans la variable `jour`. Si le numéro ne correspond pas aux jours listés, il affiche "Jour inconnu.".

**Explication :**

Dans cet exemple, différentes actions sont entreprises en fonction de la valeur de la variable `note`. Si `note` est supérieure ou égale à 90, "Excellent!" est affiché. Sinon, si `note` est supérieure ou égale à 80, "Très bien." est affiché, et ainsi de suite. Si aucune des conditions n'est vraie (c'est-à-dire, `note` est inférieure à 70), "Vous devez travailler davantage." est affiché.

En utilisant ces structures de contrôle, vous pouvez créer des programmes CodeFR flexibles et adaptables qui répondent à différentes conditions.


#### Boucles
#### a. Boucle TantQue (While)

La boucle `TantQue` permet d'exécuter un bloc d'instructions tant qu'une condition est vraie.

**Syntaxe :**

```
TantQue condition Faire
    
    // Instructions à répéter tant que la condition est vraie
    
FinTantQue
```

**Exemple :**

```codefr
Variable i: Entier

Debut
    
    i = 0
    
    TantQue i < 5 Faire
        
        Ecrire(i, "\n")
        
        i = i + 1
        
    
FinTantQue

Fin
```

**Explication :**

Ici, le programme affiche les nombres entiers de zéro à quatre inclus. La variable `i` est incrémentée après chaque itération jusqu'à ce qu'elle atteigne cinq.

#### b. Boucle Pour (For)

La boucle `Pour` permet de répéter un bloc d'instructions pour une plage spécifiée de valeurs.

**Syntaxe :**

```
Pour variable De debut A fin Faire
    
    // Instructions à répéter pour chaque itération
    
FinPour 
```

**Exemple avec For-De-A-FinPour:**

```codefr  
Variable j: Entier

Debut

    Pour j De -2 A 4 Faire 
        
        Ecrire(j)
        j = j + 2
    
    FinPour 

Fin 
```

**Explication du For-De-A-FinPour:**

Dans cet exemple, le programme affiche les nombres `-2`, puis ajoute deux (`+2`) pour obtenir zéro (`0`) puis deux encore (`+2`) pour obtenir deux (`2`). Enfin il ajoute encore deux (`+4`) mais s'arrête car il dépasse quatre.

En utilisant ces structures de contrôle efficacement, vous pouvez créer des programmes flexibles qui répondent aux besoins variés en termes de gestion du flux logique et itératif dans vos applications CodeFR !


### Tableaux

CodeFR permet l'utilisation de tableaux à une et deux dimensions. Voici comment les déclarer et les utiliser :

#### Tableaux à Une Dimension

**Déclaration :**

```
Tableau T[n]: <Type>
```

Où `n` est la taille du tableau et `<Type>` est le type de données des éléments (Entier, Decimal, Chaine, Logique).

**Exemple :**

```
Tableau T[^5]: Entier

Debut
    T[^0] = 10
    T[^1] = 20
    Ecrire(T[^0] + T[^1])
Fin
```

Dans cet exemple, nous déclarons un tableau `T` de 5 entiers, assignons des valeurs aux deux premiers éléments, puis affichons leur somme.

#### Tableaux à Deux Dimensions

**Déclaration :**

```
Tableau M[n][m]: <Type>
```

Où `n` est le nombre de lignes, `m` le nombre de colonnes, et `<Type>` le type de données des éléments.

**Exemple :**

```
Tableau M[^2][^2]: Decimal

Debut
    M[^0][^0] = 1.5
    M[^1][^1] = 2.5
    Ecrire(M[^0][^0] + M[^1][^1])
Fin
```

Ici, nous créons un tableau 2x2 de nombres décimaux, assignons des valeurs à deux éléments, puis affichons leur somme.

**Utilisation :**

```
Tableau N[^3][^2]: Entier

Debut
    N[^0][^0] = 10
    N[^1][^1] = 20
    Ecrire(N[^0][^0])
Fin
```

Dans cet exemple, nous déclarons un tableau 3x2 d'entiers, assignons des valeurs à deux éléments, puis affichons la valeur de N.

Ces exemples montrent comment déclarer, initialiser et utiliser des tableaux à une et deux dimensions en CodeFR.


### Fonctions

### Fonctions intégrées

CodeFR propose plusieurs fonctions intégrées pour les opérations courantes. Ces fonctions sont disponibles directement dans le langage, simplifiant ainsi le développement.

#### Fonctions Mathématiques

* `Racine(x)` : Calcule la racine carrée de `x`.
* `Sin(x)` : Calcule le sinus de `x` (en radians).
* `Cos(x)` : Calcule le cosinus de `x` (en radians).
* `Tan(x)` : Calcule la tangente de `x` (en radians).
* `Log(x)` : Calcule le logarithme naturel (base e) de `x`.
* `Log10(x)` : Calcule le logarithme en base 10 de `x`.
* `Arrondi(x)` : Arrondit `x` à l'entier le plus proche.
* `Abs(x)` : Retourne la valeur absolue de `x`.
* `Ent(x)` : Retourne la partie entière de `x` (tronque la partie décimale).
* `Alea()` : Génère un nombre aléatoire décimal entre 0 et 1 (inclus 0, exclus 1).
* `Alea(min, max)` : Génère un nombre entier aléatoire entre `min` (inclus) et `max` (inclus).

**Exemple :**

```
Variable x, racineCarree, nombreAleatoire: Decimal
Variable nombreAleatoireEntre1et10: Entier

Debut
    x = 25.0
    racineCarree = Racine(x)
    Ecrire("La racine carrée de ", x, " est : ", racineCarree, "\n")

    nombreAleatoire = Alea()
    Ecrire("Nombre aléatoire entre 0 et 1 : ", nombreAleatoire, "\n")

    nombreAleatoireEntre1et10 = Alea(1, 10)
    Ecrire("Nombre aléatoire entre 1 et 10 : ", nombreAleatoireEntre1et10, "\n")
Fin
```


#### Opérations sur les Chaînes

* `Longueur(str)` : Retourne la longueur (nombre de caractères) de la chaîne `str`.
* `Concatener(str1, str2)` : Concatène (assemble) les chaînes `str1` et `str2` en une seule chaîne.
* `Comparer(str1, str2)` : Compare les chaînes `str1` et `str2`. Retourne 0 si elles sont égales, une valeur négative si `str1` est inférieure à `str2`, et une valeur positive si `str1` est supérieure à `str2`.
* `Recherche(str1, str2)` : Recherche la première occurrence de la sous-chaîne `str2` dans la chaîne `str1`. Retourne la position de début de la sous-chaîne (à partir de 0) ou -1 si la sous-chaîne n'est pas trouvée.
* `Copie(str, pos, n)` : Extrait une sous-chaîne de la chaîne `str` à partir de la position `pos` (à partir de 0) et de longueur `n`.

**Exemple :**

```
Variable nomComplet, sousChaine: Chaine
Variable longueurNom: Entier
Variable positionSousChaine: Entier

Debut
    nomComplet = Concatener("Normich", " ITOUA")
    Ecrire("Nom complet : ", nomComplet, "\n")

    longueurNom = Longueur(nomComplet)
    Ecrire("Longueur du nom complet : ", longueurNom, "\n")

    positionSousChaine = Recherche(nomComplet, "ITO")
    Ecrire("Position de 'ITO' dans le nom : ", positionSousChaine, "\n")

    sousChaine = Copie(nomComplet, 9, 5) // Extrait "ITOUA"
    Ecrire("Sous-chaîne extraite : ", sousChaine, "\n")
Fin
```


### Fonctions Utilisateur

En CodeFR, les fonctions permettent de structurer le code, de le rendre plus lisible et de le réutiliser facilement. Il existe deux types de fonctions : celles qui ne retournent pas de valeur (procédures) et celles qui retournent une valeur.

#### Fonction sans retour (Procédure)

Ces fonctions exécutent une série d'instructions, mais ne renvoient pas de résultat spécifique.

**Syntaxe :**

```
Fonction NomFonction(arg1: Type1, arg2: Type2, ...)
    // Déclarations locales (variables utilisées uniquement dans la fonction)
    // Instructions
FinFonction
```

**Exemple :**

```
Fonction Saluer(nom: Chaine)
    Ecrire("Bonjour ", nom, "!\n")
FinFonction

Debut
    Saluer("Normich") // Appel de la fonction Saluer
Fin
```

**Explication :** La fonction `Saluer` prend un argument de type `Chaine` (le nom) et affiche un message de salutation. Elle ne retourne aucune valeur.

#### Fonction avec retour

Ces fonctions exécutent une série d'instructions et retournent une valeur d'un type spécifié.

**Syntaxe :**

```
Fonction NomFonction(arg1: Type1, arg2: Type2, ...): TypeRetour
    // Déclarations locales
    // Instructions
    Retourner Expression // L'expression doit correspondre au TypeRetour
FinFonction
```

**Exemple :**

```
Fonction Ajouter(a: Entier, b: Entier): Entier
    Retourner a + b
FinFonction

Variables x, y, resultat: Entier

Debut
    x = 5
    y = 10
    resultat = Ajouter(x, y) // Appel de la fonction Ajouter
    Ecrire(resultat, "\n")
Fin
```

**Explication :** La fonction `Ajouter` prend deux arguments de type `Entier` et retourne leur somme, également de type `Entier`. La valeur retournée est ensuite stockée dans la variable `resultat` et affichée.

### Modules

Les modules sont des fichiers séparés qui contiennent du code réutilisable. Ils permettent d'organiser le code en regroupant des fonctions liées entre elles, facilitant ainsi la maintenance et la réutilisation.

#### Création d'un Module

Un module est créé en écrivant un fichier avec l'extension `.cfr`. Le nom du module correspond au nom du fichier sans l'extension.

**Exemple de module `Calculs.cfr` :**

```codefr
Fonction addition(a: Entier, b: Entier): Entier
    Retourner a + b
FinFonction

Fonction soustraction(a: Entier, b: Entier): Entier
    Retourner a - b
FinFonction

Fonction multiplication(a: Entier, b: Entier): Entier
    Retourner a * b
FinFonction
```

Ce module définit trois fonctions arithmétiques : `addition`, `soustraction` et `multiplication`.

#### Utilisation d'un Module dans un Programme Principal

Pour utiliser un module dans votre programme principal, vous devez importer le module ou certaines de ses fonctions.

##### Importer un Module Complet

Lorsque vous importez tout le module, vous pouvez accéder à toutes ses fonctions en utilisant le nom du module comme préfixe.

```codefr  
Importer Calculs  

Variables x, y, resultat_addition: Entier  
Debut  
    x = 5  
    y = 3  
    
    resultat_addition = Calculs.addition(x, y)  
    Ecrire("5 + 3 = ", resultat_addition)  
    
    // Exemple avec soustraction  
    resultat_soustraction = Calculs.soustraction(10, 4)  
    Ecrire("10 - 4 = ", resultat_soustraction)  
    
Fin 
```


##### Importer des Fonctions Spécifiques

Vous pouvez également importer uniquement les fonctions dont vous avez besoin. Dans ce cas-là il n'est pas nécessaire de préciser le nom du module pour appeler ces fonctions.

```codefr   
Depuis Calculs Importer addition  

Variable x1,y1,resultatAddSpecifique :Entier 

Debut 
   x1=7 
   y1=2
   
   resultatAddSpecifique=addition(x1,y1)
   
   Ecrire(resultatAddSpecifique)
   
Fin    
```


#### Exécution de Programmes avec Modules

Pour exécuter votre programme principal qui utilise des modules :

- Assurez-vous que tous les fichiers (le programme principal et les modules nécessaires) sont bien placés dans le même répertoire.
- Compilez/exécutez votre programme en spécifiant tous les fichiers requis à la commande :

```bash    
./codefr calculs.cfr main.cfr     
```

Dans cet exemple :

- **calculs.cfr** est votre fichier de module.
- **main.cfr** est votre fichier contenant le programme principal qui utilise ce(s)module(s).

Cette approche modulaire permet une organisation claire et efficace de vos projets CodeFR !


### Commentaires

Les commentaires sont des parties du code qui ne sont pas exécutées par le programme. Ils servent à expliquer le code, à ajouter des notes ou à désactiver temporairement certaines lignes pendant la phase de développement.

#### Commentaire sur une Ligne Unique

Un commentaire sur une ligne unique commence par `//`. Tout ce qui suit ces deux barres obliques jusqu'à la fin de la ligne est ignoré par l'interpréteur.

**Syntaxe :**

```
// Ce texte sera ignoré
```

**Exemple :**

```
Variable x: Entier // Déclaration d'une variable entière
x = 5 // Assignation d'une valeur à x

Debut
    Ecrire(x) // Affiche la valeur de x
Fin
```


#### Commentaire Multi-Lignes

Un commentaire multi-lignes commence par `/*` et se termine par `*/`. Tout ce qui se trouve entre ces deux séquences est considéré comme un commentaire.

**Syntaxe :**

```
/* 
Ce texte 
sera également 
ignoré */
```

**Exemple :**

```
Variable y: Decimal

/* Cette partie du code est actuellement désactivée.
y = 3.14
Ecrire(y) */

Debut
    Ecrire("Bonjour") /* Affiche un message simple */
Fin
```

Dans cet exemple, tout le bloc entre `/*` et `*/` est traité comme un commentaire et n'est pas exécuté.

### Utilisation des Commentaires

Les commentaires sont très utiles pour :

* **Documenter le code :** Expliquer ce que fait chaque partie du programme.
* **Désactiver temporairement du code :** Pour tester ou déboguer sans supprimer définitivement certaines lignes.
* **Ajouter des notes personnelles ou pour l'équipe.**


## Guide d'installation et d'utilisation

### Installation

1. Téléchargez le compilateur CodeFR
2. Ajoutez-le à votre PATH système
3. Vérifiez l'installation avec la commande : `codefr --version`

### Compilation et exécution

Pour compiler un fichier unique :

```bash
./codefr programme.cfr
```

Pour compiler plusieurs fichiers :

```bash
./codefr calculs.cfr main.cfr

```

Pour exécuter votre programme principal qui utilise des modules :

- Assurez-vous que tous les fichiers (le programme principal et les modules nécessaires) sont bien placés dans le même répertoire.
- Compilez/exécutez votre programme en spécifiant tous les fichiers requis à la commande :

```bash    
./codefr calculs.cfr main.cfr