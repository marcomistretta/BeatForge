//
// Created by Guglielmo Fratticioli on 19/08/19.
//

#ifndef MYTEST_DRUMKITWIDGET_H
#define MYTEST_DRUMKITWIDGET_H

#include <QWidget>

class DrumWidget;
class DrumKit;
class QVBoxLayout;
class QPushButton;

class DrumKitWidget: public QWidget {
    Q_OBJECT
public:
    explicit DrumKitWidget(QWidget* parent = nullptr);

private slots:
    void on_add_pressed();

private:
    QVBoxLayout * layout;
    DrumKit* drumKit;
    QPushButton* addbutton;
    QVector<DrumWidget*> drumWidgets;
};


#endif //MYTEST_DRUMKITWIDGET_H
