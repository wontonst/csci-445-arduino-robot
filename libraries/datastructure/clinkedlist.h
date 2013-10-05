#ifndef CLINKEDLIST_H_
#define CLINKEDLIST_H_

#include "llnode.h"

template <class T>
class CLinkedList{
private:
LLNode<T>* start;
LLNode<T>* iterator;

public:
CLinkedList();
void add(T v);

void resetIterator();
T get();
T advance();
void remove();
void addAtIterator(T v);

//probably don't want to use these functions because they're uberslow
void remove(T v);
T get(T v);

};

#endif;