#ifndef GRIDDRAWER_HPP
#define GRIDDRAWER_HPP

#include <optional>

#include <QWidget>

class GridDrawer : public QWidget
{
    Q_OBJECT

public:
    GridDrawer() = delete;
    explicit GridDrawer( const QSize& size, QWidget* parent = Q_NULLPTR );
    GridDrawer( const GridDrawer& other );
    GridDrawer( GridDrawer&& other );
    virtual ~GridDrawer() override;

    GridDrawer& operator=( const GridDrawer& );
    GridDrawer& operator=( GridDrawer&& );

    QString getMark() const;
    QSize getSize() const;
    QVector< QColor > getPixelData() const;
    const QImage& getImage() const;

public slots:
    void refresh();
    void setMark( const QString& mark );
    void setSize( const QSize& size );

signals:
    void markIsChanged( const QString& newMark );

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
