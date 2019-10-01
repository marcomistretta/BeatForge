//
// Created by Guglielmo Fratticioli on 19/09/19.
//

#ifndef MYTEST_DISPLAYWIDGET_H
#define MYTEST_DISPLAYWIDGET_H

#include <QtWidgets>
#include <QStringList>
#include "Observer.h"

class Player;

class DrumKit;

class AbstractWheelWidget : public QWidget {
Q_OBJECT

public:
    AbstractWheelWidget(bool touch, QWidget *parent = 0);

    virtual ~AbstractWheelWidget();

    int currentIndex() const;

    void setCurrentIndex(int index);

    bool event(QEvent *);

    void paintEvent(QPaintEvent *e);

    virtual void paintItem(QPainter *painter, int index, const QRect &rect) = 0;

    virtual int itemWidth() const = 0;

    virtual int itemCount() const = 0;


public slots:

    void scrollTo(int index);

signals:

    void stopped(int index);

protected:
    int m_currentItem;
    int m_itemOffset; // 0-itemHeight()
    qreal m_lastY;
};

class StringWheelWidget : public AbstractWheelWidget {
Q_OBJECT

public:
    StringWheelWidget(bool touch, QWidget *parent);

    virtual ~StringWheelWidget();

    QStringList items() const;

    void setItems(const QStringList &items);

    QSize sizeHint() const;

    QSize minimumSizeHint() const;

    void paintItem(QPainter *painter, int index, const QRect &rect);

    int itemWidth() const;

    int itemCount() const;

private:
    QStringList m_items;
};

class BpmSpinBox : public QWidget {
public:
    BpmSpinBox(QWidget *parent = nullptr);

    void updateBpm(int Bpm);

    QPushButton *getupBpm() {
        return upBpm;
    }

    QPushButton *getdownBpm() {
        return downBpm;
    }

private:
    QLabel *bpmLabel;
    QPushButton *upBpm;
    QPushButton *downBpm;
    QHBoxLayout *boxLayout;
    QVBoxLayout *rightLayout;
    QVBoxLayout *leftLayout;
    QWidget *leftWidget;
    QWidget *rightWidget;

};

class DisplayWidget : public QWidget, public Observer {
Q_OBJECT

public:
    ~DisplayWidget() override;

    DisplayWidget(Player *player, DrumKit *drumKit, QWidget *parent = nullptr);

    void obsUpdate() override;

    Player *getPlayer() const {
        return player;
    }

    DrumKit *getDrumKit() const {
        return drumKit;
    }

    StringWheelWidget *getStylesWheel() const {
        return stylesWheel;
    }

    BpmSpinBox *getBpmBox() const {
        return bpmBox;
    }

    QPushButton *getRightStyle() const {
        return rightStyle;
    }

    QPushButton *getLeftStyle() const {
        return leftStyle;
    }

    QPushButton *getSaveButton() const {
        return saveButton;
    }

    QPushButton *getLoadButton() const {
        return loadButton;
    }

    QWidget *getLeftWidget() const {
        return leftWidget;
    }

    QWidget *getRightWidget() const {
        return rightWidget;
    }

    QWidget *getStyleButtonWidget() const {
        return styleButtonWidget;
    }

    QVBoxLayout *getLeftLayout() const {
        return leftLayout;
    }

    QVBoxLayout *getRightLayout() const {
        return rightLayout;
    }

    QHBoxLayout *getStyleButtonLayout() const {
        return styleButtonLayout;
    }

    QHBoxLayout *getBoxLayout() const {
        return boxLayout;
    }

private slots:

    void on_downBpm_clicked();

    void on_upBpm_clicked();

    void on_save_pressed();

    void on_load_pressed();

    void on_leftStyle_pressed();

    void on_rightStyle_pressed();

    void on_style_changed();

private:
    Player *player;
    DrumKit *drumKit;
    StringWheelWidget *stylesWheel;
    BpmSpinBox *bpmBox;
    QPushButton *rightStyle;
    QPushButton *leftStyle;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QWidget *leftWidget;
    QWidget *rightWidget;
    QWidget *styleButtonWidget;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *styleButtonLayout;
    QHBoxLayout *boxLayout;

};


#endif //MYTEST_DISPLAYWIDGET_H
