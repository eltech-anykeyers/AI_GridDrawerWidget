#include "griddrawer.hpp"

#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QtMath>

GridDrawer::GridDrawer( const QSize& size, QWidget* parent )
    : QWidget( parent )
{
    image = new QImage( size, QImage::Format::Format_Mono );
    image->fill( 1 );
}

GridDrawer::GridDrawer( const GridDrawer& other )
    : QWidget( Q_NULLPTR )
{
    image = new QImage( other.image->copy() );
}

GridDrawer::GridDrawer( GridDrawer&& other )
    : QWidget( Q_NULLPTR )
{
    image = other.image;
    other.image = Q_NULLPTR;
}

GridDrawer::~GridDrawer()
{
    if( image )
    {
        delete image;
        image = nullptr;
    }
}

void GridDrawer::refresh()
{
    if( image ) image->fill( 1 );
}

QString GridDrawer::getMark() const
{
    return mark;
}

void GridDrawer::setMark( const QString& mark )
{
    this->mark = mark;
}

std::optional< QPoint > GridDrawer::getClickPoint( const QPointF& pos ) const
{
    if( !image ) return std::nullopt;
    if( pos.x() < 0 || pos.x() >= this->width()  ) return std::nullopt;
    if( pos.y() < 0 || pos.y() >= this->height() ) return std::nullopt;

    QPoint clickPoint;
    clickPoint.setX(
        qFloor( pos.x() /
                ( static_cast< qreal >( this->width() ) / image->width() ) ) );
    clickPoint.setY(
        qFloor( pos.y() /
                ( static_cast< qreal >( this->height() ) / image->height() ) ) );

    return std::make_optional( clickPoint );
}

void GridDrawer::paintEvent( QPaintEvent* /* event */ )
{
    QPainter painter( this );

    /// Check if image exists.
    if( !image ) return;

    /// Set up coordinate system.
    painter.setWindow( 0.0, 0.0, image->width(), image->height() );

    /// Draw image.
    painter.drawImage( QPoint( 0, 0), *image );

    /// Draw grid.
    painter.setPen(
        QPen( Qt::GlobalColor::black, 0.0,
              Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin ) );
    for( int x = 1; x < image->width(); x++ )
    {
        painter.drawLine( QLine( x, 0, x, image->height() ) );
    }
    for( int y = 1; y < image->height(); y++ )
    {
        painter.drawLine( QLine( 0, y, image->width(), y ) );
    }
}

void GridDrawer::mousePressEvent( QMouseEvent* event )
{
    auto currentPoint = getClickPoint( event->localPos() );
    if( image && currentPoint )
    {
        if( event->button() == Qt::MouseButton::LeftButton )
        {
            image->setPixel( currentPoint.value(), 0 );
        }
        else if( event->button() == Qt::MouseButton::RightButton )
        {
            image->setPixel( currentPoint.value(), 1 );
        }
        prevPoint = currentPoint;
        this->repaint();
    }
    QWidget::mousePressEvent( event );
}

void GridDrawer::mouseReleaseEvent( QMouseEvent* event )
{
    auto currentPoint = getClickPoint( event->pos() );
    if( image && currentPoint )
    {
        if( event->button() == Qt::MouseButton::LeftButton )
        {
            image->setPixel( currentPoint.value(), 0 );
        }
        else if( event->button() == Qt::MouseButton::RightButton )
        {
            image->setPixel( currentPoint.value(), 1 );
        }
        prevPoint = std::nullopt;
        this->repaint();
    }

    QWidget::mouseReleaseEvent( event );
}

void GridDrawer::mouseMoveEvent( QMouseEvent* event )
{
    auto currentPoint = getClickPoint( event->pos() );
    if( image && currentPoint &&
        event->buttons() & ( Qt::MouseButton::LeftButton |
                             Qt::MouseButton::RightButton ) )
    {
        QPainter painter( image );
        painter.setPen( event->buttons() == Qt::MouseButton::LeftButton ?
                        Qt::GlobalColor::black : Qt::GlobalColor::white );

        if( prevPoint )
        {
            painter.drawLine( prevPoint.value(), currentPoint.value() );
        }
        else
        {
            painter.drawPoint( currentPoint.value() );
        }
        prevPoint = currentPoint;

        this->repaint();
    }

    QWidget::mouseMoveEvent( event );
}
