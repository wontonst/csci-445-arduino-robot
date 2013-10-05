#include "clinkedlist.h"

CLinkedList::CLinkedList() {
	this->start= NULL;
	this->iterator = NULL;
}
void CLinkedList::add(T v) {
	if(this->start == NULL) {
		this->start = new LLNode(v);
		return;
	}
	if(this->start->previous() == NULL) {
		LLNode<T>* n = new LLNode(v);
		this->start->setNext(n);
		this->start->setPrevious(n);
		n->setNext(this->start);
		n->setPrevious(this->start);
		return;
	}
}

void CLinkedList::resetIterator() {
	this->iterator = this->start;
}
T get() {
	if(this->iterator == NULL)return NULL;
	return this->iterator->value();
}
T advance() {
	if(this->iterator == NULL)return NULL;
	if(this->iterator->next() == NULL)
		return;
	this->iterator = this->iterator->next();
}
void remove() {
	if(this->iterator == NULL)return NULL;
	if(this->iterator->next == NULL) {
		LLNode<T>* n = this->iterator;
		this->iterator = NULL;
		this->start = NULL;
		delete n;
	}
}
void addAtIterator(T v) {
	if(this->iterator == NULL || this->start == NULL || this->start->next() == NULL) {
		this->add(v);
		return;
	}

	LLNode<T>* n = this->iterator->next();
	this->iterator->setNext(new LLNode<T>(v));
	this->iterator->next()->setNext(n);
	this->iterator->next()->setPrevious(this->iterator);
	n->setPrevious(this->iterator->next());
}

//probably don't want to use these functions because they're uberslow
void remove(T v){
throw new Exception();
}
T get(T v){
throw new Exception();
}