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
    QSize getSize() const;
    void setSize( const QSize& size );
    QVector< QColor > getPixelData() const;

public slots:
    void setMark( const QString& mark );

signals:
    void markIsChanged( const QString& newMark );

private:
    GridDrawer* gridDrawer;
    QLineEdit* markLineEdit;
};

#endif /// MARKEDDRAWER_HPP
