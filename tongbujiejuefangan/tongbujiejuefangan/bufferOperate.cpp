#include "stdafx.h"
#include "buffer.h"

buffer_item buffer[BUFFER_SIZE];
int currentPosition = 0;

//成功 0；失败 - 1
int insert_item(buffer_item item) {
	if (BUFFER_SIZE > currentPosition && -1 <= currentPosition) {
		buffer[currentPosition] = item;
		currentPosition++;
		return 0;
	}
	
	return -1;
}

//先按照堆栈的方式remote
int remote_item(buffer_item item) {
	if (BUFFER_SIZE >= currentPosition && 0 <= currentPosition) {
		currentPosition--;
		buffer[currentPosition] = item;
		return 0;
	}

	return -1;
}
