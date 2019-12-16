//
// Created by berilbayram on 14.12.2019.
//

#ifndef GENRE_H
#define GENRE_H
#include <string>
#include "Book.h"

using namespace std;
class Genre {
public:
    Genre(const string gname = "");
    ~Genre ();
    Genre (const Genre &genreToCopy);
    void operator=(const Genre &right);
    string getGenreName() const;
    void setGenreName(const string gName);
    bool addBook(const string bName);
    bool removeBook(const string bName);
    bool addAuthor(const int aId, const string aName, const string bookName);
    bool removeAuthor(const int aId, const string bookName);
    void displayGenre();
    int getBookCount() const;
    void displayBooks(int authorId) const;
    string findAuthorById(int authorID) const;
private:
    struct BookNode {
        Book b;
        BookNode* next;
    };
    string genreName;
    BookNode* head;
    int bookCount;
    BookNode* findBook(const string name);
};
#endif
