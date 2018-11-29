#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include "currency.h"

namespace mc {
    namespace currency {

        /**
         * money class realization
         */
        class money {
            std::uint64_t _amount;
            currency_t _currency;
        public:
            money(currency_t);
            money(const money&);
            money(currency_t, double);
            virtual ~money() = default;

            /**
             * integral part of type. For USD --> dollar, ROL --> lei,
             * RUR --> ruble.
             * @return 
             */
            const uint64_t integral() const;
            /**
             * hundredth part of type. For USD --> cent, ROL --> ban,
             * RUR --> kopek.
             * @return 
             */
            const uint64_t part() const;
            /**
             * all amount in hundredth part.
             * @return 
             */
            const uint64_t amount() const;
            /**
             * currency type
             * @return 
             */
            const currency_t currency() const;
            /**
             * textual representation of currency type.
             * @return 
             */
            const std::string currency_name() const;

            const money& operator=(const money&);
            bool equal(const money&) const;

            /**
             * Money convertor
             * @param specify what currency _to_ you need
             * @param specify rate of currencies.
             * @return new money object with _to_ currency
             */
            money convert(currency_t /* to */, double /* rate */) const;

            void operator+=(const money&);
            void operator+=(const double&);
            void operator-=(const money&);
            void operator-=(const double&);
            void operator*=(const double&);
            void operator/=(const double&);

            std::string to_string() const;
        };
        bool operator==(const money&, const money&);

        money operator+(const money&, const money&);
        money operator+(const double&, const money&);
        money operator+(const money&, const double&);
        money operator-(const money&, const money&);
        money operator*(const money&, const double&);
        money operator*(const double&, const money&);
        money operator/(const money&, const double&);
    }
}

#endif /* MONEY_H */

