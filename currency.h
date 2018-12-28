#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <map>

namespace mc {
    namespace currency {

        /**
         * all currencies
         */
        enum class currency_t {
            AED,
            AFN,
            ALL,
            AMD,
            ANG,
            AOA,
            ARS,
            AUD,
            AWG,
            AZN,
            BAM,
            BBD,
            BDT,
            BGN,
            BHD,
            BIF,
            BMD,
            BND,
            BOB,
            BRL,
            BSD,
            BTN,
            BWP,
            BYN,
            BZD,
            CAD,
            CDF,
            CHF,
            CLP,
            CNY,
            COP,
            CRC,
            CUC,
            CUP,
            CVE,
            CZK,
            DJF,
            DKK,
            DOP,
            DZD,
            EGP,
            ERN,
            ETB,
            EUR,
            FJD,
            FKP,
            GBP,
            GEL,
            GGP,
            GHS,
            GIP,
            GMD,
            GNF,
            GTQ,
            GYD,
            HKD,
            HNL,
            HRK,
            HTG,
            HUF,
            IDR,
            ILS,
            IMP,
            INR,
            IQD,
            IRR,
            ISK,
            JEP,
            JMD,
            JOD,
            JPY,
            KES,
            KGS,
            KHR,
            KMF,
            KPW,
            KRW,
            KWD,
            KYD,
            KZT,
            LAK,
            LBP,
            LKR,
            LRD,
            LSL,
            LYD,
            MAD,
            MDL,
            MGA,
            MKD,
            MMK,
            MNT,
            MOP,
            MRU,
            MUR,
            MVR,
            MWK,
            MXN,
            MYR,
            MZN,
            NAD,
            NGN,
            NIO,
            NOK,
            NPR,
            NZD,
            OMR,
            PAB,
            PEN,
            PGK,
            PHP,
            PKR,
            PLN,
            PYG,
            QAR,
            RON,
            RSD,
            RUB,
            RWF,
            SAR,
            SBD,
            SCR,
            SDG,
            SEK,
            SGD,
            SHP,
            SLL,
            SOS,
            SPL,
            SRD,
            STN,
            SVC,
            SYP,
            SZL,
            THB,
            TJS,
            TMT,
            TND,
            TOP,
            TRY,
            TTD,
            TVD,
            TWD,
            TZS,
            UAH,
            UGX,
            USD,
            UYU,
            UZS,
            VEF,
            VND,
            VUV,
            WST,
            XAF,
            XCD,
            XDR,
            XOF,
            XPF,
            YER,
            ZAR,
            ZMW,
            ZWD
        };

        // ISO 4217 Currency Codes
        // Code Country Name
        // More effective will be vector structure
        extern const std::map<currency_t, std::string> currency_name_;

        // ISO 4217 Currency Codes
        // Code Short Name
        // More effective will be vector structure
        extern const std::map<currency_t, std::string> currency_to_shortname_;
        extern const std::map<std::string, currency_t> shortname_to_currency_;

        /**
         * currency to string
         */
        std::string to_string(currency_t);
        std::string to_shortname(currency_t);
        currency_t to_currency(std::string);

        /**
         * exceptions
         */
        struct unknown_currency : public std::exception {
            virtual const char* what() const noexcept;
        };
        struct unknown_currency_shortname : public std::exception {
            virtual const char* what() const noexcept;
        };
    }
}
#endif /* CURRENCY_H */

