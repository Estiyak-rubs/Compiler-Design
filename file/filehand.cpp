#include <iostream>
#include <fstream>
using namespace std;

int main() /*
{

    ofstream MyFile("example.txt");


    MyFile << "10+10=20";


    MyFile.close();
}*/
{
    string myText;


    ifstream MyReadFile("Example.txt");


    while (getline (MyReadFile, myText))
    {

        cout << myText;
    }

// Close the file
    MyReadFile.close();
}
