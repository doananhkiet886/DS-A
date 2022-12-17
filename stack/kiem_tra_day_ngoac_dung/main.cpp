#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

void loadFromFile(int &t, string str[])
{
    ifstream fileIn;
    fileIn.open("brackets.inp", ios_base::in);
    if (fileIn.fail())
    {
        cout << "ERROR!" << endl;
        return;
    }

    fileIn >> t;
    fileIn.ignore();
    for (int i = 0; i < t; i++)
    {
        getline(fileIn, str[i]);
    }
    fileIn.close();
}

void saveToFile(int t, string strArray[])
{
    ofstream fileOut;
    fileOut.open("result.out", ios_base::out);

    for (int i = 0; i < t; i++)
    {
        fileOut << strArray[i] << endl;
    }

    fileOut.close();
    
}

bool isValid(string brackets)
{
    stack<char> stk;
    for (int i = 0 ; i < brackets.length(); i++)
    {
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')
        {
            stk.push(brackets[i]);
        }
        else
        {
            char prevBracket = stk.top();
            stk.pop();

            if ((prevBracket == '(' && brackets[i] == ')') || (prevBracket == '{' && brackets[i] == '}') || (prevBracket == '[' && brackets[i] == ']'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    
    if (stk.empty())
    {
        return true;
    }
    return false;
}

void solve()
{
    string bracketsArray[20];
    string resultArray[20];
    int t;
    loadFromFile(t, bracketsArray);
    
    for (int i = 0; i < t; i++)
    {
        if (isValid(bracketsArray[i]))
        {
            resultArray[i] = "true";
        }
        else
        {
            resultArray[i] = "false";
        }
    }

    saveToFile(t, resultArray);
}

int main()
{
    solve();
    system("pause");
    return 0;
}