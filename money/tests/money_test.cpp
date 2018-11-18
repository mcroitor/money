#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "currency.h"
#include "money.h"

TEST_CASE("currency euro", "[currency]") {
    mc::currency_t currency = mc::currency_t::EUR;
    std::cout << "euro: " << mc::currency_name.at(currency) << std::endl;
    REQUIRE(mc::currency_name.at(currency) == "Euro Member Countries");
}

TEST_CASE("money create", "[money]"){    
    mc::money cash(mc::currency_t::MDL, 200.123);
    REQUIRE(cash.currency() == mc::currency_t::MDL);
    REQUIRE(cash.integral() == 200);
    REQUIRE(cash.part() == 12);    
}

TEST_CASE("money add", "[money]"){
    mc::money salary(mc::currency_t::MDL, 200);
    REQUIRE(salary.currency() == mc::currency_t::MDL);
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