//
// Created by berilbayram on 14.12.2019.
//

#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(){
    head = nullptr;
    name = "";
    authorCount = 0;
}

Book::Book(const string name){
    this->name = name;
    authorCount = 0;
    head = nullptr;
}

Book::~Book() {
    int k = authorCount;
    for(int i = 0; i < k; i++) {
        removeAuthor(head->a.getID());
    }
}

void Book::setName(const std::string bookName) {
    this->name = bookName;
}

string Book::getName() const {
    return name;
}

int Book::getAuthorCount() const {
    return authorCount;
}

void Book::operator=(const class Book & right) {
    authorCount = right.authorCount;
    this->name = right.name;
    if (right.head == nullptr){
        head = nullptr;
    } else {
        head = new AuthorNode;
        head->a = right.head->a;
        AuthorNode* newPtr = head;
        for(AuthorNode* authorPtr = right.head->next; authorPtr != nullptr; authorPtr = authorPtr->next){
            newPtr->next = new AuthorNode;
            newPtr = newPtr->next;
            newPtr->a = authorPtr->a;
        }
        newPtr->next = nullptr;
    }
}

Book::Book(const Book &bookToCopy) {
    authorCount = bookToCopy.authorCount;
    this->name = bookToCopy.name;
    if (bookToCopy.head == nullptr){
        head = nullptr;
    } else {
        head = new AuthorNode;
        head->a = bookToCopy.head->a;
        AuthorNode* newPtr = head;

        for(AuthorNode* authorPtr = bookToCopy.head->next; authorPtr != nullptr; authorPtr = authorPtr->next){
            newPtr->next = new AuthorNode;
            newPtr = newPtr->next;
            newPtr->a = authorPtr->a;
        }
        newPtr->next = nullptr;
    }
}

Book:: AuthorNode* Book::findAuthor(int id) {
    for(AuthorNode* current = head; current != nullptr; current = current->next){
        if (current->a.getID() == id){
            return current;
        }
    }
    return nullptr;
}

bool Book::removeAuthor(const int id) {
    AuthorNode* temp = nullptr;
    temp = findAuthor(id);
    int index = 0;
    if(temp != nullptr) {
        if (temp == head) {
            temp = head;
            head = head->next;
            authorCount--;
        } else {
            for (AuthorNode *current = head; current != nullptr; current = current->next) {
                if (current->a.getID() == id) {
                    break;
                }
                index++;
            }
            index = index - 1;
            AuthorNode *previousNode = head;
            while (index > 0) {
                previousNode = previousNode->next;
                index--;
            }
            temp = previousNode->next;
            previousNode->next = temp->next;
            authorCount--;
        }
        temp->next = nullptr;
        delete temp;
        return true;
    }
    cout << "ERROR: This author (" << id <<") does not exist!" << endl;
    return false;
}

bool Book::Book:: addAuthor(const int id, const string name){
    AuthorNode* temp = findAuthor(id);
    if (temp == nullptr){
        temp = new AuthorNode;
        temp->a.setName(name);
        temp->a.setID(id);
        temp->next = head;
        head = temp;
        authorCount++;
        return true;
    }
    cout << "ERROR: This author("<< name <<") exists!" << endl;
    return false;
}

void Book::Book::displayAuthors() const {
    if (head == nullptr){
        cout<<"--EMPTY--"<<endl;
    } else{
        for(AuthorNode* current = head; current != nullptr; current = current->next){
            if(current->a.getName() == ""){
            } else{
                cout<< "\t" << current->a.getID() << ", " << current->a.getName() <<endl;
            }
        }
    }
}

string Book::hasAuthor(int id) const {
    for(AuthorNode* current = head; current != nullptr; current = current->next){
        if (current->a.getID() == id){
            return this->getName();
        }
    }
    return "";
}

string Book::findAuthorById(int authorID) {
    AuthorNode* current = head;
    while (current != nullptr){
        if (current->a.getID() == authorID) {
            return current->a.getName();
        }
        current = current->next;
    }
    return "";
}