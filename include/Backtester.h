
#include <vector>

using namespace std;

class Backtester
{
private:
    float initial_balance;
    float current_balance;
    float amount;
    unsigned int leverage;
    float fee_cost = 0.02/100;
    double inv;
    vector<float> profit;
    vector<float> drawdown;
    unsigned int num_operations = 0;
    unsigned int winned;
    unsigned int lossed;
    unsigned int num_longs;
    unsigned int num_shorts;
    bool is_long_open;
    bool is_short_open;
    float long_open_price = 0;
    float short_open_price = 0;
    float take_profit_price = 0;
    float stop_loss_price = 0;
    bool trailing_stop_loss;
    unsigned int from_opened = 0;
    
public:
    Backtester(float _initial_balance, unsigned int _leverage, bool _trailing_stop_loss);
    void reset_results();
    void open_position(float price, unsigned int side, unsigned int from_opened = 0);
    void close_position(float price);
    void set_take_profit(float price, float tp_long, float tp_short);
    void set_stop_loss(float price, float sl_long, float sl_short);
    void return_results();
};