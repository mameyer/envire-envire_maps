rock_library(envire_maps
    SOURCES 
            GridMapC.cpp
            GridMapI.cpp
            GridMapF.cpp
            GridMapD.cpp
            ElevationMap.cpp
            MLSMapKalman.cpp
            MLSMapSloped.cpp            
            ContourMap.cpp
    HEADERS 
            GridMapC.hpp
            GridMapI.hpp
            GridMapF.hpp
            GridMapD.hpp
            ElevationMap.hpp
            MLSMapKalman.hpp
            MLSMapSloped.hpp            
            ContourMap.hpp
    DEPS_CMAKE Boost
    DEPS_PKGCONFIG maps envire_core)

install_plugin_info(envire_maps)
