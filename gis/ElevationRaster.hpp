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
