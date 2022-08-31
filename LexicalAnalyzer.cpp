#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
string temp;

// check if input is matches any keyword 
bool is_Keyword(string token)
{
    ifstream input("keywords.txt");
    while (getline(input, temp))
    {
        if (token == temp)
        {
            return true;
            break;
        }
    }
    return false;
}

// check if input is an identifier
bool is_Identifier(string token)
{
    bool checkIfValid;
    if ((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || (token[0] == '_'))
    {
        for (int i = 0; i < token.length(); i++)
        {
            if (((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9') || (token[i] == '_')))
                checkIfValid = true;
            else
            {
                checkIfValid = false;
                break;
            }
        }
        return checkIfValid;
    }
    else
        return false;
}

// check if input is an operator
bool is_DefIdentifier(string token)
{
    ifstream input("Identifiers.txt");
    while (getline(input, temp))
    {
        if (token == temp)
        {
            return true;
            break;
        }
    }
    return false;
}

// check if input is an operator
bool is_Operator(string token)
{
    ifstream input("operators.txt");
    while (getline(input, temp))
    {
        if (token == temp)
        {
            return true;
            break;
        }
    }
    return false;
}

// check if input is a float
bool is_Float(string token)
{
    int countDP = 0; // count decimal point

    if (token.length() == 0)
        return (false);
    for (int i = 0; i < token.length(); i++)
    {
        if (token[i] != '0' && token[i] != '1' && token[i] != '2' && token[i] != '3' && token[i] != '4' &&
            token[i] != '5' && token[i] != '6' && token[i] != '7' && token[i] != '8' && token[i] != '9' &&
            token[i] != '.')
            return (false);
        if (token[i] == '.')
            countDP++;
    }
    if (countDP == 1)
        return true;
    else
        return false;
}

// check if input is an integer
bool is_Integer(string token)
{
    for (int i = 0; i < token.length(); i++)
    {
        if (token[i] != '0' && token[i] != '1' && token[i] != '2' && token[i] != '3' && token[i] != '4' &&
            token[i] != '5' && token[i] != '6' && token[i] != '7' && token[i] != '8' && token[i] != '9')
            return (false);
    }
    return (true);
}

// check if input is comment
bool is_Comment(string token)
{
    if (token[0] == '/' && token[1] == '/')
        return true;
    else if (token[0] == '/' && token[1] == '*' && token[token.length() - 2] == '*' && token[token.length() - 1] == '/')
        return true;
    else
        return false;
}

// check if input is a separater
bool is_Separator(string token)
{
    if (token == ";" || token == "," || token == "(" || token == ")" || token == "{" || token == "}" ||
        token == "()" || token == "{}")
        return true;
    else
        return false;
}

bool is_String(string token)
{
    if (token[0] == '"' && token[token.length() - 1] == '"')
        return true;
    else
        return false;
}

int main()
{
    vector<string> tokenArray; //all the tokens will be pushed into tokenArray
    string temp2, line; 
    // line --> Capture lines of program one by one and then converted to stringstream
    // temp2 --> hold token and then pushed into tokenArray
    cout << endl;
    ifstream file("program.cpp");
    
    // This while loop will read complete program line by line until end of file is reached (eof()==true)
    while (getline(file, line)) //file -> line
    {
        //now converting the line into stringstream
        stringstream Stream(line); //line -> Stream

        // This nested while loop will break the line into token and
        while (getline(Stream, temp2, ' ')) // stream -> temp2
        {
            if (temp2 != "") // this will deal with consecutive spaces
                tokenArray.push_back(temp2); //each token will be pushed into tokenArray
        }
    }
    //Now Identifying the token class 
    for (int i = 0; i < tokenArray.size(); i++)
    {
        if (!(is_Keyword(tokenArray[i])))
        {
            if (!(is_DefIdentifier(tokenArray[i])))
            {
                if (is_Identifier(tokenArray[i]))
                    cout << tokenArray[i] << " ----> Identifier" << endl;
                else if (is_Operator(tokenArray[i]))
                    cout << tokenArray[i] << " ----> Operator" << endl;
                else if (is_Float(tokenArray[i]))
                    cout << tokenArray[i] << " ----> Float" << endl;
                else if (is_Integer(tokenArray[i]))
                    cout << tokenArray[i] << " ----> integer" << endl;
                else if (is_Comment(tokenArray[i]))
                    cout << tokenArray[i] << " ----> Comment" << endl;
                else if (is_Separator(tokenArray[i]))
                    cout << tokenArray[i] << " ----> Separator" << endl;
                else if (is_String(tokenArray[i]))
                    cout << tokenArray[i] << " ----> String" << endl;
                else
                    cout << tokenArray[i] << " ----> Invalid" << endl;
            }
            else
                cout << tokenArray[i] << " ----> pre-defined Identifier" << endl;
        }
        else
            cout << tokenArray[i] << " ----> keyword" << endl;
    }
    system("pause");
    return 0;
}
