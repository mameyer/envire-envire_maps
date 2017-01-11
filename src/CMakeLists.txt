rock_library(envire_maps
    SOURCES 
            GridMapC.cpp
            GridMapI.cpp
            GridMapF.cpp
            GridMapD.cpp
            ElevationMap.cpp
            MLSMapKalman.cpp
            MLSMapSloped.cpp    
            MlsMapPrecalculated.cpp
            ContourMap.cpp
            OccupancyGridMap.cpp
    DEPS_CMAKE Boost
    DEPS_PKGCONFIG maps envire_core)

install_plugin_info(envire_maps)
