#include <sstream>
#include "money.h"

namespace mc {

    money::money(currency_t c) :
    _currency(c), _integral(0), _part(0) {

    }

    money::money(const money& m) :
    _currency(m.currency()), _integral(m.integral()), _part(m.part()) {

    }

    money::money(currency_t c, double sum) : _currency(c) {
        _integral = (uint64_t) sum;
        _part = (uint64_t) (100 * (sum - _integral));

    }

    const uint64_t money::integral() const {
        return _integral;
    }

    const uint64_t money::part() const {
        return _part;
    }

    const currency_t money::currency() const {
        return _currency;
    }

    const money& money::operator=(const money& m) {
        this->_currency = m.currency();
        this->_integral = m.integral();
        this->_part = m.part();
        return *this;
    }

    bool money::equal(const money& m) const {
        return this->currency() == m.currency() &&
                this->integral() == m.integral() &&
                this->part() == m.part();
    }

    void money::operator+=(const money& m) {
        if (currency() != m.currency()) {
            throw std::logic_error("incompatible currencies!");
        }
        _part = (_part + m.part()) % 100;
        _integral = _integral + m.integral() + (_part + m.part()) / 100;
    }

    void money::operator+=(const double& m) {
        money tmp(this->currency(), m);
        *this += tmp;
    }
    
    std::string money::to_string() const{
        std::ostringstream strout;
        strout << this->integral() << "," << this->part() << " " << mc::to_string(this->currency());
        return strout.str();
    }

    bool operator==(const money& m1, const money& m2) {
        return m1.equal(m2);
    }
}