//
// Created by berilbayram on 14.12.2019.
//

#include "Author.h"

Author::Author(){
}

Author::Author(const int id, const string name){
    this->name = name;
    this->id = id;
}

string Author::getName() const{
    return name;
}

int Author::getID() const {
    return id;
}

void Author::setID(const int id) {
    this->id = id;
}

void Author::setName(const std::string id) {
    this->name = id;
}
