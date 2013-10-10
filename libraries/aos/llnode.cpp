#include "llnode.h"

LLNode::LLNode(T v) {
	this->value = v;
	
	this->next_node = NULL;
	this->previous_node = NULL;
}
T LLNode::value() {
	return this->value;
}
LLNode* LLNode::next() {
	return this->next_node;
}
LLNode* LLNode::previous() {
	return this->previous_node;
}
void LLNode::setNext(LLNode* n) {
	this->next_node = n;
}
void LLNode::setPrevious(LLNode* n) {
	this->previous_node = n;
}