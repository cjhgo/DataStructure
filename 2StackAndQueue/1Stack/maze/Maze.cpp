#include "mhead.h"
#include "Maze.h"
#include "Stack.h"

#include <fstream>
ifstream data;

extern Block maze_matrix[10][10];
extern SqStack maze_path;
void InitMaze(Block maze_matrix[10][10])
{
	int row = 9;
	int col = 9;
	data.open("data.txt",ios::in);
	for(int i = 1;i < row;i++)
		for(int j = 1;j < col;j++)
		{
			cout<<"can bolck at row "<<i<<"&col "<<j<<"be passed,?,1 for yes,0 for no\n";
			int temp = -1;
			// cin>>temp;
			data>>temp;
			if(1 == temp)
			{
				maze_matrix[i][j].pass = true;
			}
		}
	data.close();
}
// void ElemType_to_Block(ElemType e,Block& block)
// {
// 	int row = e.row;
// 	int col = e.col;
// 	block = maze_matrix[row][col];//这是一个赋值,并不能改变maze_matrix
// }

void FootPrint(ElemType e)
{
	// Block block;
	// ElemType_to_Block(e,block);
	// block.foot = true;
	int row = e.row;
	int col = e.col;
	maze_matrix[row][col].foot = true;
}
void MarkPrint(ElemType e)
{
	// Block block;
	// ElemType_to_Block(e,block);
	// block.dead = true;
	int row = e.row;
	int col = e.col;
	maze_matrix[row][col].dead = true;
}
void NextPos(ElemType& e,int direction)
{
	ElemType temp;
	Stack_Top(maze_path,temp);
	switch(direction)
	{
		case 1: e.col = temp.col + 1;e.row = temp.row;break;
		case 2:	e.row = temp.row + 1;e.col = temp.col;break;
		case 3:	e.col = temp.col - 1;e.row = temp.row;break;
		case 4:	e.row = temp.row - 1;e.col = temp.col;break;
	}
}
bool Passable(ElemType curpos)
{
	int row = curpos.row;
	int col = curpos.col;
	Block curblock = maze_matrix[row][col];
	if(curblock.pass == true)
	{
		if(curblock.foot || curblock.dead)
			return false;
		else
			return true;
	}
	else 
		return false;
}

bool Solution()
{
	int curstep = 1;
	ElemType curpos;
	curpos.row = 1;
	curpos.col = 1;

	do
	{
		if(Passable(curpos))
		{
			
			FootPrint(curpos);

			curpos.di = 1;
			curpos.ord = curstep;
			Stack_Push(maze_path,curpos);

			if(curpos.row == 8 && curpos.col == 8)
				return true;
			NextPos(curpos,1);
			curstep++;
		}
		else
		{	
			if(!Stack_Empty(maze_path))
			{
				ElemType e;
				Stack_Pop(maze_path,e);
				while(e.di == 4 && !Stack_Empty(maze_path))
				{
					MarkPrint(e);
					Stack_Pop(maze_path,e);
				}
				if(e.di < 4)
				{
					e.di++;
					Stack_Push(maze_path,e);
					NextPos(curpos,e.di);
				}

			}
		}
		/*cout for debug
		*Show_Stack(maze_path);
		*cout<<"#############"<<endl;
		*Show_ElemType(curpos);
		*cout<<"---------------"<<endl<<endl;
		*/
	}
	while(!Stack_Empty(maze_path));
	return false;
}

