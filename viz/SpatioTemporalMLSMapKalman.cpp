#include <iostream>
#include "SpatioTemporalMLSMapKalman.hpp"

using namespace vizkit3d;

struct SpatioTemporalMLSMapKalman::Data {
    // Copy of the value given to updateDataIntern.
    //
    // Making a copy is required because of how OSG works
    envire::core::SpatioTemporal<maps::grid::MLSMapKalman> data;
};


SpatioTemporalMLSMapKalman::SpatioTemporalMLSMapKalman()
    : p(new Data)
{
}

SpatioTemporalMLSMapKalman::~SpatioTemporalMLSMapKalman()
{
    delete p;
}

osg::ref_ptr<osg::Node> SpatioTemporalMLSMapKalman::createMainNode()
{
    // Geode is a common node used for vizkit3d plugins. It allows to display
    // "arbitrary" geometries
    return new osg::Geode();
}

void SpatioTemporalMLSMapKalman::updateMainNode ( osg::Node* node )
{
    osg::Geode* geode = static_cast<osg::Geode*>(node);
    // Update the main node using the data in p->data
}

void SpatioTemporalMLSMapKalman::updateDataIntern(envire::core::SpatioTemporal<maps::grid::MLSMapKalman> const& value)
{
    p->data = value;
    std::cout << "got new sample data" << std::endl;
}

//Macro that makes this plugin loadable in ruby, this is optional.
VizkitQtPlugin(SpatioTemporalMLSMapKalman)

