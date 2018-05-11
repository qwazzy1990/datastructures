#ifndef STORE_H
#define STORE_H

typedef void (*PrintStoreItem)(void*);

typedef struct store
{
	void* item;
	PrintStoreItem printStore;
	
} Store;


void* getItem(Store* s);

void setItem(Store* s, void* data);

void displayStore( Store *s);

void setPrintType( Store* s, PrintStoreItem printStore );


#endif
