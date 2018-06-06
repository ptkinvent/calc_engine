# Calculation Engine

This project was developed by Prateek Sahay for nuTonomy's coding exercise.

The calculation engine's purpose is to perform generic calculations on a set
of integers. It can run on a list of integers passed as command line arguments
or by reading integers from a file. `IntStreamer`, built into the library for
parsing these integers, will read up to the end of the file or until it
encounters a broken integer (characters instead of numbers, integers larger than
32 bits, etc.).

## Assumptions:
  - `gcc` in the instructions refers to the collection of GNU compilers (which
    includes `g++`), not the C compiler.
  - If the user passes 3 arguments, e.g. `./calc_example <engine_name> <arg2>`
    then `arg2` refers to a file (rather than a list of 1 integer).
  - Skipping unit tests for the IntStreamer class because of the instructions,
    but in reality it seems crucial to test on empty files, corrupt file data,
    etc.
  - I've chosen to take "integers" in the instructions to mean 32-bit signed
    integers.
  - Engines can return floating point results.


## Dependencies
  - GTest: `sudo dnf install gtest-devel`
  - Doxygen: `sudo dnf install doxygen`


## Building and Running
Building:
```sh
mkdir build
cd build
cmake ..
make

# Optionally build Doxygen docs
make doc
```
Running:
```sh
# Run GTests
./bin/calc_test

# Run example with integers as command line arguments
./bin/calc_example <engine_name> <list of integers>

# Run example with file of integers (exclude .txt in the file name)
./bin/calc_example <engine_name> <file name>
```
Options:
  - Turn off building tests with `cmake -DBUILD_GTEST=OFF ..`
  - Turn off building documentation with `cmake -DBUILD_DOCS=OFF ..`
  - Build Doxygen docs with `make doc`
  

## Structure
| Directory    | Contents                                                      |
|--------------|---------------------------------------------------------------|
| calc_lib     | Calculation engine library and base class with factory method |
| calc_example | Example using engine library                                  |
| gtest        | GTests                                                        |
| docs         | Documentation                                                 |
  

## API
Users can implement their own engines. Simply create a custom class inheriting
from `BaseEngine`, define custom behavior in calc(), and set an allowable input
type. To plug into `BaseEngine`'s factory method, add an entry to the
`EngineType` enum list and add a custom switch-case statement to
`BaseEngine`'s static `create()` factory method.