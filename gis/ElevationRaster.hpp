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

#ifndef _ELEVATION_RASTER_HPP_
#define _ELEVATION_RASTER_HPP_

/** Envire maps **/
#include <maps/grid/ElevationMap.hpp>

/** Envire GIS **/
#include <envire_gis/RasterPlugin.hpp>

namespace envire { namespace gis
{
    class ElevationRaster: public RasterPlugin <::maps::grid::ElevationMap>
    {
        public:
            /*@brief Default constructor
             */
            ElevationRaster( GDALRasterBand *parent = NULL, const base::Vector2d &resolution = base::Vector2d::Zero())
            :RasterPlugin<::maps::grid::ElevationMap>(parent, resolution)
            {
            }

            ~ElevationRaster(){};

            static ElevationRaster *Import(GDALRasterBand *raster_band)
            {
                return dynamic_cast< ::envire::gis::ElevationRaster * >(RasterPlugin<::maps::grid::ElevationMap>::Import(raster_band));
            }


        protected:
            /* @brief Convert Elevation Map to Raster data
             */
            void convertToRasterBand(const ::maps::grid::ElevationMap &data);

            /* @brief Convert Raster data to Elevation map
             */
            void convertToEnvireType(::maps::grid::ElevationMap &data, const base::Vector2d &cell_resolution = base::Vector2d::Zero());
    };

    //Note how this is declared outside of the class body, so it is a free function instead of a memberfunction
    inline std::ostream& operator<<(std::ostream& out, const ElevationRaster& val)
    {
        out << "ElevationRaster\n";
        out << static_cast< const RasterPlugin< ::maps::grid::ElevationMap > &>(val);
        return out;
    }
}} // end namespace envire::gis

#endif // _GIS_RASTER_HPP_
