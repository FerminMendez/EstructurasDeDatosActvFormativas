#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int heapsize;
	unsigned int count;
	
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);//Por completar
	void swap(unsigned int, unsigned int);
	
public:
    //Constructor y destructor
	Heap(unsigned int);
	~Heap();

    
    //Tarea 
	void push(T);
    T pop();
    T top();
	bool empty() const;
    int size();

    //Other functions
	bool full() const;
	void clear();
	std::string toString() const;
};

//Constructores
template <class T>
Heap<T>::Heap(unsigned int sze) {
	data=new T [sze];
	count=0;
}

template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data=0;
}

//Tarea
//Tarea
template <class T>
void Heap<T>::push(T val) {
 unsigned int pos = count;
	count++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
T Heap<T>::pop(){
    T val=data[0];
    count--;
    swap(count,0);
    heapify(0);
    return val;
}

template <class T>
T Heap<T>::top(){
	T val=data[0];
    return val;
}



template <class T>
bool Heap<T>::empty() const {
	if(count==0){
		return true;
	}
	return false;
}



template <class T>
int Heap<T>:: size(){
	return count;
}





//Other functions
template <class T>
bool Heap<T>::full() const {
	if(count==heapsize){
		return true;
	}
	return false;
}



template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {//Por completar
    int le=left(pos);
    int ri=right(pos);
	int min=pos;
    if(data[min]>data[le] && le<count){
		min=le;
    }
    if(data[min]>data[ri] && ri<count){
		min=ri;
    }

	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
	
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}
#endif 
	





