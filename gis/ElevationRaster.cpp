#include "ElevationRaster.hpp"

#include <iostream>

using namespace envire::gis;

void ElevationRaster::convertToRasterBand(const ::maps::grid::ElevationMap &data)
{

}

void ElevationRaster::convertToEnvireType(::maps::grid::ElevationMap &data, const base::Vector2d &cell_resolution)
{
    /** Get the raster band **/
//    GDALRasterBand *band = dynamic_cast<GDALRasterBand*>(this->GetRasterBand(this->bandNumber()));

    /** Get the number of cells (pixel in the raster) **/
    ::maps::grid::Vector2ui cell_num(this->nRasterXSize, this->nRasterYSize);

    /** Create the Elevation Grid Map **/
    ::maps::grid::ElevationMap elevation_map(cell_num, cell_resolution, this->GetNoDataValue());

    std::cout<<"Elevation Map number of cell: "<<elevation_map.getNumCells().x()<<","<<elevation_map.getNumCells().y()<<"\n";
    std::cout<<"Elevation Map resolution: "<<elevation_map.getResolution().x()<<","<<elevation_map.getResolution().y()<<"\n";

//    ::envire::maps::ElevationMap::TemplateType::GridCellType &cells_map(elevation_map.cells)
//    ::envire::maps::ElevationMap::TemplateType::CellType* cells_map_ptr = &cells_map[0][0];

//    /** Read the Raster Band **/
//    this->RasterIO(GF_Read, 0, 0, cell_num[0], cell_num[1],
//            cells_map_ptr, cell_num[0], cell_num[1],
//            band_type, 0, 0);
//
//    std::cout<<"Elevation Map Max: "<<elevation_map.getMax()<<"\n";
//    std::cout<<"Elevation Map Min: "<<elevation_map.getMin()<<"\n";
//
//    /** Set the data in ElevationMap **/
    data = elevation_map;

    return;
}

//void ElevationRaster::fromRasterBand(const int band_number, ::envire::maps::GridMap<float> &map)
//{
//
//    /** Check the band number **/
//    if(this->dataset->GetRasterCount() < band_number)
//    {
//        std::stringstream strstr;
//        strstr << "Loaded "<<this->dataset->GetDriver()->GetDescription()<< " has " << this->dataset->GetRasterCount()
//            << " raster bands but the band " << band_number << " was requested\n";
//        throw std::runtime_error(strstr.str());
//    }
//
//    /** Get the band **/
//    GDALRasterBand  *band;
//    band = this->dataset->GetRasterBand(band_number);
//
//    GDALDataType band_type = band->GetRasterDataType();
//
//    /** Check that the band type and the grid type are compatible **/
//
//
//    /** Get the correct configuration values **/
//    envire::maps::Vector2ui cell_num(this->dataset->GetRasterXSize(), this->dataset->GetRasterYSize());
//    Eigen::Vector2d cell_resolution (this->adfGeoTransform[1], -this->adfGeoTransform[5]);
//
//    /** Create and configure the map **/
//   // map.reset (cell_num, cell_resolution, band->GetNoDataValue());
//
//    std::cout<<"Map number of cell: "<<map.getNumCells().x()<<","<<map.getNumCells().y()<<"\n";
//    std::cout<<"Map resolution: "<<map.getResolution().x()<<","<<map.getResolution().y()<<"\n";
//
//    /** Fetching the Grid Map **/
//    //typename envire::maps::GridMap<float>::GridCell &data(map.getCells());
//    //float* data_ptr = &data[0][0];
//
//    ///** Read the Raster Band **/
//    //band->RasterIO(GF_Read, 0, 0, cell_num[0], cell_num[1],
//    //        data_ptr, cell_num[0], cell_num[1],
//    //        band_type, 0, 0);
//
//    //std::cout<<"GridMap Max: "<<map.getMax()<<"\n";
//    //std::cout<<"GridMap Min: "<<map.getMin()<<"\n";
//
//    return;
//}
//
//bool ElevationRaster::checkBandType(const envire::maps::GridMap<T> const GDALRasterBand  *band)
//{
//    std::string type_name;
//    int size = 0;
//    switch(band->GetRasterDataType())
//    {
//      case  GDT_Byte:
//        if(typeid(T)== typeid(unsigned char))
//          return true;
//        type_name = typeid(unsigned char).name();
//        size = sizeof(unsigned char);
//        break;
//      case GDT_Int16:
//        if(typeid(T)== typeid(int16_t))
//          return true;
//        type_name = typeid(int16_t).name();
//        size = sizeof(int16_t);
//        break;
//      case GDT_UInt16:
//       if(typeid(T)== typeid(uint16_t))
//          return true;
//        type_name = typeid(uint16_t).name();
//        size = sizeof(uint16_t);
//        break;
//      case GDT_Int32 :
//       if(typeid(T)== typeid(int32_t))
//          return true;
//        type_name = typeid(int32_t).name();
//        size = sizeof(int32_t);
//        break;
//      case GDT_UInt32 :
//        if(typeid(T)== typeid(uint32_t))
//          return true;
//        type_name = typeid(uint32_t).name();
//        size = sizeof(uint32_t);
//        break;
//      case GDT_Float32:
//       if(typeid(T)== typeid(float)&&sizeof(T)==4)
//          return true;
//        type_name = typeid(float).name();
//        size = 4;
//        break;
//      case GDT_Float64:
//        if(typeid(T)== typeid(double)&&sizeof(T)==8)
//          return true;
//        type_name = typeid(double).name();
//        size = 8;
//        break;
//      default:
//        throw std::runtime_error("GDT type is not supported.");
//    }
//    std::stringstream strstr;
//    strstr << "enview::Grid<T>: type missmatch: the array is of type "<< typeid(T).name()
//           << " and length: " << sizeof(T) << ". But the Band data are of type "
//           << type_name << " and length: " << size;
//    throw std::runtime_error(strstr.str());
//}
