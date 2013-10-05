#ifndef LLNODE_H_
#define LLNODE_H_

template <class T>
class LLNode {
private:
	T m_value;
	LLNode* next_node;
	LLNode* previous_node;

public:
	LLNode(T v);
	T value();
	LLNode* next();
	LLNode* previous();
	void setNext(LLNode* n);
	void setPrevious(LLNode* n);
};

#endif