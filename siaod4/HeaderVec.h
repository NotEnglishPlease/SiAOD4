#ifndef _HEADERVEC_H
#define _HEADERVEC_H
#include <vector>
#include <string>

using namespace std;

struct test
{
	int topic; // ����� ���� 
	string text; // ����� ������� 
	int scope; // ���� �� ���������� �����
	vector<string> anwers; // ������ ��������� ������ (���������� ������� �� ������ 6)
	int corAnswer;	// ����� ����������� ������ (�� 1 �� 5)
};

vector<test> vec;

#endif 