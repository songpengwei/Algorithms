#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <string>

using namespace std;


vector<string> echo(string s) {
    int n = s.size();
    vector<string> words;

    int left = 0;
    string word = "";
    stack<char> brace;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '{') {
            brace.push('{');
            if (brace.size() == 1 && word.size() > 0) {
                words.push_back(word);
                word.clear();
            } else if (brace.size() > 1) {
                word += s[i];
            }
        } else if (s[i] == '}'){
            if (brace.size() > 0 && brace.top() == '{') {
                brace.pop();
            } else {
                cerr << "error braces" << endl;
                exit(-1);
            }

            if (brace.size() == 0 && word.size() > 0) {
                words.push_back(word);
                word.clear();
            } else if (brace.size() > 0) {
                 word += s[i];
            }
        } else if (s[i] == ' ' || s[i] == '\t'){
            continue;
        } else {
            word += s[i];
        }
    }

    return words;
}

int main()
{
    string s = "{a,b}{c,g{e,m}}p{q,r}";
    vector<string> ans = echo(s);
    for (int i = 0; i < ans.size(); ++i) {
         cout << ans[i] << endl;
    }
}

