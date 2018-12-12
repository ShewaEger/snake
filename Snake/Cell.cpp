#pragma once
#define NULL 0
using namespace System;
using namespace System::Drawing;
class Cell {
private:
	int x, y;
	unsigned size;
public:
	Cell(int x = 0, int y = 0, unsigned size = 9): x(x), y(y), size(size){};
	bool isIntersection(Cell &a) { //���� ����������� � ���������� �������
		unsigned tmpx = Math::Abs(x - a.x);
		unsigned tmpy = Math::Abs(y - a.y);
		if (tmpx <= size && tmpy <= size) return true;
		return false;
	}
	void Draw(Graphics^ g, SolidBrush^ b) {//���������� ����
		g->FillEllipse(b, x, y, size, size);
	}
	void Setx(int tx) { x = tx; } //������������� ����������
	void Sety(int ty) { y = ty; }
	void Setsize(unsigned ts) { size = ts; }
	int Getx() { return x; }//���������� ����������
	int Gety() { return y; }
	unsigned Getsize() { return size; }
	bool operator==(Cell &a) { //���������� ��� ������
		return (a.x == x && a.y == y && a.size == size);
	}
};
class CellWrp {
public://������� ��� ������� ������ ��� �� ��������� �� � ���������
	Cell p;
	CellWrp *next;
	CellWrp *prev;
	CellWrp(CellWrp *Prev, CellWrp *Next, Cell &P) {
		next = Next;
		prev = Prev;
		p = P;
	}
};
class List {
public:
	CellWrp *start, *end;
	unsigned Size;
	class epop {}; //������ ����������
	class erequest {};

	List() : Size(0), end(NULL), start(NULL) {} //����������� �������
	bool isEmpty() { //���� ������ ������
		return Size == 0;
	}
	void push_back(Cell &a) {//��������� � �����
		if (Size == 0) {
			start = end = new CellWrp(NULL, NULL, a);
		}
		else {
			end->next = new CellWrp(end, NULL, a);
			end = end->next;
		}
		Size++;
	}
	void pop_back() { //��������� �� ����� 
		if (Size == 0) throw epop();
		CellWrp* tmp = end;
		end = end->prev; // ������ �� ������������� �������
		if (end != NULL) end->next = NULL;
		delete tmp;
		Size--;
	}
	void push_front(Cell &a) { //��������� � ������
		if (Size == 0) {
			start = end = new CellWrp(NULL, NULL, a);
		}
		else {
			start->prev = new CellWrp(NULL, start, a);
			start = start->prev;
		}
		Size++;
	}
	Cell& First() {//���������� ������ �� ������ �������
		if (Size == 0) throw erequest();
		return start->p;
	}
	Cell& Last() {//���������� ������ �� ��������� �������
		if (Size == 0) throw erequest();
		return end->p;
	}

	~List() { //����������
		while (Size) {
			pop_back();
		}
	};
};


class Iter {//��� ������ �� ������� ������������ ����� ��������
	List& src;
	CellWrp* curr;
public:
	class estep {};
	class ecurr {};
	Iter(List& l) :src(l) { //�������������� ���������� � ������������
		curr = src.start;
	}
	Cell& First() {//���������� ������ �������
		if (src.start == NULL) {
			throw estep();
		}
		curr = src.start;
		return curr->p;
	}
	Cell& Last() { //���������� ��������� �������
		if (src.start == NULL) {
			throw estep();
		}
		curr = src.end;
		return curr->p;
	}
	bool isNext() { //�������� �� ������� �� ��������� �������
		if (curr->next == NULL) return false;
		return true;
	}
	Cell& Next() { //���������� ������ �������
		if (curr->next == NULL) {
			throw estep(); //���������� ���������� � ������ ����
		}
		curr = curr->next;
		return curr->p;
	}
	bool isPrev() { //����� �� ������� �� ���������� �������
		if (curr->prev == NULL) return false;
		return true;
	}
	Cell& Prev() { // ������� �� ���������� �������
		if (curr->prev == NULL) {
			throw estep();
		}
		curr = curr->prev;
		return curr->p;
	}
	Cell& CurrItem() { //���������� ������� �������
		if (curr == NULL) throw ecurr();
		return curr->p;
	}
	Cell& operator[](int i) { //���������� ��-� ��� ������� i
		if (i >= src.Size) throw ecurr();
		curr = src.start;
		for (int j = 0; j != i; j++) curr = curr->next;
		return curr->p;
	}
	//������� ��� �������� ������
	void Clear() {
		while (src.Size) src.pop_back();
	}
};