#
# Copyright (c) 2015, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
Vizkit::UiLoader.register_3d_plugin('SpatioTemporalContourMapVisualization', 'envire_maps', 'SpatioTemporalContourMapVisualization')
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalContourMapVisualization', "/envire/core/SpatioTemporal</maps/geometric/ContourMap>", :updateSpatioTemporalContourMap)

Vizkit::UiLoader.register_3d_plugin('SpatioTemporalElevationMapVisualization', 'envire_maps', 'SpatioTemporalElevationMapVisualization')
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalElevationMapVisualization', "/envire/core/SpatioTemporal</maps/grid/ElevationMap>", :updateSpatioTemporalElevationMap)

Vizkit::UiLoader.register_3d_plugin('SpatioTemporalGridMapVisualization', 'envire_maps', 'SpatioTemporalGridMapVisualization')
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalGridMapVisualization', "/envire/core/SpatioTemporal</maps/grid/GridMapD>", :updateSpatioTemporalGridMapD)
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalGridMapVisualization', "/envire/core/SpatioTemporal</maps/grid/GridMapI>", :updateSpatioTemporalGridMapI)
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalGridMapVisualization', "/envire/core/SpatioTemporal</maps/grid/GridMapF>", :updateSpatioTemporalGridMapF)
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalGridMapVisualization', "/envire/core/SpatioTemporal</maps/grid/GridMapC>", :updateSpatioTemporalGridMapC)

Vizkit::UiLoader.register_3d_plugin('SpatioTemporalMLSMapVisualization', 'envire_maps', 'SpatioTemporalMLSMapVisualization')
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalMLSMapVisualization', "/envire/core/SpatioTemporal</maps/grid/MLSMapKalman>", :updateSpatioTemporalMLSMapKalman)
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalMLSMapVisualization', "/envire/core/SpatioTemporal</maps/grid/MLSMapPrecalculated>", :updateSpatioTemporalMLSMapPrecalculated)
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalMLSMapVisualization', "/envire/core/SpatioTemporal</maps/grid/MLSMapSloped>", :updateSpatioTemporalMLSMapSloped)

Vizkit::UiLoader.register_3d_plugin('SpatioTemporalOccupancyGridMapVisualization', 'envire_maps', 'SpatioTemporalOccupancyGridMapVisualization')
Vizkit::UiLoader.register_3d_plugin_for('SpatioTemporalOccupancyGridMapVisualization', "/envire/core/SpatioTemporal</maps/grid/OccupancyGridMap>", :updateSpatioTemporalOccupancyGridMap)