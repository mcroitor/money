#include <sstream>
#include "money.h"

namespace mc {

    money::money(currency_t c) :
    _currency(c), _amount(0) {

    }

    money::money(const money& m) :
    _currency(m.currency()), _amount(m.amount()) {

    }

    money::money(currency_t c, double sum) : _currency(c) {
        _amount = (uint64_t) (sum * 100);
    }

    const uint64_t money::integral() const {
        return _amount / 100;
    }

    const uint64_t money::part() const {
        return _amount % 100;
    }

    const uint64_t money::amount() const {
        return _amount;
    }

    const currency_t money::currency() const {
        return _currency;
    }

    const money& money::operator=(const money& m) {
        this->_currency = m.currency();
        this->_amount = m.amount();
        return *this;
    }

    bool money::equal(const money& m) const {
        return this->currency() == m.currency() &&
                this->amount() == m.amount();
    }

    void money::operator+=(const money& m) {
        if (currency() != m.currency()) {
            throw std::logic_error("incompatible currencies!");
        }
        _amount += m.amount();
    }

    void money::operator+=(const double& m) {
        money tmp(this->currency(), m);
        *this += tmp;
    }

    std::string money::to_string() const {
        std::ostringstream strout;
        strout << this->integral() << "," << this->part() << " " << mc::to_string(this->currency());
        return strout.str();
    }

    bool operator==(const money& m1, const money& m2) {
        return m1.equal(m2);
    }
}