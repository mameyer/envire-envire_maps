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

    std::cout<<"Size : "<< raster->GetRasterXSize()<<" x "<<raster->GetRasterYSize() << " "<<
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
        /*** Envire Elevation map **/
        maps::grid::ElevationMap elevation_map;

        /** Open the dataset **/
        GDALDataset *dataset = open(static_cast<std::string>(boost::unit_test::framework::master_test_suite().argv[1]));

        double geo_transform[6];
        dataset->GetGeoTransform(geo_transform);

        /** Get the raster band **/
        //envire::gis::ElevationRaster *elevation_raster = envire::gis::ElevationRaster::Import(dataset->GetRasterBand(1));
        envire::gis::ElevationRaster *elevation_raster = new envire::gis::ElevationRaster(dataset->GetRasterBand(1), base::Vector2d(geo_transform[1], geo_transform[5]));

        std::cout<<"INFORMATION:\n"<<*elevation_raster<<"\n";

//        try
//        {
        elevation_raster->fromGis<maps::grid::ElevationMap>(elevation_map);
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
