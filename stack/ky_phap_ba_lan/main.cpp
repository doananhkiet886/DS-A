#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

void loadFromFile(string &str)
{
    ifstream fileIn;
    fileIn.open("infix_expression.inp", ios_base::in);
    if (fileIn.fail())
    {
        cout << "ERROR!" << endl;
        return;
    }

    getline(fileIn, str);

    fileIn.close();
}

void saveToFile(string infix, string suffix, double result)
{
    ofstream fileOut;
    fileOut.open("result.out", ios_base::out);
    if (fileOut.fail())
    {
        cout << "ERROR!" << endl;
        return;
    }

    fileOut << "Infix: " << infix << endl;
    fileOut << "Suffix: " << suffix << endl;
    fileOut << "Result: " << result << endl;

    fileOut.close();
}
int orderOperator(char ch)
{
    if (ch == '^')
    {
        return 1;
    }
    if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 3;
    }
    return 4;
}

bool isOperator(char ch)
{
    if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch =='-' || ch == '%')
    {
        return true;
    }
    return false;
}

bool isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }
    return false;
}

queue<string> convertInfixToSuffix(string infix)
{
    stack<char> stk;
    queue<string> queueSuffix;
    string str = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if (isDigit(infix[i]))
        {
            // Thực hiện ghép nối chữ số lại để tạo thành 1 số có nhiều chữ số
            str = str + infix[i];
            if (!isDigit(infix[i + 1])) //Lúc này ta lấy số đã đc ghép nối hoàn chỉnh, ta push nó vào queue
            {
                queueSuffix.push(str);
                str = "";
            }
        }
        else if (infix[i] == '(')
        {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stk.top() != '(')
            {
                string chTop;
                chTop.push_back(stk.top());
                stk.pop();
                queueSuffix.push(chTop); 
            }
            stk.pop();
        }
        else if (isOperator(infix[i]))
        {
            while (!stk.empty() && orderOperator(stk.top()) <= orderOperator(infix[i]))
            {
                string chTop;
                chTop.push_back(stk.top());
                stk.pop();
                queueSuffix.push(chTop);
            }

            stk.push(infix[i]);
        }
    }

    while (!stk.empty())
    {
        string chTop;
        chTop.push_back(stk.top());
        stk.pop();
        queueSuffix.push(chTop);
    }
    
    return queueSuffix;
}

double calculateTwoNumber(char oprt, double number_1, double number_2)
{
    if (oprt == '^')
    {
        return pow(number_1, number_2);
    }
    else if (oprt == '*')
    {
        return number_1 * number_2;
    }
    else if (oprt == '/')
    {
        return number_1 / number_2;
    }
    else if (oprt == '%')
    {
        return (int)number_1 % (int)number_2;
    }
    else if (oprt == '+')
    {
        return number_1 + number_2;
    }
    return number_1 - number_2;
}

double calculateSuffix(queue<string> queueSuffix)
{
    stack<double> result;
    while (!queueSuffix.empty())
    {
        string frontQueueSuffix = queueSuffix.front();
        queueSuffix.pop();
        if (isOperator(frontQueueSuffix.at(0)))
        {
            double number_1 = result.top();
            result.pop();
            double number_2 = result.top();
            result.pop();

            result.push(calculateTwoNumber(frontQueueSuffix.at(0), number_2, number_1));
        }
        else
        {
            result.push(stod(frontQueueSuffix));
        }
    }

    double lastResult = result.top();
    result.pop();
    return lastResult;
}

void solve()
{
    string infix;
    loadFromFile(infix);
    queue<string> queueSuffix = convertInfixToSuffix(infix);
    double result = calculateSuffix(queueSuffix);
   
    //queue sang string
    string suffix = "";
    while (!queueSuffix.empty())
    {
        suffix = suffix + " " + queueSuffix.front();
        queueSuffix.pop();
    }

    saveToFile(infix, suffix, result);
}

int main()
{
    solve();
    system("pause");
    return 0;
}