/***************************************************************************
                                arrow.h
                               ---------
    begin                : Sun Nov 23 2003
    copyright            : (C) 2003 by Michael Margraf
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

#ifndef ARROW_H
#define ARROW_H

#include "painting.h"

#include <QPen>


class Arrow : public Painting  {
public:
  Arrow();
  virtual ~Arrow() {}

  QRectF boundingRect() const;

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
  void getCenter(int&, int&);
  void setCenter(int, int, bool relative=false);

  Painting* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  bool load(const QString&);
  QString save();
  QString saveCpp();
  QString saveJSON();
  void MouseMoving(SchematicView*, int, int, int, int, SchematicView*, int, int, bool);
  bool MousePressing();
  bool getSelected(float, float, float);
  void Bounding(int&, int&, int&, int&);
  bool resizeTouched(float, float, float);
  void MouseResizeMoving(int, int, SchematicView*);

  void rotate();
  void mirrorX();
  void mirrorY();
  bool Dialog();

  void calcArrowHead();

  QPen   Pen;
  int    Style;
  double Height, Width;  // size of the arrow head
  double Length, beta;
  int    xp1, yp1, xp2, yp2;   // coordinates to paint the arrow head

  int ex, ey; // used to track position of mouse move event
};

#endif
