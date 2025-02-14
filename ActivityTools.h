/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef ACTIVITYTOOLS_H
#define	ACTIVITYTOOLS_H

#include <QtWidgets>
#include <QString>

class Route;
class GameObj;
class Activity;
class ActivityServiceDefinition;
class PreciseTileCoordinate;

class ActivityTools : public QWidget{
    Q_OBJECT
public:
    ActivityTools(QString name);
    virtual ~ActivityTools();

public slots:
    void loadActFiles();
    void activitySelected(QString n);
    void conFilesShowEnabled(QString);
    void routeLoaded(Route* r);
    void actNewLooseConsistToolEnabled(bool val);
    void actPathsEditToolEnabled();
    void actConsistDeleteEnabled();
    void actConsistJumpEnabled();
    void actFailedSignalsJumpEnabled();
    void actFailedSignalNewToolEnabled();
    void actFailedSignalDeleteEnabled();
    void actFailedSignalDeleteAllEnabled();
    void actReducedSpeedZonesEnabled();
    void actZoneNewToolEnabled(bool val);
    void actZoneDeleteEnabled();
    void actZoneDeleteAllEnabled();
    void newActButtonEnabled();
    void cServiceEnabled(QString val);
    void cTrafficEnabled(QString val);
    //void actServiceNewEnabled();
    //void actServiceEditEnabled();
    void msg(QString text);
    void msg(QString text, QString val);
    void eFileNameEnabled(QString val);
    void eDisplayNameEnabled(QString val);
    void cDifficultyEnabled(int val);
    void eDurationEnabled();
    void eStartTimeEnabled();
    void cSeasonEnabled(int val);
    void cWeatherEnabled(int val);
    void cHornAtCrossingsEnabled(int val);
    void eORTSAICrossingHornPatternEnabled(QString val);
    void eFuelCoalEnabled(QString val);
    void sFuelCoalEnabled();
    void eFuelDieselEnabled(QString val);
    void sFuelDieselEnabled();
    void eFuelWaterEnabled(QString val);
    void sFuelWaterEnabled();
    void eHazardAnimalEnabled(QString val);
    void sHazardAnimalEnabled();
    void eHazardPeopleEnabled(QString val);
    void sHazardPeopleEnabled();
    void descriptionOpenEnabled();
    void briefingOpenEnabled();
    void eDescriptionEnabled();
    void eBriefingEnabled();
    void actEventsOpenEnabled();
    void actServiceOpenEnabled();
    void actTrafficOpenEnabled();
    void actTimetableOpenEnabled();
    void actSettingsOpenEnabled();
    void actPlayEnabled();
    void actSaveEnabled();
    
    void reloadActivityList();
    void reloadServicesList();
    void reloadTrafficsList();
    void reloadPathsList();
    void conFilesRefreshSelected();
    void actPathsRefreshListSelected();
    
signals:
    void enableTool(QString name);
    void sendMsg(QString);
    void objectSelected(GameObj* obj);
    void showActivityEventEditor();
    void showActivityServiceEditor();
    void showEvents(Activity *a);
    void showServices(Route *r);
    void showActivityTrafficEditor();
    void showTraffic(Route *r);
    void showActivityTimetableEditor();
    void showTimetable(Activity *a);
    void jumpTo(PreciseTileCoordinate* c);
    
private:
    Route *route = NULL;
    QComboBox consists;
    QComboBox speedZones;
    QComboBox failedSignals;
    QComboBox actShow;
    QComboBox conFilesShow;
    QMap<QString, QPushButton*> buttonTools;
    
    QLineEdit eDisplayName;
    QLineEdit eFileName;

    QTimeEdit eDuration;
    QTimeEdit eStartTime;
    
    QLineEdit* eHazardAnimal;
    QLineEdit* eHazardPeople;
    QLineEdit* eFuelCoal;
    QLineEdit* eFuelWater;
    QLineEdit* eFuelDiesel;
    QSlider sHazardAnimal;
    QSlider sHazardPeople;
    QSlider sFuelCoal;
    QSlider sFuelWater;
    QSlider sFuelDiesel;
    
    QComboBox cDifficulty;
    QComboBox cSeason;
    QComboBox cWeather;
    QCheckBox cHornAtCrossings;
    QLineEdit eORTSAICrossingHornPattern;

    QComboBox cService;
    QComboBox cTraffic;
    QComboBox cPath;
    
    QWidget settingsWidget;
    QPlainTextEdit eDescription;
    QPlainTextEdit eBriefing;
    
    PreciseTileCoordinate* coordinate = NULL;
    
    void reloadActivityObjectLists();
};

#endif	/* ACTIVITYTOOLS_H */

