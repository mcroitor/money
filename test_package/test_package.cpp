#include <iostream>
#include "money.h"
#include "currency.h"

int main() {
    using mc::currency;
    using mc::money;
    using mc::operator""_USD;
    using mc::operator""_EUR;
    
    // Test basic functionality
    money cash = 100.50_USD;
    money euros = 85.25_EUR;
    
    std::cout << "Money library test successful!" << std::endl;
    std::cout << "USD: " << cash.to_string() << std::endl;
    std::cout << "EUR: " << euros.to_string() << std::endl;
    
    // Test currency conversion
    money converted = cash.convert(currency::EUR, 0.85);
    std::cout << "Converted: " << converted.to_string() << std::endl;
    
    // Test arithmetic
    money total = cash + 25.0_USD;
    std::cout << "Total: " << total.to_string() << std::endl;
    
    return 0;
}