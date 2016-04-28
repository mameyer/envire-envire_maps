#pragma once

/** Envire core **/
#include <envire_core/items/Item.hpp>
#include <envire_core/plugin/Plugin.hpp>

/** Boost **/
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>

/** Std maps **/
#include <maps/grid/GridMap.hpp>

namespace envire { namespace maps
{
    class GridMapD : public envire::core::Item< ::maps::grid::GridMapD >
    {
        ENVIRE_PLUGIN_HEADER(envire::maps::GridMapD)
    };                
}}
