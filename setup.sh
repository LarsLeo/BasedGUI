#!/bin/bash

pushd build;
conan install .. --build=missing
popd;

# ToDo: also add Visual Studio project generation
cmake -G "Xcode"
