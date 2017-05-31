//
// Copyright (c) 2015, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#ifndef envire_maps_SpatioTemporalMLSMapVisualization_H
#define envire_maps_SpatioTemporalMLSMapVisualization_H

#include <boost/noncopyable.hpp>
#include <vizkit3d/Vizkit3DPlugin.hpp>
#include <osg/Geode>
#include <envire_core/items/SpatioTemporal.hpp>
#include <maps/grid/MLSMap.hpp>
#include <vizkit3d/MLSMapVisualization.hpp>

namespace vizkit3d
{
    class SpatioTemporalMLSMapVisualization
        : public MLSMapVisualization
    {
        Q_OBJECT

    public:
        SpatioTemporalMLSMapVisualization()
        {
        }

        ~SpatioTemporalMLSMapVisualization()
        {
        }
        
        template<class T>
        void updateData(const envire::core::SpatioTemporal<T>& data)
        {
            setVisualizationFrame(QString::fromStdString(data.frame_id));
            MLSMapVisualization::updateData(data.data);
        }
        
        Q_INVOKABLE void updateData(const envire::core::SpatioTemporal<maps::grid::MLSMapKalman>& data)
        { updateData<maps::grid::MLSMapKalman>(data); }
        Q_INVOKABLE void updateData(const envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated>& data)
        { updateData<maps::grid::MLSMapPrecalculated>(data); }
        Q_INVOKABLE void updateData(const envire::core::SpatioTemporal<maps::grid::MLSMapSloped>& data)
        { updateData<maps::grid::MLSMapSloped>(data); }
        
        Q_INVOKABLE void updateSpatioTemporalMLSMapKalman(const envire::core::SpatioTemporal<maps::grid::MLSMap<maps::grid::MLSConfig::KALMAN>>& data)
        { updateData(data); }
        Q_INVOKABLE void updateSpatioTemporalMLSMapPrecalculated(const envire::core::SpatioTemporal<maps::grid::MLSMap<maps::grid::MLSConfig::PRECALCULATED>>& data)
        { updateData(data); }
        Q_INVOKABLE void updateSpatioTemporalMLSMapSloped(const envire::core::SpatioTemporal<maps::grid::MLSMap<maps::grid::MLSConfig::SLOPE>>& data)
        { updateData(data); }
    private:
    };
}

#endif