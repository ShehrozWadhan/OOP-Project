#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base user class
class User {
protected:
    string username;
    string password;
public:
    virtual bool login() = 0;
};

// Candidate (unused directly, but can help in future expansion)
class Candidate {
    string name;
    string party;
    int votes;
public:
    Candidate() { votes = 0; }
    void setInfo(string n, string p) {
        name = n;
        party = p;
    }
    void incrementVotes() { votes++; }
    int getVoteCount() const { return votes; }
    string getCandidateInfo() const { return name + " (" + party + ")"; }
};

// Election structure
class Election {
protected:
    string name;
public:
    void setName(string n) { name = n; }
    string getName() const { return name; }

    bool isLive() {
        ifstream f(name + "_status.txt");
        if (!f) return false;
        string status;
        f >> status;
        f.close();
        return status == "live";
    }

    void startElection() {
        ofstream f(name + "_status.txt");
        f << "live";
        f.close();
    }

    void endElection() {
        ofstream f(name + "_status.txt");
        f << "ended";
        f.close();
    }

    void addCandidates() {
        int num;
        cout << "Enter number of candidates: ";
        cin >> num;
        cin.ignore();
        ofstream cf(name + "_candidates.txt");
        ofstream vf(name + "_votes.txt");
        for (int i = 0; i < num; i++) {
            string cname, party;
            cout << "Enter Candidate Name: ";
            getline(cin, cname);
            cout << "Enter Party Name: ";
            getline(cin, party);
            cf << cname << "," << party << endl;
            vf << 0 << endl;
        }
        cf.close();
        vf.close();

        ofstream stat(name + "_status.txt");
        stat << "not_started";
        stat.close();
    }
};

// Admin user
class Administrator : public User {
public:
    bool login() override {
        string u, p;
        ifstream file("admin.txt");
        if (!file) {
            cout << "Admin credentials not set.\n";
            return false;
        }
        getline(file, username);
        getline(file, password);
        file.close();

        cout << "Enter Admin Username: ";
        cin >> u;
        cout << "Enter Admin Password: ";
        cin >> p;

        if (u == username && p == password) {
            cout << "Admin login successful.\n";
            adminMenu();
            return true;
        }
        cout << "Invalid credentials.\n";
        return false;
    }

    void adminMenu() {
        int choice;
        do {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. Change Admin Credentials\n2. Create Election\n3. Add Voter\n4. Start Election\n5. End Election\n6. Logout\nEnter choice: ";
            cin >> choice;
            switch (choice) {
            case 1: changeCredentials(); break;
            case 2: createElection(); break;
            case 3: addVoter(); break;
            case 4: startElection(); break;
            case 5: endElection(); break;
            case 6: cout << "Logging out...\n"; break;
            default: cout << "Invalid option.\n";
            }
        } while (choice != 6);
    }

    void changeCredentials() {
        cout << "Enter new admin username: ";
        cin >> username;
        cout << "Enter new admin password: ";
        cin >> password;
        ofstream file("admin.txt");
        file << username << endl << password << endl;
        file.close();
        cout << "Credentials updated.\n";
    }

    void createElection() {
        string elname;
        cout << "Enter Election Name: ";
        cin.ignore();
        getline(cin, elname);
        ofstream list("elections.txt", ios::app);
        list << elname << endl;
        list.close();

        Election e;
        e.setName(elname);
        e.addCandidates();
    }

    void addVoter() {
        string cnic, doi, pass;
        cout << "Enter CNIC: ";
        cin >> cnic;
        cout << "Enter Date of Issue: ";
        cin >> doi;
        cout << "Enter Password: ";
        cin >> pass;

        ofstream file("voters.txt", ios::app);
        file << cnic << " " << doi << " " << pass << endl;
        file.close();
        cout << "Voter added.\n";
    }

    void startElection() {
        string elname;
        cout << "Enter election name to start: ";
        cin.ignore();
        getline(cin, elname);
        ofstream f(elname + "_status.txt");
        f << "live";
        f.close();
        cout << "Election started.\n";
    }

    void endElection() {
        string elname;
        cout << "Enter election name to end: ";
        cin.ignore();
        getline(cin, elname);
        ofstream f(elname + "_status.txt");
        f << "ended";
        f.close();
        cout << "Election ended.\n";
    }
};

// Voter user
class Voter : public User {
public:
    bool login() override {
        string u, d, p;
        cout << "Enter CNIC: ";
        cin >> u;
        cout << "Enter Date of Issue: ";
        cin >> d;
        cout << "Enter Password: ";
        cin >> p;

        ifstream file("voters.txt");
        string file_cnic, file_doi, file_pass;
        while (file >> file_cnic >> file_doi >> file_pass) {
            if (file_cnic == u && file_doi == d && file_pass == p) {
                username = u;
                cout << "Voter login successful.\n";
                voterMenu();
                return true;
            }
        }
        cout << "Invalid voter credentials.\n";
        return false;
    }

    void voterMenu() {
        int choice;
        do {
            cout << "\n--- Voter Menu ---\n";
            cout << "1. Cast Vote\n2. Logout\nEnter choice: ";
            cin >> choice;
            if (choice == 1) castVote();
        } while (choice != 2);
    }

    void castVote() {
        string election;
        cout << "Enter Election Name: ";
        cin.ignore();
        getline(cin, election);

        ifstream stat(election + "_status.txt");
        string status;
        if (!(stat >> status) || status != "live") {
            cout << "Election not live.\n";
            return;
        }
        stat.close();

        ifstream check(election + "_voted.txt");
        string line;
        while (getline(check, line)) {
            if (line == username) {
                cout << "You have already voted.\n";
                return;
            }
        }
        check.close();

        string candidates[100], parties[100];
        int count = 0;
        ifstream cfile(election + "_candidates.txt");
        while (getline(cfile, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                candidates[count] = line.substr(0, pos);
                parties[count] = line.substr(pos + 1);
                count++;
            }
        }
        cfile.close();

        int votes[100];
        ifstream vfile(election + "_votes.txt");
        for (int i = 0; i < count; i++) vfile >> votes[i];
        vfile.close();

        cout << "\nCandidates:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << candidates[i] << " (" << parties[i] << ")\n";
        }

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > count) {
            cout << "Invalid choice.\n";
            return;
        }

        votes[choice - 1]++;
        ofstream voteOut(election + "_votes.txt");
        for (int i = 0; i < count; i++) voteOut << votes[i] << endl;
        voteOut.close();

        ofstream voted(election + "_voted.txt", ios::app);
        voted << username << endl;
        voted.close();

        cout << "Vote cast successfully.\n";
    }
};

// Results function (not in class)
void showResults() {
    string elname;
    cout << "Enter election name to view results: ";
    cin.ignore();
    getline(cin, elname);

    ifstream stat(elname + "_status.txt");
    string status;
    if (!(stat >> status) || status == "live") {
        cout << "Election is still live or status not found.\n";
        return;
    }
    stat.close();

    string candidates[100], parties[100];
    int votes[100], count = 0;
    string line;
    ifstream cf(elname + "_candidates.txt");
    while (getline(cf, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            candidates[count] = line.substr(0, pos);
            parties[count] = line.substr(pos + 1);
            count++;
        }
    }
    cf.close();

    ifstream vf(elname + "_votes.txt");
    for (int i = 0; i < count; i++) vf >> votes[i];
    vf.close();

    int maxVotes = -1, winnerIndex = -1;
    for (int i = 0; i < count; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1)
        cout << "\nElection Winner: " << candidates[winnerIndex]
        << " (" << parties[winnerIndex] << ") with " << maxVotes << " votes.\n";
    else
        cout << "No votes cast.\n";
}

// Main function
int main() {
    int choice;
    do {
        cout << "\t\t\t\t========Online Voting Portal=========";
        cout << "\n\t\t\t\t--------    Main Menu     --------\n";
        cout << "1. Admin Login\n2. Voter Login\n3. View Results\n4. Exit\nEnter choice: ";
        cin >> choice;
        User* user = nullptr;
        if (choice == 1) {
            user = new Administrator();
            user->login();
            delete user;
        }
        else if (choice == 2) {
            user = new Voter();
            user->login();
            delete user;
        }
        else if (choice == 3) {
            showResults();
        }
        else if (choice != 4) {
            cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}
