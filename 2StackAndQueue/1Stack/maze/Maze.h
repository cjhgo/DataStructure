#ifndef MAZE_H
#define MAZE_H

struct Block
{
	FLAG pass = false;
	FLAG foot = false;
	FLAG dead = false;
};


void InitMaze(Block maze_matrix[10][10]);
void FootPrint(ElemType block);
void MarkPrint(ElemType block);
void NextPos(ElemType& e,int direction);
bool Passable(ElemType curpos);
bool Solution();
#endif