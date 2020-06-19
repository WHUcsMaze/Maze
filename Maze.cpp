#include "Maze.h"
#include <QWidget>
using namespace std;
void Maze::setSize(Point size)
{
	this->size=size;
}
Point Maze::getStartLoc()
{
	return this->startLoc;
}
Point Maze::getTargetLoc()
{
	return this->targetLoc;
}
void Maze::makeMaze(int lvl)
{
	srand(time(NULL));
	int x=size.getX();
	int y=size.getY();
	connect.reserve(y);
	walls.reserve(y);
	vector<Point>tot;
	tot.reserve(x*y);
	bcj isconnect(x*y);
	for (int i=0;i<y;++i)
	{
		connect[i].reserve(x);
		walls[i].reserve(x);
		for (int j=0;j<x;++j)
		{
			Point t(i,j);
			tot.push_back(t);
		}
	}
    random_shuffle(tot.begin(),tot.end());
	vector<int>rd(4);
	for (int i=0;i<4;++i)
	{
		rd.push_back(i);
	}
	for (std::vector<Point>::iterator i = tot.begin(); i != tot.end(); ++i)
	{
		int id=i->getX()+i->getY()*x;
        random_shuffle(rd.begin(),rd.end());
		for (int j=0;j<3;++j)
		{
			if(rd[j]==0)
			{
				if(i->getY()==0)continue;
				if(isconnect.find(id)==isconnect.find(id-x))continue;
				connect[i->getY()][i->getX()].up=true;
				connect[i->getY()-1][i->getX()].down=true;
				isconnect.add(id,id-x);
				break;
			}
			if(rd[j]==1)
			{
				if(i->getY()==y-1)continue;
				if(isconnect.find(id)==isconnect.find(id+x))continue;
				connect[i->getY()][i->getX()].down=true;
				connect[i->getY()+1][i->getX()].up=true;
				isconnect.add(id,id+x);
				break;
			}
			if(rd[j]==2)
			{
				if(i->getX()==0)continue;
				if(isconnect.find(id)==isconnect.find(id-1))continue;
				connect[i->getY()][i->getX()].left=true;
				connect[i->getY()][i->getX()-1].right=true;
				isconnect.add(id,id-1);
				break;
			}
			if(rd[j]==3)
			{
				if(i->getX()==x-1)continue;
				if(isconnect.find(id)==isconnect.find(id+1))continue;
				connect[i->getY()][i->getX()].right=true;
				connect[i->getY()][i->getX()+1].left=true;
				isconnect.add(id,id+1);
				break;
			}
		}
	}
	for(int i=0;i<y;++i)
	{
		for(int j=0;j<x;++j)
		{
			int ck=0;
			if(!connect[i][j].up)ck+=1;
			if(!connect[i][j].down)ck+=2;
			if(!connect[i][j].left)ck+=4;
			if(!connect[i][j].right)ck+=8;
            if(ck==0)walls[i][j].type="all";
			if(ck==1)walls[i][j].type="up";
			if(ck==2)walls[i][j].type="down";
			if(ck==3)walls[i][j].type="updown";
			if(ck==4)walls[i][j].type="left";
			if(ck==5)walls[i][j].type="upleft";
			if(ck==6)walls[i][j].type="downleft";
			if(ck==7)walls[i][j].type="noright";
			if(ck==8)walls[i][j].type="right";
			if(ck==9)walls[i][j].type="upright";
			if(ck==10)walls[i][j].type="downright";
			if(ck==11)walls[i][j].type="noleft";
			if(ck==12)walls[i][j].type="leftright";
			if(ck==13)walls[i][j].type="noleft";
			if(ck==14)walls[i][j].type="noup";

		}
	}
}
Maze::Maze(QString pic,Point size, Point startLoc, Point targetLoc,int lvl, QWidget *parent)
{

	this->startLoc=startLoc;
	this->targetLoc=targetLoc;
	this->lvl=lvl;
	this->size=size;

}
