#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include "currency.h"

namespace mc {

    /**
     * money class realization
     */
    class money {
        std::uint64_t _amount;
        currency _currency;
    public:
        money(currency);
        money(const money&);
        money(currency, double);
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
        const currency currency() const;
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
        money convert(currency /* to */, double /* rate */) const;

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

    money operator "" _AED(long double);
    money operator "" _AFN(long double);
    money operator "" _ALL(long double);
    money operator "" _AMD(long double);
    money operator "" _ANG(long double);
    money operator "" _AOA(long double);
    money operator "" _ARS(long double);
    money operator "" _AUD(long double);
    money operator "" _AWG(long double);
    money operator "" _AZN(long double);
    money operator "" _BAM(long double);
    money operator "" _BBD(long double);
    money operator "" _BDT(long double);
    money operator "" _BGN(long double);
    money operator "" _BHD(long double);
    money operator "" _BIF(long double);
    money operator "" _BMD(long double);
    money operator "" _BND(long double);
    money operator "" _BOB(long double);
    money operator "" _BRL(long double);
    money operator "" _BSD(long double);
    money operator "" _BTN(long double);
    money operator "" _BWP(long double);
    money operator "" _BYN(long double);
    money operator "" _BZD(long double);
    money operator "" _CAD(long double);
    money operator "" _CDF(long double);
    money operator "" _CHF(long double);
    money operator "" _CLP(long double);
    money operator "" _CNY(long double);
    money operator "" _COP(long double);
    money operator "" _CRC(long double);
    money operator "" _CUC(long double);
    money operator "" _CUP(long double);
    money operator "" _CVE(long double);
    money operator "" _CZK(long double);
    money operator "" _DJF(long double);
    money operator "" _DKK(long double);
    money operator "" _DOP(long double);
    money operator "" _DZD(long double);
    money operator "" _EGP(long double);
    money operator "" _ERN(long double);
    money operator "" _ETB(long double);
    money operator "" _EUR(long double);
    money operator "" _FJD(long double);
    money operator "" _FKP(long double);
    money operator "" _GBP(long double);
    money operator "" _GEL(long double);
    money operator "" _GGP(long double);
    money operator "" _GHS(long double);
    money operator "" _GIP(long double);
    money operator "" _GMD(long double);
    money operator "" _GNF(long double);
    money operator "" _GTQ(long double);
    money operator "" _GYD(long double);
    money operator "" _HKD(long double);
    money operator "" _HNL(long double);
    money operator "" _HRK(long double);
    money operator "" _HTG(long double);
    money operator "" _HUF(long double);
    money operator "" _IDR(long double);
    money operator "" _ILS(long double);
    money operator "" _IMP(long double);
    money operator "" _INR(long double);
    money operator "" _IQD(long double);
    money operator "" _IRR(long double);
    money operator "" _ISK(long double);
    money operator "" _JEP(long double);
    money operator "" _JMD(long double);
    money operator "" _JOD(long double);
    money operator "" _JPY(long double);
    money operator "" _KES(long double);
    money operator "" _KGS(long double);
    money operator "" _KHR(long double);
    money operator "" _KMF(long double);
    money operator "" _KPW(long double);
    money operator "" _KRW(long double);
    money operator "" _KWD(long double);
    money operator "" _KYD(long double);
    money operator "" _KZT(long double);
    money operator "" _LAK(long double);
    money operator "" _LBP(long double);
    money operator "" _LKR(long double);
    money operator "" _LRD(long double);
    money operator "" _LSL(long double);
    money operator "" _LYD(long double);
    money operator "" _MAD(long double);
    money operator "" _MDL(long double);
    money operator "" _MGA(long double);
    money operator "" _MKD(long double);
    money operator "" _MMK(long double);
    money operator "" _MNT(long double);
    money operator "" _MOP(long double);
    money operator "" _MRU(long double);
    money operator "" _MUR(long double);
    money operator "" _MVR(long double);
    money operator "" _MWK(long double);
    money operator "" _MXN(long double);
    money operator "" _MYR(long double);
    money operator "" _MZN(long double);
    money operator "" _NAD(long double);
    money operator "" _NGN(long double);
    money operator "" _NIO(long double);
    money operator "" _NOK(long double);
    money operator "" _NPR(long double);
    money operator "" _NZD(long double);
    money operator "" _OMR(long double);
    money operator "" _PAB(long double);
    money operator "" _PEN(long double);
    money operator "" _PGK(long double);
    money operator "" _PHP(long double);
    money operator "" _PKR(long double);
    money operator "" _PLN(long double);
    money operator "" _PYG(long double);
    money operator "" _QAR(long double);
    money operator "" _RON(long double);
    money operator "" _RSD(long double);
    money operator "" _RUB(long double);
    money operator "" _RWF(long double);
    money operator "" _SAR(long double);
    money operator "" _SBD(long double);
    money operator "" _SCR(long double);
    money operator "" _SDG(long double);
    money operator "" _SEK(long double);
    money operator "" _SGD(long double);
    money operator "" _SHP(long double);
    money operator "" _SLL(long double);
    money operator "" _SOS(long double);
    money operator "" _SPL(long double);
    money operator "" _SRD(long double);
    money operator "" _STN(long double);
    money operator "" _SVC(long double);
    money operator "" _SYP(long double);
    money operator "" _SZL(long double);
    money operator "" _THB(long double);
    money operator "" _TJS(long double);
    money operator "" _TMT(long double);
    money operator "" _TND(long double);
    money operator "" _TOP(long double);
    money operator "" _TRY(long double);
    money operator "" _TTD(long double);
    money operator "" _TVD(long double);
    money operator "" _TWD(long double);
    money operator "" _TZS(long double);
    money operator "" _UAH(long double);
    money operator "" _UGX(long double);
    money operator "" _USD(long double);
    money operator "" _UYU(long double);
    money operator "" _UZS(long double);
    money operator "" _VEF(long double);
    money operator "" _VND(long double);
    money operator "" _VUV(long double);
    money operator "" _WST(long double);
    money operator "" _XAF(long double);
    money operator "" _XCD(long double);
    money operator "" _XDR(long double);
    money operator "" _XOF(long double);
    money operator "" _XPF(long double);
    money operator "" _YER(long double);
    money operator "" _ZAR(long double);
    money operator "" _ZMW(long double);
    money operator "" _ZWD(long double);
}

#endif /* MONEY_H */

