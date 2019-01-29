#include "../money.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using mc::currency::money;
using mc::currency::to_currency;
using currency = mc::currency::currency_t;

struct exchange_data {
    currency from;
    currency to;
    double rate;
};

struct has_exchange {
    exchange_data _test;

    has_exchange(exchange_data t) : _test(t) {
    }

    bool operator()(exchange_data ex) {
        return (ex.from == _test.from && _test.to == ex.to);
    }
};

int main(int argc, char** argv) {
    std::vector<exchange_data> exchange;
    std::ifstream fin("exchange.txt");

    while (fin.eof() == false) {
        std::string from, to;
        double rate;
        fin >> from >> to >> rate;
        exchange_data tmp;
        std::cout << from << " " << to << " " << rate << std::endl;
        tmp.from = to_currency(from);
        tmp.to = to_currency(to);
        tmp.rate = rate;
        exchange.push_back(tmp);
        tmp.from = to_currency(to);
        tmp.to = to_currency(from);
        tmp.rate = 1. / rate;
        exchange.push_back(tmp);
    }
    std::string shortname_from, shortname_to;
    double total;
    std::cin >> shortname_from >> shortname_to >> total;

    exchange_data test = {
        mc::currency::to_currency(shortname_from),
        mc::currency::to_currency(shortname_to),
        0.
    };

    // TODO#: very ideal case. if exchange does not exists, will fail
    exchange_data data = *(std::find_if(exchange.begin(), exchange.end(), has_exchange(test)));

    std::cout << "result = " 
            << money(data.from, total).convert(data.to, data.rate).amount() / 100. 
            << " " 
            << mc::currency::to_shortname(data.to);

    return 0;
}

