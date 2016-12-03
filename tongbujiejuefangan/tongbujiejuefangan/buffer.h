#pragma once
#define BUFFER_SIZE 5
#define RAND_MAX 100
typedef int buffer_item;

extern int currentPosition;
int insert_item(buffer_item item);
int remote_item(buffer_item item);

