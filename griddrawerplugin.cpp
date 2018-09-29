#include "griddrawer.hpp"
#include "griddrawerplugin.hpp"

#include <QtPlugin>

GridDrawerPlugin::GridDrawerPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void GridDrawerPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool GridDrawerPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *GridDrawerPlugin::createWidget(QWidget *parent)
{
    return new GridDrawer(parent);
}

QString GridDrawerPlugin::name() const
{
    return QLatin1String("GridDrawer");
}

QString GridDrawerPlugin::group() const
{
    return QLatin1String("");
}

QIcon GridDrawerPlugin::icon() const
{
    return QIcon();
}

QString GridDrawerPlugin::toolTip() const
{
    return QLatin1String("");
}

QString GridDrawerPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool GridDrawerPlugin::isContainer() const
{
    return false;
}

QString GridDrawerPlugin::domXml() const
{
    return QLatin1String("<widget class=\"GridDrawer\" name=\"gridDrawer\">\n</widget>\n");
}

QString GridDrawerPlugin::includeFile() const
{
    return QLatin1String("griddrawer.hpp");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(griddrawerplugin, GridDrawerPlugin)
#endif // QT_VERSION < 0x050000
