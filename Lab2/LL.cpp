////
////  LL.cpp
////  Compilation principle
////
////  Created by 周天逸 on 2023/11/25.
////
//
//#include<iostream>
//#include<string>
//#include<stack>
//#define M 5
//#define N 8
//
//using namespace std;
//
//stack<char> analyse;
//char Vn[M] = { 'E', 'G', 'T', 'S', 'F' };
//char Vt[N] = { 'i', '+', '-', '*', '/', '(', ')', '$' };
//string L[M][N] = {
//    { "TG", "ERROR", "ERROR", "ERROR", "ERROR", "TG", "ERROR", "ERROR" },
//    { "ERROR", "+TG", "-TG", "ERROR", "ERROR", "ERROR", "NULL", "NULL" },
//    { "FS", "ERROR", "ERROR", "ERROR", "ERROR", "FS", "ERROR", "ERROR" },
//    { "ERROR", "NULL", "NULL", "*FS", "/FS", "ERROR", "NULL", "NULL" },
//    { "i", "ERROR", "ERROR", "ERROR", "ERROR", "(E)", "ERROR", "ERROR" }
//};
//
//void outstack()
//{
//   
//    stack<char> temp;
//    
//    int l = analyse.size();
//    for (int i = 0; i < l; i++)
//    {
//        char a = analyse.top();
//        analyse.pop();
//        temp.push(a);
//    }
//    
//    l = temp.size();
//    for (int i = 0; i < l; i++)
//    {
//        char a = temp.top();
//        temp.pop();
//        analyse.push(a);
//        cout << a;
//    }
//}
//
//void outinput(string s, int n)
//{
//    for (; n < s.length(); n++)
//        cout << s[n];
//}
//
//void LL_1(string input)
//{
//   
//    analyse.push('$');
//    analyse.push(Vn[0]);
//    //
//    cout << "步骤" << "\t 剩余分析栈" << "\t 剩余输入串" << "产生式" << "\t动作" << endl;
//    cout << '0' << "\t";
//    outstack();
//    cout << "\t\t" << input;
//    cout << "\t\t\t\t" << "初始化" << endl;
//
//    int i = 0;
//    for (int j = 1; i < input.length(); j++)
//    {
//       
//        char v = analyse.top();
//        analyse.pop();
//       
//        if (v == input[i])
//        {
//            cout << j << "\t";
//            outstack();
//            cout << "\t\t";
//            outinput(input, i+1);
//            cout << "\t\t" << input[i] << "匹配" << "\t\tPOP" << endl;
//            i++;
//            continue;
//        }
//        else
//        {
//            int m, n;
//            m = -1;
//           
//            for (int j = 0; j < M; j++)
//            {
//                if (v == Vn[j])
//                {
//                    m = j;
//                    break;
//                }
//
//            }
//            
//            if (m == -1)
//            {
//                cout << "失败";
//                cout << "第" << i << "个字符" << input[i] << "匹配错误" << endl;
//                cout << input << "非法串" << endl;
//                break;
//            }
//           
//            for (int j = 0; j < N; j++)
//            {
//                if (input[i] == Vt[j])
//                {
//                    n = j;
//                    break;
//                }
//            }
//           
//            if (L[m][n] == "ERROR")
//            {
//                cout << "第" << i << "个字符" << input[i] << "匹配错误" << endl;
//                cout << input << "非法串" << endl;
//                break;
//            }
//            if (L[m][n] == "NULL")
//            {
//                cout << j << "\t";
//                outstack();
//                cout << "\t\t";
//                outinput(input, i);
//                cout << "\t\t\t\t" << v << "->" << "ɛ" << endl;
//                continue;
//            }
//            else
//            {
//                //
//                string t = "";
//                for (int j = L[m][n].length() - 1; j >= 0; j--)
//                {
//                    t += L[m][n][j];
//                    analyse.push(L[m][n][j]);
//                }
//                cout << j << "\t";
//                outstack();
//                cout << "\t\t";
//                outinput(input, i);
//                cout << "\t\t" << v << "->" << L[m][n];
//                cout << "\t\tPOP,PUSH(" << t << ")";
//            }
//        }
//        cout << endl;
//    }
//    if (i == input.length())
//        cout << input << "合法串" << endl;
//}
//
//int main()
//{
//    cout << "输入以$结尾的符号串";
//    string in;
//    cin >> in;
//    cout << "匹配过程" << endl;
//    LL_1(in);
//   
//}
// 
//
