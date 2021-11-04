#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(int prices[],int NumOfDays){
        int today = 0, 
            fall=prices[0], rise=prices[0], 
            profit = 0;
        while(today < NumOfDays){
            while(today < NumOfDays && prices[today] > prices[today+1])
                today++;
            fall = prices[today];
            while(today < NumOfDays && prices[today] < prices[today+1])
                today++;
            rise = prices[today];
            profit += rise-fall;
        }
        return profit;
    }
    int maxProfit2(int prices[],int len){
        int profit = 0;
        for(int i=1; i<len;i++){
            if(prices[i] > prices[i-1])
                profit += prices[i]-prices[i-1];
        }
        return profit;
    }
   
};
int main(){
    Solution l;
    int prices[] = {7,1,5,3,6,4};
    int v = l.maxProfit2(prices,5);
    cout << v << endl;
    return 0;
}