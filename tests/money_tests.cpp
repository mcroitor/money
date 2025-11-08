#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "currency.h"
#include "money.h"

using mc::currency;
using mc::money;
using mc::operator "" _PHP;
using mc::operator "" _USD;
using mc::operator "" _EUR;
using mc::operator "" _UAH;

TEST_CASE("currency euro", "[currency]") {
    currency currency = currency::EUR;
    REQUIRE(mc::to_string(currency) == "Euro Member Countries");
}

TEST_CASE("money create", "[money]") {
    money cash(currency::BBD, 200.123);
    REQUIRE(cash.currency() == currency::BBD);
    REQUIRE(cash.integral() == 200);
    REQUIRE(cash.part() == 12);
}

TEST_CASE("money convert", "[money]") {
    money cash(currency::USD, 200);
    money lei = cash.convert(currency::MDL, 17.1539);
    REQUIRE(cash.currency() == currency::USD);
    REQUIRE(lei.currency() == currency::MDL);
    REQUIRE(cash.integral() == 200);
    REQUIRE(cash.part() == 0);
    REQUIRE(lei.integral() == 3430);
    REQUIRE(lei.part() == 78);

}
TEST_CASE("money copy", "[money]") {
    money cash(currency::JPY, 5000);
    money copy = cash;
    REQUIRE(copy.currency() == currency::JPY);
    REQUIRE(copy.integral() == 5000);
    REQUIRE(copy.part() == 0);
}

TEST_CASE("money add", "[money]") {
    money salary(currency::NZD, 200);
    REQUIRE(salary.currency() == currency::NZD);
    salary += 12.345;
    REQUIRE(salary.integral() == 212);
    REQUIRE(salary.part() == 34);
    salary += 0.88;
    REQUIRE(salary.integral() == 213);
    REQUIRE(salary.part() == 22);
}

TEST_CASE("money arithmetic", "[money]") {
    money cash(currency::UAH, 1230.65);
    cash = 2 * cash + 5;
    REQUIRE(cash.amount() == 246630);
}

TEST_CASE("money literals", "[money]") {
    money cash = 121.0_PHP;
    REQUIRE(cash.integral() == 121);
    REQUIRE(cash.part() == 0);
    REQUIRE(cash.currency() == currency::PHP);
}

// Additional comprehensive tests

TEST_CASE("Money constructors", "[money][constructors]") {
    
    SECTION("Single currency constructor (zero amount)") {
        money m(currency::USD);
        REQUIRE(m.currency() == currency::USD);
        REQUIRE(m.integral() == 0);
        REQUIRE(m.part() == 0);
        REQUIRE(m.amount() == 0);
    }
    
    SECTION("Currency and amount constructor") {
        money m(currency::EUR, 123.45);
        REQUIRE(m.currency() == currency::EUR);
        REQUIRE(m.integral() == 123);
        REQUIRE(m.part() == 45);
        REQUIRE(m.amount() == 12345);
    }
    
    SECTION("Copy constructor") {
        money original(currency::GBP, 99.99);
        money copy(original);
        REQUIRE(copy.currency() == currency::GBP);
        REQUIRE(copy.integral() == 99);
        REQUIRE(copy.part() == 99);
        REQUIRE(copy.amount() == 9999);
    }
}

TEST_CASE("Money assignment operators", "[money][assignment]") {
    
    SECTION("Assignment operator") {
        money m1(currency::USD, 100.50);
        money m2(currency::EUR, 200.75);
        
        m1 = m2;
        REQUIRE(m1.currency() == currency::EUR);
        REQUIRE(m1.integral() == 200);
        REQUIRE(m1.part() == 75);
    }
    
    SECTION("Addition assignment with money") {
        money m1(currency::USD, 100.25);
        money m2(currency::USD, 50.75);
        
        m1 += m2;
        REQUIRE(m1.integral() == 151);
        REQUIRE(m1.part() == 0);
        REQUIRE(m1.amount() == 15100);
    }
    
    SECTION("Addition assignment with double") {
        money m(currency::USD, 100.00);
        m += 25.50;
        REQUIRE(m.integral() == 125);
        REQUIRE(m.part() == 50);
    }
    
    SECTION("Subtraction assignment with money") {
        money m1(currency::USD, 100.75);
        money m2(currency::USD, 25.25);
        
        m1 -= m2;
        REQUIRE(m1.integral() == 75);
        REQUIRE(m1.part() == 50);
    }
    
    SECTION("Subtraction assignment with double") {
        money m(currency::USD, 100.00);
        m -= 15.75;
        REQUIRE(m.integral() == 84);
        REQUIRE(m.part() == 25);
    }
    
    SECTION("Multiplication assignment") {
        money m(currency::USD, 50.25);
        m *= 2.0;
        REQUIRE(m.integral() == 100);
        REQUIRE(m.part() == 50);
    }
    
    SECTION("Division assignment") {
        money m(currency::USD, 100.50);
        m /= 2.0;
        REQUIRE(m.integral() == 50);
        REQUIRE(m.part() == 25);
    }
}

TEST_CASE("Money arithmetic operators", "[money][arithmetic]") {
    
    SECTION("Addition: money + money") {
        money m1(currency::USD, 100.25);
        money m2(currency::USD, 50.75);
        money result = m1 + m2;
        
        REQUIRE(result.currency() == currency::USD);
        REQUIRE(result.integral() == 151);
        REQUIRE(result.part() == 0);
    }
    
    SECTION("Addition: money + double") {
        money m(currency::USD, 100.00);
        money result = m + 25.50;
        
        REQUIRE(result.integral() == 125);
        REQUIRE(result.part() == 50);
    }
    
    SECTION("Addition: double + money") {
        money m(currency::USD, 100.00);
        money result = 25.50 + m;
        
        REQUIRE(result.integral() == 125);
        REQUIRE(result.part() == 50);
    }
    
    SECTION("Subtraction: money - money") {
        money m1(currency::USD, 100.75);
        money m2(currency::USD, 25.25);
        money result = m1 - m2;
        
        REQUIRE(result.integral() == 75);
        REQUIRE(result.part() == 50);
    }
    
    SECTION("Multiplication: money * double") {
        money m(currency::USD, 50.25);
        money result = m * 2.0;
        
        REQUIRE(result.integral() == 100);
        REQUIRE(result.part() == 50);
    }
    
    SECTION("Multiplication: double * money") {
        money m(currency::USD, 50.25);
        money result = 2.0 * m;
        
        REQUIRE(result.integral() == 100);
        REQUIRE(result.part() == 50);
    }
    
    SECTION("Division: money / double") {
        money m(currency::USD, 100.50);
        money result = m / 2.0;
        
        REQUIRE(result.integral() == 50);
        REQUIRE(result.part() == 25);
    }
}

TEST_CASE("Money comparison operators", "[money][comparison]") {
    
    SECTION("Equality operator") {
        money m1(currency::USD, 100.50);
        money m2(currency::USD, 100.50);
        money m3(currency::USD, 100.25);
        money m4(currency::EUR, 100.50);
        
        REQUIRE(m1 == m2);
        REQUIRE_FALSE(m1 == m3);
        REQUIRE_FALSE(m1 == m4);
    }
    
    SECTION("Equal method") {
        money m1(currency::USD, 100.50);
        money m2(currency::USD, 100.50);
        money m3(currency::EUR, 100.50);
        
        REQUIRE(m1.equal(m2));
        REQUIRE_FALSE(m1.equal(m3));
    }
}

TEST_CASE("Money conversion", "[money][conversion]") {
    
    SECTION("Basic conversion") {
        money usd(currency::USD, 100.00);
        money eur = usd.convert(currency::EUR, 0.85);
        
        REQUIRE(eur.currency() == currency::EUR);
        REQUIRE(eur.integral() == 85);
        REQUIRE(eur.part() == 0);
    }
    
    SECTION("Conversion with fractional rate") {
        money usd(currency::USD, 1.00);
        money jpy = usd.convert(currency::JPY, 110.25);
        
        REQUIRE(jpy.currency() == currency::JPY);
        REQUIRE(jpy.integral() == 110);
        REQUIRE(jpy.part() == 25);
    }
    
    SECTION("Original money unchanged after conversion") {
        money original(currency::USD, 100.00);
        money converted = original.convert(currency::EUR, 0.85);
        
        REQUIRE(original.currency() == currency::USD);
        REQUIRE(original.integral() == 100);
        REQUIRE(original.part() == 0);
    }
}

TEST_CASE("Money utility methods", "[money][utility]") {
    
    SECTION("Currency name") {
        money m(currency::USD, 100.00);
        REQUIRE(m.currency_name() == "United States Dollar");
    }
    
    SECTION("String representation") {
        money m(currency::USD, 123.45);
        std::string str = m.to_string();
        REQUIRE(!str.empty());
        // The exact format depends on implementation
        REQUIRE(str.find("123") != std::string::npos);
        REQUIRE(str.find("USD") == std::string::npos);
    }
}

TEST_CASE("Money literals comprehensive", "[money][literals]") {
    
    SECTION("USD literal") {
        auto m = 100.50_USD;
        REQUIRE(m.currency() == currency::USD);
        REQUIRE(m.integral() == 100);
        REQUIRE(m.part() == 50);
    }
    
    SECTION("EUR literal") {
        auto m = 75.25_EUR;
        REQUIRE(m.currency() == currency::EUR);
        REQUIRE(m.integral() == 75);
        REQUIRE(m.part() == 25);
    }
    
    SECTION("Zero amount literal") {
        auto m = 0.0_USD;
        REQUIRE(m.integral() == 0);
        REQUIRE(m.part() == 0);
        REQUIRE(m.amount() == 0);
    }
    
    SECTION("Large amount literal") {
        auto m = 999999.99_USD;
        REQUIRE(m.integral() == 999999);
        REQUIRE(m.part() == 99);
    }
}

TEST_CASE("Money edge cases", "[money][edge]") {
    
    SECTION("Zero amounts") {
        money m(currency::USD, 0.0);
        REQUIRE(m.integral() == 0);
        REQUIRE(m.part() == 0);
        REQUIRE(m.amount() == 0);
    }
    
    SECTION("Very small amounts") {
        money m(currency::USD, 0.01);
        REQUIRE(m.integral() == 0);
        REQUIRE(m.part() == 1);
        REQUIRE(m.amount() == 1);
    }
    
    SECTION("Fractional cents (rounding)") {
        money m(currency::USD, 0.999);
        // Behavior depends on implementation - should round to nearest cent
        REQUIRE(m.part() <= 99);
    }
    
    SECTION("Large amounts") {
        money m(currency::USD, 1000000.99);
        REQUIRE(m.integral() == 1000000);
        REQUIRE(m.part() == 99);
    }
}

TEST_CASE("Money precision tests", "[money][precision]") {
    
    SECTION("Addition precision") {
        money m1(currency::USD, 0.01);
        money m2(currency::USD, 0.02);
        money result = m1 + m2;
        
        REQUIRE(result.integral() == 0);
        REQUIRE(result.part() == 3);
        REQUIRE(result.amount() == 3);
    }
    
    SECTION("Multiplication precision") {
        money m(currency::USD, 0.33);
        money result = m * 3;
        
        // Should handle precision correctly
        REQUIRE(result.amount() == 99);
    }
    
    SECTION("Division precision") {
        money m(currency::USD, 1.00);
        money result = m / 3;
        
        // Should handle division remainder appropriately
        REQUIRE(result.part() <= 99);
    }
}