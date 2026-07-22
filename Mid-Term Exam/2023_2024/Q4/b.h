#include <iostream>
#include <vector>

using std::string;

class book {
public:
    string title;
    string author;
    string ISBN;
    bool isCOed;

    virtual void CO();
    virtual void CO(int days);
    virtual void CO(string user_id);
    virtual void CO(string user_id, int days);

    book(string title, string author, string ISBN);
    virtual ~book() = default;
};

class printed : public book {
public:
    int page;

    printed(string title, string author, string ISBN, int page) 
        : book(title, author, ISBN), page(page) {}
};

class ebook : public book {
public:
    float size;

    void CO() override;
    void CO(int days) override;
    void CO(string user_id) override;
    void CO(string user_id, int days) override;
    void CO_part(int start, int end);
    ebook(string title, string author, string ISBN, float size) 
        : book(title, author, ISBN), size(size) {}
};

class audio : public book {
public:
    int duration;

    void CO() override;
    void CO(int days) override;
    void CO(string user_id) override;
    void CO(string user_id, int days) override;
    void CO_part(int start, int end);
    audio(string title, string author, string ISBN, int duration) 
        : book(title, author, ISBN), duration(duration) {}
};

class library {
public:
    std::vector<book*> books;

    void add(book* b);
    void COBook(string ISBN);
    ~library();
};