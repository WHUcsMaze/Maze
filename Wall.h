#ifndef WALL_H
#define WALL_H

#include "Obj.h"
#include "Point.h"
#include "Walls.h"

class Wall:public Obj
{
	private:
	Point loc;//ǽ������ 
	Walls type;//ǽ������ 
	public:
	wall(Qwidget *parent,QString pic,Point loc);
	Walls getType();
		
};

#endif

