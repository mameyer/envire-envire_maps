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
            /*@brief Default constructor
             */
            ElevationRaster( RasterPlugin <::envire::maps::ElevationMap> *parent = NULL)
            :RasterPlugin<::envire::maps::ElevationMap>(parent)
            {
            }

            ~ElevationRaster(){};

            static ElevationRaster *Import(GDALRasterBand *raster_band)
            {
                return dynamic_cast< ::envire::gis::ElevationRaster * >(RasterPlugin<::envire::maps::ElevationMap>::Import(raster_band));
            }


        protected:
            /* @brief Convert Elevation Map to Raster data
             */
            void convertToRasterBand(const ::envire::maps::ElevationMap &data);

            /* @brief Convert Raster data to Elevation map
             */
            void convertToEnvireType(::envire::maps::ElevationMap &data);
    };

}} // end namespace envire::gis

#endif // _GIS_RASTER_HPP_
