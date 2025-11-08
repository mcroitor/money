/**
 * @file money.h
 * @brief Money handling library with multi-currency support.
 * 
 * This library provides a robust and type-safe way to handle monetary values
 * with different currencies. It avoids floating-point precision issues by
 * storing amounts as integers in the smallest currency units.
 * 
 * Key features:
 * - Precise monetary arithmetic using integer representation
 * - Support for multiple world currencies
 * - Currency conversion with custom exchange rates
 * - User-defined literals for easy money object creation
 * - Type-safe operations preventing mixing incompatible currencies
 * - String formatting for display purposes
 * 
 * @author Mihail Croitor
 * @date 2025
 */

#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include "currency.h"

namespace mc {

    /**
     * @brief A class representing monetary values with currency information.
     * 
     * The money class provides a safe and precise way to handle monetary calculations
     * by storing amounts as integers (in the smallest currency unit) to avoid
     * floating-point precision issues. It supports multiple currencies and
     * provides arithmetic operations, conversions, and formatting.
     */
    class money {
        std::uint64_t _amount;  ///< Amount stored in smallest currency units (e.g., cents for USD)
        mc::currency _currency; ///< Currency type of this monetary value
    public:
        /**
         * @brief Constructs a money object with zero amount and specified currency.
         * @param curr The currency type for this monetary value
         */
        money(mc::currency curr);
        
        /**
         * @brief Copy constructor.
         * @param other The money object to copy from
         */
        money(const money& other);
        
        /**
         * @brief Constructs a money object with specified currency and amount.
         * @param curr The currency type for this monetary value
         * @param amount The monetary amount (will be converted to smallest units)
         */
        money(mc::currency curr, double amount);
        
        /**
         * @brief Virtual destructor (default implementation).
         */
        virtual ~money() = default;

        /**
         * @brief Gets the integral part of the monetary amount.
         * 
         * Returns the main currency unit (e.g., dollars for USD, euros for EUR,
         * rubles for RUB). This is the amount divided by 100 (assuming 2 decimal places).
         * 
         * @return The integral part of the amount (major currency units)
         */
        const uint64_t integral() const;
        
        /**
         * @brief Gets the fractional part of the monetary amount.
         * 
         * Returns the minor currency unit (e.g., cents for USD, kopecks for RUB,
         * bani for RON). This is the remainder when dividing by 100.
         * 
         * @return The fractional part of the amount (minor currency units, 0-99)
         */
        const uint64_t part() const;
        
        /**
         * @brief Gets the total amount in the smallest currency units.
         * 
         * Returns the complete amount stored internally, representing the total
         * value in the smallest possible units for the currency (typically cents).
         * 
         * @return The total amount in smallest currency units
         */
        const uint64_t amount() const;
        
        /**
         * @brief Gets the currency type of this monetary value.
         * 
         * @return The currency enumeration value
         */
        const mc::currency currency() const;
        
        /**
         * @brief Gets the textual name of the currency.
         * 
         * Returns a human-readable string representation of the currency type
         * (e.g., "United States Dollar", "Russia Ruble").
         * 
         * @return The currency name as a string
         */
        const std::string currency_name() const;

        /**
         * @brief Assignment operator.
         * 
         * Assigns the value and currency from another money object to this one.
         * 
         * @param other The money object to assign from
         * @return Reference to this money object
         */
        const money& operator=(const money& other);
        
        /**
         * @brief Checks equality with another money object.
         * 
         * Two money objects are considered equal if they have the same currency
         * and the same amount.
         * 
         * @param other The money object to compare with
         * @return true if the objects are equal, false otherwise
         */
        bool equal(const money& other) const;

        /**
         * @brief Converts this money object to a different currency.
         * 
         * Creates a new money object with the specified target currency,
         * converting the amount using the provided exchange rate.
         * 
         * @param to The target currency to convert to
         * @param rate The exchange rate from this currency to the target currency
         * @return A new money object with the converted amount and target currency
         */
        money convert(mc::currency to, double rate) const;

        /**
         * @brief Addition assignment operator for money objects.
         * 
         * Adds the amount from another money object to this one.
         * Both objects must have the same currency.
         * 
         * @param other The money object to add
         * @throws std::invalid_argument if currencies don't match
         */
        void operator+=(const money& other);
        
        /**
         * @brief Addition assignment operator for double values.
         * 
         * Adds a double value to this money object. The value is treated
         * as being in the same currency as this object.
         * 
         * @param value The amount to add
         */
        void operator+=(const double& value);
        
        /**
         * @brief Subtraction assignment operator for money objects.
         * 
         * Subtracts the amount from another money object from this one.
         * Both objects must have the same currency.
         * 
         * @param other The money object to subtract
         * @throws std::invalid_argument if currencies don't match
         */
        void operator-=(const money& other);
        
        /**
         * @brief Subtraction assignment operator for double values.
         * 
         * Subtracts a double value from this money object. The value is treated
         * as being in the same currency as this object.
         * 
         * @param value The amount to subtract
         */
        void operator-=(const double& value);
        
        /**
         * @brief Multiplication assignment operator.
         * 
         * Multiplies this money object's amount by a scalar value.
         * 
         * @param multiplier The scalar value to multiply by
         */
        void operator*=(const double& multiplier);
        
        /**
         * @brief Division assignment operator.
         * 
         * Divides this money object's amount by a scalar value.
         * 
         * @param divisor The scalar value to divide by
         * @throws std::invalid_argument if divisor is zero
         */
        void operator/=(const double& divisor);

        /**
         * @brief Converts the money object to a string representation.
         * 
         * Returns a formatted string showing the amount and currency,
         * typically in the format "amount currency_code" (e.g., "123.45 USD").
         * 
         * @return String representation of the money object
         */
        std::string to_string() const;
    };
    
    /**
     * @brief Equality operator for money objects.
     * 
     * Compares two money objects for equality. Objects are equal if they
     * have the same currency and amount.
     * 
     * @param lhs Left-hand side money object
     * @param rhs Right-hand side money object
     * @return true if objects are equal, false otherwise
     */
    bool operator==(const money& lhs, const money& rhs);

    /**
     * @brief Addition operator for two money objects.
     * 
     * Adds two money objects together. Both objects must have the same currency.
     * 
     * @param lhs Left-hand side money object
     * @param rhs Right-hand side money object
     * @return New money object with the sum of both amounts
     * @throws std::invalid_argument if currencies don't match
     */
    money operator+(const money& lhs, const money& rhs);
    
    /**
     * @brief Addition operator for double and money object.
     * 
     * Adds a double value to a money object. The double is treated as
     * being in the same currency as the money object.
     * 
     * @param value The double value to add
     * @param money_obj The money object
     * @return New money object with the added amount
     */
    money operator+(const double& value, const money& money_obj);
    
    /**
     * @brief Addition operator for money object and double.
     * 
     * Adds a double value to a money object. The double is treated as
     * being in the same currency as the money object.
     * 
     * @param money_obj The money object
     * @param value The double value to add
     * @return New money object with the added amount
     */
    money operator+(const money& money_obj, const double& value);
    
    /**
     * @brief Subtraction operator for two money objects.
     * 
     * Subtracts the second money object from the first. Both objects
     * must have the same currency.
     * 
     * @param lhs Left-hand side money object (minuend)
     * @param rhs Right-hand side money object (subtrahend)
     * @return New money object with the difference
     * @throws std::invalid_argument if currencies don't match
     */
    money operator-(const money& lhs, const money& rhs);
    
    /**
     * @brief Multiplication operator for money object and scalar.
     * 
     * Multiplies a money object by a scalar value.
     * 
     * @param money_obj The money object
     * @param multiplier The scalar multiplier
     * @return New money object with the multiplied amount
     */
    money operator*(const money& money_obj, const double& multiplier);
    
    /**
     * @brief Multiplication operator for scalar and money object.
     * 
     * Multiplies a money object by a scalar value.
     * 
     * @param multiplier The scalar multiplier
     * @param money_obj The money object
     * @return New money object with the multiplied amount
     */
    money operator*(const double& multiplier, const money& money_obj);
    
    /**
     * @brief Division operator for money object and scalar.
     * 
     * Divides a money object by a scalar value.
     * 
     * @param money_obj The money object
     * @param divisor The scalar divisor
     * @return New money object with the divided amount
     * @throws std::invalid_argument if divisor is zero
     */
    money operator/(const money& money_obj, const double& divisor);

    /// User-defined literals for currency creation
    /// These operators allow creation of money objects using syntax like: 100.50_USD, 75.25_EUR, etc.
    /// Each operator creates a money object with the specified amount and corresponding currency.

    /**
     * @brief User-defined literal for United Arab Emirates Dirham.
     * @param amount The monetary amount
     * @return money object with AED currency
     */
    money operator "" _AED(long double amount);
    /**
     * @brief User-defined literal for Afghan Afghani.
     * @param amount The monetary amount
     * @return money object with AFN currency
     */
    money operator "" _AFN(long double amount);
    /**
     * @brief User-defined literal for Albanian Lek.
     * @param amount The monetary amount
     * @return money object with ALL currency
     */
    money operator "" _ALL(long double amount);    
    /**
     * @brief User-defined literal for Armenian Dram.
     * @param amount The monetary amount
     * @return money object with AMD currency
     */
    money operator "" _AMD(long double amount);
    /**
     * @brief User-defined literal for Netherlands Antillean Guilder.
     * @param amount The monetary amount
     * @return money object with ANG currency
     */
    money operator "" _ANG(long double amount);
    /**
     * @brief User-defined literal for Angolan Kwanza.
     * @param amount The monetary amount
     * @return money object with AOA currency
     */
    money operator "" _AOA(long double amount);
    /**
     * @brief User-defined literal for Argentine Peso.
     * @param amount The monetary amount
     * @return money object with ARS currency
     */
    money operator "" _ARS(long double amount);
    /**
     * @brief User-defined literal for Australian Dollar.
     * @param amount The monetary amount
     * @return money object with AUD currency
     */
    money operator "" _AUD(long double amount);
    /**
     * @brief User-defined literal for Aruban Florin.
     * @param amount The monetary amount
     * @return money object with AWG currency
     */
    money operator "" _AWG(long double amount);
    /**
     * @brief User-defined literal for Azerbaijani Manat.
     * @param amount The monetary amount
     * @return money object with AZN currency
     */
    money operator "" _AZN(long double amount);
    /**
     * @brief User-defined literal for Bosnia and Herzegovina Convertible Mark.
     * @param amount The monetary amount
     * @return money object with BAM currency
     */
    money operator "" _BAM(long double amount);
    /**
     * @brief User-defined literal for Barbados Dollar.
     * @param amount The monetary amount
     * @return money object with BBD currency
     */
    money operator "" _BBD(long double amount);
    /**
     * @brief User-defined literal for Bangladeshi Taka.
     * @param amount The monetary amount
     * @return money object with BDT currency
     */
    money operator "" _BDT(long double amount);
    /**
     * @brief User-defined literal for Bulgarian Lev.
     * @param amount The monetary amount
     * @return money object with BGN currency
     */
    money operator "" _BGN(long double amount);
    /**
     * @brief User-defined literal for Bahraini Dinar.
     * @param amount The monetary amount
     * @return money object with BHD currency
     */
    money operator "" _BHD(long double amount);
    /**
     * @brief User-defined literal for Burundian Franc.
     * @param amount The monetary amount
     * @return money object with BIF currency
     */
    money operator "" _BIF(long double amount);
    /**
     * @brief User-defined literal for Bermudian Dollar.
     * @param amount The monetary amount
     * @return money object with BMD currency
     */
    money operator "" _BMD(long double amount);
    /**
     * @brief User-defined literal for Brunei Dollar.
     * @param amount The monetary amount
     * @return money object with BND currency
     */
    money operator "" _BND(long double amount);
    /**
     * @brief User-defined literal for Boliviano.
     * @param amount The monetary amount
     * @return money object with BOB currency
     */
    money operator "" _BOB(long double amount);
    /**
     * @brief User-defined literal for Brazilian Real.
     * @param amount The monetary amount
     * @return money object with BRL currency
     */
    money operator "" _BRL(long double amount);
    /**
     * @brief User-defined literal for Bahamian Dollar.
     * @param amount The monetary amount
     * @return money object with BSD currency
     */
    money operator "" _BSD(long double amount);
    /**
     * @brief User-defined literal for Bhutanese Ngultrum.
     * @param amount The monetary amount
     * @return money object with BTN currency
     */
    money operator "" _BTN(long double amount);
    /**
     * @brief User-defined literal for Botswana Pula.
     * @param amount The monetary amount
     * @return money object with BWP currency
     */
    money operator "" _BWP(long double amount);
    /**
     * @brief User-defined literal for Belarusian Ruble.
     * @param amount The monetary amount
     * @return money object with BYN currency
     */
    money operator "" _BYN(long double amount);
    /**
     * @brief User-defined literal for Belize Dollar.
     * @param amount The monetary amount
     * @return money object with BZD currency
     */
    money operator "" _BZD(long double amount);
    /**
     * @brief User-defined literal for Canadian Dollar.
     * @param amount The monetary amount
     * @return money object with CAD currency
     */
    money operator "" _CAD(long double amount);
    /**
     * @brief User-defined literal for Congolese Franc.
     * @param amount The monetary amount
     * @return money object with CDF currency
     */
    money operator "" _CDF(long double amount);
    /**
     * @brief User-defined literal for Swiss Franc.
     * @param amount The monetary amount
     * @return money object with CHF currency
     */
    money operator "" _CHF(long double amount);
    /**
     * @brief User-defined literal for Chilean Peso.
     * @param amount The monetary amount
     * @return money object with CLP currency
     */
    money operator "" _CLP(long double amount);
    /**
     * @brief User-defined literal for Chinese Yuan.
     * @param amount The monetary amount
     * @return money object with CNY currency
     */
    money operator "" _CNY(long double amount);
    /**
     * @brief User-defined literal for Colombian Peso.
     * @param amount The monetary amount
     * @return money object with COP currency
     */
    money operator "" _COP(long double amount);
    /**
     * @brief User-defined literal for Costa Rican Colón.
     * @param amount The monetary amount
     * @return money object with CRC currency
     */
    money operator "" _CRC(long double amount);
    /**
     * @brief User-defined literal for Cuban Convertible Peso.
     * @param amount The monetary amount
     * @return money object with CUC currency
     */
    money operator "" _CUC(long double amount);
    /**
     * @brief User-defined literal for Cuban Peso.
     * @param amount The monetary amount
     * @return money object with CUP currency
     */
    money operator "" _CUP(long double amount);
    /**
     * @brief User-defined literal for Cape Verdean Escudo.
     * @param amount The monetary amount
     * @return money object with CVE currency
     */
    money operator "" _CVE(long double amount);
    /**
     * @brief User-defined literal for Czech Koruna.
     * @param amount The monetary amount
     * @return money object with CZK currency
     */
    money operator "" _CZK(long double amount);
    /**
     * @brief User-defined literal for Djiboutian Franc.
     * @param amount The monetary amount
     * @return money object with DJF currency
     */
    money operator "" _DJF(long double amount);
    /**
     * @brief User-defined literal for Danish Krone.
     * @param amount The monetary amount
     * @return money object with DKK currency
     */
    money operator "" _DKK(long double amount);
    /**
     * @brief User-defined literal for Dominican Peso.
     * @param amount The monetary amount
     * @return money object with DOP currency
     */
    money operator "" _DOP(long double amount);
    /**
     * @brief User-defined literal for Algerian Dinar.
     * @param amount The monetary amount
     * @return money object with DZD currency
     */
    money operator "" _DZD(long double amount);
    /**
     * @brief User-defined literal for Egyptian Pound.
     * @param amount The monetary amount
     * @return money object with EGP currency
     */
    money operator "" _EGP(long double amount);
    /**
     * @brief User-defined literal for Eritrean Nakfa.
     * @param amount The monetary amount
     * @return money object with ERN currency
     */
    money operator "" _ERN(long double amount);
    /**
     * @brief User-defined literal for Ethiopian Birr.
     * @param amount The monetary amount
     * @return money object with ETB currency
     */
    money operator "" _ETB(long double amount);
    /**
     * @brief User-defined literal for Euro.
     * @param amount The monetary amount
     * @return money object with EUR currency
     */
    money operator "" _EUR(long double amount);
    /**
     * @brief User-defined literal for Fijian Dollar.
     * @param amount The monetary amount
     * @return money object with FJD currency
     */
    money operator "" _FJD(long double amount);
    /**
     * @brief User-defined literal for Falkland Islands Pound.
     * @param amount The monetary amount
     * @return money object with FKP currency
     */
    money operator "" _FKP(long double amount);
    /**
     * @brief User-defined literal for British Pound Sterling.
     * @param amount The monetary amount
     * @return money object with GBP currency
     */
    money operator "" _GBP(long double amount);
    /**
     * @brief User-defined literal for Georgian Lari.
     * @param amount The monetary amount
     * @return money object with GEL currency
     */
    money operator "" _GEL(long double amount);
    /**
     * @brief User-defined literal for Guernsey Pound.
     * @param amount The monetary amount
     * @return money object with GGP currency
     */
    money operator "" _GGP(long double amount);
    /**
     * @brief User-defined literal for Ghanaian Cedi.
     * @param amount The monetary amount
     * @return money object with GHS currency
     */
    money operator "" _GHS(long double amount);
    /**
     * @brief User-defined literal for Gibraltar Pound.
     * @param amount The monetary amount
     * @return money object with GIP currency
     */
    money operator "" _GIP(long double amount);
    /**
     * @brief User-defined literal for Gambian Dalasi.
     * @param amount The monetary amount
     * @return money object with GMD currency
     */
    money operator "" _GMD(long double amount);
    /**
     * @brief User-defined literal for Guinean Franc.
     * @param amount The monetary amount
     * @return money object with GNF currency
     */
    money operator "" _GNF(long double amount);
    /**
     * @brief User-defined literal for Guatemalan Quetzal.
     * @param amount The monetary amount
     * @return money object with GTQ currency
     */
    money operator "" _GTQ(long double amount);
    /**
     * @brief User-defined literal for Guyanese Dollar.
     * @param amount The monetary amount
     * @return money object with GYD currency
     */
    money operator "" _GYD(long double amount);
    /**
     * @brief User-defined literal for Hong Kong Dollar.
     * @param amount The monetary amount
     * @return money object with HKD currency
     */
    money operator "" _HKD(long double amount);
    /**
     * @brief User-defined literal for Honduran Lempira.
     * @param amount The monetary amount
     * @return money object with HNL currency
     */
    money operator "" _HNL(long double amount);
    /**
     * @brief User-defined literal for Croatian Kuna.
     * @param amount The monetary amount
     * @return money object with HRK currency
     */
    money operator "" _HRK(long double amount);
    /**
     * @brief User-defined literal for Haitian Gourde.
     * @param amount The monetary amount
     * @return money object with HTG currency
     */
    money operator "" _HTG(long double amount);
    /**
     * @brief User-defined literal for Hungarian Forint.
     * @param amount The monetary amount
     * @return money object with HUF currency
     */
    money operator "" _HUF(long double amount);
    /**
     * @brief User-defined literal for Indonesian Rupiah.
     * @param amount The monetary amount
     * @return money object with IDR currency
     */
    money operator "" _IDR(long double amount);
    /**
     * @brief User-defined literal for Israeli New Shekel.
     * @param amount The monetary amount
     * @return money object with ILS currency
     */
    money operator "" _ILS(long double amount);
    /**
     * @brief User-defined literal for Isle of Man Pound.
     * @param amount The monetary amount
     * @return money object with IMP currency
     */
    money operator "" _IMP(long double amount);
    /**
     * @brief User-defined literal for Indian Rupee.
     * @param amount The monetary amount
     * @return money object with INR currency
     */
    money operator "" _INR(long double amount);
    /**
     * @brief User-defined literal for Iraqi Dinar.
     * @param amount The monetary amount
     * @return money object with IQD currency
     */
    money operator "" _IQD(long double amount);
    /**
     * @brief User-defined literal for Iranian Rial.
     * @param amount The monetary amount
     * @return money object with IRR currency
     */
    money operator "" _IRR(long double amount);
    /**
     * @brief User-defined literal for Icelandic Króna.
     * @param amount The monetary amount
     * @return money object with ISK currency
     */
    money operator "" _ISK(long double amount);
    /**
     * @brief User-defined literal for Jersey Pound.
     * @param amount The monetary amount
     * @return money object with JEP currency
     */
    money operator "" _JEP(long double amount);
    /**
     * @brief User-defined literal for Jamaican Dollar.
     * @param amount The monetary amount
     * @return money object with JMD currency
     */
    money operator "" _JMD(long double amount);
    /**
     * @brief User-defined literal for Jordanian Dinar.
     * @param amount The monetary amount
     * @return money object with JOD currency
     */
    money operator "" _JOD(long double amount);
    /**
     * @brief User-defined literal for Japanese Yen.
     * @param amount The monetary amount
     * @return money object with JPY currency
     */
    money operator "" _JPY(long double amount);
    /**
     * @brief User-defined literal for Kenyan Shilling.
     * @param amount The monetary amount
     * @return money object with KES currency
     */
    money operator "" _KES(long double amount);
    /**
     * @brief User-defined literal for Kyrgyzstani Som.
     * @param amount The monetary amount
     * @return money object with KGS currency
     */
    money operator "" _KGS(long double amount);
    /**
     * @brief User-defined literal for Cambodian Riel.
     * @param amount The monetary amount
     * @return money object with KHR currency
     */
    money operator "" _KHR(long double amount);
    /**
     * @brief User-defined literal for Comorian Franc.
     * @param amount The monetary amount
     * @return money object with KMF currency
     */
    money operator "" _KMF(long double amount); 
    /**
     * @brief User-defined literal for North Korean Won.
     * @param amount The monetary amount
     * @return money object with KPW currency
     */
    money operator "" _KPW(long double amount);
    /**
     * @brief User-defined literal for South Korean Won.
     * @param amount The monetary amount
     * @return money object with KRW currency
     */
    money operator "" _KRW(long double amount);
    /**
     * @brief User-defined literal for Kuwaiti Dinar.
     * @param amount The monetary amount
     * @return money object with KWD currency
     */
    money operator "" _KWD(long double amount);
    /**
     * @brief User-defined literal for Cayman Islands Dollar.
     * @param amount The monetary amount
     * @return money object with KYD currency
     */
    money operator "" _KYD(long double amount);
    /**
     * @brief User-defined literal for Kazakhstani Tenge.
     * @param amount The monetary amount
     * @return money object with KZT currency
     */
    money operator "" _KZT(long double amount);
    /**
     * @brief User-defined literal for Laotian Kip.
     * @param amount The monetary amount
     * @return money object with LAK currency
     */
    money operator "" _LAK(long double amount);
    /**
     * @brief Lebanese Pound literal
     * @param amount The monetary amount
     * @return money object with LBP currency
     */
    money operator "" _LBP(long double amount);
    /**
     * @brief Sri Lankan Rupee literal
     * @param amount The monetary amount
     * @return money object with LKR currency
     */
    money operator "" _LKR(long double amount);
    /**
     * @brief Liberian Dollar literal
     * @param amount The monetary amount
     * @return money object with LRD currency
     */
    money operator "" _LRD(long double amount);
    /**
     * @brief Lesotho Loti literal
     * @param amount The monetary amount
     * @return money object with LSL currency
     */
    money operator "" _LSL(long double amount);
    /**
     * @brief Libyan Dinar literal
     * @param amount The monetary amount
     * @return money object with LYD currency
     */
    money operator "" _LYD(long double amount);
    /**
     * @brief Moroccan Dirham literal
     * @param amount The monetary amount
     * @return money object with MAD currency
     */
    money operator "" _MAD(long double amount);
    /**
     * @brief Moldovan Leu literal
     * @param amount The monetary amount
     * @return money object with MDL currency
     */
    money operator "" _MDL(long double amount);
    /**
     * @brief Malagasy Ariary literal
     * @param amount The monetary amount
     * @return money object with MGA currency
     */
    money operator "" _MGA(long double amount);
    /**
     * @brief Macedonian Denar literal
     * @param amount The monetary amount
     * @return money object with MKD currency
     */
    money operator "" _MKD(long double amount);
    /**
     * @brief Myanmar Kyat literal
     * @param amount The monetary amount
     * @return money object with MMK currency
     */
    money operator "" _MMK(long double amount);
    /**
     * @brief Mongolian Tugrik literal
     * @param amount The monetary amount
     * @return money object with MNT currency
     */
    money operator "" _MNT(long double amount);
    /**
     * @brief Macanese Pataca literal
     * @param amount The monetary amount
     * @return money object with MOP currency
     */
    money operator "" _MOP(long double amount);
    /**
     * @brief Mauritanian Ouguiya literal
     * @param amount The monetary amount
     * @return money object with MRU currency
     */
    money operator "" _MRU(long double amount);
    /**
     * @brief Mauritian Rupee literal
     * @param amount The monetary amount
     * @return money object with MUR currency
     */
    money operator "" _MUR(long double amount);
    /**
     * @brief Maldivian Rufiyaa literal
     * @param amount The monetary amount
     * @return money object with MVR currency
     */
    money operator "" _MVR(long double amount);
    /**
     * @brief Malawian Kwacha literal
     * @param amount The monetary amount
     * @return money object with MWK currency
     */
    money operator "" _MWK(long double amount);
    /**
     * @brief Mexican Peso literal
     * @param amount The monetary amount
     * @return money object with MXN currency
     */
    money operator "" _MXN(long double amount);
    /**
     * @brief Malaysian Ringgit literal
     * @param amount The monetary amount
     * @return money object with MYR currency
     */
    money operator "" _MYR(long double amount);
    /**
     * @brief Mozambican Metical literal
     * @param amount The monetary amount
     * @return money object with MZN currency
     */
    money operator "" _MZN(long double amount);
    /**
     * @brief Namibian Dollar literal
     * @param amount The monetary amount
     * @return money object with NAD currency
     */
    money operator "" _NAD(long double amount);
    /**
     * @brief Nigerian Naira literal
     * @param amount The monetary amount
     * @return money object with NGN currency
     */
    money operator "" _NGN(long double amount);
    /**
     * @brief Nicaraguan Córdoba literal
     * @param amount The monetary amount
     * @return money object with NIO currency
     */
    money operator "" _NIO(long double amount);
    /**
     * @brief Norwegian Krone literal
     * @param amount The monetary amount
     * @return money object with NOK currency
     */
    money operator "" _NOK(long double amount);
    /**
     * @brief Nepalese Rupee literal
     * @param amount The monetary amount
     * @return money object with NPR currency
     */
    money operator "" _NPR(long double amount);
    /**
     * @brief New Zealand Dollar literal
     * @param amount The monetary amount
     * @return money object with NZD currency
     */
    money operator "" _NZD(long double amount);
    /**
     * @brief Omani Rial literal
     * @param amount The monetary amount
     * @return money object with OMR currency
     */
    money operator "" _OMR(long double amount);
    /**
     * @brief Panamanian Balboa literal
     * @param amount The monetary amount
     * @return money object with PAB currency
     */
    money operator "" _PAB(long double amount);
    /**
     * @brief Peruvian Sol literal
     * @param amount The monetary amount
     * @return money object with PEN currency
     */
    money operator "" _PEN(long double amount);
    /**
     * @brief Papua New Guinean Kina literal
     * @param amount The monetary amount
     * @return money object with PGK currency
     */
    money operator "" _PGK(long double amount);
    /**
     * @brief Philippine Peso literal
     * @param amount The monetary amount
     * @return money object with PHP currency
     */
    money operator "" _PHP(long double amount);
    /**
     * @brief Pakistani Rupee literal
     * @param amount The monetary amount
     * @return money object with PKR currency
     */
    money operator "" _PKR(long double amount);
    /**
     * @brief Polish Złoty literal
     * @param amount The monetary amount
     * @return money object with PLN currency
     */
    money operator "" _PLN(long double amount);
    /**
     * @brief Paraguayan Guaraní literal
     * @param amount The monetary amount
     * @return money object with PYG currency
     */
    money operator "" _PYG(long double amount);
    /**
     * @brief Qatari Riyal literal
     * @param amount The monetary amount
     * @return money object with QAR currency
     */
    money operator "" _QAR(long double amount);
    /**
     * @brief User-defined literal for Romanian Leu.
     * @param amount The monetary amount
     * @return money object with RON currency
     */
    money operator "" _RON(long double amount);
    /**
     * @brief Serbian Dinar literal
     * @param amount The monetary amount
     * @return money object with RSD currency
     */
    money operator "" _RSD(long double amount);
    /**
     * @brief User-defined literal for Russian Ruble.
     * @param amount The monetary amount
     * @return money object with RUB currency
     */
    money operator "" _RUB(long double amount);
    /**
     * @brief Rwandan Franc literal
     * @param amount The monetary amount
     * @return money object with RWF currency
     */
    money operator "" _RWF(long double amount);
    /**
     * @brief Saudi Riyal literal
     * @param amount The monetary amount
     * @return money object with SAR currency
     */
    money operator "" _SAR(long double amount);
    /**
     * @brief Solomon Islands Dollar literal
     * @param amount The monetary amount
     * @return money object with SBD currency
     */
    money operator "" _SBD(long double amount);
    /**
     * @brief Seychellois Rupee literal
     * @param amount The monetary amount
     * @return money object with SCR currency
     */
    money operator "" _SCR(long double amount);
    /**
     * @brief Sudanese Pound literal
     * @param amount The monetary amount
     * @return money object with SDG currency
     */
    money operator "" _SDG(long double amount);
    /**
     * @brief Swedish Krona literal
     * @param amount The monetary amount
     * @return money object with SEK currency
     */
    money operator "" _SEK(long double amount);
    /**
     * @brief Singapore Dollar literal
     * @param amount The monetary amount
     * @return money object with SGD currency
     */
    money operator "" _SGD(long double amount);
    /**
     * @brief Saint Helena Pound literal
     * @param amount The monetary amount
     * @return money object with SHP currency
     */
    money operator "" _SHP(long double amount);
    /**
     * @brief Sierra Leonean Leone literal
     * @param amount The monetary amount
     * @return money object with SLL currency
     */
    money operator "" _SLL(long double amount);
    /**
     * @brief Somali Shilling literal
     * @param amount The monetary amount
     * @return money object with SOS currency
     */
    money operator "" _SOS(long double amount);
    /**
     * @brief Seborgan Luigino literal
     * @param amount The monetary amount
     * @return money object with SPL currency
     */
    money operator "" _SPL(long double amount);
    /**
     * @brief Surinamese Dollar literal
     * @param amount The monetary amount
     * @return money object with SRD currency
     */
    money operator "" _SRD(long double amount);
    /**
     * @brief São Tomé and Príncipe Dobra literal
     * @param amount The monetary amount
     * @return money object with STN currency
     */
    money operator "" _STN(long double amount);
    /**
     * @brief Salvadoran Colón literal
     * @param amount The monetary amount
     * @return money object with SVC currency
     */
    money operator "" _SVC(long double amount);
    /**
     * @brief Syrian Pound literal
     * @param amount The monetary amount
     * @return money object with SYP currency
     */
    money operator "" _SYP(long double amount);
    /**
     * @brief Swazi Lilangeni literal
     * @param amount The monetary amount
     * @return money object with SZL currency
     */
    money operator "" _SZL(long double amount);
    /**
     * @brief Thai Baht literal
     * @param amount The monetary amount
     * @return money object with THB currency
     */
    money operator "" _THB(long double amount);
    /**
     * @brief Tajikistani Somoni literal
     * @param amount The monetary amount
     * @return money object with TJS currency
     */
    money operator "" _TJS(long double amount);
    /**
     * @brief Turkmenistani Manat literal
     * @param amount The monetary amount
     * @return money object with TMT currency
     */
    money operator "" _TMT(long double amount);
    /**
     * @brief Tunisian Dinar literal
     * @param amount The monetary amount
     * @return money object with TND currency
     */
    money operator "" _TND(long double amount);
    /**
     * @brief Tongan Paʻanga literal
     * @param amount The monetary amount
     * @return money object with TOP currency
     */
    money operator "" _TOP(long double amount);
    /**
     * @brief Turkish Lira literal
     * @param amount The monetary amount
     * @return money object with TRY currency
     */
    money operator "" _TRY(long double amount);
    /**
     * @brief Trinidad and Tobago Dollar literal
     * @param amount The monetary amount
     * @return money object with TTD currency
     */
    money operator "" _TTD(long double amount);
    /**
     * @brief Tuvaluan Dollar literal
     * @param amount The monetary amount
     * @return money object with TVD currency
     */
    money operator "" _TVD(long double amount);
    /**
     * @brief Taiwan Dollar literal
     * @param amount The monetary amount
     * @return money object with TWD currency
     */
    money operator "" _TWD(long double amount);
    /**
     * @brief Tanzanian Shilling literal
     * @param amount The monetary amount
     * @return money object with TZS currency
     */
    money operator "" _TZS(long double amount);
    /**
     * @brief Ukrainian Hryvnia literal
     * @param amount The monetary amount
     * @return money object with UAH currency
     */
    money operator "" _UAH(long double amount);
    /**
     * @brief Ugandan Shilling literal
     * @param amount The monetary amount
     * @return money object with UGX currency
     */
    money operator "" _UGX(long double amount);
    /**
     * @brief User-defined literal for US Dollar.
     * @param amount The monetary amount
     * @return money object with USD currency
     * @example auto price = 123.45_USD;
     */
    money operator "" _USD(long double amount);
    /**
     * @brief Uruguayan Peso literal
     * @param amount The monetary amount
     * @return money object with UYU currency
     */
    money operator "" _UYU(long double amount);
    /**
     * @brief Uzbekistan Som literal
     * @param amount The monetary amount
     * @return money object with UZS currency
     */
    money operator "" _UZS(long double amount);
    // Final currency literals (V-Z currencies)
    /**
     * @brief Venezuelan Bolívar literal
     * @param amount The monetary amount
     * @return money object with VEF currency
     */
    money operator "" _VEF(long double amount);
    /**
     * @brief Vietnamese Dong literal
     * @param amount The monetary amount
     * @return money object with VND currency
     */
    money operator "" _VND(long double amount);
    /**
     * @brief Vanuatu Vatu literal
     * @param amount The monetary amount
     * @return money object with VUV currency
     */
    money operator "" _VUV(long double amount);
    /**
     * @brief Samoan Tala literal
     * @param amount The monetary amount
     * @return money object with WST currency
     */
    money operator "" _WST(long double amount);
    /**
     * @brief Central African CFA Franc literal
     * @param amount The monetary amount
     * @return money object with XAF currency
     */
    money operator "" _XAF(long double amount);
    /**
     * @brief East Caribbean Dollar literal
     * @param amount The monetary amount
     * @return money object with XCD currency
     */
    money operator "" _XCD(long double amount);
    /**
     * @brief Special Drawing Rights literal
     * @param amount The monetary amount
     * @return money object with XDR currency
     */
    money operator "" _XDR(long double amount);
    /**
     * @brief West African CFA Franc literal
     * @param amount The monetary amount
     * @return money object with XOF currency
     */
    money operator "" _XOF(long double amount);
    /**
     * @brief CFP Franc literal
     * @param amount The monetary amount
     * @return money object with XPF currency
     */
    money operator "" _XPF(long double amount);
    /**
     * @brief Yemeni Rial literal
     * @param amount The monetary amount
     * @return money object with YER currency
     */
    money operator "" _YER(long double amount);
    /**
     * @brief South African Rand literal
     * @param amount The monetary amount
     * @return money object with ZAR currency
     */
    money operator "" _ZAR(long double amount);
    /**
     * @brief Zambian Kwacha literal
     * @param amount The monetary amount
     * @return money object with ZMW currency
     */
    money operator "" _ZMW(long double amount);
    /**
     * @brief Zimbabwean Dollar literal
     * @param amount The monetary amount
     * @return money object with ZWD currency
     */
    money operator "" _ZWD(long double amount);
}

#endif /* MONEY_H */

