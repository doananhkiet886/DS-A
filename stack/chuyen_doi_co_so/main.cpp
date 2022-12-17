#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

void loadFromFile(int &number)
{
    ifstream fileIn;
    fileIn.open("decimal.inp", ios_base::in);

    if (fileIn.fail())
    {
        cout << "ERROR!" << endl;
        return;
    }

    fileIn >> number;

    fileIn.close();
}

void saveToFile(string str)
{
    ofstream fileOut;
    fileOut.open("binary.out", ios_base::out);
    
    fileOut << str;

    fileOut.close();
}

string decimalToBin(int number)
{
    stack<int> result;
    while(number != 0)
    {
        result.push(number % 2);
        number = number / 2;
    }

    string bin = "";
    while(!result.empty())
    {
        bin = bin + to_string(result.top());
        result.pop();
    }
    return bin;
}

void solve()
{
    int number;
    loadFromFile(number);
    string bin = decimalToBin(number);
    saveToFile(bin);
}
int main()
{
    solve();
    system("pause");
    return 0;
}