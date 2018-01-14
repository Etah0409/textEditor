#include "stdafx.h"
#include <assert.h>

void LList::insert(char it[100]) {
	Link* temp = new Link(it, curr->next, curr);
	int i = 0;
	curr->next = temp;
	if (curr == tail)
		tail = temp;
	else
	curr->next->next->previous = curr->next;
	Link* p = head;
	while (p != NULL) {
		p->index = i;
		i++;
		p = p->next;
	}//change the index
	cnt++;
	for (i = 0; it[i] != '\0'; i++);
	totalchar += i;
	delete p;
}

void LList::getValue() {
	assert(("No value", curr != NULL));
	if (curr == head) cout << "you are in the head of the text." << endl;
	else cout << curr->element << endl;
}

void LList::printList() {
	Link* p = head->next;
	assert(("No value", p != NULL));
	while (p != NULL) {
		cout << p->element;
		p = p->next;
		cout << endl;
	}
}

void LList::append(char it[100]) {
	tail = tail->next = new Link(it, tail->index + 1, NULL, tail);
	cnt++;
	totalchar += tail->getSize();
}

void LList::moveCurr(const int& it) {
	curr = head;
	for (int i = 0; i < it; i++) {
		curr = curr->next;
	}
}

void LList::deleteCurr() {
	assert(("No value", head->next != NULL && curr != head));
	totalchar -= curr->getSize();
	Link* temp = curr->next;
	curr->previous->next = curr->next;
	if (curr != tail)  
	curr->next->previous = curr->previous;
	curr->~Link();
	if (temp == NULL) curr = tail;
	else
		curr = temp;
}

void LList::replaceCurr(char s[100]) {
	assert(("No place", curr != NULL && curr != head));
	int i;
	for (i = 0; s[i] != '\0'; i++);
	totalchar = totalchar - curr->getSize() + i;
	strcpy_s(curr->element, s);
}

void LList::checkString(char it[20]) {
	assert(("No place", head->next != NULL));
	Link* te = head->next;  bool found = 0;
	char temp[50][20];
	while (te != NULL) { 
		int count = 0, k = 0;
		for (int i = 0; te->element[i] != '\0'; i++) {
			if (tolower(te->element[i]) <= 'z' && tolower(te->element[i]) >= 'a') {
				temp[count][k] = te->element[i];
				k++;
			}
			else {
				temp[count][k] = '\0';
				count++;
				k = 0;
			}
		}
		temp[count][k] = '\0';
		for (int i = 0; i < count; i++) {
			if (!strcmp(temp[i], it)) {
				cout << "line" << te->index << "," << "word" << i + 1 << endl;
				found = 1;
			}
		}
		memset(temp, 0, sizeof(char) * 50 * 20); //clean
		te = te->next;
	}
	if (!found) cout << "can not find it." << endl;
	delete te;
}

void LList::replaceString(char it[20], char s[20]) {
	assert(("No value", head->next != NULL));
	Link* te = curr;
	int lenIt = 0, lenS = 0;
	for (; it[lenIt] != '\0'; lenIt++);
	for (; s[lenS] != '\0'; lenS++);
	te = head->next;  bool found = 0;
	while (te != NULL) {
		char temp[20], s1[100]; int count = 0, m = 0;
		for (int i = 0; te->element[i - 1] != '\0'; i++) {
			if (tolower(te->element[i]) <= 'z' && tolower(te->element[i]) >= 'a') {
				temp[count] = te->element[i];
				count++;
			}
			else {
				temp[count] = '\0';
				if (!strcmp(temp, it)) {
					int countS = 0;
					found = 1;
					for (m = i - lenIt; countS < lenS; m++, countS++)
						s1[m] = s[countS];  //copy the word
				}
				count = 0;
				strcpy_s(temp, ""); //clean
			}
			s1[m] = te->element[i]; 
			m++;
		}
		s1[m] = '\0';
		strcpy_s(te->element, s1);
		te = te->next;
	}
	if (!found) cout << "can not find it." << endl;
}