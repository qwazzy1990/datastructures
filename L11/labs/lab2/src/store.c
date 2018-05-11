#include "Store.h"

void* getItem(Store* s)
{
	return s->item;
}

void setItem(Store* s, void* data)
{
	s->item = data;
}

void displayStore( Store *s)
{
	s->printStore(s->item);
}

void setPrintType( Store* s, PrintStoreItem printStoreFunc )
{
	s->printStore = printStoreFunc; 
}

