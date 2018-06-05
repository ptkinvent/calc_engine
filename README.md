# Calculation Engine #

This project was developed by Prateek Sahay for nuTonomy's coding challenge.

Disclosure: This took a bit more than 4 hours.

The calculation engine's purpose is to perform calculations on a generic set
of integers.

Assumptions:
  - `gcc` refers to the collection of GNU compilers, which includes `g++`

## Dependencies ##
  - gtest
  - Doxygen

## Building ##
Options: 
  - Build tests with `cmake -DBUILD_GTEST=ON ..`
  - Build documentation with `cmake .. && make doc`

```sh
mkdir build
cd build
cmake .. # Optionally turn on/off gtests and docs
make
```