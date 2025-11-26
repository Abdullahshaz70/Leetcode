class Solution {
public:
    
int maxProfit(vector<int>& prices) {

    int size = prices.size();
    int profit = 0;

    int d = prices[0];

    for(int i = 1 ; i < size ; i++){

        if(prices[i] < d)
            d = prices[i];
        else if( d < prices[i] && profit < prices[i]-d)
            profit =  prices[i] - d ;

    }



    return profit;
}


};