# DFT_cpp
A faster module that calculate the probability of the number of edges existed in (sub)graph, built with CMake-based build system. This is useful for C++ codebases that have an existing CMake project structure.
## Prerequisites
. A compiler with C++11 support
. Pip 10+ or CMake >= 3.4 (or 3.14+ on Windows, which was the first version to support VS 2019)
. Ninja or Pip 10+
## Installation
Note the --recursive option which is needed for the pybind11 submodule:
```
git clone --recursive https://github.com/XINS3/DFT_cpp.git
pip install ./DFT_cpp
```
## Building the documentation
```
cd DFT_cpp/docs
make html
```
## License
Pybind11 is provided under a BSD-style license that can be found in the LICENSE file. By using, distributing, or contributing to this project, you agree to the terms and conditions of this license.

## Test call
```
import DFT_cpp
DFT_cpp.dft(2,[0.2,0.4,0.5])
```
