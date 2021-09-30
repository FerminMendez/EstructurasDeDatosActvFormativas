#ifndef DLIST_H_
#define DLIST_H_

#include <sstream>
#include <string>
using namespace std;

template <class T> class DList;

template<class T>
class DLink {
private:
DLink<T> *next;
DLink<T> *previous;

T value;
//Constructores
DLink(T);
DLink(T,DLink<T>*,DLink<T>*);

friend class DList<T>;
};

template<class T>
DLink<T>::DLink(T val):value(val),next(0),previous(0){}

template<class T>
DLink<T>::DLink(T val,DLink* nex,DLink* prev):value(val),next(nex),previous(prev){}


template<class T>
class DList{
  private:
  int size;
  DLink<T>* head;
  DLink<T>* tail;

  public:
  DList();
  ~DList();

  string toString() const;
  string toStringForward() const;
  string toStringBackward() const;

  void insertion(T);
  int search(T);
  void update(int,T);
  int deleteAt(int);
};

template <class T>
DList<T>::DList(): head(0),tail(0), size(0){}

template <class T>
DList<T>::~DList() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
  tail=0;
	size = 0;
}

	// Incluye estos funciones en tu dlist.h para poder imprimir tus respuestas
	// en formatos compatibles con el main

	template <class T>
	string DList<T>::toStringForward() const {
		std::stringstream aux;
		DLink<T> *p;

		p = head;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->next != 0) {
				aux << ", ";
			}
			p = p->next;
		}
		aux << "]";
		return aux.str();
	}

	template <class T>
	string DList<T>::toStringBackward() const {
		std::stringstream aux;
		DLink<T> *p;

		p = tail;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->previous != 0) {
				aux << ", ";
			}
			p = p->previous;
		}
		aux << "]";
		return aux.str();
	}


template <class T>
void DList<T>::insertion(T valor){
  DLink<T> *newLink, *temp;
  newLink = new DLink<T>(valor);
  if(head == 0){
    newLink->next=0;
    newLink->previous=0;
    head = newLink;
    tail = newLink;
    size++;
    return;
	}
  temp=tail;
  
	newLink->next=0;
  newLink->previous=temp;
  tail=newLink;
	temp->next=newLink;
  size++;
}


template <class T>
int DList<T>::search(T valor){
  DLink<T> *temp;
  temp=head;
  int i=0;
  while(temp!=0){
    if(temp->value==valor){
      return i;
    }
    i++;
    temp=temp->next;
  }
  return -1;

}

template <class T>
void DList<T>::update(int index, T valor){
  DLink<T> *temp;
  if(index<=size/2+1){
     temp=head;
  for(int i=0;i<index;i++){
    temp=temp->next;
  }
  }
  else{
     temp=tail;
  for(int i=0;i<size-index;i++){
    temp=temp->previous;
  }
  }
  temp->value=valor;
}



template<class T>
  int DList<T>::deleteAt(int index){
    int val;
    int i=0;
    DLink<T>  *aux, *refer;
    if(index==0){
      aux=head->next;
      aux->previous=0;
      val=head->value;
      delete(head);
      head=aux;
    }
    else if(index==size){
      aux=tail->previous;
      aux->next=0;
      val=tail->value;
      delete(tail);
      tail=aux;
    }
    else if(index>size/2){
      refer = tail;
      for(int i=0;i<size-index;i++){
        refer=refer->previous;
      }
      refer=refer->previous;
      aux=refer->next;
      refer->next=aux->next;
      aux->next->previous=aux->previous;
      val=aux->value;
      delete(aux);
    }
    else{
      refer = head;
      i = 0;
      for(int i=0;i<index-1;i++){
        refer=refer->next;
      }
      aux=refer->next;
      refer->next=aux->next;
      aux->next->previous=aux->previous;
      val=aux->value;
      delete(aux);
    }
    size=size-1;
    return val;
  }

#endif
