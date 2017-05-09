#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct queue {
	string passname;
	struct queue *ptr;
};
typedef struct queue QUEUE;

struct flights
{
	int flightId;
	string startPoint;
	string endPoint;
	int startTime;
	int endTime;
	int price;
	char planeType;
	int seats;
	int numberOfReservations;
	QUEUE *first;
	struct flights *ptr;
};
typedef struct flights FLIGHTS;

struct passenger {
	string name;
	int numberOfPassport;
	string nationality;
	string address;
	int telephone;
	struct passenger *ptr;
};
typedef struct passenger PASSENGER;



int main()
{
	int fIDinput;
	int num_of_fl = 0; //Αριθμός πτήσεων.
	int flights[10], temp3, temp4; //Πίνακας πτήσεων, για να αποθηκεύει τους κωδικούς πτήσεων των επιβατών.
	// Βοηθητικές μεταβλητές.
	char input; //Εισαγωγή επιλογής από τον χρήστη για το βρόχο switch.
	string temp1, temp2 , passname;//Βοηθητικές μεταβλητές.
	QUEUE *tempQ = NULL; //Βοηθητικοί pointers
	FLIGHTS *temp= NULL, *tempD= NULL, *first=NULL; 
	PASSENGER *tempP = NULL, *Pfirst = NULL; 
	bool helper = 0; //βοηθητική μεταβλητή
	cout<<"Pathste A gia eisagwgh kwdikwn pthshs-eggrafh epibath"<<endl;
	cout << "B gia ektypwsh leptomereiwn kapoias pthshs" << endl;
	cout << "C gia ektypwsh leptomereiwn kapoiou epibath"<<endl;
	cout << "D gia diagrafh pthshs"<<endl;
	cout << "E gia kataxwrhsh pthshs"<<endl;
	cout << "F gia akyrwsh krathshs"<<endl;
	cout << "G gia termatismo tou programmatos" << endl;
	cin >> input;
	while (true) { //Για να τρέχει το πρόγραμμα όσες φορές θέλουμε
		switch (input) { //βρόχος switch. οικονομικότερο από πολλά if-else if 
		case 'A': {
			cout << "Pliktrologiste ton arithmo twn ptisewn pou tha kanete" << endl;
			cin >> num_of_fl; //αριθμός πτήσεων
			for (int i = 0;i < num_of_fl;i++) {
				cout<<"Pliktrologiste ton kwdiko ths pthshs"<<endl;
				cin >> flights[i]; //Εισαγωγή στον πίνακα των αριθμών της κάθε πτήσης. 
				//Λαμβάνουμε την παραδοχή ότι ο χρήστης βάζει τους κωδικούς με την σωστή σειρά.
			}
			//Αναζήτηση για τις πτήσεις που αντιστοιχούν στους κωδικούς που δόθηκαν.
			//Έλεγχοι για τους προορισμούς και τις ώρες ότι στέκουν μεταξύ τους για να μπορεί να γίνει το ταξίδι.
			for (int i = 0;i < num_of_fl - 1;i++) {
				temp = first; //Αρχή λίστας
				while (temp != 0) //Όσο έχει η λίστα ακόμα στοιχεία
				{
					if (flights[i] == temp->flightId) {
						temp1 = temp->endPoint; //Ψάχνει τον προορισμό της πρώτης πτήσης
						temp3 = temp->endTime; //Ψάχνει τι ώρα φτάνει η πτήση τον προορισμό
						
					}
					if (flights[i + 1] == temp->flightId) {
						temp2 = temp->startPoint; //Ψάχνει από που ξεκιάει η δεύτερη πτήση
						temp4 = temp->startTime; // Τι ώρα ξεκινάει, πρέπει να είναι μετά την ώρα άφιξης της πρώτης πτήσης.
					}
					temp = temp->ptr; //Μετάβαση στο επόμενο στοιχείο της λίστας.
				}
				if (temp4 < temp3 || temp1 != temp2) { //Αν τα δεδομένα είναι λάθος, βγάλε μήνυμα στην οθόνη.
				//Δηλαδή, αν η ώρα που προσγειώνεται η πρώτη πτήση, είναι μετά την ώρα που ξεκινά η δεύτερη πτήση
				//ή αν ο προορισμός της πρώτης πτήσης, είναι διαφορετικός από την αφετηρία της δεύτερης πτήσης
					cout << "Lathos dedomena." << endl;
					goto FIRST_OPTION;
				}
			}
			//Έλεγχος διαθεσιμότητας πτήσεων
			helper = 0;
			for (int i = 0;i < num_of_fl;i++) {
				temp = first; //Αρχή λίστας
				while (temp != 0) { //Όσο έχει η λίστα ακόμα στοιχεία
					if (flights[i] == temp->flightId) { //Σταμάτα την αναζήτηση μόλις βρεις την πτήση.
						break;
					}
					temp = temp->ptr; //Μετάβαση στο επόμενο στοιχείο της λίστας.
				}
				if (temp->seats == temp->numberOfReservations) {//Αν οι διαθέσιμες θέσεις για την εκάστοτε 
					//πτήση είναι ίσες με τον αριθμό των θέσεων του αεροπλάνου, σταμάτα τον έλεγχο
					printf("H pthsh %d einai gemath", flights[i]);
					helper = 1;
					break;
				}

			}
			if (helper == 0) {
				for (int i = 0; i < num_of_fl;i++) {
					temp = first; //Αρχικός κόμβος λίστας.
					while (temp != 0) { //Όσο έχει η λίστα ακόμα στοιχεία
						if (flights[i] == temp->flightId) { //Αναζήτηση της πτήσης που επιθυμούμε
							temp->numberOfReservations = temp->numberOfReservations + 1; 
							//Αύξηση κατά μιας μονάδας του αριθμού των κρατημένων θέσεων
							break;
						}
						temp = temp->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
					}
				}

				//κώδικας για την εισαγωγή των στοιχείων του εκάστοτε επιβάτη
				if (Pfirst != NULL) {
					tempP = Pfirst; //Αρχικοποιήση pointer tempP με την τιμή του πρώτου κόμβου της λίστας Passenger
					while (tempP->ptr != NULL) { //Όσο η λίστα έχει στοιχεία
						tempP = tempP->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
					}
					tempP->ptr = new PASSENGER;
					tempP = tempP->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας

				}
				else {
					Pfirst = new PASSENGER;
					tempP = Pfirst;
				}

				cout << "Plhktrologhste to onomatepwnymo tou epibath" << endl;
				cin.ignore(); //Αγνοεί ότι υπάρχει στον buffer
				getline(cin, tempP->name); //Εισαγωγή ονόματος επιβάτη.
				//Χρήση της getline ώστε αν δοθούν από τον χρήστη παραπάνω από μία λέξεις
				//να τις εκχωρήσει όλες, και όχι μόνο την πρώτη λέξη όπως θα γινόταν με σκέτο cin
				cout << endl << "Plhktrologhste ton arithmo diabathriou" << endl;
				cin >> tempP->numberOfPassport; //Εισαγωγή αριθμού διαβατηρίου επιβάτη
				cout << endl << "Plhktrologhste ethikothta" << endl;
				cin >> tempP->nationality; //Εισαγωγή εθνικότητας επιβάτη
				cout << endl << "Plhktrologhste dieuthinsi" << endl;
				cin.ignore();
				getline(cin, tempP->address); //Εισαγωγή διεύθυνσης επιβάτη
				cout << endl << "Plhktrologhste thlefwno" << endl;
				cin >> tempP->telephone; //Εισαγωγή τηλεφώνου επιβάτη
				tempP->ptr = NULL; //Τελευταίος κόμβος της λίστας
			}
			else { //αναζήτηση στην λίστα
				cin.ignore();
				cout << "Plhktrologiste to onomaneponumo sas" << endl;
				getline(cin, passname);
				for (int i = 0;i < num_of_fl;i++) {
					temp = first; //Αρχικός κόμβος λίστας.

					while (temp != 0) { //Όσο έχει η λίστα ακόμα στοιχεία

						if (flights[i] == temp->flightId) { //Ψάχνει την πτήση που θέλουμε να αναζητήσουμε
							break;
						}
						temp = temp->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
					}
					
					if (temp->first != NULL) { //Αν το στοιχείο δεν είναι το τελευταίο της λίστας
						tempQ = temp->first; //Μετάβαση στον επόμενο κόμβο της λίστας
						while (tempQ->ptr != 0) { //Όσο υπάρχουν στοιχεία στη ουράς
							tempQ = tempQ->ptr; //Πάμε στο επόμενο στοιχείο της ουράς
						}
						tempQ->ptr = new QUEUE; //Δέσμευση χώρου στη μνήμη για νέο κόμβο τύπου QUEUE
						tempQ = tempQ->ptr; //Μετάβαση στον επόμενο κόμβο της ουράς
						tempQ->ptr = 0; //τέλος ουράς
						tempQ->passname = passname;

					}
					else {
						tempQ = new QUEUE; //Δέσμευση χώρου στην μνήμη για νέο κόμβο τύπου QUEUE
						tempQ->ptr = NULL; //Δήλωση του τέλους της ουράς
						tempQ->passname = passname;
						temp->first = tempQ; //Η first θα δείχνει στην θέση μνήμης του tempQ
					}
				}

			}
			break;
		FIRST_OPTION: {
			break;
			}
		}//Τέλος case A
		case 'B': {
			//εκτύπωση λεπτομερειών πτήσης
			int kwdikos_ptisis;
			cout << "Plhktrologhste ton kwdiko ths pthshs gia thn opoia thelete na mathete leptomereies" << endl;
			cin >> kwdikos_ptisis;
			temp = first; //Αρχικός κόμβος λίστας.
		    while (temp != 0) {
				if (kwdikos_ptisis == temp->flightId) { //Αναζήτηση της εκάστοτε πτήσης
						//Εμφάνιση στην οθόνη όλων των στοιχείων του επιβάτη
					cout << "Afetiria: "<< temp->startPoint << endl;
					cout << "Proorismos: " << temp->endPoint << endl;
					cout << "Wra anaxwrishs: " << temp->startTime << endl;
					cout << "Wra afikshs: " << temp->endTime << endl;
					cout << "Kostos eishthriou: " << temp->price << endl;
					cout << "Typos aeroplanou: " << temp->planeType << endl;
					cout << "Theseis: " << temp->seats << endl;
					cout << "Kratiseis: " << temp->numberOfReservations << endl;
					break;
				}
				temp = temp->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
			}
			//τέλος εκτύπωσης λεπτομερειών πτήσης
			break;
		}//Τέλος case B
		case 'C': {
			//εκτύπωση λεπτομερειών επιβάτη
			int diabathrio;
			cout << "Plhktrologhste arithmo diabathriou epibath";
			cin >> diabathrio;
			for (int i = 0; i < num_of_fl;i++) {
				tempP = Pfirst; //Αρχικός κόμβος λίστας.
				if (tempP == 0) break; //να σταματήσει η αναζήτηση αν έχει πάρει το temp την τιμή 0 από το while παρακάτω
				while (tempP != 0) { //Όσο η λίστα έχει στοιχέία
					if (diabathrio == tempP->numberOfPassport) { //Μόλις βρεις αριθμό διαβατηρίου στη λίστα ίδιο με αυτόν που
						//δόθηκε από το πληκτρολόγιο, εμφάνισε τα στοιχεία του επιβάτη
						cout << tempP->name << endl;
						cout << tempP->nationality << endl;
						cout << tempP->address << endl;
						cout << tempP->telephone << endl;
						tempP = 0;
						break;
					}
					tempP = tempP->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
				}
				//τέλος εκτύπωσης λεπτομερειών επιβάτη
			}
			break;
		}//Τέλος case C
		case 'D': {
			cout << "Plhktrologhste ton kwdiko ths pthshs" << endl;
			cin >> fIDinput;
			tempD = first; 
			temp = first;
			while (tempD != 0) { //Όσο η λίστα έχει στοιχεία
				if (tempD->flightId == fIDinput) { 
					//Μόλις βρει την πτήση με κωδικό αυτόν που δόθηκε από τον χρήστη
					break; //σταματάει την αναζήτηση
				}
				temp = tempD; //Η μεταβλητή temp παίρνει την τιμή του προηγούμενου κόμβου
				tempD = temp->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
			}
			if(tempD==first) { //Αν είμαστε στο πρώτο στοιχείο της λίστας
				temp = tempD->ptr; //Το temp παίρνει την τιμή του δεύτερου στοιχείου
				delete(tempD); //Διαγραφή του κόμβου tempD
				first = temp;
			}
			else if (tempD != 0) { //Μόλις βρει την πτήση που θέλουμε
				temp->ptr = tempD->ptr; //Ο προηγούμενος κόμβος πρέπει να δείχνει
				//στον κόμβο που δείχνει ο κόμβος ο οποίος θα διαγραφεί
				delete tempD; //Διαγραφή του κόμβου
			}
			else {
				cout << "Den yparxei pthsh pou na antistoixei sto dwsmeno ID" << endl;
			}
			break;
		}//Τέλος case D
		case 'E': {
			if (first != NULL) { //Αν το πρώτο στοιχείο δεν είναι και το τελευταίο
				temp = first; //Ξεκινάμε από την αρχή της λίστας
				while (temp->ptr != NULL) { //Όσο η λίστα έχει κόμβους
					temp = temp->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
				}
				temp->ptr = new FLIGHTS; //Δέσμευση χώρου στην μνήμη για νέο κόμβο τύπου FLIGHTS
				temp = temp->ptr; //Μετάβαση στον επόμενο κόμβο της λίστας
			}
			else {
				first = new FLIGHTS; //Δέσμευση χώρου στην μνήμη για νέο κόμβο τύπου FLIGHTS
				temp = first;
			}
			cout << endl << "Plhktrologiste ton kodiko ths pthshs"<< endl;
			cin >> temp->flightId;
			cout << endl << "Plhktrologiste thn afethria ths pthshs" << endl;
			cin >> temp->startPoint;
			cout << endl << "Plhktrologiste ton termatismo ths pthshs" << endl;
			cin >> temp->endPoint;
			cout << endl << "Plhktrologiste thn wra anaxwrhshs" << endl;
			cin >> temp->startTime;
			cout << endl << "Plhktrologiste thn wra afhkshs" << endl;
			cin >> temp->endTime;
			cout << endl << "Plhktrologiste thn timh ths pthshs" << endl;
			cin >> temp->price;
			cout << endl << "Plhktrologiste ton typo toy aeroplanoy" << endl;
			cin >> temp->planeType;
			cout << endl << "Plhktrologiste ton arithmo twn theseon ths pthshs" << endl;
			cin >> temp->seats;
			temp->numberOfReservations = 0;
			temp->first = NULL;
			temp->ptr = NULL;
			break;
		}//Τέλος case E
		case 'F': { //Ακύρωση κράτησης
			cout << "Plhktrologhste ton arithmo ths pthshs thn opoia thelete na akurosete" << endl;
			cin >> fIDinput;
			temp = first;
			while (temp->flightId != fIDinput) { //Ψάχνουμε το στοιχείο της λίστας 
				temp = temp->ptr; //που είναι ίδιο με το fIDinput που δόθηκε από τον χρήστη
			}
			if (temp->first != NULL) {
				tempQ = temp->first; //Το tempQ γίνεται ίσο με το πρώτο στοιχείο της λίστας με τις πτήσεις
				tempQ = tempQ->ptr; //Το tempQ πάει στο δεύτερο στοιχείο της λίστας 
				//Το σπάσαμε σε δύο εντολές για να αποφύγουμε εντολές με 2 " -> "
				delete temp->first; //Διαγραφή του πρώτου στοιχείου της λίστας
				temp->first = tempQ; //Το first γίνεται ίσο με το δεύτερο στοιχείο της λίστας
			}
			else {
				cout << "Den yparxei stoixeio sthn oura gia diagrafh" << endl;
				if (temp->numberOfReservations == 0) {
					//Αν δεν υπάρχουν κρατήσεις, δεν γίνεται τίποτα
				}
				else {
					temp->numberOfReservations = temp->numberOfReservations - 1;
					//Μείωση του αριθμού κρατήσεων κατά μία μονάδα
				}
			}
		}//Τέλος case F
		case 'G': {
			break;
		}//Τέλος case G
		}//Τέλος switch
		cout << "Pathste A gia eisagwgh kwdikwn pthshs-eggrafh epibath" << endl;
		cout << "B gia ektypwsh leptomereiwn kapoias pthshs" << endl;
		cout << "C gia ektypwsh leptomereiwn kapoiou epibath" << endl;
		cout << "D gia diagrafh pthshs" << endl;
		cout << "E gia kataxwrhsh pthshs" << endl;
		cout << "F gia akyrwsh krathshs" << endl;
		cout << "G gia termatismo tou programmatos" << endl;
		cin >> input;
	}
	
		return 0;
}
	