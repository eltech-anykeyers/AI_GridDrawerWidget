#ifndef MARKEDDRAWER_HPP
#define MARKEDDRAWER_HPP

#include <QWidget>
#include <QLineEdit>

#include "griddrawer.hpp"

class MarkedDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit MarkedDrawer( const QSize& size, QWidget* parent = Q_NULLPTR );
    MarkedDrawer( const MarkedDrawer& other ) = default;
    MarkedDrawer( MarkedDrawer&& other ) = default;

private:
    GridDrawer* gridDrawer;
    QLineEdit* markLineEdit;
};

#endif /// MARKEDDRAWER_HPP
