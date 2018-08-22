#pragma once

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* head;
Node* tail;

void initHeadTailNode(); // head와 tail노드의 초기값 지정
void freeNode(); // 노드에 할당해준 메모리를 free()

void insertNode();
void insertHeadNode();
void insertTailNode();
void insertAnyNode();

void deleteNode();
void deleteHeadNode();
void deleteTailNode();
void deleteAnyNode();

void printNode();

void sortNode();
void reSortNode();