#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "currency.h"
#include "money.h"

using namespace mc::currency;
TEST_CASE("currency euro", "[currency]") {
    currency_t currency = currency_t::EUR;
    std::cout << "euro: " << currency_name.at(currency) << std::endl;
    REQUIRE(currency_name.at(currency) == "Euro Member Countries");
}

TEST_CASE("money create", "[money]"){    
    money cash(currency_t::MDL, 200.123);
    REQUIRE(cash.currency() == currency_t::MDL);
    REQUIRE(cash.integral() == 200);
    REQUIRE(cash.part() == 12);    
}

TEST_CASE("money convert", "[money]"){    
    money cash(currency_t::USD, 200);
    money lei = cash.convert(currency_t::MDL, 17.1539);
    REQUIRE(cash.currency() == currency_t::USD);
    REQUIRE(lei.currency() == currency_t::MDL);
    REQUIRE(cash.integral() == 200);
    REQUIRE(cash.part() == 0);
    REQUIRE(lei.integral() == 3430);
    REQUIRE(lei.part() == 78);
    
}

TEST_CASE("money add", "[money]"){
    money salary(currency_t::MDL, 200);
    REQUIRE(salary.currency() == currency_t::MDL);
    std::cout << "initial = " << salary.to_string() << std::endl;
    salary += 12.345;
    std::cout << "changed = " << salary.to_string() << std::endl;
    REQUIRE(salary.integral() == 212);
    REQUIRE(salary.part() == 34);
    salary += 0.88;
    std::cout << "final = " << salary.to_string() << std::endl;
    REQUIRE(salary.integral() == 213);
    REQUIRE(salary.part() == 22);
}