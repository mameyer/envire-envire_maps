rock_testsuite(test_suite suite.cpp test_ElevationRaster.cpp test_plugins.cpp
    DEPS_PKGCONFIG envire_gis
    DEPS envire_maps envire_maps-gis)

#if( vizkit3d_FOUND )
#    add_subdirectory(viz)
#endif( vizkit3d_FOUND )

