#include "media.h"
#include <stdio.h>

void setMedia( Media * media, void * data )
{
    media->data = data;
}

void* getMedia( Media * media )
{
    return media->data;
}

void printMedia( Media* media, PrintMediaType print)
{
    print(media);
}
