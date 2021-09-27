#ifndef LIST_H_
#define LIST_H_

#include <sstream>
#include <string>
using namespace std;

template <class T> class List;

template<class T>
class Link {
private:
Link<T> *next;
T value;
//Constructores
Link(T);
Link(T,Link<T>*);

friend class List<T>;
};

template<class T>
Link<T>::Link(T val):value(val),next(0){}

template<class T>
Link<T>::Link(T val,Link* nex):value(val),next(nex){}



template<class T>
class List{
  private:
  int size;
  Link<T>* head;

  public:
  List();
  ~List();

  string toString() const;

  void insertion(T);
  int search(T);
  void update(int,T);
  int deleteAt(int);

};
template <class T>
List<T>::List(): head(0), size(0){}

template <class T>
List<T>::~List() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}


/* Agregar un metodo toString a su clase.h
*/
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;
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
void List<T>::insertion(T valor){
  Link<T> *newLink, *temp;
  newLink = new Link<T>(valor);
  if(head == 0){
    newLink->next=head;
    head = newLink;
    size++;
    return;
	}
  temp=head;
  while (temp->next != 0) {
	 temp=temp->next;
	}
	newLink->next=0;
	temp->next=newLink;
  size++;
}


template <class T>
int List<T>::search(T valor){
  Link<T> *temp;
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
void List<T>::update(int index, T valor){
  Link<T> *temp;
  temp=head;
  for(int i=0;i<index;i++){
    temp=temp->next;
  }
  temp->value=valor;
}


template<class T>
  int List<T>::deleteAt(int index){
    int val;
    int i=0;
    Link<T>  *aux, *refer;
    if(index==0){
      aux=head->next;
      val=head->value;
      delete(head);
      head=aux;
    }
    else{
      refer = head;
      i = 0;
      for(int i=0;i<index-1;i++){
        refer=refer->next;
      }
      aux=refer->next;
      refer->next=aux->next;
      val=aux->value;
      delete(aux);
    }
    size=size-1;
    return val;
  }


#endif