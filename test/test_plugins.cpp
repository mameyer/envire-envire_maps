#include <boost/test/unit_test.hpp>
#include <exception>
#include <maps/geometric/ContourMap.hpp>
#include <maps/grid/ElevationMap.hpp>
#include <maps/grid/GridMap.hpp>
#include <maps/grid/MLSMap.hpp>
#include <envire_core/plugin/ClassLoader.hpp>
#include <envire_core/items/Item.hpp>

struct LoadLocalPlugins {
    LoadLocalPlugins()
    {
        envire::core::ClassLoader* loader = envire::core::ClassLoader::getInstance();
        std::vector<std::string> xml_paths;
        const char* root_folder = std::getenv("AUTOPROJ_CURRENT_ROOT");
        std::string root_folder_str(root_folder);
        root_folder_str += "/envire/envire_maps/src";
        xml_paths.push_back(root_folder_str);
        loader->clear();
        loader->overridePluginXmlPaths(xml_paths);
        loader->reloadXMLPluginFiles();
    }
    ~LoadLocalPlugins()
    {
        envire::core::ClassLoader::getInstance()->clear();
    }
};

BOOST_GLOBAL_FIXTURE( LoadLocalPlugins );

#define ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE( _test_name, _embedded_type ) \
ADD_ENVIRE_ITEM_BOOST_TEST_CASE( _test_name, envire::core::Item<_embedded_type> )

#define ADD_ENVIRE_ITEM_BOOST_TEST_CASE( _test_name, _classname ) \
BOOST_AUTO_TEST_CASE(_test_name) \
{ \
    BOOST_CHECK(envire::core::ClassLoader::getInstance()->hasEnvireItem(#_classname)); \
    envire::core::ItemBase::Ptr base_plugin; \
    BOOST_CHECK(envire::core::ClassLoader::getInstance()->createEnvireItem(#_classname, base_plugin)); \
    _classname::Ptr map_plugin = boost::dynamic_pointer_cast< _classname >(base_plugin);\
    BOOST_CHECK(map_plugin != NULL); \
    std::string class_name; \
    BOOST_CHECK(map_plugin->getClassName(class_name)); \
    BOOST_CHECK(class_name == #_classname); \
}

ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_contour_map_plugin, maps::geometric::ContourMap)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_elevation_map_plugin, maps::grid::ElevationMap)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_grid_char_map_plugin, maps::grid::GridMapC)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_grid_double_map_plugin, maps::grid::GridMapD)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_grid_float_map_plugin, maps::grid::GridMapF)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_grid_int_map_plugin, maps::grid::GridMapI)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_mls_kalman_map_plugin, maps::grid::MLSMapKalman)
ADD_ENVIRE_PLUGIN_BOOST_TEST_CASE(load_mls_sloped_map_plugin, maps::grid::MLSMapSloped)