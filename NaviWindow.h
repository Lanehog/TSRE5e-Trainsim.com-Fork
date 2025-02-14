/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef NAVIWINDOW_H
#define	NAVIWINDOW_H

#include <QtWidgets>
#include <QMap>

class PreciseTileCoordinate;
class IghCoordinate;
class LatitudeLongitudeCoordinate;
class Coords;

class NaviWindow : public QWidget {
    Q_OBJECT
public:
    NaviWindow(QWidget* parent);
    virtual ~NaviWindow();
    
public slots:
    void jumpTileSelected();  
    void naviInfo(int all, int hidden);
    void posInfo(PreciseTileCoordinate* coords);
    void pointerInfo(float* coords);
    void latLonChanged(QString val);
    void xyChanged(QString val);
    void mkrList(QMap<QString, Coords*> list);
    void mkrFilesSelected(QString item);
    void mkrListSelected(QString item);
    void reloadMkrLists();
//    void camRot(QString camrot);


    void recStatus(QString statName, QString statVal );       
    
    
signals:
    void jumpTo(PreciseTileCoordinate*);
    void sendMsg(QString name);
    void sendMsg(QString name, bool val);
    void sendMsg(QString name, int val);
    void sendMsg(QString name, float val);
    void sendMsg(QString name, QString val);
    void windowClosed();
    
protected:
    void hideEvent(QHideEvent *e);
    
private:
    QComboBox markerFiles;
    QComboBox markerList;
    QLineEdit txBox;
    QLineEdit tyBox;
    QLineEdit latBox;
    QLineEdit lonBox;
    QLineEdit xBox;
    QLineEdit yBox;
    QLineEdit zBox;
    QLineEdit pxBox;
    QLineEdit pyBox;
    QLineEdit pyBoxx;    
    QLineEdit pzBox;
//    QLineEdit pRot;
    QLabel tileInfo;
    QString lastEdit = "";


    /// EFO New
    QLineEdit status1;
    QLineEdit status2;
    QLineEdit status3;
    QLineEdit status4;        
    ///
    
    int lastTX = 0; 
    int lastTZ = 0;
    int lastX = 0; 
    int lastY = 0;
    int lastZ = 0;
    int objCount = 0;
    int objHidden = 0;
    
    IghCoordinate* igh = NULL;
    LatitudeLongitudeCoordinate* latlon = NULL;
    PreciseTileCoordinate* aCoords = NULL;
    QMap<QString, Coords*> mkrFiles;
    QMap<QString, LatitudeLongitudeCoordinate*> mkrPlaces;
    QString jumpType = "";
};

#endif	/* NAVIWINDOW_H */

