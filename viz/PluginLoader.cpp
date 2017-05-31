#include <vizkit3d/Vizkit3DPlugin.hpp>
#include "SpatioTemporalContourMapVisualization.hpp"
#include "SpatioTemporalElevationMapVisualization.hpp"
#include "SpatioTemporalGridMapVisualization.hpp"
#include "SpatioTemporalMLSMapVisualization.hpp"
#include "SpatioTemporalOccupancyGridMapVisualization.hpp"

namespace vizkit3d {
    class QtPluginVizkitBase : public vizkit3d::VizkitPluginFactory {
    private:
    public:
        
        QtPluginVizkitBase() {
        }
        
        /**
        * Returns a list of all available visualization plugins.
        * @return list of plugin names
        */
        virtual QStringList* getAvailablePlugins() const
        {
            QStringList *pluginNames = new QStringList();
            pluginNames->push_back("SpatioTemporalContourMapVisualization");
            pluginNames->push_back("SpatioTemporalElevationMapVisualization");
            pluginNames->push_back("SpatioTemporalGridMapVisualization");
            pluginNames->push_back("SpatioTemporalMLSMapVisualization");
            pluginNames->push_back("SpatioTemporalOccupancyGridMapVisualization");
            return pluginNames;
        }
        
        virtual QObject* createPlugin(QString const& pluginName)
        {
            vizkit3d::VizPluginBase* plugin = 0;
            if (pluginName == "SpatioTemporalContourMapVisualization")
            {
                plugin = new vizkit3d::SpatioTemporalContourMapVisualization();
            }
            else if (pluginName == "SpatioTemporalElevationMapVisualization")
            {
                plugin = new vizkit3d::SpatioTemporalElevationMapVisualization();
            }
            else if (pluginName == "SpatioTemporalGridMapVisualization")
            {
                plugin = new vizkit3d::SpatioTemporalGridMapVisualization();
            }
            else if (pluginName == "SpatioTemporalMLSMapVisualization")
            {
                plugin = new vizkit3d::SpatioTemporalMLSMapVisualization();
            }
            else if (pluginName == "SpatioTemporalOccupancyGridMapVisualization")
            {
                plugin = new vizkit3d::SpatioTemporalOccupancyGridMapVisualization();
            }

            if (plugin) 
            {
                return plugin;
            }
            return NULL;
        };
    };
    Q_EXPORT_PLUGIN2(QtPluginVizkitBase, QtPluginVizkitBase)
}