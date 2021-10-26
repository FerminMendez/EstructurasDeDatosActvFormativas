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
        Node<T>* parent;

        //Auxiliares
        void removeChilds();
        Node<T>* splay(Node<T>*, Node<T>*);
        Node<T>* rot_left(Node<T>*);
        Node<T>* rot_right(Node<T>*);
        Node<T>* succesor();
		bool amIleft(); //Auxiliar para determinar si es hijo izquierdo
    public:
        //Node constructors
        Node(T);                            //Con value
        Node(T,Node<T>*);                   //Con value y parent
        Node(T,Node<T>*,Node<T>*,Node<T>*); //Con value, left, right y parent

        //Methods
        Node<T>* add(T);
        Node<T>* remove(T);
        Node<T>* find(T);

        //Prints
        void inorder(std::stringstream&) const;
        void print_tree(std::stringstream&) const;
        void preorder(std::stringstream&) const;

    friend class SplayTree<T>;
};
//Auxiliares
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

template <class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* x){
	while(x->parent != 0){
		if(x->parent->value == root->value){//Cuando el padre es la raiz
			if(x->parent->left && amIleft()){
				rot_right(x->parent);
			}else{
				rot_left(x->parent);
			}
		}else{
			Node<T>*p = x->parent; 
			Node<T>*g = p->parent;//Rotaciones cuand hay buelo y padre
			if(p->left && g->left &&
				x->value == p->left->value && p->value == g->left->value){
				rot_right(g);
				rot_right(p);//Doble derecha
			}else if(p->right && g->right &&
				x->value == p->right->value && p->value == g->right->value){
				rot_left(g);
				rot_left(p);//Doble izquierda
			}else	if(p->left && g->right &&
				x->value == p->left->value && p->value == g->right->value){
				rot_right(p);//Derecha-izquierdaa
				rot_left(g);
			}else{
				rot_left(p);
				rot_right(g);//Izquierda-derecha
			}
		}
	}
	return x;
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x){
	Node<T> *y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	y->right = x;
	// enlace de y con el padre de x
	y->parent = x->parent;
	x->parent = y;
	// hace enlace del padre de x a y
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
	Node<T> *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->left = x;
	// enlace de y con el padre de x
	y->parent = x->parent;
	x->parent = y;
	// hace enlace del padre de x a y
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}


template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (right->left == 0) {
		right = right->right;
		ri->right = 0;
		return ri;
	}

	Node<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != 0) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = 0;
	return child;
}

template <class T>
bool Node<T>::amIleft(){
	if(value==parent->left->value){
		return true;
	}
	return false;
}

//Constructors
template<class T>
Node<T>::Node(T val):value(val),right(0),left(0),parent(0){}

template<class T>
Node<T>::Node(T val,Node<T>* pa):value(val),left(0),right(0),parent(pa){}

template<class T>
Node<T>::Node(T val,Node<T>* le,Node<T>* ri,Node<T>* pa):value(val),left(le),right(ri),parent(pa){}

//Methods
template<class T>
Node<T>* Node<T>::add(T val){
    if(val < value){
        if(left==0){
            left=new Node(val,this);
            return left;
        }
        else{
            return left->add(val);
        }
    }
    else if(val>value){
        if(right==0){
            right=new Node(val,this);
            return right;
        }
        else{
            return right->add(val);
        }
    }
    return this;//To avoid warning
}


template <class T>
Node<T>* Node<T>::remove(T val){
	Node<T>* suc,*p;
	//Valor encontrado rama izquierda
	if(left && left->value==val){//4 casos por lado
		if(left->left==0 && left->right==0){//1- Si es hoja
			delete left;
			left==0;
		}
		else if(left->left==0){//2- Si solo tiene derecho //Amarres sencillos como linked list
			p=left;
			left=p->right;
			p->right->parent=this;
			delete p;
		}
		else if(left->right==0){//3- Solo hijo izquierdo
			p=left;
			left=p->left;
			p->left->parent=this;
			delete p;
		}
		else{
			suc=left->succesor();
			if(suc->right!=0){ 		//Si tiene hijo
				if(suc->amIleft()){//Amarre del hijo de sucesor
				suc->parent->left=suc->right;
				suc->right->parent=suc->parent;
				}
				else{
					suc->parent->right=suc->right;
					suc->right->parent=suc->parent;
				}
				p=left;
				left=suc;//Enkace padre-sucesor, sucesor-padre
				suc->parent=this;
				suc->right=p->right;
				suc->left=suc->left;
				delete p;
			}

		
		}
	}
	//Valor por la rama derecha
	else if(right && right->value==val){//4 casos por lado derecho ahora
		if(right->left==0 && right->right==0){//1- Si es hoja
			delete right;
			right==0;
		}
		else if(right->left==0){//2- Si solo tiene derecho
			p=right;
			right=p->right;//Enlace como linked list
			p->right->parent=this;
			delete p;
		}
		else if(left->right==0){//3- Solo hijo izquierdo
			p=right;
			right=p->left;
			p->left->parent=this;
			delete p;
		}
		else{
			suc=right->succesor();//Este sucesor no puede tener hijo izquierdo porque es sucesor
			if(suc->right!=0){ 		//Si tiene hijo
				if(suc->amIleft()){//Amarre del hijo de sucesor
				suc->parent->left=suc->right;
				suc->right->parent=suc->parent;
				}
				else{
					suc->parent->right=suc->right;
					suc->right->parent=suc->parent;
				}
				p=right;
				right=suc;//Enlace padre-sucesor, sucesor-padre
				suc->parent=this;
				suc->right=p->right;
				suc->left=p->left;
				delete p;
			}
		
		}
		return this;
	}
	else if(val>value){
		return right->remove(val);
	}
	else if(val<value){
		return left->remove(val);
		}
	return this;
}

template <class T>
Node<T>* Node<T>::find(T val){
    if(value==val){
        return this;
    }
    else if(val>value){
        if(right==0){
            return 0;
        }
        return right->find(val);
    }
    else if(val<value){
        if(left==0){
            return 0;
        }
        return left->find(val);
    }
    return 0;
}

// Prints
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
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
void Node<T>::print_tree(std::stringstream &aux) const {
	if (parent != 0){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}else
		aux << "\n root " << value;
	if (left != 0)
		aux << " left " << left->value;
	if (right != 0)
		aux << " right " << right->value;
	aux << "\n";

	if (left != 0) {
		left->print_tree(aux);
	}
	if (right != 0) {
		right->print_tree(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
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



//////////////////////SplayTree implementation
template<class T> 
class SplayTree{
    private:
        Node<T> *root;
        int sze;

        //Auxiliares
        void splay(Node<T>*);
        void clearAll();
    public:
        //SplayTree Constructors and destructor
        SplayTree();
        ~SplayTree();
        //Mehtods
        bool empty();//Queda de más porque se puede hacer sze==0
        void add(T);
        void remove(T);
        bool find(T);
        int size();

        //Prints
        std::string inorder() const;
        std::string print_tree() const;
        std::string preorder() const;
};
//Auxiliares
template <class T>
void SplayTree<T>::splay(Node<T>* x){
    root=x->splay(root,x);
} 
template <class T>
void SplayTree<T>::clearAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

//SplayTree Constructors and destructor
template <class T>
SplayTree<T>::SplayTree() :root(0),sze(0){}

template <class T>
SplayTree<T>::~SplayTree(){
    clearAll();
}

//SplayTree Methods
template <class T>
bool SplayTree<T>::empty(){
    if(root==0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void SplayTree<T>::add(T val){
    if(sze==0){
        root=new Node<T>(val);
    }
    else{
        Node<T>* y=root->add(val);
        splay(y);
    }
    sze++;
}
template <class T>
void SplayTree<T>::remove(T val){
	Node<T> *suc;
	if(val==root->value){//Caso cuando queremos quitar la raiz
		suc=root->succesor();
		if(suc->amIleft()){//Amarre del hijo de sucesor
			suc->parent->left=suc->right;
			}
		else{
			suc->parent->right=suc->right;
			
		}
		if(suc->right!=0){
			suc->right->parent=suc->parent;
		}
		suc->parent=0;
		suc->left=root->left;
		suc->right=root->right;
		delete(root);
		root=suc;
	}
	else{
		splay(root->remove(val));
	}
	sze--;
}
template <class T>
bool SplayTree<T>::find(T val){
	Node<T>* p=0;
    if(sze>0){
        p=root->find(val);
    }
	if(p==0){//De Node->find si devuelve un 0 significa que no lo encontró y manda un false
 		return false;
	}
	splay(p);
	return true;
}

template <class T>
int SplayTree<T>::size(){
    return sze;
}


template <class T>
std::string SplayTree<T>::inorder() const {
	std::stringstream aux;
    	aux << "[";
	if (sze>0) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string SplayTree<T>::print_tree() const {
	std::stringstream aux;

	aux << "\n ================================ ";
	if (!empty()) {
		root->print_tree(aux);
	}
	aux << " ================================ \n";
	return aux.str();
}



template <class T>
std::string SplayTree<T>::preorder() const {
 std::stringstream aux;
    	aux << "[";
	if (sze>0) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif