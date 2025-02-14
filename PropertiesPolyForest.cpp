/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#include "PropertiesPolyForest.h"
#include "WorldObj.h"
#include "PolyForestObj.h"
#include "Game.h"

PropertiesPolyForest::PropertiesPolyForest() {
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setSpacing(2);
    vbox->setContentsMargins(0,1,1,1);
    infoLabel = new QLabel("PolyForest:");
    infoLabel->setStyleSheet(QString("QLabel { color : ")+Game::StyleMainLabel+"; }");
    infoLabel->setContentsMargins(3,0,0,0);
    
   
    vbox->addWidget(infoLabel);
    QFormLayout *vlistt = new QFormLayout;
    vlistt->setSpacing(2);
    vlistt->setContentsMargins(3,0,3,0);
    this->tX.setDisabled(true);
    this->tY.setDisabled(true);
    vlistt->addRow("Tile X:",&this->tX);
    vlistt->addRow("Tile Z:",&this->tY);
    vbox->addItem(vlistt);
    
    QLabel * label = new QLabel("Texture:");
    label->setStyleSheet(QString("QLabel { color : ")+Game::StyleMainLabel+"; }");
    label->setContentsMargins(3,0,0,0);
    vbox->addWidget(label);
    QLabel * label1 = new QLabel("FileName:");
    label1->setContentsMargins(3,0,0,0);
    vbox->addWidget(label1);
    this->fileName.setDisabled(true);
    this->fileName.setAlignment(Qt::AlignCenter);
    vbox->addWidget(&this->fileName);
    QPushButton *copyF = new QPushButton("Copy FileName", this);
    vbox->addWidget(copyF);
    
    QLabel * label12 = new QLabel("Size:");
    label12->setStyleSheet(QString("QLabel { color : ")+Game::StyleMainLabel+"; }");
    label12->setContentsMargins(3,0,0,0);
    vbox->addWidget(label12);
    QFormLayout *vlist = new QFormLayout;
    vlist->setSpacing(2);
    vlist->setContentsMargins(3,0,3,0);
    vlist->addRow("Width:",&this->sizeX);
    vlist->addRow("Height:",&this->sizeY);
    QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1000, 2, this); 
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    sizeX.setValidator(doubleValidator);
    QObject::connect(&sizeX, SIGNAL(textEdited(QString)),
                      this, SLOT(sizeEnabled(QString)));
    sizeY.setValidator(doubleValidator);
    QObject::connect(&sizeY, SIGNAL(textEdited(QString)),
                      this, SLOT(sizeEnabled(QString)));
    
    vlist->addRow("Population:",&this->population);
    population.setValidator( new QIntValidator(0, 1000000, this) );
    QObject::connect(&population, SIGNAL(textEdited(QString)),
                      this, SLOT(populationEnabled(QString)));
    
    vlist->addRow("Density/KM:",&this->densitykm);
    densitykm.setValidator( new QIntValidator(0, 1000000, this) );
    QObject::connect(&densitykm, SIGNAL(textEdited(QString)),
                      this, SLOT(densitykmEnabled(QString)));
    vbox->addItem(vlist);
    
    label = new QLabel("Position & Rotation:");
    label->setStyleSheet(QString("QLabel { color : ")+Game::StyleMainLabel+"; }");
    label->setContentsMargins(3,0,0,0);
    vbox->addWidget(label);
    vlist = new QFormLayout;
    vlist->setSpacing(2);
    vlist->setContentsMargins(3,0,3,0);
    vlist->addRow("X:",&this->posX);
    vlist->addRow("Y:",&this->posY);
    vlist->addRow("Z:",&this->posZ);
    this->quat.setDisabled(true);
    this->quat.setAlignment(Qt::AlignCenter);
    vlist->addRow("Rot:",&this->quat);
    vbox->addItem(vlist);
    QGridLayout *posRotList = new QGridLayout;
    posRotList->setSpacing(2);
    posRotList->setContentsMargins(0,0,0,0);    

    QPushButton *copyPos = new QPushButton("Copy Pos", this);
    QObject::connect(copyPos, SIGNAL(released()),
                      this, SLOT(copyPEnabled()));
    QPushButton *pastePos = new QPushButton("Paste", this);
    QObject::connect(pastePos, SIGNAL(released()),
                      this, SLOT(pastePEnabled()));
    QPushButton *copyQrot = new QPushButton("Copy Rot", this);
    QObject::connect(copyQrot, SIGNAL(released()),
                      this, SLOT(copyREnabled()));
    QPushButton *pasteQrot = new QPushButton("Paste", this);
    QObject::connect(pasteQrot, SIGNAL(released()),
                      this, SLOT(pasteREnabled()));
    QPushButton *copyPosRot = new QPushButton("Copy Pos+Rot", this);
    QObject::connect(copyPosRot, SIGNAL(released()),
                      this, SLOT(copyPREnabled()));
    QPushButton *pastePosRot = new QPushButton("Paste", this);
    QObject::connect(pastePosRot, SIGNAL(released()),
                      this, SLOT(pastePREnabled()));
    QPushButton *resetQrot = new QPushButton("Reset Rot", this);
    QObject::connect(resetQrot, SIGNAL(released()),
                      this, SLOT(resetRotEnabled()));
    QPushButton *qRot90 = new QPushButton("Rot Y 90°", this);
    QObject::connect(qRot90, SIGNAL(released()),
                      this, SLOT(rotYEnabled()));
    QPushButton *transform = new QPushButton("Transform ...", this);
    QObject::connect(transform, SIGNAL(released()),
                      this, SLOT(transformEnabled()));
    
    posRotList->addWidget(copyPos, 0, 0);
    posRotList->addWidget(pastePos, 0, 1);
    posRotList->addWidget(copyQrot, 1, 0);
    posRotList->addWidget(pasteQrot, 1, 1);
    posRotList->addWidget(copyPosRot, 2, 0);
    posRotList->addWidget(pastePosRot, 2, 1);
    posRotList->addWidget(resetQrot, 3, 0);
    posRotList->addWidget(qRot90, 3, 1);
    posRotList->addWidget(transform, 4, 0, 1, 2);
    vbox->addItem(posRotList);
    
    label = new QLabel("Detail Level:");
    label->setStyleSheet(QString("QLabel { color : ")+Game::StyleMainLabel+"; }");
    label->setContentsMargins(3,0,0,0);
    vbox->addWidget(label);
    this->defaultDetailLevel.setDisabled(true);
    this->defaultDetailLevel.setAlignment(Qt::AlignCenter);
    this->enableCustomDetailLevel.setText("Custom");
    QCheckBox* defaultDetailLevelLabel = new QCheckBox("Default", this);
    defaultDetailLevelLabel->setDisabled(true);
    defaultDetailLevelLabel->setChecked(true);
    QObject::connect(&enableCustomDetailLevel, SIGNAL(stateChanged(int)),
                      this, SLOT(enableCustomDetailLevelEnabled(int)));
    this->customDetailLevel.setDisabled(true);
    this->customDetailLevel.setAlignment(Qt::AlignCenter);
    QObject::connect(&customDetailLevel, SIGNAL(textEdited(QString)),
                      this, SLOT(customDetailLevelEdited(QString)));
    QGridLayout *detailLevelView = new QGridLayout;
    detailLevelView->setSpacing(2);
    detailLevelView->setContentsMargins(0,0,0,0);    
    detailLevelView->addWidget(defaultDetailLevelLabel, 0, 0);
    detailLevelView->addWidget(&defaultDetailLevel, 0, 1);
    detailLevelView->addWidget(&enableCustomDetailLevel, 1, 0);
    detailLevelView->addWidget(&customDetailLevel, 1, 1);
    vbox->addItem(detailLevelView);
    
    label = new QLabel("Flags:");
    label->setStyleSheet(QString("QLabel { color : ")+Game::StyleMainLabel+"; }");
    label->setContentsMargins(3,0,0,0);
    vbox->addWidget(label);
    this->flags.setDisabled(true);
    this->flags.setAlignment(Qt::AlignCenter);
    vbox->addWidget(&this->flags);
    QGridLayout *flagslView = new QGridLayout;
    flagslView->setSpacing(2);
    flagslView->setContentsMargins(0,0,0,0);    
    QPushButton *copyFlags = new QPushButton("Copy Flags", this);
    QObject::connect(copyFlags, SIGNAL(released()),
                      this, SLOT(copyFEnabled()));
    QPushButton *pasteFlags = new QPushButton("Paste", this);
    QObject::connect(pasteFlags, SIGNAL(released()),
                      this, SLOT(pasteFEnabled()));
    flagslView->addWidget(copyFlags,0,0);
    flagslView->addWidget(pasteFlags,0,1);
    vbox->addItem(flagslView);
    
    vbox->addStretch(1);
    this->setLayout(vbox);
}

PropertiesPolyForest::~PropertiesPolyForest() {
}

void PropertiesPolyForest::showObj(GameObj* obj){
    if(obj == NULL){
        infoLabel->setText("NULL");
        return;
    }
    worldObj = (WorldObj*)obj;
    polyForestObj = (PolyForestObj*)obj;
    PolyForestObj* tobj = (PolyForestObj*)obj;
        
    this->infoLabel->setText("Object: "+polyForestObj->type);
    this->fileName.setText(tobj->treeTexture);
        
    this->tX.setText(QString::number(polyForestObj->x, 10));
    this->tY.setText(QString::number(-polyForestObj->y, 10));
    this->sizeX.setText(QString::number(tobj->areaX, 'G', 4));
    this->sizeY.setText(QString::number(tobj->areaZ, 'G', 4));
    this->population.setText(QString::number((int)tobj->population, 10));
    this->densitykm.setText(QString::number((int)(tobj->population*(1000000.0/(tobj->areaX*tobj->areaZ))), 10));
    this->posX.setText(QString::number(polyForestObj->position[0], 'G', 6));
    this->posY.setText(QString::number(polyForestObj->position[1], 'G', 6));
    this->posZ.setText(QString::number(-polyForestObj->position[2], 'G', 6));
    this->quat.setText(
            QString::number(polyForestObj->qDirection[0], 'G', 4) + " " +
            QString::number(polyForestObj->qDirection[1], 'G', 4) + " " +
            QString::number(-polyForestObj->qDirection[2], 'G', 4) + " " +
            QString::number(polyForestObj->qDirection[3], 'G', 4)
            );
}

void PropertiesPolyForest::sizeEnabled(QString val){
    if(polyForestObj == NULL)
        return;
    bool ok;
    sizeX.text().toFloat(&ok);
    if(!ok) return;
    if(sizeX.text().toFloat() <= 0) return;
    sizeY.text().toFloat(&ok);
    if(!ok) return;
    if(sizeY.text().toFloat() <= 0) return;
    Undo::SinglePushWorldObjData(worldObj);
    polyForestObj->set("areaX", sizeX.text().toFloat());
    polyForestObj->set("areaZ", sizeY.text().toFloat());
    polyForestObj->setModified();
    polyForestObj->deleteVBO();
}

void PropertiesPolyForest::populationEnabled(QString val){
    if(polyForestObj == NULL)
        return;
    Undo::SinglePushWorldObjData(worldObj);
    polyForestObj->set("population", population.text().toLongLong());
    this->densitykm.setText(QString::number((int)(polyForestObj->population*(1000000.0/(polyForestObj->areaX*polyForestObj->areaZ))), 10));
    polyForestObj->setModified();
    polyForestObj->deleteVBO();
}

void PropertiesPolyForest::densitykmEnabled(QString val){
    if(polyForestObj == NULL)
        return;
    Undo::SinglePushWorldObjData(worldObj);
    this->population.setText(QString::number((int)(densitykm.text().toUInt()/(1000000.0/(polyForestObj->areaX*polyForestObj->areaZ))), 10));
    polyForestObj->set("population", population.text().toLongLong());
    polyForestObj->setModified();
    polyForestObj->deleteVBO();
}

bool PropertiesPolyForest::support(GameObj* obj){
    if(obj == NULL)
        return false;
    if(obj->typeObj != GameObj::worldobj)
        return false;
    if(((WorldObj*)obj)->type == "polyForest")
        return true;
    return false;
}

void PropertiesPolyForest::enableCustomDetailLevelEnabled(int val){
    if(worldObj == NULL)
        return;
    PolyForestObj* polyForestObj = (PolyForestObj*) worldObj;
    Undo::SinglePushWorldObjData(worldObj);
    if(val == 2){
        customDetailLevel.setEnabled(true);
        customDetailLevel.setText("0");
        polyForestObj->setCustomDetailLevel(0);
    } else {
        customDetailLevel.setEnabled(false);
        customDetailLevel.setText("");
        polyForestObj->setCustomDetailLevel(-1);
    }
}

void PropertiesPolyForest::customDetailLevelEdited(QString val){
    if(worldObj == NULL)
        return;
    PolyForestObj* polyForestObj = (PolyForestObj*) worldObj;
    bool ok = false;
    int level = val.toInt(&ok);

    if(ok){
        Undo::SinglePushWorldObjData(worldObj);
        polyForestObj->setCustomDetailLevel(level);
    }
}