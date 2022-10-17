# C++ Multithreading Demo
This demo takes two integer command line inputs: `X` and `Z`. It will then spawn `X` threads, which will then increment a shared integer variable `Z` times each. The threads will log their status and use mutex locks to avoid race conditions.

# Build
Compile with `g++ multithreading.cpp -o multithreading -std=c++11`

# Run
Once the demo is compiled, you can run it with `./multithreading X Z`
- `X` and `Z` must be integers
- Ex: `./multithreading 3 8` (this will spawn 3 threads which operate 8 times)
