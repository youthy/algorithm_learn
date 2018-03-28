#include<iostream>
#include<string>
#include<vector>
using namespace std;

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

void fullarray(string s, int index) {
    if (index == s.size() - 1) {
        cout << s << endl;
    } else {
        for (int i = index; i < s.size(); i++) {
            swap(s[i], s[index]);
            fullarray(s, index + 1);
        }
    }
}

int main()
{
    string s = "abc";
    fullarray(s, 0);
    return 0;
}
