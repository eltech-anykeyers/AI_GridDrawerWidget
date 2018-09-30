#ifndef GRIDDRAWER_HPP
#define GRIDDRAWER_HPP

#include <optional>

#include <QWidget>

class GridDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit GridDrawer( const QSize& size, QWidget* parent = Q_NULLPTR );
    GridDrawer( const GridDrawer& other );
    GridDrawer( GridDrawer&& other );
    virtual ~GridDrawer() override;

    void refresh();
    QString getMark() const;
    void setMark( const QString& mark );
    QSize getSize() const;
    void setSize( const QSize& size );

protected:
    std::optional< QPoint > getClickPoint( const QPointF& pos ) const;

    virtual void paintEvent( QPaintEvent* event ) override;
    virtual void mousePressEvent( QMouseEvent* event ) override;
    virtual void mouseReleaseEvent( QMouseEvent* event ) override;
    virtual void mouseMoveEvent( QMouseEvent* event ) override;

    virtual QSize minimumSizeHint() const override;

private:
    static const QSize cellMinimumSize;

    QString mark;
    QImage* image;
    std::optional< QPoint > prevPoint;
};

#endif /// GRIDDRAWER_HPP
