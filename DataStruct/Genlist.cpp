//
// Created by 86158 on 2025/4/23.
//

#include "Genlist.h"
#include<iostream>
using namespace std;

template<class E>
Genlist<E>::Genlist() {
    first = new GenlistNode<E>;
}

template<class E>
bool Genlist<E>::Head(GenlistNode<E> &x) {
    if (first->link == nullptr) return false;
    x.utype = first->link->utype;
    x.info = first->link->info;
    return true;
}

template<class E>
bool Genlist<E>::Tail(Genlist<E> &lt) {
    if (first->link == nullptr) return false;
    lt.first->utype = 0;
    lt.info.ref = 0;
    lt.first->link = Copy(first->link->link);
    return true;
}

template<class E>
GenlistNode<E> *Genlist<E>::First() {
    return first->link;
}

template<class E>
GenlistNode<E>* Genlist<E>::Next(GenlistNode<E> *elem) {
    if (elem == nullptr) return nullptr;
    return elem->link;
}

template<class E>
void Genlist<E>::Copy(const Genlist<E> &ls) {
    first = Copy(ls.first);
}

template<class E>
GenlistNode<E>* Genlist<E>:: Copy(GenlistNode<E>* ls){
    GenlistNode<E>* p = NULL;
    if(ls != NULL){
        p = new GenlistNode<E>;
        p->utype = ls->utype;
        switch(p->utype){
            case 0:
                p->info.ref = ls->info.ref;
                break;
            case 1:
                p->info.value = ls->info.value;
                break;
            case 2:
                p->info.link = Copy(ls->info.link);
                break;
        }
        p->link = Copy(ls->link); // 拷贝下一个广义表元素
    }
    return p;
}

template<class E>
int Genlist<E>:: Length(){
    return Length(first->link);
}

template<class E>
int Genlist<E>::Length(GenlistNode<E>* ls){
    if(ls == NULL) return 0;
    int n = 0;
    GenlistNode<E>* temp = ls->link;
    while(temp != NULL){
        n++;
        temp = temp->link;
    }
    return n;
}

template<class E>
int Genlist<E>::Depth(){
    return Depth(first->link);
}

template<class E>
int Genlist<E>::Depth(GenlistNode<E>* ls){
    if(ls == NULL) return 1;
    GenlistNode<E>* temp = ls->link;
    int max = 0,n;
    while(temp!= NULL){
        if(temp->utype == 2){
            n = Length(temp->info.link);
            if(n > max) max = n;
        }
        temp = temp->link;
    }
    return max + 1;
}

template<class E>
void Genlist<E>::deltevalue(E x) {
    deltevalue(first, x);
}

template<class E>
void Genlist<E>::deltevalue(GenlistNode<E> *ls, E x) {
    if(ls == NULL) return;
    GenlistNode<E>* temp = ls->link;
    while(temp != NULL && temp->utype == 1 && temp->info.value == x){
        ls->link = temp->link;
        delete temp;
        temp = ls->link;
    }
    if(temp!= NULL){
        if(temp->utype == 2){
            deltevalue(temp->info.link, x);
        }
        deltevalue(temp->link, x); // 递归删除下一个元素
    }
}

template<class E>
Genlist<E>::~Genlist() {
    Remove(first);
}

template<class E>
void Genlist<E>::Remove(GenlistNode<E> *ls) {
    ls->info.ref--;
    if(ls->info.ref <= 0){
        GenlistNode<E>* p;
        while(ls->link!=NULL){
            p = ls->link;
            if(p->utype == 2){
                Remove(p->info.link);
                if(p->info.link->info.ref <= 0){
                    delete p->info.link;
                }
            }
            ls->link = p->link;
            delete p;
        }
    }
}