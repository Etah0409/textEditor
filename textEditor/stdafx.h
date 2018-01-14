// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#ifndef _TEXT_EDITOR_
#define _TEXT_EDITOR_
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include <ostream>
using namespace std;

class Link {
public:
	char element[100];
	int index;
	Link* next;
	Link* previous;
	~Link(){
	}
	Link(char s[100], int i, Link* nex = NULL, Link* pre = NULL) {
		strcpy_s(element, s);
		index = i;
		next = nex;  previous = pre;
	}
	Link(char s[100], Link* nex = NULL, Link* pre = NULL) {
		strcpy_s(element, s);
		index = 0;
		next = nex;  previous = pre;
	}
	Link(Link* nex = NULL, Link* pre = NULL) {
		next = nex;  previous = pre;  index = 0;
	}
	int getSize() {
		int i;
		for (i = 0; element[i] != '\0'; i++);
		return i;
	}
};

class LList {
private:
	int cnt;
	int totalchar;
	Link* head;
	Link* tail;
public:
	Link* curr;
	LList() {
		cnt = totalchar = 0;
		curr = head = tail = new Link;
	}
	~LList() {
	}
	void printList();
	void printCharsAndLines() {
		cout << "characters:" << totalchar << " lines:" << cnt << endl;
	}
	int getSize() const {
		return cnt;
	}
	void getValue();
	void insert(char it[100]);
	void append(char it[100]);
	void moveCurr(const int& it);
	void deleteCurr();
	void replaceCurr(char it[100]);
	void firstCurr() {
		curr = head->next;
	}
	void nextCurr() {
		curr = curr->next;
	}
	void tailCurr() {
		curr = tail;
	}
	void preCurr() {
		curr = curr->previous;
	}
	void replaceString(char it[20], char s[20]);
	void checkString(char it[20]);
};

class textEditor {
private:
	LList textBuffer;
	void goToSureLine() {
		int line; 
		cout << "input the number of the line:";
		cin >> line;
		textBuffer.moveCurr(line);
	}
	void insertLine() {
		char s[100];
		cout << "input the line you want to add:";
		getchar();
		gets_s(s);
		textBuffer.insert(s);
	}
	void replaceCurrentLine() {
		char s[100];
		cout << "input the line you want to replace:";
		getchar();
		gets_s(s);
		textBuffer.replaceCurr(s);
	}
	void replaceString() {
		char it[20], s[20];
		cout << "input the resource string:";
		cin >> it; 
		cout << "input the replace string:";
		getchar();
		gets_s(s);
		textBuffer.replaceString(it, s);
	}
	void checkString() {
		char it[20];
		cout << "input the string you want to check:";
		getchar();
		gets_s(it);
		textBuffer.checkString(it);
	}
public:
	void run();
};



#endif


// TODO: 在此处引用程序需要的其他头文件
