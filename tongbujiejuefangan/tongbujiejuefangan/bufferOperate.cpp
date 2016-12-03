#include "stdafx.h"
#include "buffer.h"

buffer_item buffer[BUFFER_SIZE];
int currentPosition = 0;

//�ɹ� 0��ʧ�� - 1
int insert_item(buffer_item item) {
	if (BUFFER_SIZE > currentPosition && -1 <= currentPosition) {
		buffer[currentPosition] = item;
		currentPosition++;
		return 0;
	}
	
	return -1;
}

//�Ȱ��ն�ջ�ķ�ʽremote
int remote_item(buffer_item item) {
	if (BUFFER_SIZE >= currentPosition && 0 <= currentPosition) {
		currentPosition--;
		buffer[currentPosition] = item;
		return 0;
	}

	return -1;
}
