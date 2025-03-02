//
// Created by berilbayram on 14.12.2019.
//

#ifndef __BOOKCOLLECTION_H
#define __BOOKCOLLECTION_H
#include <string>
using namespace std;
#include "Genre.h"
#include "Book.h"
class BookCollection {
public:
    BookCollection();
    ~BookCollection();
    BookCollection(const BookCollection& bcToCopy);
    void operator=(const BookCollection& right);
    void addGenre(string genreName);
    void removeGenre (string genreName);
    void displayAllGenres() const;
    void addBook(string genreName, string bookName);
    void removeBook(string genreName, string bookName);
    void addAuthor(string genreName, string bookName, int authorID, string
    authorName);
    void removeAuthor(string genreName, string bookName, int authorID);
    void displayGenre(string genreName);
    void displayAuthor(int authorID);
    string findAuthorById(int authorID);
private:
    struct GenreNode {
        Genre g;
        GenreNode* next;
    };
    GenreNode *head;
    int genreCount;
    GenreNode* findGenre(string genreName);
};
#endif