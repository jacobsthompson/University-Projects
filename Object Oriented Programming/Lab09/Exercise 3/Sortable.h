#ifndef SORTABLE_H
#define SORTABLE_H

class Sortable {
public:
	virtual bool compare( const Sortable* ) = 0;
	virtual void print() = 0;
};

#endif