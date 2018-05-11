struct boardgame{
    char* name;
    double price;
    char* brandName;
};
typedef struct boardgame BoardGame;

BoardGame* createBoardGame(char* name, double price, char* brandName);

double getPrice(BoardGame* x);

char* getName(BoardGame* x);

char* getBrandName(BoardGame* x);

void printBoardGame(void* x);
