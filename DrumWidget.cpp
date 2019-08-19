
#include "DrumWidget.h"


#include <QPalette>
#include <QSizePolicy>


DrumWidget::DrumWidget( QWidget *parent): QWidget(parent) {
    this->setUpGui();
}

DrumWidget::~DrumWidget() {
    drum->removeObserver(this);
}
void DrumWidget::obsUpdate() {
    for(int pos = 0; pos<16; pos ++){
        if (drum->isChecked(pos))
            buttons[pos]->setBackground(Qt::red);
        else
            buttons[pos]->setBackground(Qt::white);
    }
}
void DrumWidget::setUpGui() {

    QPalette pal;
    pal.setColor(QPalette::Background,QColor(72,71,90));
    this->setPalette(pal);
    this->setAutoFillBackground(true);


    //DECLARING HORIZONTAL LAYOUT
    layout = new QHBoxLayout();
    //BUILDING INFO BOX

    drum_info = new QPushButton();
    drum_info->setStyleSheet("background: #23B400");
    drum_info->setText(drum->getName());
    layout->addWidget(drum_info);
    layout->setStretchFactor(drum_info, 3);
    //BUILDING PLAY-PAUSE-MUTE-SOLO

    playButton = new QPushButton();
    QIcon playicon;
    playicon.addFile(QString("/home/gege/Studio/C++/png/playicon.png"));
    playButton->setIcon(playicon);
    pauseButton = new QPushButton();
    QIcon pauseicon;
    pauseicon.addFile(QString("/home/gege/Studio/C++/png/pause1icon.png"));
    pauseButton->setIcon(pauseicon);

    layout->addWidget(playButton,0,0);
    layout->addWidget(pauseButton,1,0);



    //BUILDING STEP_BUTTONS
    for (int i = 0; i < 16; i++) {
        buttons[i] = new StepButton(this);
        buttons[i]->setStyleSheet("background: white");
        buttons[i]->setPosition(i);

        layout->addWidget(buttons[i]);
        layout->setStretchFactor(buttons[i], 1);
    }

    this->setLayout(layout);                                                                //SETTING THE LAYOUT

}


