#include "b.h"

void library::add(book* b) {
    books.push_back(b);
}

void library::COBook(string ISBN) {
    for (book* b : books) {
        if (b->ISBN == ISBN) {
            b->CO();
            return;
        }
    }
}