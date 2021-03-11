#include<vector>

#include "Backtester.h"
using namespace std;

Backtester::Backtester(float _initial_balance, unsigned int _leverage, bool _trailing_stop_loss){
    this-> initial_balance = _initial_balance;
    this-> current_balance = _initial_balance;
    this-> amount = 0;
    this-> num_operations = 0;
    this-> leverage = _leverage;
    this-> fee_cost = 0.02/100;
    this-> inv = this->current_balance*0.01*this->leverage;
    this-> winned = 0;
    this-> lossed = 0;
    this-> num_longs = 0;
    this-> num_shorts = 0;
    this-> is_long_open = false;
    this-> is_short_open = false;
    this-> long_open_price = 0;
    this-> short_open_price = 0;
    this-> take_profit_price = 0;
    this-> stop_loss_price = 0;
    this-> trailing_stop_loss = _trailing_stop_loss;

};

void Backtester::reset_results(){
    this-> current_balance = this-> initial_balance;
    this-> amount = 0;
    this-> winned = 0;
    this-> lossed = 0;
    this->num_operations = 0;
    this-> num_longs = 0;
    this-> num_shorts = 0;
    this-> is_long_open = false;
    this-> is_short_open = false;
    this->profit.clear();
    this->drawdown.clear();
}

void Backtester::open_position(float price, unsigned int side, unsigned int from_opened){
     this->num_operations++;

    // 0 means open short
    // 1 means open long
    if (side == 0)
    {
        this->num_shorts++;

        if (this->is_long_open)
        {
            this->close_position(price);
        }

        if (this->is_short_open)
        {
            this-> short_open_price = (this->short_open_price + price)/2;
        }
        else{
            this->is_short_open = true;
            this->short_open_price = price;
        }
    }
    else if (side == 1)
    {
       if (this->is_short_open)
       {
           this->close_position(price);
       }

       if (this->is_long_open)
       {
           this->long_open_price = (this->long_open_price + price)/2;
       }
       else
       {
           this->is_long_open = true;
           this->long_open_price = price
       }
       
       
    }
    
    this->amount = this->inv/price

}

