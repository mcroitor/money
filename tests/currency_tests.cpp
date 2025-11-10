#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "currency.hpp"

using mc::currency;

// Test suite for to_string() function
TEST_CASE("to_string() converts currency enum to full name", "[currency][to_string]") {
    
    SECTION("Major international currencies") {
        REQUIRE(mc::to_string(currency::USD) == "United States Dollar");
        REQUIRE(mc::to_string(currency::EUR) == "Euro Member Countries");
        REQUIRE(mc::to_string(currency::GBP) == "United Kingdom Pound");
        REQUIRE(mc::to_string(currency::JPY) == "Japan Yen");
        REQUIRE(mc::to_string(currency::CHF) == "Switzerland Franc");
    }
    
    SECTION("Regional currencies") {
        REQUIRE(mc::to_string(currency::CAD) == "Canada Dollar");
        REQUIRE(mc::to_string(currency::AUD) == "Australia Dollar");
        REQUIRE(mc::to_string(currency::CNY) == "China Yuan Renminbi");
        REQUIRE(mc::to_string(currency::RUB) == "Russia Ruble");
        REQUIRE(mc::to_string(currency::RON) == "Romania Leu");
    }
    
    SECTION("Other significant currencies") {
        REQUIRE(mc::to_string(currency::BRL) == "Brazil Real");
        REQUIRE(mc::to_string(currency::INR) == "India Rupee");
        REQUIRE(mc::to_string(currency::KRW) == "Korea(South) Won");
        REQUIRE(mc::to_string(currency::MXN) == "Mexico Peso");
        REQUIRE(mc::to_string(currency::SGD) == "Singapore Dollar");
    }
}

// Test suite for to_shortname() function  
TEST_CASE("to_shortname() converts currency enum to ISO code", "[currency][to_shortname]") {
    
    SECTION("Major international currencies") {
        REQUIRE(mc::to_shortname(currency::USD) == "USD");
        REQUIRE(mc::to_shortname(currency::EUR) == "EUR");
        REQUIRE(mc::to_shortname(currency::GBP) == "GBP");
        REQUIRE(mc::to_shortname(currency::JPY) == "JPY");
        REQUIRE(mc::to_shortname(currency::CHF) == "CHF");
    }
    
    SECTION("Regional currencies") {
        REQUIRE(mc::to_shortname(currency::CAD) == "CAD");
        REQUIRE(mc::to_shortname(currency::AUD) == "AUD");
        REQUIRE(mc::to_shortname(currency::CNY) == "CNY");
        REQUIRE(mc::to_shortname(currency::RUB) == "RUB");
        REQUIRE(mc::to_shortname(currency::RON) == "RON");
    }
    
    SECTION("First and last currencies in enum") {
        REQUIRE(mc::to_shortname(currency::AED) == "AED");
        REQUIRE(mc::to_shortname(currency::ZWD) == "ZWD");
    }
    
    SECTION("All enum values have corresponding short names") {
        // Test that every currency enum value has a valid short name
        std::vector<currency> all_currencies = {
            currency::AED, currency::AFN, currency::ALL, currency::AMD, currency::ANG,
            currency::AOA, currency::ARS, currency::AUD, currency::AWG, currency::AZN,
            currency::BAM, currency::BBD, currency::BDT, currency::BGN, currency::BHD,
            currency::BIF, currency::BMD, currency::BND, currency::BOB, currency::BRL,
            currency::BSD, currency::BTN, currency::BWP, currency::BYN, currency::BZD,
            currency::CAD, currency::CDF, currency::CHF, currency::CLP, currency::CNY,
            currency::COP, currency::CRC, currency::CUC, currency::CUP, currency::CVE,
            currency::CZK, currency::DJF, currency::DKK, currency::DOP, currency::DZD,
            currency::EGP, currency::ERN, currency::ETB, currency::EUR, currency::FJD,
            currency::FKP, currency::GBP, currency::GEL, currency::GGP, currency::GHS,
            currency::GIP, currency::GMD, currency::GNF, currency::GTQ, currency::GYD,
            currency::HKD, currency::HNL, currency::HRK, currency::HTG, currency::HUF,
            currency::IDR, currency::ILS, currency::IMP, currency::INR, currency::IQD,
            currency::IRR, currency::ISK, currency::JEP, currency::JMD, currency::JOD,
            currency::JPY, currency::KES, currency::KGS, currency::KHR, currency::KMF,
            currency::KPW, currency::KRW, currency::KWD, currency::KYD, currency::KZT,
            currency::LAK, currency::LBP, currency::LKR, currency::LRD, currency::LSL,
            currency::LYD, currency::MAD, currency::MDL, currency::MGA, currency::MKD,
            currency::MMK, currency::MNT, currency::MOP, currency::MRU, currency::MUR,
            currency::MVR, currency::MWK, currency::MXN, currency::MYR, currency::MZN,
            currency::NAD, currency::NGN, currency::NIO, currency::NOK, currency::NPR,
            currency::NZD, currency::OMR, currency::PAB, currency::PEN, currency::PGK,
            currency::PHP, currency::PKR, currency::PLN, currency::PYG, currency::QAR,
            currency::RON, currency::RSD, currency::RUB, currency::RWF, currency::SAR,
            currency::SBD, currency::SCR, currency::SDG, currency::SEK, currency::SGD,
            currency::SHP, currency::SLL, currency::SOS, currency::SPL, currency::SRD,
            currency::STN, currency::SVC, currency::SYP, currency::SZL, currency::THB,
            currency::TJS, currency::TMT, currency::TND, currency::TOP, currency::TRY,
            currency::TTD, currency::TVD, currency::TWD, currency::TZS, currency::UAH,
            currency::UGX, currency::USD, currency::UYU, currency::UZS, currency::VEF,
            currency::VND, currency::VUV, currency::WST, currency::XAF, currency::XCD,
            currency::XDR, currency::XOF, currency::XPF, currency::YER, currency::ZAR,
            currency::ZMW, currency::ZWD
        };
        
        for (const auto& curr : all_currencies) {
            REQUIRE_NOTHROW(mc::to_shortname(curr));
            std::string shortname = mc::to_shortname(curr);
            REQUIRE(shortname.length() == 3);
            // Check that shortname contains only uppercase letters
            for (char c : shortname) {
                REQUIRE(std::isupper(c));
            }
        }
    }
}

// Test suite for to_currency() function
TEST_CASE("to_currency() converts string to currency enum", "[currency][to_currency]") {
    
    SECTION("ISO codes conversion") {
        REQUIRE(mc::to_currency("USD") == currency::USD);
        REQUIRE(mc::to_currency("EUR") == currency::EUR);
        REQUIRE(mc::to_currency("GBP") == currency::GBP);
        REQUIRE(mc::to_currency("JPY") == currency::JPY);
        REQUIRE(mc::to_currency("CHF") == currency::CHF);
        REQUIRE(mc::to_currency("RON") == currency::RON);
        REQUIRE(mc::to_currency("RUB") == currency::RUB);
    }
    
    SECTION("Case sensitivity tests") {
        // Test if function handles different cases
        REQUIRE_NOTHROW(mc::to_currency("USD"));
        // Lowercase are acceptable too
        REQUIRE_NOTHROW(mc::to_currency("usd"));
    }
    
    SECTION("Boundary cases") {
        REQUIRE(mc::to_currency("AED") == currency::AED); // First in enum
        REQUIRE(mc::to_currency("ZWD") == currency::ZWD); // Last in enum
    }
}

// Test suite for exception handling
TEST_CASE("Exception handling for invalid currencies", "[currency][exceptions]") {
    
    SECTION("unknown_currency exception for to_currency()") {
        REQUIRE_THROWS_AS(mc::to_currency("INVALID"), mc::unknown_currency_shortname);
        REQUIRE_THROWS_AS(mc::to_currency("XXX"), mc::unknown_currency_shortname);
        REQUIRE_THROWS_AS(mc::to_currency(""), mc::unknown_currency_shortname);
        REQUIRE_THROWS_AS(mc::to_currency("TOOLONG"), mc::unknown_currency_shortname);
        REQUIRE_THROWS_AS(mc::to_currency("123"), mc::unknown_currency_shortname);
        REQUIRE_THROWS_AS(mc::to_currency("Unknown Currency"), mc::unknown_currency_shortname);
    }
    
    SECTION("unknown_currency exception for invalid enum values") {
        // Test with invalid currency enum values (cast from integers)
        currency invalid_currency = static_cast<currency>(999);
        REQUIRE_THROWS_AS(mc::to_shortname(invalid_currency), mc::unknown_currency);
        
        invalid_currency = static_cast<currency>(-1);
        REQUIRE_THROWS_AS(mc::to_shortname(invalid_currency), mc::unknown_currency);
        
        invalid_currency = static_cast<currency>(999);
        REQUIRE_THROWS_AS(mc::to_string(invalid_currency), mc::unknown_currency);
    }
    
    SECTION("Exception messages are meaningful") {
        try {
            mc::to_currency("INVALID");
            FAIL("Expected unknown_currency_shortname exception");
        } catch (const mc::unknown_currency_shortname& e) {
            std::string message = e.what();
            REQUIRE(!message.empty());
            // Message should contain some indication of the error
            REQUIRE(message.length() > 5);
        }
        
        try {
            currency invalid_currency = static_cast<currency>(999);
            mc::to_shortname(invalid_currency);
            FAIL("Expected unknown_currency exception");
        } catch (const mc::unknown_currency& e) {
            std::string message = e.what();
            REQUIRE(!message.empty());
            REQUIRE(message.length() > 5);
        }
    }
}

// Test suite for round-trip conversions
TEST_CASE("Round-trip conversions", "[currency][roundtrip]") {
    
    SECTION("enum -> shortname -> enum") {
        std::vector<currency> test_currencies = {
            currency::USD, currency::EUR, currency::GBP, currency::JPY,
            currency::CHF, currency::CAD, currency::AUD, currency::RON,
            currency::RUB, currency::CNY, currency::AED, currency::ZWD
        };
        
        for (const auto& original : test_currencies) {
            std::string shortname = mc::to_shortname(original);
            currency converted = mc::to_currency(shortname);
            REQUIRE(converted == original);
        }
    }
    
    SECTION("enum -> string -> enum (if full names are supported)") {
        std::vector<currency> test_currencies = {
            currency::USD, currency::EUR, currency::GBP, currency::JPY, currency::CHF
        };
        
        for (const auto& original : test_currencies) {
            std::string fullname = mc::to_string(original);
            // This test assumes that to_currency() accepts full names
            // If not implemented, this will throw and that's also valid behavior to test
            try {
                currency converted = mc::to_currency(fullname);
                REQUIRE(converted == original);
            } catch (const mc::unknown_currency_shortname&) {
                // If full names aren't supported for to_currency(), that's acceptable
                INFO("Full name to currency conversion not supported for: " + fullname);
            }
        }
    }
}

// Test suite for data consistency
TEST_CASE("Data consistency checks", "[currency][consistency]") {
    
    SECTION("All currency enum values have unique short names") {
        std::set<std::string> shortnames;
        std::vector<currency> all_currencies = {
            currency::AED, currency::AFN, currency::ALL, currency::AMD, currency::ANG,
            currency::AOA, currency::ARS, currency::AUD, currency::AWG, currency::AZN,
            currency::BAM, currency::BBD, currency::BDT, currency::BGN, currency::BHD,
            currency::BIF, currency::BMD, currency::BND, currency::BOB, currency::BRL,
            currency::BSD, currency::BTN, currency::BWP, currency::BYN, currency::BZD,
            currency::CAD, currency::CDF, currency::CHF, currency::CLP, currency::CNY,
            currency::COP, currency::CRC, currency::CUC, currency::CUP, currency::CVE,
            currency::CZK, currency::DJF, currency::DKK, currency::DOP, currency::DZD,
            currency::EGP, currency::ERN, currency::ETB, currency::EUR, currency::FJD,
            currency::FKP, currency::GBP, currency::GEL, currency::GGP, currency::GHS,
            currency::GIP, currency::GMD, currency::GNF, currency::GTQ, currency::GYD,
            currency::HKD, currency::HNL, currency::HRK, currency::HTG, currency::HUF,
            currency::IDR, currency::ILS, currency::IMP, currency::INR, currency::IQD,
            currency::IRR, currency::ISK, currency::JEP, currency::JMD, currency::JOD,
            currency::JPY, currency::KES, currency::KGS, currency::KHR, currency::KMF,
            currency::KPW, currency::KRW, currency::KWD, currency::KYD, currency::KZT,
            currency::LAK, currency::LBP, currency::LKR, currency::LRD, currency::LSL,
            currency::LYD, currency::MAD, currency::MDL, currency::MGA, currency::MKD,
            currency::MMK, currency::MNT, currency::MOP, currency::MRU, currency::MUR,
            currency::MVR, currency::MWK, currency::MXN, currency::MYR, currency::MZN,
            currency::NAD, currency::NGN, currency::NIO, currency::NOK, currency::NPR,
            currency::NZD, currency::OMR, currency::PAB, currency::PEN, currency::PGK,
            currency::PHP, currency::PKR, currency::PLN, currency::PYG, currency::QAR,
            currency::RON, currency::RSD, currency::RUB, currency::RWF, currency::SAR,
            currency::SBD, currency::SCR, currency::SDG, currency::SEK, currency::SGD,
            currency::SHP, currency::SLL, currency::SOS, currency::SPL, currency::SRD,
            currency::STN, currency::SVC, currency::SYP, currency::SZL, currency::THB,
            currency::TJS, currency::TMT, currency::TND, currency::TOP, currency::TRY,
            currency::TTD, currency::TVD, currency::TWD, currency::TZS, currency::UAH,
            currency::UGX, currency::USD, currency::UYU, currency::UZS, currency::VEF,
            currency::VND, currency::VUV, currency::WST, currency::XAF, currency::XCD,
            currency::XDR, currency::XOF, currency::XPF, currency::YER, currency::ZAR,
            currency::ZMW, currency::ZWD
        };
        
        for (const auto& curr : all_currencies) {
            std::string shortname = mc::to_shortname(curr);
            REQUIRE(shortnames.find(shortname) == shortnames.end()); // Should be unique
            shortnames.insert(shortname);
        }
        
        // Should have as many unique shortnames as currencies
        REQUIRE(shortnames.size() == all_currencies.size());
    }
    
    SECTION("All currency enum values have non-empty string representations") {
        std::vector<currency> test_currencies = {
            currency::USD, currency::EUR, currency::GBP, currency::JPY,
            currency::CHF, currency::CAD, currency::AUD, currency::RON,
            currency::RUB, currency::CNY, currency::AED, currency::ZWD
        };
        
        for (const auto& curr : test_currencies) {
            std::string fullname = mc::to_string(curr);
            REQUIRE(!fullname.empty());
            REQUIRE(fullname.length() > 2);
            
            std::string shortname = mc::to_shortname(curr);
            REQUIRE(!shortname.empty());
            REQUIRE(shortname.length() == 3);
        }
    }
}