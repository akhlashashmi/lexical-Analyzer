#include <iostream>   // Includes the input/output stream library
#include <string>     // Includes the string library
#include <vector>     // Includes the vector library
#include <unordered_set>  // Includes the unordered_set library
#include <fstream>    // Includes the file stream library
#include <sstream>    // Includes the string stream library
#include <cctype>     // Includes functions for character classification

using namespace std;  // Allows the usage of standard library elements without prefixing them with "std::"

// Global variables for storing keywords and identifiers
unordered_set<string> keywords;    // Set to store keywords
unordered_set<string> identifiers; // Set to store predefined identifiers

// Function prototypes
bool is_Keyword(const string& token);    // Function to check if a token is a keyword
bool is_Identifier(const string& token); // Function to check if a token is an identifier
bool is_Operator(const string& token);   // Function to check if a token is an operator
bool is_Float(const string& token);      // Function to check if a token is a float
bool is_Integer(const string& token);    // Function to check if a token is an integer
bool is_Comment(const string& token);    // Function to check if a token is a comment
bool is_Separator(const string& token);  // Function to check if a token is a separator
bool is_String(const string& token);     // Function to check if a token is a string

// Load keywords and identifiers from files
void loadKeywordsAndIdentifiers() {
    ifstream keywordFile("keywords.txt");        // Opens the file containing keywords
    ifstream identifierFile("Identifiers.txt");  // Opens the file containing predefined identifiers
    
    string word;  // Variable to store each word read from the files
    // Read keywords from the file and insert them into the 'keywords' set
    while (getline(keywordFile, word)) {
        keywords.insert(word);
    }
    // Read predefined identifiers from the file and insert them into the 'identifiers' set
    while (getline(identifierFile, word)) {
        identifiers.insert(word);
    }
}

int main() {
    loadKeywordsAndIdentifiers();  // Load keywords and identifiers
    
    vector<string> tokenArray;  // Vector to store tokens
    string line;                // Variable to store each line read from the file
    
    ifstream file("program.cpp");  // Open the file containing the program
    
    // Read each line from the file
    while (getline(file, line)) {
        stringstream Stream(line);  // Create a string stream to tokenize the line
        string temp2;               // Variable to store each token
        
        // Tokenize the line and store tokens in 'tokenArray'
        while (getline(Stream, temp2, ' ')) {
            if (!temp2.empty()) 
                tokenArray.push_back(temp2);
        }
    }
    
    // Iterate over each token in 'tokenArray'
    for (const auto& token : tokenArray) {
        // Check if token is a keyword
        if (keywords.count(token) > 0) {
            cout << token << " ----> Keyword" << endl;
        } 
        // Check if token is a predefined identifier
        else if (identifiers.count(token) > 0) {
            cout << token << " ----> Pre-defined Identifier" << endl;
        } 
        // Check other types of tokens
        else if (is_Identifier(token)) {
            cout << token << " ----> Identifier" << endl;
        } else if (is_Operator(token)) {
            cout << token << " ----> Operator" << endl;
        } else if (is_Float(token)) {
            cout << token << " ----> Float" << endl;
        } else if (is_Integer(token)) {
            cout << token << " ----> Integer" << endl;
        } else if (is_Comment(token)) {
            cout << token << " ----> Comment" << endl;
        } else if (is_Separator(token)) {
            cout << token << " ----> Separator" << endl;
        } else if (is_String(token)) {
            cout << token << " ----> String" << endl;
        } else {
            cout << token << " ----> Invalid" << endl;
        }
    }
    
    return 0;
}

// Function definitions

// Function to check if a token is an identifier
bool is_Identifier(const string& token) {
    if (token.empty()) return false;  // Check if token is empty
    // Check if the first character of the token is an alphabet or underscore
    if (!isalpha(token[0]) && token[0] != '_') return false;
    // Check if the token contains only alphanumeric characters or underscore
    for (char c : token) {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

// Function to check if a token is an operator
bool is_Operator(const string& token) {
    ifstream operatorsFile("operators.txt"); // Open the file containing the list of operators

    // Set to store operators
    unordered_set<string> operators;
    string op;
    
    // Read operators from the file and insert them into the 'operators' set
    while (getline(operatorsFile, op)) {
        operators.insert(op);
    }
    
    // Check if the token is present in the set of operators
    return operators.count(token) > 0;
}

// Function to check if a token is a float
bool is_Float(const string& token) {
    if (token.empty()) return false;  // Check if token is empty
    int countDP = 0;  // Counter for decimal points
    // Check if the token contains only digits or a single decimal point
    for (char c : token) {
        if (!isdigit(c) && c != '.') return false;
        if (c == '.') countDP++;  // Increment counter if decimal point is encountered
    }
    return countDP == 1;  // Return true if there is exactly one decimal point
}

// Function to check if a token is an integer
bool is_Integer(const string& token) {
    if (token.empty()) return false;  // Check if token is empty
    // Check if the token contains only digits
    for (char c : token) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Function to check if a token is a comment
bool is_Comment(const string& token) {
    // Check if the token represents a single-line comment or a multi-line comment
    return token.size() >= 2 && token[0] == '/' && ((token[1] == '/' && token.back() == '\n') || (token[1] == '*' && token.back() == '/' && token.size() >= 4));
}

// Function to check if a token is a separator
bool is_Separator(const string& token) {
    // Set of separators
    static unordered_set<string> separators = {";", ",", "(", ")", "{", "}", "()", "{}"};
    // Check if the token is present in the set of separators
    return separators.count(token) > 0;
}

// Function to check if a token is a string
bool is_String(const string& token) {
    // Check if the token represents a string literal
    return token.size() >= 2 && token.front() == '"' && token.back() == '"';
}