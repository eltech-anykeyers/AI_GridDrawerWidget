#ifndef MARKEDDRAWER_HPP
#define MARKEDDRAWER_HPP

#include <QWidget>
#include <QLineEdit>

#include "grid_drawer.hpp"

class MarkedDrawer : public QWidget
{
    Q_OBJECT

public:
    MarkedDrawer() = delete;
    explicit MarkedDrawer(
            const QSize& size, bool enableGrid = true,
            QWidget* parent = Q_NULLPTR );
    MarkedDrawer( const MarkedDrawer& other );
    MarkedDrawer( MarkedDrawer&& other );

    MarkedDrawer& operator=( const MarkedDrawer& other ) = delete;
    MarkedDrawer& operator=( MarkedDrawer&& other ) = delete;

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
    MarkedDrawer(
        GridDrawer* gridDrawer, QLineEdit* markLineEdit,
        QWidget* parent = Q_NULLPTR );

private:
    GridDrawer* gridDrawer;
    QLineEdit* markLineEdit;
};

#endif /// MARKEDDRAWER_HPP
