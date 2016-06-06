#ifndef _ELEVATION_RASTER_HPP_
#define _ELEVATION_RASTER_HPP_

/** Envire maps **/
#include <envire_maps/ElevationMap.hpp>

/** Envire GIS **/
#include <envire_gis/RasterPlugin.hpp>

namespace envire { namespace gis
{
    class ElevationRaster: public RasterPlugin <::envire::maps::ElevationMap>
    {
        public:
            ElevationRaster(GDALDataset* parent = NULL)
            {
            }

            ~ElevationRaster();

        protected:
            /* @brief Convert Elevation Map to Raster data
             */
            void toRasterBand(const ::envire::maps::ElevationMap &data);

            /* @brief Convert Raster data to Elevation map
             */
            void fromRasterBand(::envire::maps::ElevationMap &data);
    };

}} // end namespace envire::gis

#endif // _GIS_RASTER_HPP_
