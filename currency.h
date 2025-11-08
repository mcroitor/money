/**
 * @file currency.h
 * @brief Currency enumeration and utility functions for the money library.
 * 
 * This file defines the currency enumeration containing all supported world currencies
 * and provides utility functions for currency conversion between different representations
 * (enum, string, short name). It also defines currency-related exceptions.
 * 
 * The currency system supports 169 different world currencies including major
 * currencies like USD, EUR, GBP, JPY as well as regional and special currencies.
 * 
 * @author Mihail Croitor
 * @date 2025
 */

#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <map>

namespace mc {

    /**
     * @brief Enumeration of all supported world currencies.
     * 
     * This enum class contains ISO 4217 currency codes for all major world currencies.
     * Each currency is represented by its standard three-letter code (e.g., USD for
     * US Dollar, EUR for Euro, GBP for British Pound).
     * 
     * The enumeration supports 169 different currencies including:
     * - Major international currencies (USD, EUR, GBP, JPY, CHF)
     * - Regional currencies (CAD, AUD, CNY, RUB, RON)
     * - Developing market currencies
     * - Special drawing rights and regional monetary units
     * 
     * @note All currency codes follow ISO 4217 standard
     * @see https://www.iso.org/iso-4217-currency-codes.html
     */
    enum class currency {
        AED,  ///< United Arab Emirates Dirham
        AFN,  ///< Afghan Afghani
        ALL,  ///< Albanian Lek
        AMD,  ///< Armenian Dram
        ANG,  ///< Netherlands Antillean Guilder
        AOA,  ///< Angolan Kwanza
        ARS,  ///< Argentine Peso
        AUD,  ///< Australian Dollar
        AWG,  ///< Aruban Florin
        AZN,  ///< Azerbaijani Manat
        BAM,  ///< Bosnia and Herzegovina Convertible Mark
        BBD,  ///< Barbados Dollar
        BDT,  ///< Bangladeshi Taka
        BGN,  ///< Bulgarian Lev
        BHD,  ///< Bahraini Dinar
        BIF,  ///< Burundian Franc
        BMD,  ///< Bermudian Dollar
        BND,  ///< Brunei Dollar
        BOB,  ///< Boliviano
        BRL,  ///< Brazilian Real
        BSD,  ///< Bahamian Dollar
        BTN,  ///< Bhutanese Ngultrum
        BWP,  ///< Botswana Pula
        BYN,  ///< Belarusian Ruble
        BZD,  ///< Belize Dollar
        CAD,  ///< Canadian Dollar
        CDF,  ///< Congolese Franc
        CHF,  ///< Swiss Franc
        CLP,  ///< Chilean Peso
        CNY,  ///< Chinese Yuan
        COP,  ///< Colombian Peso
        CRC,  ///< Costa Rican Colón
        CUC,  ///< Cuban Convertible Peso
        CUP,  ///< Cuban Peso
        CVE,  ///< Cape Verdean Escudo
        CZK,  ///< Czech Koruna
        DJF,  ///< Djiboutian Franc
        DKK,  ///< Danish Krone
        DOP,  ///< Dominican Peso
        DZD,  ///< Algerian Dinar
        EGP,  ///< Egyptian Pound
        ERN,  ///< Eritrean Nakfa
        ETB,  ///< Ethiopian Birr
        EUR,  ///< Euro
        FJD,  ///< Fijian Dollar
        FKP,  ///< Falkland Islands Pound
        GBP,  ///< British Pound Sterling
        GEL,  ///< Georgian Lari
        GGP,  ///< Guernsey Pound
        GHS,  ///< Ghanaian Cedi
        GIP,  ///< Gibraltar Pound
        GMD,  ///< Gambian Dalasi
        GNF,  ///< Guinean Franc
        GTQ,  ///< Guatemalan Quetzal
        GYD,  ///< Guyanese Dollar
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
        JEP,  ///< Jersey Pound
        JMD,  ///< Jamaican Dollar
        JOD,  ///< Jordanian Dinar
        JPY,  ///< Japanese Yen
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
        QAR,  ///< Qatari Riyal
        RON,  ///< Romanian Leu
        RSD,  ///< Serbian Dinar
        RUB,  ///< Russian Ruble
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
        UAH,  ///< Ukrainian Hryvnia
        UGX,  ///< Ugandan Shilling
        USD,  ///< US Dollar
        UYU,  ///< Uruguayan Peso
        UZS,  ///< Uzbekistan Som
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
        ZWD  ///< Zimbabwean Dollar
    };
    
    /**
     * @brief Converts a currency enumeration value to its full string representation.
     * 
     * Returns the human-readable full name of the currency (e.g., "US Dollar" for USD,
     * "Euro" for EUR, "British Pound Sterling" for GBP).
     * 
     * @param curr The currency enumeration value to convert
     * @return std::string The full name of the currency
     * @throws unknown_currency if the currency value is not recognized
     * 
     * @example
     * std::string name = to_string(currency::USD); // Returns "US Dollar"
     */
    std::string to_string(currency curr);
    
    /**
     * @brief Converts a currency enumeration value to its short name (ISO code).
     * 
     * Returns the standard three-letter ISO 4217 currency code as a string
     * (e.g., "USD", "EUR", "GBP").
     * 
     * @param curr The currency enumeration value to convert
     * @return std::string The ISO 4217 three-letter currency code
     * @throws unknown_currency_shortname if the currency value is not recognized
     * 
     * @example
     * std::string code = to_shortname(currency::USD); // Returns "USD"
     */
    std::string to_shortname(currency curr);
    
    /**
     * @brief Converts a string representation to a currency enumeration value.
     * 
     * Parses a string containing either the full currency name or the ISO code
     * and returns the corresponding currency enumeration value. The function
     * accepts both full names and three-letter codes.
     * 
     * @param currency_str The string representation of the currency (name or code)
     * @return currency The corresponding currency enumeration value
     * @throws unknown_currency if the string does not match any known currency
     * 
     * @example
     * currency c1 = to_currency("USD");        // From ISO code
     * currency c2 = to_currency("US Dollar");  // From full name
     */
    currency to_currency(std::string currency_str);

    /**
     * @brief Exception thrown when an unknown currency is encountered.
     * 
     * This exception is thrown by currency conversion functions when they
     * encounter a currency enumeration value or string that is not recognized
     * or supported by the system.
     * 
     * Typically thrown by:
     * - to_string(currency) when given an invalid currency enum value
     * - to_currency(std::string) when given an unrecognized currency string
     * 
     * @example
     * try {
     *     auto curr = to_currency("INVALID");
     * } catch (const unknown_currency& e) {
     *     std::cout << "Error: " << e.what() << std::endl;
     * }
     */
    struct unknown_currency : public std::exception {
        /**
         * @brief Returns a description of the exception.
         * @return const char* A C-style string describing the exception
         */
        virtual const char* what() const noexcept;
    };

    /**
     * @brief Exception thrown when an unknown currency short name is encountered.
     * 
     * This exception is thrown by the to_shortname() function when it encounters
     * a currency enumeration value that cannot be converted to a valid ISO 4217
     * three-letter currency code.
     * 
     * This typically indicates an internal error or corruption in the currency
     * enumeration system, as all valid currency enum values should have
     * corresponding short names.
     * 
     * @example
     * try {
     *     std::string code = to_shortname(static_cast<currency>(999));
     * } catch (const unknown_currency_shortname& e) {
     *     std::cout << "Error: " << e.what() << std::endl;
     * }
     */
    struct unknown_currency_shortname : public std::exception {
        /**
         * @brief Returns a description of the exception.
         * @return const char* A C-style string describing the exception
         */
        virtual const char* what() const noexcept;
    };
}
#endif /* CURRENCY_H */

