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
    explicit MarkedDrawer( const QSize& size, QWidget* parent = Q_NULLPTR );
    MarkedDrawer( const MarkedDrawer& other );
    MarkedDrawer( MarkedDrawer&& other );

    MarkedDrawer& operator=( const MarkedDrawer& other ) = delete;
    MarkedDrawer& operator=( MarkedDrawer&& other ) = delete;

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
    MarkedDrawer(
        GridDrawer* gridDrawer, QLineEdit* markLineEdit,
        QWidget* parent = Q_NULLPTR );

private:
    GridDrawer* gridDrawer;
    QLineEdit* markLineEdit;
};

#endif /// MARKEDDRAWER_HPP
