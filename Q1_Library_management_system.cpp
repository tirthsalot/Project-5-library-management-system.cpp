#include <iostream>
using namespace std;


class LibraryItem {
private:
    string itemTitle;
    string itemAuthor;
    string dueDate;

public:
    LibraryItem(string title, string author, string date) {
        itemTitle = title;
        itemAuthor = author;
        dueDate = date;
    }

    virtual ~LibraryItem() {}

    string getTitle() {
        return itemTitle;
    }

    string getAuthor() {
        return itemAuthor;
    }

    string getDueDate() {
        return dueDate;
    }

    void setTitle(string title) {
        itemTitle = title;
    }

    void setAuthor(string author) {
        itemAuthor = author;
    }

    void setDueDate(string date) {
        dueDate = date;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};


class Book : public LibraryItem {
private:
    int totalPages;

public:
    Book(string title, string author, string date, int pages)
        : LibraryItem(title, author, date) {

        totalPages = pages;
    }

    void checkOut() override {
        cout << "\nBook Checked Out Successfully!\n";
    }

    void returnItem() override {
        cout << "Book Returned Successfully!\n";
    }

    void displayDetails() override {
        cout << "\n========== BOOK DETAILS ==========\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Author     : " << getAuthor() << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Pages      : " << totalPages << endl;
    }
};


class DVD : public LibraryItem {
private:
    int durationMinutes;

public:
    DVD(string title, string author, string date, int duration)
        : LibraryItem(title, author, date) {

        durationMinutes = duration;
    }

    void checkOut() override {
        cout << "\nDVD Checked Out Successfully!\n";
    }

    void returnItem() override {
        cout << "DVD Returned Successfully!\n";
    }

    void displayDetails() override {
        cout << "\n========== DVD DETAILS ==========\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Director   : " << getAuthor() << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Duration   : " << durationMinutes << " Minutes\n";
    }
};


class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string title, string author, string date, int issue)
        : LibraryItem(title, author, date) {

        issueNumber = issue;
    }

    void checkOut() override {
        cout << "\nMagazine Checked Out Successfully!\n";
    }

    void returnItem() override {
        cout << "Magazine Returned Successfully!\n";
    }

    void displayDetails() override {
        cout << "\n======== MAGAZINE DETAILS ========\n";
        cout << "Title        : " << getTitle() << endl;
        cout << "Publisher    : " << getAuthor() << endl;
        cout << "Due Date     : " << getDueDate() << endl;
        cout << "Issue Number : " << issueNumber << endl;
    }
};


int main() {

    const int MAX_ITEMS = 100;

    LibraryItem* library[MAX_ITEMS];

    int totalItems = 0;

    int choice;

    do {

        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {


        case 1: {

            string title, author, dueDate;
            int pages;

            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter Total Pages: ";
            cin >> pages;

            try {

                if (pages <= 0) {
                    throw pages;
                }

                library[totalItems] =
                    new Book(title, author, dueDate, pages);

                totalItems++;

                cout << "Book Added Successfully!\n";
            }

            catch (...) {
                cout << "Invalid Page Number!\n";
            }

            break;
        }


        case 2: {

            string title, director, dueDate;
            int duration;

            cin.ignore();

            cout << "Enter DVD Title: ";
            getline(cin, title);

            cout << "Enter Director Name: ";
            getline(cin, director);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter Duration (Minutes): ";
            cin >> duration;

            try {

                if (duration <= 0) {
                    throw duration;
                }

                library[totalItems] =
                    new DVD(title, director, dueDate, duration);

                totalItems++;

                cout << "DVD Added Successfully!\n";
            }

            catch (...) {
                cout << "Invalid Duration!\n";
            }

            break;
        }


        case 3: {

            string title, publisher, dueDate;
            int issueNo;

            cin.ignore();

            cout << "Enter Magazine Title: ";
            getline(cin, title);

            cout << "Enter Publisher Name: ";
            getline(cin, publisher);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter Issue Number: ";
            cin >> issueNo;

            try {

                if (issueNo <= 0) {
                    throw issueNo;
                }

                library[totalItems] =
                    new Magazine(title, publisher, dueDate, issueNo);

                totalItems++;

                cout << "Magazine Added Successfully!\n";
            }

            catch (...) {
                cout << "Invalid Issue Number!\n";
            }

            break;
        }


        case 4: {

            if (totalItems == 0) {
                cout << "\nNo Library Items Available!\n";
            }

            else {

                for (int i = 0; i < totalItems; i++) {
                    library[i]->displayDetails();
                }
            }

            break;
        }


        case 5: {

            int itemNumber;

            if (totalItems == 0) {
                cout << "\nNo Items Available!\n";
                break;
            }

            cout << "Enter Item Number (1 to "
                 << totalItems << "): ";

            cin >> itemNumber;

            if (itemNumber >= 1 && itemNumber <= totalItems) {

                library[itemNumber - 1]->checkOut();
            }

            else {
                cout << "Invalid Item Number!\n";
            }

            break;
        }


        case 6: {

            int itemNumber;

            if (totalItems == 0) {
                cout << "\nNo Items Available!\n";
                break;
            }

            cout << "Enter Item Number (1 to "
                 << totalItems << "): ";

            cin >> itemNumber;

            if (itemNumber >= 1 && itemNumber <= totalItems) {

                library[itemNumber - 1]->returnItem();
            }

            else {
                cout << "Invalid Item Number!\n";
            }

            break;
        }


        case 7:
            cout << "\nExiting Library Management System...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);


    for (int i = 0; i < totalItems; i++) {
        delete library[i];
    }

    return 0;
}