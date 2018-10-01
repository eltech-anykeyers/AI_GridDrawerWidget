#include "marked_drawer.hpp"

#include <QVBoxLayout>

MarkedDrawer::MarkedDrawer( const QSize& size, QWidget* parent )
    : QWidget ( parent )
{
    gridDrawer = new GridDrawer( size );
    markLineEdit = new QLineEdit();
    connect( markLineEdit, &QLineEdit::textChanged,
             this, &MarkedDrawer::setMark );
    connect( gridDrawer, &GridDrawer::markIsChanged,
             this, &MarkedDrawer::markIsChanged );

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget( gridDrawer );
    mainLayout->addWidget( markLineEdit );
    mainLayout->setSpacing( 0 );
    mainLayout->setMargin( 0 );

    this->setLayout( mainLayout );
}

void MarkedDrawer::refresh()
{
    gridDrawer->refresh();
}

QString MarkedDrawer::getMark() const
{
    return gridDrawer->getMark();
}

void MarkedDrawer::setMark( const QString& mark )
{
    gridDrawer->setMark( mark );
    markLineEdit->setText( mark );
}

QSize MarkedDrawer::getSize() const
{
    return gridDrawer->getSize();
}

void MarkedDrawer::setSize( const QSize& size )
{
    gridDrawer->setSize( size );
}

QVector< QColor > MarkedDrawer::getPixelData() const
{
    return gridDrawer->getPixelData();
}
