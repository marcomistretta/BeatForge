//
// Created by Guglielmo Fratticioli on 29/09/19.
//
//TODO CHECK
//#include <QTest>
#include <QtTest/QtTest>
#include <QVector>
#include "../src/MainWindow.h"
#include "../src/DrumKitWidget.h"
#include "../src/DrumKit.h"
#include "../src/DrumWidget.h"
#include "../src/Drum.h"
#include "../src/DisplayWidget.h"
#include "../src/StepButton.h"
#include "../src/Enum.h"

class SingleDrumTest : public QObject {

Q_OBJECT
private slots:

    void test() {
        mainWindow = new MainWindow(nullptr);
        //Has layout Been Initialised?
        QVERIFY(mainWindow->getUpperWidget() != nullptr);
        QVERIFY(mainWindow->getMidWidget() != nullptr);
        QVERIFY(mainWindow->getBottomWidget() != nullptr);

        //Has DrumKit,DrumKitWidget Been Constructed?
        QVERIFY(mainWindow->getDrumKit() != nullptr);
        QVERIFY(mainWindow->getDrumKitWidget() != nullptr);

        drumKit = mainWindow->getDrumKit();
        drumKitWidget = mainWindow->getDrumKitWidget();


    }

    void testAdd() {

        int count = drumKitWidget->getLayout()->count();

        QTest::mouseClick(drumKitWidget->getAddbutton(), Qt::LeftButton);
        //Has Drum Been Constructed ?
        QVERIFY(drumKit->getDrums().size() == 1);
        QVERIFY(drumKit->getDrums()[0] != nullptr);

        //Has DrumWidget Been Constructed ?
        QVERIFY(drumKitWidget->getDrumWidgets().size() == 1);
        QVERIFY(drumKitWidget->getDrumWidgets()[0] != nullptr);

        //Has Layout Been Edited ?
        QVERIFY(drumKitWidget->getLayout()->count() == count + 1);

        drum = drumKit->getDrums()[0];

    }

    void testPattern() {
        for (int i = 0; i < 16; i++) {
            //Pressing Buttons
            QTest::mouseClick(drumKitWidget->getDrumWidgets()[0]->getButtons()[i], Qt::LeftButton);
            //Has Been Switched ON?
            QVERIFY(drum->getGroove()[i] == ON);
        }
        for (int i = 0; i < 16; i++) {
            //Pressing Buttons
            QTest::mouseClick(drumKitWidget->getDrumWidgets()[0]->getButtons()[i], Qt::LeftButton);
            //Has Been Switched OFF?
            QVERIFY(drum->getGroove()[i] == OFF);
        }
    }

private:

    void testMute() {

    }

    void testVolume() {

    }

    void testTypeChange() {

    }

    void testStyleChange() {

    }

    MainWindow *mainWindow;
    Drum *drum;
    DrumKit *drumKit;
    DrumKitWidget *drumKitWidget;
};

QTEST_MAIN(SingleDrumTest)

#include "SingleDrumTest.moc"
