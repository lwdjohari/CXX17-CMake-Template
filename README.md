# CXX17-Cmake-Template
Quick CMAKE Template for C++17 Cross Platform Development. 

## What is inside
1. Google Abseil Library
2. Catch2 Unit Test
3. Doxygen documentation
4. Modern Template for Doxygen.
5. Sanitizer & collection of cmake module

## Pre-requisites
You have to install below pre-requisites
1. Build tool : CMake >= 3.27 (No regret when you need protoc support)
2. C++17 Compiler: Clang or GCC or MSVC
3. Dev IDE : Visual Studio Code (VS CODE) with C++ Extension
4. GDB for debugging
5. Doxygen for generating documentation
6. Catch 2 for testing
7. Abseil will use git submodule to LTS 20230802.1 version

## VS CODE Extension
**C/C++ Extension Pack** [[Link]](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)<br>
This extension pack includes a set of popular extensions for C++ development in Visual Studio Code:

- C/C++
- C/C++ Themes
- CMake
- CMake Tools

**Optional Extension**<br>
a.  Visual Studio Code WSL [[Link]](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl)<br>
    If you developing inside WSL<br>
b.  Visual Studio Code Remote - SSH [[Link]](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh)

## How to use
Asuming that you have all pre-requisites installed on your dev env

1. Clone this repo.
2. Delete all git.
3. Move files to your git local repo. DO NOT copy the git files.
4. Run  again `git submodule add -b lts_2023_08_02  https://github.com/abseil/abseil-cpp.git deps/abseil-lts.20230802.1` on your project git local repo. 
5. Open folder in `VS Code` with extension already installed.
6. On first time run, `CMAKE` dialog will appear for you to choose which main CMakeLists.txt to be used.
7. Adjust and changes project name to reflect your development on `CmakeLists.txt` file.
8. `Ctrl+Shift+P` then choose `CMAKE: Configure` for configure the build.
9. `Ctrl+Shift+P` then choose `CMAKE: Build` to build.
10. Repeat step 7 if you add new source or header files.

Notes : 
<p>I'am personally most of the time are writing C++ for server application or embedded application development on Linux/WSL.</p>
<p>This workflow/approach help me focus on development rather than struggling with dev env, especially when doing it on WIN.</p>

## LICENSE
**MIT LICENSE**
Copyright 2023 Linggawasistha Djohari

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
