#include <iostream>
#include <string>
using namespace std;

//用于识别是基本字或标识符
void Letter(string str)
{
    //识别基本字
    if (str == "int")
        cout << "(intsym,int)" << endl;
    else if (str == "float")
        cout << "(floatsym,float)" << endl;
    else if (str == "double")
        cout << "(doublesym,double)" << endl;
    else if (str == "char")
        cout << "(charsym,char)" << endl;
    else if (str == "const")
        cout << "(constsym,const)" << endl;
    else if (str == "do")
        cout << "(dosym,do)" << endl;
    else if (str == "while")
        cout << "(whilesym,while)" << endl;
    else if (str == "if")
        cout << "(ifsym,if)" << endl;
    else if (str == "else")
        cout << "(elsesym,else)" << endl;
    else if (str == "switch")
        cout << "(switchsym,switch)" << endl;
    else if (str == "case")
        cout << "(casesym,case)" << endl;
    else if (str == "continue")
        cout << "(continuesym,continue)" << endl;
    else if (str == "break")
        cout << "(breaksym,break)" << endl;
    else if (str == "return")
        cout << "(returnsym,return)" << endl;
    //识别标识符
    else
        cout << "(id," << str << ")" << endl;
}

int main()
{
    string str1, str;
    while (cin >> str1)
    {
        //读入代码（换行，Ctrl + Z结束）
        str = str + ' ' + str1;
    }
    //开始处理读入的代码
    int length_str = str.length();
    for (int i = 0; i < length_str; i++)
    {
        //当遇到空格或换行时，跳过继续执行
        if (str[i] == ' ' || str[i] == '\n') continue;
        //识别常数
        else if (isdigit(str[i]))
        {
            string digit;
            //以字符串形式表示这个常数
            while (isdigit(str[i]))
            {
                digit += str[i];
                i++;
            }
            i--;
            cout << "(num," << digit << ")" << endl;
        }
        //识别基本字或标识符
        else if (isalpha(str[i]))
        {
            string lett;
            //以字符串形式表示这个基本字或者标识符
            while (isdigit(str[i]) || isalpha(str[i]))
            {
                lett += str[i];
                i++;
            }
            i--;
            Letter(lett);
        }
        //识别运算符
        else
        {
            switch (str[i])
            {
            case '+':
                cout << "(plus,+)" << endl;
                break;
            case '-':
                cout << "(minus,-)" << endl;
                break;
            case '*':
                cout << "(times,*)" << endl;
                break;
            case '/':
                cout << "(divide,/)" << endl;
                break;
            case '=':
                cout << "(equal,=)" << endl;
                break;
            case '<':
                i++;
                if (str[i] == '>')
                {
                    cout << "(NE,<>)" << endl;
                }
                else if (str[i] == '=')
                {
                    cout << "(less equal,<=)" << endl;
                }
                else
                {
                    i--;
                    cout << "(less than,<)" << endl;
                }
                break;
            case '>':
                i++;
                if (str[i] == '=')
                {
                    cout << "(greater equal,>=)" << endl;
                }
                else
                {
                    i--;
                    cout << "(greater than,>)" << endl;
                }
                break;
                //识别界符
            case '(':
                cout << "(lparen,()" << endl;
                break;
            case ')':
                cout << "(rparen,))" << endl;
                break;
            case ',':
                cout << "(comma,,)" << endl;
                break;
            case ';':
                cout << "(semicolon,;)" << endl;
                break;
                //错误处理
            default:
                cout << "error" << endl;
                break;
            }
        }
    }
    return 0;
}