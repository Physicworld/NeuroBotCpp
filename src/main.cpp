#include <iostream>
#include "../include/DBmanager.h"
#include <vector>
using namespace std;

int main()
{
    DBmanager::DBmanager database;
    vector<double> ohlcv;
    ohlcv = database.read_database_ohlcv("BINANCE", "BTCUSDT1hFutures");

    for (int i = 1; i < ohlcv.size(); i++)
    {   
        cout<<ohlcv.at(i-1)<<' ';

        if ((i % 6) == 0){
            cout<<endl;
        }
    }
    
    
}
