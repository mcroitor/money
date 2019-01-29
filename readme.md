## Money library ##

The C++ library that proposes currency / money types. Are defined in mc::currency
namespace.
```C++
using currency_t = mc::currency::currency_t;
using money = mc::currency::money;

money cash(currency_t::USD, 200);
std::cout << cash.convert( currency_t::GBP, 1.14).to_string();
```