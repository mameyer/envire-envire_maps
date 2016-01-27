rock_library(envire_maps
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(envire_maps_bin Main.cpp
    DEPS envire_maps)

