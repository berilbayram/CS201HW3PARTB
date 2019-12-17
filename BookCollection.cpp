//
// Created by berilbayram on 14.12.2019.
//

#include <iostream>
#include "BookCollection.h"


BookCollection::BookCollection(){
    head = nullptr;
    genreCount = 0;
}

BookCollection::~BookCollection(){
    int k = genreCount;
    for(int i = 0; i < k; i++){
        removeGenre(head->g.getGenreName());
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
        cout<<"ERROR: Genre (" << genreName <<  ") does not exist"<<endl;
    }
}

void BookCollection::removeBook(std::string genreName, std::string bookName) {
    GenreNode* temp = findGenre(genreName);
    if(temp != nullptr){
        temp->g.removeBook(bookName);
    } else{
        cout<<"ERROR: Genre (" << genreName <<  ") does not exist"<<endl;
    }
}

void BookCollection::BookCollection::removeAuthor(std::string genreName, std::string bookName, int authorID) {
    GenreNode* temp = findGenre(genreName);
    if(temp != nullptr){
        temp->g.removeAuthor(authorID,bookName);
    } else{
        cout<<"ERROR: Genre (" << genreName <<  ") does not exist"<<endl;
    }
}

void BookCollection::BookCollection::addAuthor(std::string genreName, std::string bookName, int authorID, std::string authorName) {
    GenreNode* temp = findGenre(genreName);
    if(temp != nullptr){
        temp->g.addAuthor(authorID,authorName, bookName);
    } else{
        cout<<"ERROR: Genre (" << genreName <<  ") does not exist"<<endl;
    }
}

void BookCollection::BookCollection:: displayAllGenres() const {
    if (head == nullptr) {
        cout << "--EMPTY--" << endl;
    } else {
        for (GenreNode *current = head; current != nullptr; current = current->next) {
            cout << current->g.getGenreName() << endl;
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
                    break;
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
    } else {
        cout<<"ERROR: Genre (" << genreName <<  ") does not exist"<<endl;
    }
}

BookCollection:: GenreNode* BookCollection::findGenre(string genreName) {
    for(GenreNode* current = head; current != nullptr; current = current->next){
        if (current->g.getGenreName() == genreName || toUpper(current->g.getGenreName()) == toUpper(genreName)){
            return current;
        }
    }
    return nullptr;
}

void BookCollection::displayAuthor(int authorID) {
    cout << authorID << ", " << findAuthorById(authorID) << endl;
    for (GenreNode* current = head ; current != nullptr ; current = current->next) {
        current->g.displayBooks(authorID);
    }

}

void BookCollection::addGenre(std::string genreName) {
    GenreNode* temp = nullptr;
    temp = findGenre(genreName);
    if (temp == nullptr){
        temp = new GenreNode;
        temp->g.setGenreName(genreName);
        temp->next = head;
        head = temp;
        genreCount++;
    } else {
        cout << "ERROR: This genre("<< genreName <<") exists!" << endl;
    }
}

void BookCollection::displayGenre(string genreName) {
    cout << genreName << endl;
    for (GenreNode* current = head; current != nullptr; current = current->next ){
        if( current->g.getGenreName() == genreName ){
            current->g.displayGenre();
            return;
        }
    }
    cout << "--EMPTY--"<< endl;
}

string BookCollection::findAuthorById(int authorID){
    string authorName = "";
    for(GenreNode* current = head; current != nullptr; current = current->next){
        authorName = current->g.findAuthorById(authorID);
        if(authorName != "")
            return authorName;
    }
    return authorName;
}
