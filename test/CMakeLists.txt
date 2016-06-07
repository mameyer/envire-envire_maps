rock_testsuite(test_elevation suite.cpp test_ElevationRaster.cpp
    DEPS_PKGCONFIG envire_maps envire_gis envire_maps-gis)

#if( vizkit3d_FOUND )
#    add_subdirectory(viz)
#endif( vizkit3d_FOUND )

