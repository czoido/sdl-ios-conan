xcodegen generate
conan install . -s build_type=Release --install-folder=conan -pr:b=default -pr:h=./ios_simulator --build=missing
conan install . -s build_type=Debug --install-folder=conan -pr:b=default -pr:h=./ios_simulator --build=missing
conan install . -s build_type=Release --install-folder=conan -pr:b=default -pr:h=./ios_profile --build=missing
conan install . -s build_type=Debug --install-folder=conan -pr:b=default -pr:h=./ios_profile --build=missing