#include "marked_drawer.hpp"

#include <QVBoxLayout>

MarkedDrawer::MarkedDrawer( const QSize& size, QWidget* parent )
    : MarkedDrawer( new GridDrawer( size ), new QLineEdit(), parent )
{}

MarkedDrawer::MarkedDrawer( const MarkedDrawer& other )
    : MarkedDrawer( new GridDrawer( *other.gridDrawer ),
                    new QLineEdit( other.markLineEdit->text() ) )
{}

MarkedDrawer::MarkedDrawer( MarkedDrawer&& other )
    : MarkedDrawer( other.gridDrawer, other.markLineEdit )
{
    other.gridDrawer = Q_NULLPTR;
    other.markLineEdit = Q_NULLPTR;
}

MarkedDrawer::MarkedDrawer(
    GridDrawer* gridDrawer, QLineEdit* markLineEdit, QWidget* parent)
    : QWidget( parent )
{
    this->gridDrawer = gridDrawer;
    this->markLineEdit = markLineEdit;

    connect( this->markLineEdit, &QLineEdit::textChanged,
             this, &MarkedDrawer::setMark );
    connect( this->gridDrawer, &GridDrawer::markIsChanged,
             this, &MarkedDrawer::markIsChanged );

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget( this->gridDrawer );
    mainLayout->addWidget( this->markLineEdit );
    mainLayout->setSpacing( 0 );
    mainLayout->setMargin( 0 );

    this->setLayout( mainLayout );
}

QString MarkedDrawer::getMark() const
{
    return gridDrawer->getMark();
}

QSize MarkedDrawer::getSize() const
{
    return gridDrawer->getSize();
}

QVector< QColor > MarkedDrawer::getPixelData() const
{
    return gridDrawer->getPixelData();
}

const QImage& MarkedDrawer::getImage() const
{
    return gridDrawer->getImage();
}

void MarkedDrawer::refresh()
{
    gridDrawer->refresh();
}

void MarkedDrawer::setMark( const QString& mark )
{
    gridDrawer->setMark( mark );
    markLineEdit->setText( mark );
}

void MarkedDrawer::setSize( const QSize& size )
{
    gridDrawer->setSize( size );
}
