/*  This file is part of TSRE5.
 *
 *  TSRE5 - train sim game engine and MSTS/OR Editors. 
 *  Copyright (C) 2016 Piotr Gadecki <pgadecki@gmail.com>
 *
 *  Licensed under GNU General Public License 3.0 or later. 
 *
 *  See LICENSE.md or https://www.gnu.org/licenses/gpl.html
 */

#ifndef GLSHAPEWIDGET_H
#define	GLSHAPEWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include <QBasicTimer>
#include <math.h>

class SFile;
class Eng;
class Consist;
class GLUU;
class Camera;
class ShapeLib;
class EngLib;
class QImage;
class ShapeTextureInfo;
class ShapeHierarchyInfo;
class ContentHierarchyInfo;

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class ShapeViewerGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    ShapeViewerGLWidget(QWidget *parent = 0);
    virtual ~ShapeViewerGLWidget();
    
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    int heightForWidth(int w) const {
        return w/10;
    }
    void setCamera(Camera* cam);
    ShapeLib *currentShapeLib = NULL;
    //EngLib *currentEngLib = NULL;
    QImage *screenShot = NULL;
    void setMode(QString n);
    void resetRot();
    void resetCamRoster(float profile);
    void getImg();
    void setBackgroundGlColor(float r, float g, float b);
    void fillCurrentShapeHierarchyInfo(ShapeHierarchyInfo *info);
    void fillCurrentShapeTextureInfo(QHash<int, ShapeTextureInfo*> &list);
    void fillCurrentContentHierarchyInfo(QVector<ContentHierarchyInfo*> &list);
public slots:
    void showEng(QString path, QString name);
    void showEng(Eng *e);
    void showEngSet(int id);
    void showCon(int id);
    void showConSimple(Consist *currentCon);
    void showConSimple(int id);
    void showCon(int aid, int id);
    void showShape(QString path, QString texPath, SFile **currentSFile = NULL);
    void showShape(SFile *currentSFile = NULL);
    void cleanup();
    void flipConSelected();
    void leftConSelected();
    void rightConSelected();
    void deleteConSelected();
    void copyUnitConSelected();
    void pasteUnitConSelected();
    
signals:
    void selected(int id);
    void refreshItem();
    
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void showContextMenu(const QPoint & point);
    void keyPressEvent(QKeyEvent * event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent * event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private:
    void setupVertexAttribs();
    QBasicTimer timer;
    unsigned long long int lastTime;
    unsigned long long int timeNow;
    bool m_core;
    int m_xRot;
    int m_yRot;
    int m_zRot;
    int fps;
    QPoint m_lastPos;
    GLUU* gluu;
    int mousex, mousey;
    bool mousePressed = false;
    bool mouseRPressed = false;
    bool mouseLPressed = false;
    SFile* sFile = NULL;
    Eng* eng = NULL;
    Consist* con = NULL;
    Camera* camera = NULL;
    int renderItem = 0;
    QString mode = "";
    float rotY = M_PI;
    float rotZ = 0;
    bool selection = false;
    bool getImage = false;
    float backgroundGlColor[3];
    bool cameraInit = false;
    
    QMap<QString, QAction*> defaultMenuActions;
};

#endif	/* GLSHAPEWIDGET_H */

