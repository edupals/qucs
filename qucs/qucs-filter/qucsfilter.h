/***************************************************************************
                                qucsfilter.h
                             -------------------
    begin                : Wed Mar 02 2005
    copyright            : (C) 2005 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QUCSFILTER_H
#define QUCSFILTER_H

#include <qdialog.h>

class QGridLayout;
class QComboBox;
class QLineEdit;
class QLabel;
class QIntValidator;
class QDoubleValidator;

/**
  *@author Michael Margraf
  */

struct tQucsSettings {
  int x, y;      // position of main window
  QFont font;
  QString LangDir;
  QString BitmapDir;
};

extern struct tQucsSettings QucsSettings;

class QucsFilter : public QDialog
{
  Q_OBJECT
public:
  QucsFilter();
 ~QucsFilter();

private slots:
  void slotQuit();
  void slotHelpIntro();
  void slotHelpAbout();
  void slotHelpAboutQt();
  void slotCalculate();
  void slotTypeChanged(int);
  void slotClassChanged(int);
  void slotShowResult();

private:
  int ResultState;

  QGridLayout *gbox;
  QComboBox *ComboType, *ComboClass, *ComboCorner, *ComboStop;
  QLineEdit *EditOrder, *EditCorner, *EditStop, *EditRipple, *EditImpedance;
  QLabel *LabelRipple, *Label_dB, *LabelStop, *LabelResult;
  QIntValidator *IntVal;
  QDoubleValidator *DoubleVal;
};

#endif
