#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include "currency.h"

namespace mc {
    namespace currency {

        class money {
            std::uint64_t _amount;
            currency_t _currency;
        public:
            money(currency_t);
            money(const money&);
            money(currency_t, double);
            virtual ~money() = default;

            const uint64_t integral() const;
            const uint64_t part() const;
            const uint64_t amount() const;
            const currency_t currency() const;
            const std::string currency_name() const;

            const money& operator=(const money&);
            bool equal(const money&) const;
            
            money convert(currency_t /* to */, double /* rate */) const;

            void operator+=(const money&);
            void operator+=(const double&);

            std::string to_string() const;
        };
        bool operator==(const money&, const money&);
    }
}

#endif /* MONEY_H */

