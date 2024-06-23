﻿#ifndef SimCenterEventAppSelection_H
#define SimCenterEventAppSelection_H

/* *****************************************************************************
Copyright (c) 2016-2017, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS 
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, 
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written by: fmk

#include "SimCenterAppWidget.h"
#include <QList>
#include "SectionTitle.h"

class QStackedWidget;
class QComboBox;

class SimCenterEventAppSelection : public  SimCenterAppWidget
{
    Q_OBJECT

public:
   explicit SimCenterEventAppSelection(QString label, QString jsonkeyword, QString eventType, QWidget *parent);
    ~SimCenterEventAppSelection();

    bool outputAppDataToJSON(QJsonObject &jsonObject);
    bool inputAppDataFromJSON(QJsonObject &jsonObject);
    bool outputToJSON(QJsonObject &rvObject);
    bool inputFromJSON(QJsonObject &rvObject);
    bool copyFiles(QString &destName);

    void clear(void);
    void clearSelections();
    bool addComponent(QString comboBoxText, QString appNameText, SimCenterAppWidget *);
  
    SimCenterAppWidget *getComponent(QString text);
    SimCenterAppWidget *getCurrentSelection(void);
    QString getCurrentSelectionName(void);
    bool selectComponent(const QString text);
    bool outputCitation(QJsonObject &jsonObject);

    void removeItem(QString itemName);
    QString getComboName(int index);
    QString getCurrentComboName(void);
    int count();
    void hideHeader();

		     
public slots:
    void selectionChangedSlot(const QString &);
    void setCurrentlyViewable(bool);
    void setSelectionsActive(bool);

signals:
  void selectionChangedSignal(const QString &);
  void typeEVT(QString type);
  
protected:


private:
    virtual bool displayComponent(QString text);
    void initializeWidget(QString label);


    QStackedWidget* theStackedWidget;
    QComboBox* theSelectionCombo;

    int currentIndex;
    SimCenterAppWidget *theCurrentSelection;

    QList<QString> theComboNames;
    QList<QString> theApplicationNames;
    QList<SimCenterAppWidget *> theComponents;
  
    QString jsonKeyword; // application type that appears in json
    QString assetType;
    QString eventType;

    bool viewableStatus;

    SectionTitle *selectionText;
};

#endif // SimCenterEventAppSelection_H
