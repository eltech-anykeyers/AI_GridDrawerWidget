#include "markeddrawer.hpp"

#include <QVBoxLayout>

MarkedDrawer::MarkedDrawer( const QSize& size, QWidget* parent )
    : QWidget ( parent )
{
    gridDrawer = new GridDrawer( size );
    markLineEdit = new QLineEdit();

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget( gridDrawer );
    mainLayout->addWidget( markLineEdit );
    mainLayout->setSpacing( 0 );
    mainLayout->setMargin( 0 );

    this->setLayout( mainLayout );
}
