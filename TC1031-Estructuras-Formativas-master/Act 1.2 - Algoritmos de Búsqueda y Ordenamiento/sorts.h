#ifndef SORTS_H_ //Por qué _H_?
#define SORTS_H_

#include <iostream>
#include <vector>

template <class T>
class Sorts{
private:
std::vector<T> swap(std::vector<T>&,int,int);
void splitMerge(std::vector<T>&,std::vector<T>&,int,int);
void orderMerge(std::vector<T>&,std::vector<T>&,int,int,int);
void pasteVector(std::vector<T>&,std::vector<T>&,int,int);
int binarysplit(std::vector<T>&,int,int,int);
public:
void ordenaSeleccion(std::vector<T>&);
void ordenaBurbuja(std::vector<T>&);
void ordenaMerge(std::vector<T>&);
int busqSecuencial(std::vector<T>&,int val);
int busqBinaria(std::vector<T>&, int val);
};

template <class T>
std::vector<T> Sorts<T>::swap(std::vector<T> &v,int a,int b){
  T aux=v[a];
  v[a]=v[b];
  v[b]=aux;
  return v;
}

template <class T>
void Sorts<T>::ordenaSeleccion( std::vector<T> &v){
  for (int i=0;i<v.size();i++){
    int j=i;
    while (j>0 && v[j]<v[j-1]){
      swap(v,j,j-1);
      j=j-1;
    }
  }
}

template <class T>
void Sorts<T>::ordenaBurbuja( std::vector<T> &v){
    int min;
    for(int i=0;i<=v.size()-1;i++){
      min=i;
      for (int j=i+1;j<v.size();j++){
        if(v[min]>v[j]){
          min=j;
        }
      }
      v=swap(v,i,min);
    }

}




template <class T>

void Sorts<T>::ordenaMerge(std::vector<T> &v){
std::vector<T> aux(v.size());
int low=0;
int high=v.size()-1;

splitMerge(v,aux,low,high);
}

template <class T>
void Sorts<T>::splitMerge(std::vector<T> &v,std::vector<T> &aux,int low,int high){
  if(high-low==0){
    return;
  }
  int mid=(high+low)/2;

  splitMerge(v,aux,low,mid);
  splitMerge(v,aux,mid+1,high);
  orderMerge(v,aux,low,mid,high);
  pasteVector(v,aux,low,high);

}

template <class T>
void Sorts<T>::orderMerge(std::vector<T> &v,std::vector<T> &aux,int low, int mid,int high){
  int i=low;
  int j=mid+1;
  int k=low;
  
  while(k<=high){
    if(i>mid || (v[i]>=v[j] && j<=high)){
      aux[k]=v[j];
      j=j+1;
    }
    else if(j>high || (v[i]<=v[j] && i<=mid)){
      aux[k]=v[i];
       i=i+1;
    }

    k=k+1;
  }
}

template <class T>
void Sorts<T>::pasteVector(std::vector<T> &v,std::vector<T> &aux,int low,int high){
  for (int i=low;i<=high;i++){
    v[i]=aux[i];
  }
}


template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> &v,int val){
  for (int i=0;i<v.size();i++){
    if(v[i]==val){
      return i;
    }
  }
  return -1;
}

template <class T>
int Sorts<T>::binarysplit(std::vector<T> &v,int val,int low,int high){
  int mid=(high+low)/2;
  if (high-low==0){
    return -1;
  }
  if (v[mid]==val){
    return mid;
  }
  if (v[mid]>val){
    return binarysplit(v,val,low,mid-1);
  }
  if (v[mid]<val){
    return binarysplit(v,val,mid+1,high);
  }
}


template <class T>
int Sorts<T>::busqBinaria(std::vector<T> &v, int val){
  return binarysplit(v,val,0,v.size()-1);
}



#endif 