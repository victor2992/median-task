# Alcatraz Task

Solution to the median problem.

Time complexity of the current solution for finding the median is O(1) and O(log(n)) for adding new elements.

Another possible solution would be with time complexity O(n) for calculating the median (using the median of the median algorithm) and O(1) for adding new elements.

Depending on the situation either could be optimal.

## Build Instructions

```bash
# install cmake
sudo apt-get install cmake

# install gtest
sudo apt-get install libgtest-dev
cd /usr/src/googletest/googletest
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp libgtest* /usr/lib/
cd ..
sudo rm -rf build

# build and run (inside the project directory)
cmake CMakeLists.txt
make
./alcatraz
```
