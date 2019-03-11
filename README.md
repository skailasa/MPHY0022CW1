MPHY0022CW1
------------
This application was completed as a part of a piece of coursework for the 
Research Computing with C++ module.

Use this app to solve a 1D linear system, using either the normal equations
or singular value decomposition.

Build Application
-----------------
#### Windows (using cmake gui and visual studio):
Taken from [link](http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/01research/sec03CMake.html)
1. Run cmake-gui.exe
1. Select source folder
1. Specify new build folder (ensure it's out of source)
1. Hit configure
1. When asked, specify compiler
1. Set flags and repeatedly configure
1. When generate option is present, hit generate
1. Compile, normally using Visual Studio 

#### *nix (using terminal)

Out of source build

```
# exit source directory
cd ../

# create build directory
mkdir build
cd build

# configure and build
ccmake ../MPHY0022CW1
make
```

Navigate to binary application `LinearRegression`
```bash
cd bin

# run app
./LinearRegression
```

Usage
-----

```bash
./LinearRegression -f, --file <data_file> -s, --solver <solver_method>

# for example
./LinarRegression -f data.txt -s 'normal'

# or 
./LinearRegression data.txt 'normal'
```

Build Tests
-----------

#### Windows (using visual studio):
Ctest is fully integrated with test explorer in visual studio, allowing you
to build and run tests from there. See the following 
[link](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-ctest-for-cpp?view=vs-2017)
for instructions.

#### *nix (using terminal)
If you have built the app, navigate to build directory and run tests with CTest

```asm
cd build
ctest
```

Otherwise, follow instructions above to build app, ensuring to select the
build tests configuration in the CMake gui.

Add to Bash Profile (*nix users)
--------------------------------
Adding to bash profile will allow you to use the application from your Terminal,
without having to remember where you've stored the app binary.

Create alias in `.bash_profile` (mac) `.bashrc` Linux.

```
alias linreg='~/Path/To/App/LinearRegression'
```

Reset bash settings

e.g.
```
source ~/.bash_profile
```

And access from a new terminal window.