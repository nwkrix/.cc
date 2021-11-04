#include <iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = -1, multiplier = 1, number = 0;
        do{
            i++;
        }while(s[i] == ' ');

        if(s[i] == '-'){
            multiplier = -1;
            i++;
        }
        if(s[i]=='+')
            i++;
        if(!isdigit(s[i])){
            return number;
        }
        int num_start = i;
        while(isdigit(s[i]))
            i++;
            
        int j = 0; i--;
        while(num_start <= i){
            number += ( int(s[i])-int('0') ) * ceil(pow(10,j++));
            i--;
        }

        if(number > 2 << (31-1)-2){
            number = 2 << (31-1)-1;
        }

        return number * multiplier;
    }
};

int main(){
    Solution l;
    string s = """""  2147483648 WORD""""";
    cout << l.myAtoi(s) << endl;
    return 0;
}