#ifndef DATASTRUCT_GENLIST_H
#define DATASTRUCT_GENLIST_H

template<class E>
struct GenlistNode {
    int utype;
    GenlistNode<E> *link;
    union{
        int ref;
        E value;
        GenlistNode<E> * link;
    } info;
    GenlistNode():utype(0), link(nullptr){ info.ref = 0;}
    GenlistNode(GenlistNode<E>& R){
        utype = R.utype;
        link = R.link;
        info = R.info;
    }
};

template<class E>
class Genlist {
private:
    GenlistNode<E> *first;

    GenlistNode<E> *Copy(GenlistNode<E> *ls);

    int Length(GenlistNode<E> *ls);

    int Depth(GenlistNode<E> *ls);

    bool Equal(GenlistNode<E> *s, GenlistNode<E> *t);

    void Remove(GenlistNode<E> *ls);
    void deltevalue(GenlistNode<E> *ls, E x);

public:
    Genlist();

    ~Genlist();

    bool Head(GenlistNode<E> &x);  //x返回表头元素
    bool Tail(Genlist<E> &lt);  //lt返回表尾
    GenlistNode<E> *First(); //返回第一个元素地址
    GenlistNode<E> *Next(GenlistNode<E> *elem); //返回下一个元素地址
    void Copy(const Genlist<E> &ls); //复制表
    int Length(); //返回表长;
    int Depth(); //返回表深度
    void deltevalue(E x); //删除值为x的元素
};


#endif //DATASTRUCT_GENLIST_H
