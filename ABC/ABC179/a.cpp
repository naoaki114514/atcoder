#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;


    if(s[s.size()-1] == 's') s = s + "es";
    else s = s + 's';

    cout << s << endl;
    return 0;
}