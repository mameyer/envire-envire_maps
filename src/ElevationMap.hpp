#pragma once

/** Envire core **/
#include <envire_core/items/Item.hpp>
#include <envire_core/plugin/Plugin.hpp>

/** Boost **/
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>

/** Std maps **/
#include <maps/grid/ElevationMap.hpp>

namespace envire { namespace maps
{
    class ElevationMap : public envire::core::Item< ::maps::grid::ElevationMap >
    {
        ENVIRE_PLUGIN_HEADER(envire::maps::ElevationMap)
    };
}}
