#pragma once

/** Envire core **/
#include <envire_core/items/Item.hpp>
#include <envire_core/plugin/Plugin.hpp>

/** Boost **/
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>

/** Std maps **/
#include <maps/geometric/ContourMap.hpp>

namespace envire { namespace maps
{
    class ContourMap : public envire::core::Item< ::maps::geometric::ContourMap >
    {
        ENVIRE_PLUGIN_HEADER(envire::maps::ContourMap)
    };
}}
