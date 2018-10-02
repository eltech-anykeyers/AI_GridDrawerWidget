#ifndef GRIDDRAWER_HPP
#define GRIDDRAWER_HPP

#include <optional>
#include <memory>

#include <QWidget>

class GridDrawer : public QWidget
{
    Q_OBJECT

public:
    GridDrawer() = delete;
    explicit GridDrawer(
        const QSize& size, bool enableGrid = true,
        QWidget* parent = Q_NULLPTR );
    GridDrawer( const GridDrawer& other );
    GridDrawer( GridDrawer&& other );
    virtual ~GridDrawer() override;

    GridDrawer& operator=( const GridDrawer& ) = delete;
    GridDrawer& operator=( GridDrawer&& ) = delete;

    QString getMark() const;
    QSize getSize() const;
    QVector< QColor > getPixelData() const;
    const QImage& getImage() const;
    std::shared_ptr< QImage > getImagePtr() const;
    bool isGridEnabled() const;

public slots:
    void enableGrid( bool enable );
    void refresh();
    void setMark( const QString& mark );
    void setSize( const QSize& size );

signals:
    void imageUpdated( const QImage& image );
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
    std::shared_ptr< QImage > image;
    std::optional< QPoint > prevPoint;
    bool gridIsEnabled;
};

#endif /// GRIDDRAWER_HPP
