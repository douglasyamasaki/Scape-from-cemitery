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
		Element<T>* prox;
		Element<T>* ultimo;
		Element<T>* ant;
	public:
		void setInfo(T* info) { this->info = info; }
		T* getInfo() { return info; }
		Element() { this->info = nullptr; prox = nullptr; ant = nullptr; }
		void setProx(Element<T>* prox) { this->prox = prox; }
		Element<T>* getProx() const { return prox; }
		void setAnterior(Element<T>* ant) { this->ant = ant; }
		Element<T>* getAnterior() const { return ant; }
	};
	Element<T>* primeiro;
	Element<T>* atual;

public:

	class Iterator {
	private:
		Element<T>* it;
	public:
		void operator++ (int) {
			if (it != nullptr)
				it = it->getProx();
		}
		void operator--() {
			if (it != nullptr)
				it = it->getAnterior();
		}
		bool operator!= (Element<T>* ele) { return !(ele == it); }
		T* operator* () { return it->getInfo(); }
		Element<T>* getIt() { return it; }
		void operator= (Element<T>* ele) { it = ele; }
	};
	List() { primeiro = nullptr; atual = nullptr; }
	
	void operator+ (T* info) {
		Element<T>* aux = new Element<T>;
		size++;
		aux->setInfo(info);
		if (primeiro == nullptr)
			primeiro = atual = aux;
		else {
			aux->setAnterior(atual);
			atual->setProx(aux);
			atual = aux;
		}
	}
	
	int getSize() { return size; }
	Element<T>* getPrimeiro() { return primeiro; }
};
template <class T>
int List<T>::size = 0;