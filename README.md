Simple example of an application in C++ using SDL for iOS. Using Conan for managing dependencies.

```
conan install . -s build_type=Release --install-folder=conan -pr:b=default -pr:h=./ios_simulator --build=missing
conan install . -s build_type=Debug --install-folder=conan -pr:b=default -pr:h=./ios_simulator --build=missing
conan install . -s build_type=Release --install-folder=conan -pr:b=default -pr:h=./ios_profile --build=missing
conan install . -s build_type=Debug --install-folder=conan -pr:b=default -pr:h=./ios_profile --build=missing
xcodegen generate
```

Some code from here: https://github.com/MarcelBraghetto/a-simple-triangle
