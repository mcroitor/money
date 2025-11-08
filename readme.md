# Money library

## Description

The C++ library that proposes currency / money types. Types are defined in _mc_ namespace.

## Installation

This is a _NetBeans_ project, you can just use this nice IDE for building.
Was simple _cmake_ configuration file created. If you have cmake, do next:

```bash
mkdir dist
cd dist
cmake -G "Unix Makefiles" ..
```

## Usage

```C++
using mc::currency;
using mc::money;
using mc::_USD;
using mc::_GBP;

money cash = 200.0_USD;
std::cout << cash.convert( currency::GBP, 1.14).to_string();
```

## TODO

- [ ] implement precision and round rules
- [x] Create documentation with Doxygen.
- [ ] Add unit tests with Catch2.
