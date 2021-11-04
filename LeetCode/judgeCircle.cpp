#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        len = moves.size();
        d['U'] = 1; d['D'] = -1; d['R'] = 1; d['L'] = -1;
        for(int i=0; i < len; i++){
            origin += d[moves[i]];
        }
        return (origin == 0);
    }
private:
    int origin = 0;
    size_t len;
    map<char, int> d;
};

int main(){
    /*
            "UD"
            "LL"
            "RRDD"
            "LDRRLRUULR"
            "UDDURRRLRLUURDDLLL"
    */
    string moves = "RRDD";
    Solution l;
    cout << l.judgeCircle(moves) << endl;
    return 0;
}