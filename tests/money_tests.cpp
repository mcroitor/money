#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <iostream>

#include "currency.h"
#include "money.h"

using mc::currency;
using mc::money;
using mc::operator "" _PHP;

TEST_CASE("currency euro", "[currency]") {
    currency currency = currency::EUR;
    std::cout << "euro: " << mc::to_string(currency) << std::endl;
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

TEST_CASE("money add", "[money]") {
    money salary(currency::NZD, 200);
    REQUIRE(salary.currency() == currency::NZD);
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