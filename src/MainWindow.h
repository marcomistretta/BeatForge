//
// Created by Guglielmo Fratticioli on 09/07/19.
//

#ifndef MYTEST_MAINWINDOW_H
#define MYTEST_MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;
class QWidget;
class DrumKit;
class DrumKitWidget;
class Metronome;
class MetronomeWidget;
class Player;
class PlayerWidget;
class Timeline;



class MainWindow : public QMainWindow {
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QWidget * mainWidget;
    DrumKit* drumKit;
    DrumKitWidget* drumKitWidget;
    Metronome* metronome;
    MetronomeWidget* metronomeWidget;
    Player* player;
    PlayerWidget *playerWidget;

    QGridLayout* mainLayout;
    Timeline *timeline;


};


#endif //MYTEST_MAINWINDOW_H
