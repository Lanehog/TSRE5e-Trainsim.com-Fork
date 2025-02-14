/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef SERVICE_H
#define	SERVICE_H

#include <QString>
#include <QVector>

class GLUU;
class Path;
class Consist;

class Service {
public:
    struct StationStop{
        int platformStartID;
        float distanceDownPath;
        int skipCount;
    };
    
    QString displayName;
    QString name;
    QString nameId;
    QString path;
    QString pathid;  
    QString trainConfig;
    QString pathId;
    float maxWheelAcceleration;
    float efficiency;
    float startingSpeed;
    float endingSpeed;
    float startInWorld;
    float endInWorld;
    QVector<StationStop> stationStop;
    int loaded = -1;
    int ref = 0;
    
    Service(QString p, QString n, bool nowe = false);
    Service(const Service& orig);
    virtual ~Service();
    bool isModified();
    void setNameId(QString val);
    void setNewPath(QString pathName);
    void disableStationStop(int count);
    void enableStationStop(int count);
    void setDisplayName(QString val);
    void setEfficiency(float val);
    void setStartSpeed(float val);
    void setEndSpeed(float val);
    void setTrainConfig(QString val);
    void load();
    void save();
    Consist *getConsistPointer();
    void updateSim(float *playerT, float deltaTime);
    void render(GLUU* gluu, float* playerT, int selectionColor);
    void initToPlay();
private:
    bool modified = false;
    int serial = -1;
    Path *pathPointer = NULL;
    Consist *conPointer = NULL;
};

#endif	/* SERVICE_H */

