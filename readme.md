## Money library ##

The C++ library that proposes currency / money types. Are defined in _mc_ namespace.
```C++
using mc::currency;
using mc::money;
using mc::_USD;
using mc::_GBP;

money cash = 200.0_USD;
std::cout << cash.convert( currency::GBP, 1.14).to_string();
```