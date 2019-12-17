//
// Created by berilbayram on 14.12.2019.
//
#include <iostream>
#include "Genre.h"
#include "Book.h"
using namespace std;

Genre::Genre(const string gname){
    this->genreName = gname;
    this->bookCount = 0;
    this->head = nullptr;
}

Genre::~Genre(){
    int k = bookCount;
    for(int i = k; i != 0; i--){
        removeBook(head->b.getName());
    }
}

void Genre::setGenreName(const string gName) {
    this->genreName = gName;
}

string Genre::getGenreName() const {
    return genreName;
}

int Genre::getBookCount() const {
    return bookCount;
}

string toUpperBookName(string str) {
    string upper = "";
    for( int i = 0; i < str.length(); ++i)
        upper += toupper(str[i]);
    return upper;
}

void Genre::operator=(const class Genre & right) {
    bookCount = right.bookCount;
    if (right.head == nullptr){
        head = nullptr;
    } else{
        head = new BookNode;
        head->b = right.head->b;
        BookNode* newPtr = head;

        for(BookNode* current = right.head->next; current != nullptr; current = current->next ){
            newPtr->next = new BookNode;
            newPtr = newPtr->next;
            newPtr->b = current->b;
        }
        newPtr ->next = nullptr;
    }
}

Genre::Genre(const Genre &genreToCopy) {
    bookCount = genreToCopy.bookCount;
    if (genreToCopy.head == nullptr){
        head = nullptr;
    } else{
        head = new BookNode;
        head->b = genreToCopy.head->b;
        BookNode* newPtr = head;

        for(BookNode* current = genreToCopy.head->next; current != nullptr; current = current->next ){
            newPtr->next = new BookNode;
            newPtr = newPtr->next;
            newPtr->b = current->b;
        }
        newPtr ->next = nullptr;
    }
}

Genre::BookNode* Genre::findBook(const string name){
    for(BookNode* current = head; current != nullptr; current = current->next){
        if (current->b.getName() == name || toUpperBookName(current->b.getName()) == toUpperBookName(name)){
            return current;
        }
    }
    return nullptr;
}

bool Genre::addBook(const string bName) {
    BookNode* temp = findBook(bName);
    if (findBook(bName) == nullptr){
        BookNode* node = new BookNode;
        node->b.setName(bName);
        node->next = head;
        head = node;
        bookCount++;
        delete temp;
        return true;
    }
    cout << "ERROR: This book("<< bName <<") exists!" << endl;
    delete temp;
    return false;
}

bool Genre::removeBook(const std::string bName) {
    BookNode* temp = findBook(bName);
    int index = 0;
    if(temp != nullptr) {
        if (temp == head) {
            temp = head;
            head = head->next;
            bookCount--;
        } else {
            for (BookNode *current = head; current != nullptr; current = current->next) {
                if (current->b.getName() == bName) {
                    break;
                }
                index++;
            }
            index = index - 1;
            BookNode *previousNode = head;
            while (index > 0) {
                previousNode = previousNode->next;
                index--;
            }
            temp = previousNode->next;
            previousNode->next = temp->next;
            bookCount--;
        }
        temp->next = nullptr;
        delete temp;
        return true;
    }
    cout << "ERROR: This book ("<< bName << ") does not exist!" << endl;
    return false;
}

bool Genre::addAuthor(const int aId, const string aName, const string bookName) {
    BookNode* temp = findBook(bookName);
    if ( temp == nullptr ){
        cout << "ERROR: This book ("<< bookName << ") does not exist!" << endl;
        return false;
    } else {
        bool isAdded = temp->b.addAuthor(aId,aName);
        if(isAdded){
            return true;
        } else{
            return false;
        }
    }
}

bool Genre::removeAuthor(const int aId, const string bookName) {
    BookNode* temp = findBook(bookName);
    bool isRemoved;
    if( temp != nullptr){
        isRemoved = temp->b.removeAuthor(aId);
        if (isRemoved){
            return true;
        } else {
            return false;
        }
    } else {
        cout << "ERROR: This book ("<< bookName << ") does not exist!" << endl;
        return false;
    }
}

void Genre::displayGenre() {
    if (head == nullptr){
        cout<<"--EMPTY--"<<endl;
    } else{
        for(BookNode* current = head; current != nullptr; current = current->next){
            if(current->b.getName() == ""){
                cout<<"--EMPTY--"<< endl;
            } else{
                cout<< current->b.getName()<<endl;
                current->b.displayAuthors();
            }
        }
    }
}

void Genre::displayBooks(int authorId) const {
    cout << genreName << endl;
    for(BookNode* current = head; current != nullptr; current = current->next){
        if(!current->b.hasAuthor(authorId).empty() ){
            cout << "\t" << current->b.getName() << endl;
        }
    }
}

string Genre::findAuthorById(int authorID) const {
    string authorName;
    for(BookNode* current = head; current != nullptr; current = current->next){
        authorName = current->b.findAuthorById(authorID);
        if(authorName != "")
            return authorName;
    }
    return "";
}

