#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/client_session.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

#include <iostream>
#include <vector>
#include <string.h>

#include "DBmanager.h"


using namespace std;

#define CLIENT_URI "mongodb://0.0.0.0:27017"

namespace DBmanager
{

	DBmanager::DBmanager() {}

	vector<double> DBmanager::read_database_ohlcv(string db_name, string collection_name)
	{
		vector<double> ohlcv;

		mongocxx::instance instance{};
		mongocxx::uri uri(CLIENT_URI);

		try
		{
			mongocxx::client client(uri);
			mongocxx::database db = client[db_name];
			// mongocxx::collection col = db[collection_name];
			// mongocxx::cursor mycur = col.find({});

			auto cursor = db[collection_name].find({});

			for (auto doc : cursor)
			{
				// cout << bsoncxx::to_json(doc) << endl;

				bsoncxx::document::element id = doc["_id"];
				auto oid = id.get_oid().value.to_string();

				bsoncxx::document::element timestamp = doc["timestamp"];
				auto _timestamp = timestamp.get_int64().value;

				bsoncxx::document::element open = doc["open"];
				float _open = open.get_double().value;

				bsoncxx::document::element high = doc["high"];
				float _high = high.get_double().value;

				bsoncxx::document::element low = doc["low"];
				float _low = low.get_double().value;

				bsoncxx::document::element close = doc["close"];
				float _close = close.get_double().value;

				bsoncxx::document::element volume = doc["volume"];
				float _volume = volume.get_double().value;

				// cout<< oid<< " "<< _timestamp <<" "<< _open << " "<< _high << " "<< _low<< " "<< _close<<" "<<_volume<<endl;
				ohlcv.push_back(_timestamp);
				ohlcv.push_back(_open);
				ohlcv.push_back(_high);
				ohlcv.push_back(_low);
				ohlcv.push_back(_close);
				ohlcv.push_back(_volume);

				/*
				0 -> timestamp
				1 -> open
				2 -> high
				3 -> low
				4 -> close
				5 -> volume
				*/
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		return ohlcv;
	}
}