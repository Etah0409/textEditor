#include "stdafx.h"
// this is the run() of text editor

void textEditor::run() {
	char s1[20], s2[20],temp[100], h; int n, count = 0;
	cout << "Name of the input file:";    cin >> s1;
	ifstream fin;
	fin.open(s1);
	if (fin.fail()) {
		cout << "open failed." << endl;
		perror(s1);
		system("pause");
		exit(1);
	}
	while (!fin.eof()) {
		fin.getline(temp, 100);
		textBuffer.append(temp);
	}
	strcpy(temp, "");
	cout << "Name of the output file:";   cin >> s2;
	cout << "This is a TEXT Editor.  Press 'h' to get the help." << endl ;
	cin >> h;
	if (h == 'h') {
		cout << "input the number to finish your operation:" << endl;
		cout << "1:print the text;" << endl;
		cout << "2:move the current to the first line." << endl;
		cout << "3:move the current to the last line." << endl;
		cout << "4:move the current to the previous line." << endl;
		cout << "5:move the current to the next line." << endl;
		cout << "6:move the current to a sure line." << endl;
		cout << "7:insert a new line next to the current." << endl;
		cout << "8:delete the current line." << endl;
		cout << "9:replace the current line by a new line." << endl;
		cout << "10:replace a sure string by a new string." << endl;
		cout << "11:check a sure string." << endl;
		cout << "12:print the lines and total characters." << endl;
		cout << "13:print your current location." << endl;
		cout << "0:exit this text editor." << endl;
	}
	cin >> n;
	while (n) {
		switch (n) {
		case(1):textBuffer.printList(); break;
		case(2):textBuffer.firstCurr(); break;
		case(3):textBuffer.tailCurr(); break;
		case(4):textBuffer.preCurr(); break;
		case(5):textBuffer.nextCurr(); break;
		case(6):goToSureLine(); break;
		case(7):insertLine(); break;
		case(8):textBuffer.deleteCurr(); break;
		case(9):replaceCurrentLine(); break;
		case(10):replaceString(); break;
		case(11):checkString(); break;
		case(12):textBuffer.printCharsAndLines(); break;
		case(13):textBuffer.getValue(); break;
		case(0):break; break;
		default:break;
		}
		cin >> n;
	}
	fstream fout(s2, ios::out);
	textBuffer.firstCurr();
	textBuffer.curr = textBuffer.curr->next;
	while (textBuffer.curr != NULL) {
		strcpy(temp, textBuffer.curr->element);
		fout << temp << endl;
		textBuffer.curr = textBuffer.curr->next;
	}
	fin.close();
	fout.close();
}