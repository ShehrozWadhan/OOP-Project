#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Election {
public:
    string name;
    string type; // National or Local

    Election(string n, string t) : name(n), type(t) {}
};

class Candidate {
public:
    string name;
    string party;
    string area;
    string type; // National or Local

    Candidate(string n, string p, string a, string t)
        : name(n), party(p), area(a), type(t) {
    }
};

class Voter {
private:
    map<string, string> registeredVoters;
public:
    void login() {
        string voterId, password;
        cout << "Enter Voter ID: ";
        cin >> voterId;
        cout << "Enter Password: ";
        cin >> password;

        if (registeredVoters.count(voterId) && registeredVoters[voterId] == password) {
            cout << "Login successful. You can now vote.\n";
        }
        else {
            cout << "Invalid credentials.\n";
        }
    }

    void registerVoter(string voterId, string password) {
        registeredVoters[voterId] = password;
        cout << "Voter registered successfully.\n";
    }
};

class Administrator {
private:
    string name;
    string adminUsername = "admin";
    string adminPassword = "admin123";
    vector<Election> elections;
    vector<Candidate> candidates;
    Voter voter;

    bool authenticate() {
        string username, password;
        cout << "Enter Admin Username: ";
        cin >> username;
        cout << "Enter Admin Password: ";
        cin >> password;
        return username == adminUsername && password == adminPassword;
    }

public:
    Administrator(string n) : name(n) {}

    void adminMenu() {
        if (!authenticate()) {
            cout << "Authentication failed.\n";
            return;
        }

        int choice;
        while (true) {
            cout << "\n--- ADMIN MENU ---\n";
            cout << "1. Create Election\n";
            cout << "2. Add Candidate\n";
            cout << "3. Show National Candidates\n";
            cout << "4. Show Local Candidates\n";
            cout << "5. Show All Elections\n";
            cout << "6. Add Voter\n";
            cout << "7. Logout\n";
            cin >> choice;

            switch (choice) {
            case 1:
                createElection(); break;
            case 2:
                addCandidate(); break;
            case 3:
                AllCandidatesInfoNational(); break;
            case 4:
                AllCandidatesInfoLocal(); break;
            case 5:
                AllElectionsCreated(); break;
            case 6:
                addVoter(); break;
            case 7:
                return;
            default:
                cout << "Invalid choice.\n";
            }
        }
    }

    void createElection() {
        string name, type;
        cout << "Enter Election Name: ";
        cin >> name;
        cout << "Enter Election Type (National/Local): ";
        cin >> type;
        elections.push_back(Election(name, type));
        cout << "Election created successfully.\n";
    }

    void addCandidate() {
        string name, party, area, type;
        cout << "Enter Candidate Name: ";
        cin >> name;
        cout << "Enter Party: ";
        cin >> party;
        cout << "Enter Area: ";
        cin >> area;
        cout << "Enter Type (National/Local): ";
        cin >> type;
        candidates.push_back(Candidate(name, party, area, type));
        cout << "Candidate added successfully.\n";
    }

    void AllCandidatesInfoNational() {
        cout << "--- National Candidates ---\n";
        for (auto& c : candidates) {
            if (c.type == "National") {
                cout << "Name: " << c.name << ", Party: " << c.party << ", Area: " << c.area << endl;
            }
        }
    }

    void AllCandidatesInfoLocal() {
        cout << "--- Local Candidates ---\n";
        for (auto& c : candidates) {
            if (c.type == "Local") {
                cout << "Name: " << c.name << ", Party: " << c.party << ", Area: " << c.area << endl;
            }
        }
    }

    void AllElectionsCreated() {
        cout << "--- Elections Created ---\n";
        for (auto& e : elections) {
            cout << "Election: " << e.name << ", Type: " << e.type << endl;
        }
    }

    void addVoter() {
        string voterId, password;
        cout << "Enter Voter ID: ";
        cin >> voterId;
        cout << "Enter Password: ";
        cin >> password;
        voter.registerVoter(voterId, password);
    }
};

int main() {
    Administrator admin("Junaid");
    Voter voter;
    int choice;

    while (true) {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Login as Admin\n2. Login as Voter\n3. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            admin.adminMenu(); break;
        case 2:
            voter.login(); break;
        case 3:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option.\n";
        }
    }
    return 0;
}
