#pragma once
#pragma once
template <class T>
class GenericList {
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
	Iterator it;
	void remove() {
		Element<T>* aux;
		if (primeiro == it.getIt()) {
			primeiro = it.getIt()->getProx();
			if (primeiro != nullptr)
				it.getIt()->getProx()->setAnterior(nullptr);
			aux = it.getIt()->getProx();
		}
		else if (atual == it.getIt()){
			it.getIt()->getAnterior()->setProx(nullptr);
			atual = it.getIt()->getAnterior();
			aux = nullptr;
		}
		else {
			it.getIt()->getProx()->setAnterior(it.getIt()->getAnterior());
			it.getIt()->getAnterior()->setProx(it.getIt()->getProx());
			aux = it.getIt()->getProx();
		}
		delete it.getIt()->getInfo();
		delete it.getIt();
		it = aux;
	}
	GenericList() { primeiro = nullptr; atual = nullptr; }
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
	void clean() {
		Element<T>* it;
		Element<T>* saveIt;
		it = saveIt = primeiro;
		while (it != nullptr) {
			saveIt = saveIt->getProx();
			delete it;
			it = saveIt;
		}
		primeiro = nullptr;
		atual = nullptr;
		size = 0;
	}
};
template <class T>
int GenericList<T>::size = 0;