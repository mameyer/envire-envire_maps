rock_library(envire_maps
    SOURCES ElevationMap.cpp
            ContourMap.cpp
    HEADERS ElevationMap.hpp
            ContourMap.hpp
    DEPS_CMAKE Boost
    DEPS_PKGCONFIG maps envire_core)

install_plugin_info(envire_maps)
