# Calculation Engine #

This project was developed by Prateek Sahay for nuTonomy's coding exercise.

The calculation engine's purpose is to perform generic calculations on a set
of integers. It can run on a list of integers passed as command line arguments
or by reading integers from a file. `IntStreamer`, built into the library for
parsing these integers, will read up to the end of the file or until it
encounters a broken integer (characters instead of numbers, doesn't fit inside
an int, etc.).

Assumptions:
  - `gcc` in the instructions refers to the collection of GNU compilers (which
    includes `g++`), not the C compiler
  - If the user passes 3 arguments, e.g. `./calc_example <engine_name> <arg3>`
    then `arg3` refers to a file (rather than a list of 1 integer)
  - Skipping unit tests for the IntStreamer class because of the instructions,
    but in reality it seems crucial to test on empty files, corrupt data, etc.
  - I've chosen to take "integers" very seriously -- not using long long ints
    or anything, although this would add more functionality


## Dependencies ##
  - GTest (`sudo dnf install gtest-devel`)
  - Doxygen (`sudo dnf install doxygen`)


## Building and Running ##
Build with the following commands:
```sh
mkdir build
cd build
cmake ..
make
# Example with command line arguments
./bin/calc_example <engine_name> <list of integers>
# Example with file
./bin/calc_example <engine_name> <file name>
# Run GTests
./bin/calc_test
# Make Doxygen docs
make doc
```
Options: 
  - Turn off building tests with `cmake -DBUILD_GTEST=OFF ..`
  - Turn off building documentation with `cmake -DBUILD_DOCS=OFF ..`
  - Build Doxygen docs with `make doc`
  

## Structure ##
| Directory    | Contents                                                      |
|--------------|---------------------------------------------------------------|
| calc_lib     | Calculation engine library and base class with factory method |
| calc_example | Example using engine library                                  |
| gtest        | GTests                                                        |
| docs         | Documentation                                                 |
  

## API ##
Users can add their own engines. Simply create your own class inheriting from
`BaseEngine`, define custom behavior in calc(), and set an allowable input type.
To plug into `BaseEngine`'s factory method, add an entry to the `EngineType`
enum list and add a custom switch() case statement to `BaseEngine`'s static
create() factory method.