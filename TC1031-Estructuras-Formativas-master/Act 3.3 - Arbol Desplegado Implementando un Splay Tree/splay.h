#ifndef SplayTree_H
#define SplayTree_H
//Fermín Méndez A01703366
//Libraries
#include <string>
#include <sstream>
#include <iostream>
////////Arbol SplayTree
template<class T> class SplayTree;
//Nodo
template<class T>
class Node{
    private:
        T value;
        Node<T>* left;
        Node<T>* right;
    //
    public:
        //Node constructors
        Node(T);
        Node(T,Node<T>*,Node<T>*);
        //Methods
        void add(T);
        bool find(T);
        void removeChilds();
        //orders
        void preorder(std::stringstream&) const;
        void inorder(std::stringstream&) const;
        void postorder(std::stringstream&) const;
        void levelbylevel(std::stringstream*);
        //height
        int height(int);
        //ancestors
        void ancestors(std::stringstream&,int) const;
        //FindLevel
        int findlevel(T, int);

    friend class SplayTree<T>;
};
//Constructors
template<class T>
Node<T>::Node(T val):value(val),right(0),left(0){}

template<class T>
Node<T>::Node(T val,Node<T>* le,Node<T>* ri):value(val),left(le),right(ri){}

//Methods
template<class T>
void Node<T>::add(T val){
    if(val < value){
        if(left==0){
            left=new Node(val);
        }
        else{
            left->add(val);
        }
    }
    else if(val>value){
        if(right==0){
            right=new Node(val);
        }
        else{
            right->add(val);
        }
    }
}

template <class T>
bool Node<T>::find(T val){
    if(value==val){
        return true;
    }
    else if(val>value){
        if(right==0){
            return false;
        }
        return right->find(val);
    }
    else if(val<value){
        if(left==0){
            return false;
        }
        return left->find(val);
    }
    return false;
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

//Orders
template <class T>
void Node<T>::preorder(std::stringstream &aux) const{
    aux<<value;
    if(left!=0){
        aux<<" ";
        left->preorder(aux);
    }
    if(right!=0){
        aux<<" ";
        right->preorder(aux);
    }
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const{
    if(left!=0){
        left->inorder(aux);
    }
    if (aux.tellp() != 1) {
	    aux << " ";
	}
    aux<<value;
    if(right!=0){
        right->inorder(aux);
    }
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const{
    if(left!=0){
        left->postorder(aux);
    }
    if(right!=0){
        right->postorder(aux);
    }
    if (aux.tellp() != 1) {
	    aux << " ";
	}
    aux<<value;
}

template <class T>
void Node<T>::levelbylevel(std::stringstream *ptr){
    if (ptr->tellp() != 0) {
	    *ptr << " ";
	}
    *(ptr)<<value;
    if(left!=0){
        left->levelbylevel(ptr+1);
    }
    if(right!=0){
        right->levelbylevel(ptr+1);
    }

}
// Height

template<class T>
int Node<T>::height(int prev){
    int le,ri;
    if(left==0 && right==0){
        return prev;
    }
    else if(left==0){
        return right->height(prev+1);
    }
    else if(right==0){
        return left->height(prev+1);
    }
    else{
        le=left->height(prev+1);
        ri=right->height(prev+1);
        if(le>=ri){return le;}
        else{return ri;}
    }

}

// Ancestors
template <class T>
void Node<T>::ancestors(std::stringstream &aux, int val) const{
    if(value==val){
        return;
    }
    if (aux.tellp() != 1) {
	    aux << " ";
	}
    aux<<value;
    if(val>value){
        right->ancestors(aux,val);
    }
    else if(val<value){
        left->ancestors(aux,val);
    }

}
//Find level
template <class T>
int Node<T>::findlevel(T val,int prev){
    if(val==value){
        return prev+1;
    }
    else if(val>value){
        return right->findlevel(val,prev+1);
    }
    else if(val<value){
        return left->findlevel(val,prev+1);
    }
    return -1;
}
 
//SplayTree implementation
template<class T> 
class SplayTree{
    private:
        Node<T> *root;
        int treeSize;
    
    public:
        //SplayTree Constructors and destructor
        SplayTree();
        ~SplayTree();
        //Mehtods
        bool is_empty();
       
        void clearAll();
        
        std::string visit();
        int height();
        std::string ancestors(T);
        T whatlevelamI(T);

        //Tarea
        void add(T);//Semi-implementado
        void remove(T);//Sin implemetar
        bool find(T); //Semi-implementado
        int size();//Sin implementar

        //Orders
        std::string preorder();
        std::string inorder();
        std::string postorder();
        std::string levelbylevel();

};
//SplayTree Constructors and destructor
template <class T>
SplayTree<T>::SplayTree() :root(0){}

template <class T>
SplayTree<T>::~SplayTree(){
    clearAll();
}

//SplayTree Methods
template <class T>
bool SplayTree<T>::is_empty(){
    if(root==0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void SplayTree<T>::add(T val){
    if(is_empty()){
        root=new Node<T>(val);
    }
    else{
        root->add(val);
    }
}

template <class T>
bool SplayTree<T>::find(T val){
    if(!is_empty()){
        return root->find(val);
    }
    return false;
}

//Por implementar
template <class T>
void SplayTree<T>::remove(T){
    
}

template <class T>
int SplayTree<T>::size(){
 return 0;
}



template <class T>
void SplayTree<T>::clearAll(){
    if(!is_empty()){
        root->removeChilds();
    }
    delete (root);
    root=0;
}


template <class T>
std::string SplayTree<T>::visit(){
    return preorder()+"\n"+inorder()+"\n"+postorder()+"\n"+levelbylevel();
}

template <class T>
int SplayTree<T>::height(){
    if(is_empty()){
        return 0;
    }
    else{
        return root->height(1);
    }
}

template <class T>
std::string SplayTree<T>::ancestors(T val){
    std::stringstream aux;
    aux<<"[";
    if(!is_empty() && find(val)){
        root->ancestors(aux,val);
    }
    aux<<"]";
    return aux.str();
}

template <class T>
T SplayTree<T>::whatlevelamI(T val){
    if(is_empty() || !find(val)){
        return -1;
    }
    return root->findlevel(val,0);
}

//Orders
template <class T> 
std::string SplayTree<T>::preorder(){
    std::stringstream aux;
    	aux << "[";
	if (!is_empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T> 
std::string SplayTree<T>::inorder(){
    std::stringstream aux;
    	aux << "[";
	if (!is_empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T> 
std::string SplayTree<T>::postorder(){
    std::stringstream aux;
    	aux << "[";
	if (!is_empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T> 
std::string SplayTree<T>::levelbylevel(){
    std::stringstream aux;
    aux << "[";
    if(is_empty()){
        aux<<"]";
        return aux.str();
    }

    int h=height();
    std::stringstream array[h];
    std::stringstream *ptr;
    ptr=array;
    root->levelbylevel(ptr);

    //////////////////////////////////////
        for (int i=0;i<h;i++){
            if (aux.tellp() != 1) {
                aux << " ";
            }
            aux<<(ptr+i)->str();
        }
	    aux << "]";       
	return aux.str();
}

#endif