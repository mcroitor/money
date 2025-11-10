# Money Library

## Description

A comprehensive C++ library for handling monetary values with currency support. The library provides type-safe monetary arithmetic operations and supports 169 different currencies according to ISO 4217 standard. All types are defined in the `mc` namespace.

## Features

- **ISO 4217 Compliant**: Support for all 169 official currencies
- **Type Safety**: Strong typing prevents mixing incompatible currencies
- **Precise Arithmetic**: Fixed-point arithmetic prevents floating-point precision errors
- **User-Defined Literals**: Convenient syntax for creating monetary values (e.g., `100.50_USD`)
- **Currency Conversion**: Built-in support for currency conversion with custom exchange rates
- **Exception Safety**: Comprehensive error handling for invalid operations
- **Full Documentation**: Complete Doxygen documentation for all APIs
- **Comprehensive Tests**: Extensive test suite with Catch2 framework

## Installation

### Prerequisites

- C++17 compatible compiler
- CMake 3.10 or higher
- Git (for fetching Catch2 dependency)

### Building

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Running Tests

```bash
# From build directory
ctest
# Or run directly
./Debug/money_tests.exe  # Windows
./money_tests           # Linux/macOS
```

## Usage

### Basic Usage

```cpp
#include "money.h"
#include "currency.h"

using mc::currency;
using mc::money;
using mc::operator""_USD;
using mc::operator""_EUR;

// Create money using user-defined literals
money cash = 200.50_USD;
money euros = 150.75_EUR;

// Arithmetic operations (same currency only)
money total = cash + 50.25_USD;
money doubled = cash * 2.0;

// Currency conversion
money converted = cash.convert(currency::EUR, 0.85);

// Display
std::cout << cash.to_string();  // Output: "200,50 USD"
```

### Currency Operations

```cpp
// Currency information
std::string name = mc::to_string(currency::USD);      // "United States Dollar"
std::string code = mc::to_shortname(currency::USD);   // "USD"
currency cur = mc::to_currency("EUR");                // currency::EUR

// All 169 currencies are supported with user-defined literals
money examples[] = {
    100.0_EUR,   // Euro
    50.0_GBP,    // British Pound
    1000.0_JPY,  // Japanese Yen
    75.0_CAD,    // Canadian Dollar
    // ... and 165 more currencies
};
```

### Exception Handling

```cpp
try {
    money usd = 100.0_USD;
    money eur = 50.0_EUR;
    
    // This will throw - incompatible currencies
    money invalid = usd + eur;
} catch (const std::logic_error& e) {
    std::cout << "Error: " << e.what() << std::endl;
}

try {
    // This will throw - unknown currency code
    currency unknown = mc::to_currency("XYZ");
} catch (const mc::unknown_currency_shortname& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## API Reference

### Core Classes

- `mc::money`: Main class for monetary values with currency
- `mc::currency`: Enumeration of all supported currencies (169 values)

### Key Methods

- `mc::money::integral()`: Get the whole part of the amount
- `mc::money::part()`: Get the fractional part (cents)
- `mc::money::convert()`: Convert to another currency
- `mc::money::to_string()`: Format as string
- `mc::to_string()`: Get currency full name
- `mc::to_shortname()`: Get currency ISO code
- `mc::to_currency()`: Parse currency from ISO code

### Supported Operations

- Addition/Subtraction (same currency only)
- Multiplication/Division by scalar values
- Equality comparison
- Assignment operations
- Currency conversion with exchange rates

## Documentation

Full API documentation is available via Doxygen. All classes, methods, and user-defined literals are thoroughly documented with usage examples.

## Testing

The library includes a comprehensive test suite covering:

- All currency operations and conversions
- Money arithmetic and edge cases
- Exception handling scenarios
- User-defined literal functionality
- ISO 4217 compliance validation

Total: 1193+ assertions across 22 test cases ensuring reliability and correctness.

## Project Status

✅ **Complete and Production Ready**

- [x] All 169 ISO 4217 currencies implemented
- [x] Full arithmetic operations support
- [x] Comprehensive exception handling
- [x] Complete Doxygen documentation
- [x] Extensive unit test coverage with Catch2
- [x] User-defined literals for all currencies
- [x] Currency conversion functionality
- [x] Fixed-point precision arithmetic
