#include <iostream>
#include <string>
using namespace std;

//����ʶ���ǻ����ֻ��ʶ��
void Letter(string str)
{
    //ʶ�������
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
    //ʶ���ʶ��
    else
        cout << "(id," << str << ")" << endl;
}

int main()
{
    string str1, str;
    while (cin >> str1)
    {
        //������루���У�Ctrl + Z������
        str = str + ' ' + str1;
    }
    //��ʼ�������Ĵ���
    int length_str = str.length();
    for (int i = 0; i < length_str; i++)
    {
        //�������ո����ʱ����������ִ��
        if (str[i] == ' ' || str[i] == '\n') continue;
        //ʶ����
        else if (isdigit(str[i]))
        {
            string digit;
            //���ַ�����ʽ��ʾ�������
            while (isdigit(str[i]))
            {
                digit += str[i];
                i++;
            }
            i--;
            cout << "(num," << digit << ")" << endl;
        }
        //ʶ������ֻ��ʶ��
        else if (isalpha(str[i]))
        {
            string lett;
            //���ַ�����ʽ��ʾ��������ֻ��߱�ʶ��
            while (isdigit(str[i]) || isalpha(str[i]))
            {
                lett += str[i];
                i++;
            }
            i--;
            Letter(lett);
        }
        //ʶ�������
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
                //ʶ����
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
                //������
            default:
                cout << "error" << endl;
                break;
            }
        }
    }
    return 0;
}