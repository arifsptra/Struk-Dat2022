#include <iostream>
#include <string>
using namespace std;

class List
{
private:
    struct node
    {
        string firstName;
        string lastName;
        string phoneNumber;
        node *next;
    };
    node *head, *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void create_contact(string first, string last, string cellNumber) // Create node and add it onto the linked list
    {
        node *temp = new node;
        temp->firstName = first;
        temp->lastName = last;
        temp->phoneNumber = cellNumber;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display_all() const
    {
        int contactNum = 0;
        if (head == NULL) {
            cout << "You have no contacts.";
        }
        for (node *curr = head; curr; curr = curr->next)
        {
            cout << "\nContact Number: " << ++contactNum << "\n";
            cout << "First Name: " << curr->firstName << "\n";
            cout << "Last Name: " << curr->lastName << "\n";
            cout << "Phone Number: " << curr->phoneNumber << "\n";
        }
    }

    void display_contact(string first, string last)
    {
        bool found;

        node *curr = head;
        found = false;
        int idx = -1;

        while (curr != NULL & !found)
        {
            if (curr->firstName == first && curr->lastName == last)
            {
                idx++;
                found = true;
            }
            else
            {
                curr = curr->next;
            }

        }
        if (found)
        {
            cout << "First Name: " << curr->firstName << "\n";
            cout << "Last Name: " << curr->lastName << "\n";
            cout << "Phone Number: " << curr->phoneNumber << "\n";
            delete_position(idx);
        }
        else
        {
            cout << "\n" << first << " " << last << " was not found.\n";
        }
    }

    void name_search(string titleSearched)
    {
        bool found;

        node *curr = head;
        found = false;

        while (curr != NULL & !found)
        {
            if (curr->firstName == titleSearched)
            {
                found = true;
            }
            else
            {
                curr = curr->next;
            }

        }
        if (found)
        {
            cout << "\n" << titleSearched << " was found.\n";
            cout << "-----------------------------------\n";
            cout << "First Name: " << curr->firstName << "\n";
            cout << "Last Name: " << curr->lastName << "\n";
            cout << "Phone Number: " << curr->phoneNumber << "\n";
        }
        else
        {
            cout << "\n" << titleSearched << " was not found.\n";
        }
    }


    void delete_position(int pos)
    {
        if (pos < 1 || head == nullptr)
            return;
        node *victim{ head };
        if (pos == 1) {  // deleting head
            if (tail == victim) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
            }
        }
        else {
            // deleting non-head node
            node *prev{ head };
            for (pos -= 2; pos; --pos) {
                if (prev == nullptr)
                    return;
                prev = prev->next;
            }
            victim = prev->next;
            prev->next = victim->next;
            if (tail == victim) {
                tail = prev;
            }
        }
        delete victim;
    }

    void pause() {
        getchar();
    }

};

int main()
{
    List Contacts; // create a Contacts item for the List class
    int position;
    string firstName;
    string lastName;
    string phoneNumber;
    string choice;
    int x;

    enum {
        ShowAll = 1,
        AddContact,
        RemoveContact,
        EditContact,
        SearchContacts,
        ExitContacts
    };

    bool exit_contacts = false;

    while (!exit_contacts) {
        cout << "\nWhat would you like to do?: " << "\n";
        cout << "1. Show All Contacts" << "\n";
        cout << "2. Add A Contact" << "\n";
        cout << "3. Remove A Contact" << "\n";
        cout << "4. Edit A Contact" << "\n";
        cout << "5. Search Contacts" << "\n";
        cout << "6. Exit The Program" << "\n\n";
        cin >> choice;

        try {
            x = stoi(choice);
        }
        catch (...) {
            x = 0;
        }

        switch (x)
        {
        case ShowAll:
            cout << "\n";
            Contacts.display_all();
            cout << "\n";
            break;
        case AddContact:
            cout << "\nEnter the contacts' first name: ";
            cin >> firstName;
            cout << "\nEnter the contacts' last name: ";
            cin >> lastName;
            cout << "\nEnter the contacts' phone number: ";
            cin >> phoneNumber;
            Contacts.create_contact(firstName, lastName, phoneNumber);
            cout << "\n";
            break;
        case RemoveContact:
            cout << "\nEnter the contact number of the contact you would like to remove: ";
            cin >> position;
            Contacts.delete_position(position);
            break;
        case EditContact:
            cout << "\nTo find the contact you would like to edit: ";
            cout << "\nEnter the contacts' first name: ";
            cin >> firstName;
            cout << "\nEnter the contacts' last name: ";
            cin >> lastName;
            Contacts.display_contact(firstName, lastName);
            cout << "\nEnter the contacts' NEW first name: ";
            cin >> firstName;
            cout << "\nEnter the contacts' NEW last name: ";
            cin >> lastName;
            cout << "\nEnter the contacts' NEW phone number: ";
            cin >> phoneNumber;
            Contacts.create_contact(firstName, lastName, phoneNumber);
            break;
        case SearchContacts:
            cout << "\nEnter the contacts' first name: ";
            cin >> firstName;
            Contacts.name_search(firstName);
            break;
        case ExitContacts:
            exit_contacts = true;
            break;
        default:
            cout << "\n" << choice << " is not an option. Please select a valid option." << "\n";
            break;
        }
    }
    Contacts.pause();
    return 0;
}
