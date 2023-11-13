#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

// Function to check if a string is a keyword
bool isKeyword(const string &token) {
    vector<string> keywords = {"if", "else", "while", "for", "int", "float", "double", "char", "return"};
    return find(keywords.begin(), keywords.end(), token) != keywords.end();
}

// Function to check if a string is an identifier
bool isIdentifier(const string &token) {
    return regex_match(token, regex("^[a-zA-Z_][a-zA-Z0-9_]*$"));
}

// Function to check if a string is a constant
bool isConstant(const string &token) {
    return regex_match(token, regex("^\\d+$"));
}

// Function to check if a string is an operator
bool isOperator(const string &token) {
    vector<string> operators = {"+", "-", "*", "/", "%", "=", "==", "<", ">", "<=", ">=", "&&", "||"};
    return find(operators.begin(), operators.end(), token) != operators.end();
}

// Function to check if a string is a punctuation
bool isPunctuation(const string &token) {
    vector<string> punctuations = {";", ",", ".", "(", ")", "{", "}"};
    return find(punctuations.begin(), punctuations.end(), token) != punctuations.end();
}

int main() {
    ifstream file("test.txt"); // Replace test.txt with your file name
    if (!file.is_open()) {
        cerr << "Unable to open file\n";
        return 1;
    }

    string line;
    int lineNum = 0;
    while (getline(file, line)) {
        lineNum++;
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (isKeyword(word)) {
                cout << "Line " << lineNum << ": Keyword: " << word << endl;
            } else if (isIdentifier(word)) {
                cout << "Line " << lineNum << ": Identifier: " << word << endl;
            } else if (isConstant(word)) {
                cout << "Line " << lineNum << ": Constant: " << word << endl;
            } else if (isOperator(word)) {
                cout << "Line " << lineNum << ": Operator: " << word << endl;
            } else if (isPunctuation(word)) {
                cout << "Line " << lineNum << ": Punctuation: " << word << endl;
            } else {
                cout << "Line " << lineNum << ": Unidentified Token: " << word << endl;
            }
        }
    }
    file.close();

    return 0;
}
