#include <boost/test/unit_test.hpp>
#include <envire_gis/ElevationRaster.hpp>
#include <exception>

using namespace envire::gis;

GDALDataset *open(std::string const& path)
{

    GDALDataset *raster = (GDALDataset *) (GDALOpen(path.c_str(), GA_ReadOnly ));

    if(raster == NULL)
    {
        throw std::runtime_error("can not open raster file " + path);
    }

    std::cout<< "Driver: "<< raster->GetDriver()->GetDescription() <<" "<<
            raster->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME )<<"\n";

    std::cout<<"Size : "<< raster->GetRasterXSize()<<" "<<raster->GetRasterYSize() << " "<<
            raster->GetRasterCount()<<"\n";

    if(raster->GetProjectionRef()  != NULL)
    {
        std::cout<<"Projection is "<<raster->GetProjectionRef()<<"\n";
    }

    double geo_transform[6];

    if(raster->GetGeoTransform(geo_transform) == CE_None)
    {
        std::cout<<"Origin = "<<geo_transform[0]<<" "<<geo_transform[3]<<"\n";
        std::cout<<"Pixel Size = "<<geo_transform[1]<<" "<<geo_transform[5]<<"\n";
    }

    return raster;
}

void close(GDALDataset *raster)
{

    if (raster != NULL)
    {
        GDALClose((GDALDatasetH)raster);
    }
    return;
}


BOOST_AUTO_TEST_CASE(test_read_raster)
{

    /** Register all known drivers **/
    GDALAllRegister();
    std::cout<<"Registering all known drivers\n";

    if (boost::unit_test::framework::master_test_suite().argc > 1.0)
    {
        /** Open the dataset **/
        GDALDataset *dataset = open(static_cast<std::string>(boost::unit_test::framework::master_test_suite().argv[1]));

        /** Get the raster band **/
        envire::gis::ElevationRaster *elevation_raster = envire::gis::ElevationRaster::Import(dataset->GetRasterBand(1));
        //envire::gis::ElevationRaster *elevation_raster = new envire::gis::ElevationRaster();

        envire::maps::ElevationMap elevation_map;

//        try
//        {
            //elevation_raster->fromGis<envire::maps::ElevationMap>(elevation_map);
//        }
//        catch(std::exception& e)
//        {
//            std::cout << e.what() << '\n';
//        }

        close(dataset);
    }
    else
    {
        std::cout<<"Missing Raster file as argument\n";
    }
}
