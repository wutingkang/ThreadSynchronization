// tongbujiejuefangan.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "buffer.h"

using namespace std; 

HANDLE Full;
HANDLE Empty;
HANDLE Mutex;

//��취�� #include "bufferOperate.cpp"
extern int currentPosition;
int insert_item(buffer_item item);
int remote_item(buffer_item item);

int init()
{
	currentPosition = 0;
	Mutex = CreateMutex(NULL, FALSE, NULL);
	Full = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);
	Empty = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);

	return 0;
}

//�������߳�
DWORD WINAPI producer(LPVOID lpPara)
{
	buffer_item randnum;

	while (TRUE) {
		Sleep(10 + rand() % 100);

		WaitForSingleObject(Empty, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);

		randnum = rand() % RAND_MAX;
		cout << "������" << (int)lpPara << "������һ�ݲ�Ʒ:" << randnum << endl;
		if (insert_item(randnum))
			cout << "report error condition" << endl;

		ReleaseMutex(Mutex);
		ReleaseSemaphore(Full, 1, NULL);
	}
	
	return 0;
}

//�������߳�
DWORD WINAPI comsumer(LPVOID lpPara)
{
	buffer_item randnum;

	while (TRUE) {
		Sleep(1000 + rand() % 100);

		WaitForSingleObject(Full, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);

		randnum = rand() % RAND_MAX;
		if (remote_item(randnum))
			cout << "report error condition" << endl;
		else
			cout << "������" << (int)lpPara << "������һ�ݲ�Ʒ:" << randnum << endl;

		ReleaseMutex(Mutex);
		ReleaseSemaphore(Empty, 1, NULL);
	}
	
	return 0;
}

//F:\Users\King_Tom_user_name\Desktop\�μ�\����ϵͳ\ʵ�����\tongbu\tongbujiejuefangan\Debug tongbujiejuefangan.exe 5000 3 3
int main(int argc, char *argv[]) {
	//1.Get command line arguments argc[1..2..3]
	int mianSleepTime = atoi(argv[1]), producerNum = atoi(argv[2]), comsumerNum = atoi(argv[3]);

	//2.INTIALIZE BUFFER
	init();

	//3.CREATE PRODUCER 
	HANDLE *producer_handle = new HANDLE[producerNum];
	for (int i = 0; i < producerNum; i++)
		producer_handle[i] = CreateThread(NULL, 0, producer, (LPVOID)i, 0, NULL);

	//4.CREATE CONSUMER THREAD
	HANDLE *consumer_handle = new HANDLE[comsumerNum];
	for (int i = 0; i < comsumerNum; i++)
		consumer_handle[i] = CreateThread(NULL, 0, comsumer, (LPVOID)i, 0, NULL);

	//5.SLEEP
	Sleep(5000);

	//6.EXIT
	CloseHandle(Mutex);
	CloseHandle(Full);
	CloseHandle(Empty);
	delete[]producer_handle;
	delete[]consumer_handle;

	return 0;
}
