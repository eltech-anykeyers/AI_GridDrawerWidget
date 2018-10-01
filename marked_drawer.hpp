#ifndef MARKEDDRAWER_HPP
#define MARKEDDRAWER_HPP

#include <QWidget>
#include <QLineEdit>

#include "grid_drawer.hpp"

class MarkedDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit MarkedDrawer( const QSize& size, QWidget* parent = Q_NULLPTR );
    MarkedDrawer( const MarkedDrawer& other ) = default;
    MarkedDrawer( MarkedDrawer&& other ) = default;

    void refresh();
    QString getMark() const;
    void setMark( const QString& mark );
    QSize getSize() const;
    void setSize( const QSize& size );
    QVector< QColor > getPixelData() const;

private:
    GridDrawer* gridDrawer;
    QLineEdit* markLineEdit;
};

#endif /// MARKEDDRAWER_HPP
