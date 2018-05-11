struct store{
    void* item;
    void (*printFuncPtr)(void*);
};
typedef struct store store;

void* getItemFromStore(store* s);
void displayStore(store*s);
void setStore(store* s, void* x, void(*display)(void* data));

