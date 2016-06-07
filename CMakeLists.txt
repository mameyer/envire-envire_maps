# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 2.6)
find_package(Rock)
set(ROCK_USE_CXX11 TRUE)
set(ROCK_TEST_ENABLED ON)

include(PluginManager)
include(EnvireGIS)
rock_init(envire_maps 0.1)
envire_gis_plugin_layout() #it extends rock_standard_layout
