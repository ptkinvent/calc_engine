# Calculation Engine #

This project was developed by Prateek Sahay for nuTonomy's coding challenge.

The calculation engine's purpose is to perform calculations on a generic set
of integers.

Assumptions:
  - `gcc` refers to the collection of GNU compilers (which includes `g++`),
    not the C compiler
  - If the user passes 3 arguments, e.g. `./calc_example <arg2> <arg3>`
    then `arg2` refers to the engine name and `arg3` refers to a file (rather
    than a list of 1 integer)

## Dependencies ##
  - GTest
  - Doxygen (optional)


## Building ##
Build with the following commands:
```sh
mkdir build
cd build
cmake ..
make
```
Options: 
  - Build tests with `cmake -DBUILD_GTEST=ON ..`
  - Build documentation with `cmake .. && make doc`
  

## Structure ##
| Directory    | Contents |
|--------------|---|
| calc_lib     | Calculation engine library and base class |
| calc_example | Example using engine library              |
| gtest        | GTests                                    |
| docs         | Documentation                             |
  

## API ##
Users can add their own engines. Simply inherit from the `BaseEngine` class,
define custom behavior, add to `BaseEngine`'s enum list, and add to
`BaseEngine`'s factory method. 