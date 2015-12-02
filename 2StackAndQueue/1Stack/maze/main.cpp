#include "mhead.h"
#include "Stack.h"
#include "Maze.h"

Block maze_matrix[10][10];
SqStack maze_path = NULL;
int main(int argc, char const *argv[])
{


	
	maze_path = new Stack;
	InitStack(maze_path);
	InitMaze(maze_matrix);	

	if(Solution())
	{
		cout<<"we solved the maze!\n";
		Show_Stack(maze_path);
	}
	else 
		cout<<"it is bad.......\n";
	return 0;
}