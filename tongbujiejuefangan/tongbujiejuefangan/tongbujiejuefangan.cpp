// tongbujiejuefangan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "buffer.h"

using namespace std; 

HANDLE full, empty;
HANDLE mutex = CreateMutex(NULL, FALSE, NULL);

//想办法： #include "bufferOperate.cpp"
extern int currentPosition;
int insert_item(buffer_item item);
int remote_item(buffer_item *item);

//do what?
int init()
{
	currentPosition = 0;
	return 0;
}



int main(int argc, char *argv[]) {
	/*Get command line arguments argc[1..2..3]*/

	/*
		2.intialize buffer
		3.create producer thread
		4.create consumer thread
		5.sleep
		6.exit*/
	init();
	

	printf("hello\n %d", currentPosition);
	return 0;
}
