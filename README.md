# Token Identifier

This program written in C++ reads a C++ source code file and identifies different types of tokens such as keywords, identifiers, operators, floats, integers, comments, separators, and strings.

## How it Works

The program follows these steps:

1. It reads the C++ source code file line by line.
2. Each line is then broken down into individual tokens.
3. The program then checks each token against predefined lists to determine its type.
4. The identified tokens and their types are then displayed as output.

## Usage

1. **Compile the Program:** Compile the `token_identifier.cpp` file using a C++ compiler. You can do this by running the following command:

   ```bash
   g++ token_identifier.cpp -o token_identifier
