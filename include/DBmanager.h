// En include van todos los archivos de cabecera.


#pragma once

#include <string.h>
#include <vector>

using namespace std;

namespace DBmanager
{
    class DBmanager
    {
    private:

    public:
        DBmanager();
        vector<double> read_database_ohlcv(string db_name, string collection_name);
    };
    


}