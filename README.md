
# Token Classifier

This C++ program reads a file containing source code and classifies each token into different categories such as keywords, identifiers, operators, integers, floats, comments, separators, and strings.

## Usage

### Prerequisites

Make sure you have a C++ compiler installed on your system.

### Instructions

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/your-username/token-classifier.git
    ```

2. Compile the source code:

    ```bash
    g++ -o token_classifier token_classifier.cpp
    ```

3. Run the executable and provide the input source code file:

    ```bash
    ./token_classifier
    ```

    The program will prompt you to enter the name of the source code file. Upon entering the filename, it will classify each token in the file and display the results.

## Token Categories

- **Keywords**: Identifies reserved words in the programming language.
- **Identifiers**: Checks if the token is a valid identifier.
- **Pre-defined Identifiers**: Identifies identifiers that are pre-defined.
- **Operators**: Identifies operators used in the code.
- **Integers**: Identifies integer numbers.
- **Floats**: Identifies floating-point numbers.
- **Comments**: Identifies comments in the code.
- **Separators**: Identifies separators such as semicolons, commas, parentheses, and braces.
- **Strings**: Identifies string literals.

## Notes

- The program requires few additional files:
  - `keywords.txt`: Contains a list of keywords.
  - `Identifiers.txt`: Contains a list of predefined identifiers.
  - `operators.txt`: Contains a list of operators.
- Make sure these files are present in the same directory as the executable.

## Example

Suppose you have a file named `program.cpp` containing the source code. You can run the program as follows:

```bash
g++ LexicalAnalyzer.cpp -o g++ LexicalAnalyzer
./LexicalAnalyzer

