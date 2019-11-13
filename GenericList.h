#pragma once
#pragma once
template <class T>
class List {
protected:
	static int size;
	template <class T>
	class Element {
	private:
		T* info;
		Element<T>* next;
		Element<T>* last;
		Element<T>* prev;
	public:
		void setInfo(T* info) { this->info = info; }
		T* getInfo() { return info; }
		Element() { this->info = nullptr; next = nullptr; prev = nullptr; }
		void setnext(Element<T>* next) { this->next = next; }
		Element<T>* getnext() const { return next; }
		void setPrev(Element<T>* prev) { this->prev = prev; }
		Element<T>* getPrev() const { return prev; }
	};
	Element<T>* first;
	Element<T>* current;

public:

	class Iterator {
	private:
		Element<T>* it;
	public:
		void operator++ (int) {
			if (it != nullptr)
				it = it->getnext();
		}
		void operator--() {
			if (it != nullptr)
				it = it->getPrev();
		}
		bool operator!= (Element<T>* ele) { return !(ele == it); }
		T* operator* () { return it->getInfo(); }
		Element<T>* getIt() { return it; }
		void operator= (Element<T>* ele) { it = ele; }
	};
	Iterator it;
	void remove() {
		Element<T>* aux;
		if (first == it.getIt()) {
			first = it.getIt()->getnext();
			if (first != nullptr)
				it.getIt()->getnext()->setPrev(nullptr);
			aux = it.getIt()->getnext();
		}
		else if (current == it.getIt()){
			it.getIt()->getPrev()->setnext(nullptr);
			current = it.getIt()->getPrev();
			aux = nullptr;
		}
		else {
			it.getIt()->getnext()->setPrev(it.getIt()->getPrev());
			it.getIt()->getPrev()->setnext(it.getIt()->getnext());
			aux = it.getIt()->getnext();
		}
		delete it.getIt()->getInfo();
		delete it.getIt();
		it = aux;
	}
	List() { first = nullptr; current = nullptr; }
	void operator+ (T* info) {
		Element<T>* aux = new Element<T>;
		size++;
		aux->setInfo(info);
		if (first == nullptr)
			first = current = aux;
		else {
			aux->setPrev(current);
			current->setnext(aux);
			current = aux;
		}
	}
	
	int getSize() { return size; }
	Element<T>* getFirst() { return first; }
};
template <class T>
int List<T>::size = 0;