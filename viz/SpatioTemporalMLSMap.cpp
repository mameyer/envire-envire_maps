#include "SpatioTemporalMLSMap.hpp"
#include <envire_core/items/SpatioTemporal.hpp>

using namespace vizkit3d;

SpatioTemporalMLSMap::SpatioTemporalMLSMap()
{
}

SpatioTemporalMLSMap::~SpatioTemporalMLSMap()
{
}

void SpatioTemporalMLSMap::updateData(const envire::core::SpatioTemporal<maps::grid::MLSMapKalman>& data)
{
    MLSMapVisualization::updateData(data.data);
}

void SpatioTemporalMLSMap::updateData(const envire::core::SpatioTemporal< maps::grid::MLSMapPrecalculated >& data)
{
    MLSMapVisualization::updateData(data.data);
}

void SpatioTemporalMLSMap::updateData(const envire::core::SpatioTemporal< maps::grid::MLSMapSloped >& data)
{
    MLSMapVisualization::updateData(data.data);
}

//Macro that makes this plugin loadable in ruby, this is optional.
VizkitQtPlugin(SpatioTemporalMLSMap)