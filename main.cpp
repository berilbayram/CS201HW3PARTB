#include <iostream>
#include "BookCollection.h"
using namespace std;


int main(){
    BookCollection bookCollection;
    bookCollection.addGenre("Fantasy");
    bookCollection.addBook("Fantasy", "Bible");
    bookCollection.addBook("Fantasy", "Quran");
    bookCollection.addAuthor("Fantasy", "Quran", 1, "God");
    bookCollection.addAuthor("Fantasy", "Bible", 2, "Jesus");
    bookCollection.addAuthor("Fantasy", "Bible", 1, "God");
    bookCollection.addGenre("Sci-Fi");
    bookCollection.addBook("Sci-Fi", "A Hitchhiker's Guide to The Galaxy");
    cout << "c1" << endl;
    bookCollection.addAuthor("Fantasy", "A Hitchhiker's Guide to The Galaxy", 1, "God");
    bookCollection.addAuthor("Sci-Fi", "A Hitchhiker's Guide to The Galaxy", 3, "Douglas Adams");
    cout << "c2" << endl;
    bookCollection.displayAllGenres();
    cout << "c3" << endl;
    bookCollection.displayGenre("Fantasy");
    cout << "c4" << endl;
    bookCollection.displayAuthor(1);
    cout << "c5" << endl;
    bookCollection.displayAuthor(3);
    bookCollection.addGenre("Romantic");
    bookCollection.addBook("Romantic", "Love is a Cake");
    bookCollection.addBook("Romantic", "Love is a Bike");
    bookCollection.addAuthor("Romantic", "Love is a Cake", 90, "Beril Bayram");
    bookCollection.addAuthor("Romantic", "Love is a Bike", 85, "Alp");
    bookCollection.addAuthor("Romantic", "Love is a Bike", 90, "Beril Bayram");
    bookCollection.addAuthor("Romantic", "Love is a Bike", 87, "John Doe");
    cout << "c6" << endl;
    bookCollection.displayGenre("Romantic");
    cout << "c7" << endl;
    bookCollection.removeAuthor("Romantic", "Love is a Bike", 87);
    bookCollection.removeAuthor("Romantic", "Love is a Bike", 1);
    cout << "c8" << endl;
    bookCollection.displayGenre("Romantic");
    cout << "c9" << endl;
    bookCollection.addAuthor("Fantasy", "Quran", 85, "Alp");
    bookCollection.displayAuthor(85);
    cout << "c10" << endl;
    bookCollection.displayGenre("Romantic");
    BookCollection bookCollection1 = BookCollection();
    bookCollection1 = bookCollection;
    cout<<"c11"<< endl;
    bookCollection1.displayGenre("Romantic");
    BookCollection bookCollection2 = bookCollection;
    cout<<"c12"<< endl;
    bookCollection2.displayGenre("Romantic");
    bookCollection2.removeBook("Romantic", "Love is a Bike" );
    bookCollection2.displayGenre("Romantic");

    return 0;
}