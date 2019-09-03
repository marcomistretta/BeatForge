//
// Created by Guglielmo Fratticioli on 09/07/19.
//

#ifndef MYTEST_DRUMKIT_H
#define MYTEST_DRUMKIT_H


#include <QAbstractListModel>
#include <QVector>

class QString;
class Observer;
class Drum;

class DrumKit: public QAbstractListModel {
    Q_OBJECT
public:
    DrumKit(QObject* parent = nullptr);
    DrumKit(const QVector<Drum*> &drums, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    QVariant data(const QModelIndex & index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;


    Qt::ItemFlags flags(const QModelIndex &index) const override;

    const QVector<Drum*> &getDrums() const;

private:
    QVector<Drum*> drums;
};

#endif //MYTEST_DRUMKIT_H
