#ifndef MEDIA_H
#define MEDIA_H

/**
 * A structure to store media
 * This is just a void data, we don't actually need a structure here
 * But it creates an interface and an expectation.
 * It Improves readability since Media is more specific than void
 */
typedef struct media
{
    void * data;

} Media;

/**
 * Set data for a media type
 * @param media Media Storage
 * @param data  to be inserted
 */
void setMedia( Media * media, void * data );

/**
 * Retrieve the data from the media.
 * @param media [description]
 */
void* getMedia( Media * media );

// Creating a function Pointer
typedef void (*PrintMediaType)(void*);

/**
 * Print a media item
 * @param media Data to be print
 * @param print function pointer that can print that type of data.
 */
void printMedia( Media* media, PrintMediaType print);

#endif
