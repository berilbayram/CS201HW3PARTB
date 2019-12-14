//
// Created by berilbayram on 14.12.2019.
//

#include <iostream>
#include "BookCollection.h"


BookCollection::BookCollection(){

}

BookCollection::~BookCollection(){
    GenreNode* temp;
    for(GenreNode* current = head; current != nullptr; current = current ->next){
        temp = current;
        removeGenre(current->g.getGenreName());
        current = temp;
    }
    genreCount = 0;
}

void BookCollection::operator=(const class BookCollection & right) {
    genreCount = right.genreCount;
    if (right.head == nullptr){
        head = nullptr;
    } else {
        head = new GenreNode;
        head->g = right.head->g;
        GenreNode* newPtr = head;

        for(GenreNode* bcToCopyGenrePtr = right.head->next; bcToCopyGenrePtr != nullptr; bcToCopyGenrePtr = bcToCopyGenrePtr->next){
            newPtr->next = new GenreNode;
            newPtr = newPtr->next;
            newPtr->g = bcToCopyGenrePtr->g;
        }
        newPtr->next = nullptr;
    }
}

BookCollection::BookCollection(const BookCollection &bcToCopy) {
    genreCount = bcToCopy.genreCount;
    if (bcToCopy.head == nullptr){
        head = nullptr;
    } else {
        head = new GenreNode;
        head->g = bcToCopy.head->g;
        GenreNode* newPtr = head;

        for(GenreNode* bcToCopyGenrePtr = bcToCopy.head->next; bcToCopyGenrePtr != nullptr; bcToCopyGenrePtr = bcToCopyGenrePtr->next){
            newPtr->next = new GenreNode;
            newPtr = newPtr->next;
            newPtr->g = bcToCopyGenrePtr->g;
        }
        newPtr->next = nullptr;
    }
}
string toUpper(string str) {
    string upper = "";
    for( int i = 0; i < str.length(); ++i)
        upper += toupper(str[i]);
    return upper;
}

void BookCollection::addBook(std::string genreName, std::string bookName) {
    GenreNode* temp = findGenre(genreName);
    if (temp != nullptr){
        temp->g.addBook(bookName);
    }else{
        cout<<"Genre does not exist"<<endl;
    }
}

void BookCollection::removeBook(std::string genreName, std::string bookName) {
    GenreNode* temp = findGenre(genreName);
    if(temp != nullptr){
        temp->g.removeBook(bookName);
    } else{
        cout<<"Genre does not exist"<<endl;
    }
}

void BookCollection::BookCollection::removeAuthor(std::string genreName, std::string bookName, int authorID) {
    GenreNode* temp = findGenre(genreName);
    if(temp != nullptr){
        temp->g.removeAuthor(authorID,bookName);
    } else{
        cout<<"Genre does not exist"<<endl;
    }
}

void BookCollection::BookCollection::addAuthor(std::string genreName, std::string bookName, int authorID, std::string authorName) {
    GenreNode* temp = findGenre(genreName);
    if(temp != nullptr){
        temp->g.addAuthor(authorID,bookName, authorName);
    } else{
        cout<<"Genre does not exist"<<endl;
    }
}

void BookCollection::BookCollection:: displayAllGenres() const {
    if (head == nullptr) {
        cout << "--EMPTY--" << endl;
    } else {
        for (GenreNode *current = head; current != nullptr; current = current->next) {
            cout << "Genre: " << current->g.getGenreName() << endl;
            current->g.displayGenre();
        }
    }
}

void BookCollection::BookCollection::removeGenre(std::string genreName) {
    GenreNode* temp = findGenre(genreName);
    int index = 0;
    if(temp != nullptr) {
        if (temp == head) {
            temp = head;
            head = head->next;
            genreCount--;
        } else {
            for (GenreNode *current = head; current != nullptr; current = current->next) {
                if (current->g.getGenreName() == genreName) {
                    return;
                }
                index++;
            }
            index = index - 1;
            GenreNode *previousNode = head;
            while (index > 0) {
                previousNode = previousNode->next;
                index--;
            }
            temp = previousNode->next;
            previousNode->next = temp->next;
            genreCount--;
        }
        temp->next = nullptr;
        delete temp;
    }
    cout << "This genre does not exist!" << endl;
}

BookCollection:: GenreNode* BookCollection::findGenre(string genreName) {
    for(GenreNode* current = head; current != nullptr; current = current->next){
        if (current->g.getGenreName() == genreName || toUpper(current->g.getGenreName()) == toUpper(genreName)){
            return current;
        }
    }
    return nullptr;
}