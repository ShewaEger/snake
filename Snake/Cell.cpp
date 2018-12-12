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
	bool isIntersection(Cell &a) { //Ищет пересечение с переданной ячейкой
		unsigned tmpx = Math::Abs(x - a.x);
		unsigned tmpy = Math::Abs(y - a.y);
		if (tmpx <= size && tmpy <= size) return true;
		return false;
	}
	void Draw(Graphics^ g, SolidBrush^ b) {//Отрисовует себя
		g->FillEllipse(b, x, y, size, size);
	}
	void Setx(int tx) { x = tx; } //устанавливает переменные
	void Sety(int ty) { y = ty; }
	void Setsize(unsigned ts) { size = ts; }
	int Getx() { return x; }//Возвращает переменные
	int Gety() { return y; }
	unsigned Getsize() { return size; }
	bool operator==(Cell &a) { //Сравнивает две ячейки
		return (a.x == x && a.y == y && a.size == size);
	}
};
class CellWrp {
public://Обертка для объекта ячейки что бы применить ее в структуре
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
	class epop {}; //Классы исключений
	class erequest {};

	List() : Size(0), end(NULL), start(NULL) {} //конструктор обжекта
	bool isEmpty() { //Если обжект пустой
		return Size == 0;
	}
	void push_back(Cell &a) {//добавляет в конец
		if (Size == 0) {
			start = end = new CellWrp(NULL, NULL, a);
		}
		else {
			end->next = new CellWrp(end, NULL, a);
			end = end->next;
		}
		Size++;
	}
	void pop_back() { //Извлекает из конца 
		if (Size == 0) throw epop();
		CellWrp* tmp = end;
		end = end->prev; // Прыгаю на предпоследний элемент
		if (end != NULL) end->next = NULL;
		delete tmp;
		Size--;
	}
	void push_front(Cell &a) { //добавляет в начало
		if (Size == 0) {
			start = end = new CellWrp(NULL, NULL, a);
		}
		else {
			start->prev = new CellWrp(NULL, start, a);
			start = start->prev;
		}
		Size++;
	}
	Cell& First() {//Возвращает ссылку на первый элемент
		if (Size == 0) throw erequest();
		return start->p;
	}
	Cell& Last() {//Возвращает ссылку на последний элемент
		if (Size == 0) throw erequest();
		return end->p;
	}

	~List() { //Деструктор
		while (Size) {
			pop_back();
		}
	};
};


class Iter {//Вся работа со списком производится через итератор
	List& src;
	CellWrp* curr;
public:
	class estep {};
	class ecurr {};
	Iter(List& l) :src(l) { //Инициализируем переменные в конструкторе
		curr = src.start;
	}
	Cell& First() {//возвращает первый элемент
		if (src.start == NULL) {
			throw estep();
		}
		curr = src.start;
		return curr->p;
	}
	Cell& Last() { //возвращает последний элемент
		if (src.start == NULL) {
			throw estep();
		}
		curr = src.end;
		return curr->p;
	}
	bool isNext() { //возможен ли переход на следующий элемент
		if (curr->next == NULL) return false;
		return true;
	}
	Cell& Next() { //возвращает первый элемент
		if (curr->next == NULL) {
			throw estep(); //Генерирует исключение в случае чего
		}
		curr = curr->next;
		return curr->p;
	}
	bool isPrev() { //можно ли перейти на предыдущий элемент
		if (curr->prev == NULL) return false;
		return true;
	}
	Cell& Prev() { // переход на предыдущий элемент
		if (curr->prev == NULL) {
			throw estep();
		}
		curr = curr->prev;
		return curr->p;
	}
	Cell& CurrItem() { //возвращает текущий элемент
		if (curr == NULL) throw ecurr();
		return curr->p;
	}
	Cell& operator[](int i) { //возвращает эл-т под номером i
		if (i >= src.Size) throw ecurr();
		curr = src.start;
		for (int j = 0; j != i; j++) curr = curr->next;
		return curr->p;
	}
	//Удаляет все элементы списка
	void Clear() {
		while (src.Size) src.pop_back();
	}
};