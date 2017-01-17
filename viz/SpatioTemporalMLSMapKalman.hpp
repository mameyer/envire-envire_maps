#ifndef envire_maps_SpatioTemporalMLSMapKalman_H
#define envire_maps_SpatioTemporalMLSMapKalman_H

#include <boost/noncopyable.hpp>
#include <vizkit3d/Vizkit3DPlugin.hpp>
#include <osg/Geode>
#include <envire/items/SpatioTemporal.hpp>

namespace vizkit3d
{
    class SpatioTemporalMLSMapKalman
        : public vizkit3d::Vizkit3DPlugin<envire::core::SpatioTemporal<maps::grid::MLSMapKalman>>
        , boost::noncopyable
    {
    Q_OBJECT
    public:
        SpatioTemporalMLSMapKalman();
        ~SpatioTemporalMLSMapKalman();

    Q_INVOKABLE void updateData(envire::core::SpatioTemporal<maps::grid::MLSMapKalman> const &sample)
    {vizkit3d::Vizkit3DPlugin<envire::core::SpatioTemporal<maps::grid::MLSMapKalman>>::updateData(sample);}

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(envire::core::SpatioTemporal<maps::grid::MLSMapKalman> const& plan);
        
    private:
        struct Data;
        Data* p;
    };
}
#endif
