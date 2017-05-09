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
	int num_of_fl = 0; //������� �������.
	int flights[10], temp3, temp4; //������� �������, ��� �� ���������� ���� �������� ������� ��� ��������.
	// ���������� ����������.
	char input; //�������� �������� ��� ��� ������ ��� �� ����� switch.
	string temp1, temp2 , passname;//���������� ����������.
	QUEUE *tempQ = NULL; //���������� pointers
	FLIGHTS *temp= NULL, *tempD= NULL, *first=NULL; 
	PASSENGER *tempP = NULL, *Pfirst = NULL; 
	bool helper = 0; //��������� ���������
	cout<<"Pathste A gia eisagwgh kwdikwn pthshs-eggrafh epibath"<<endl;
	cout << "B gia ektypwsh leptomereiwn kapoias pthshs" << endl;
	cout << "C gia ektypwsh leptomereiwn kapoiou epibath"<<endl;
	cout << "D gia diagrafh pthshs"<<endl;
	cout << "E gia kataxwrhsh pthshs"<<endl;
	cout << "F gia akyrwsh krathshs"<<endl;
	cout << "G gia termatismo tou programmatos" << endl;
	cin >> input;
	while (true) { //��� �� ������ �� ��������� ���� ����� �������
		switch (input) { //������ switch. �������������� ��� ����� if-else if 
		case 'A': {
			cout << "Pliktrologiste ton arithmo twn ptisewn pou tha kanete" << endl;
			cin >> num_of_fl; //������� �������
			for (int i = 0;i < num_of_fl;i++) {
				cout<<"Pliktrologiste ton kwdiko ths pthshs"<<endl;
				cin >> flights[i]; //�������� ���� ������ ��� ������� ��� ���� ������. 
				//���������� ��� �������� ��� � ������� ����� ���� �������� �� ��� ����� �����.
			}
			//��������� ��� ��� ������� ��� ������������ ����� �������� ��� �������.
			//������� ��� ���� ����������� ��� ��� ���� ��� ������� ������ ���� ��� �� ������ �� ����� �� ������.
			for (int i = 0;i < num_of_fl - 1;i++) {
				temp = first; //���� ������
				while (temp != 0) //��� ���� � ����� ����� ��������
				{
					if (flights[i] == temp->flightId) {
						temp1 = temp->endPoint; //������ ��� ��������� ��� ������ ������
						temp3 = temp->endTime; //������ �� ��� ������ � ����� ��� ���������
						
					}
					if (flights[i + 1] == temp->flightId) {
						temp2 = temp->startPoint; //������ ��� ��� ������� � ������� �����
						temp4 = temp->startTime; // �� ��� ��������, ������ �� ����� ���� ��� ��� ������ ��� ������ ������.
					}
					temp = temp->ptr; //�������� ��� ������� �������� ��� ������.
				}
				if (temp4 < temp3 || temp1 != temp2) { //�� �� �������� ����� �����, ����� ������ ���� �����.
				//������, �� � ��� ��� ������������� � ����� �����, ����� ���� ��� ��� ��� ������ � ������� �����
				//� �� � ���������� ��� ������ ������, ����� ������������ ��� ��� �������� ��� �������� ������
					cout << "Lathos dedomena." << endl;
					goto FIRST_OPTION;
				}
			}
			//������� �������������� �������
			helper = 0;
			for (int i = 0;i < num_of_fl;i++) {
				temp = first; //���� ������
				while (temp != 0) { //��� ���� � ����� ����� ��������
					if (flights[i] == temp->flightId) { //������� ��� ��������� ����� ����� ��� �����.
						break;
					}
					temp = temp->ptr; //�������� ��� ������� �������� ��� ������.
				}
				if (temp->seats == temp->numberOfReservations) {//�� �� ���������� ������ ��� ��� �������� 
					//����� ����� ���� �� ��� ������ ��� ������ ��� ����������, ������� ��� ������
					printf("H pthsh %d einai gemath", flights[i]);
					helper = 1;
					break;
				}

			}
			if (helper == 0) {
				for (int i = 0; i < num_of_fl;i++) {
					temp = first; //������� ������ ������.
					while (temp != 0) { //��� ���� � ����� ����� ��������
						if (flights[i] == temp->flightId) { //��������� ��� ������ ��� ����������
							temp->numberOfReservations = temp->numberOfReservations + 1; 
							//������ ���� ���� ������� ��� ������� ��� ���������� ������
							break;
						}
						temp = temp->ptr; //�������� ���� ������� ����� ��� ������
					}
				}

				//������� ��� ��� �������� ��� ��������� ��� �������� �������
				if (Pfirst != NULL) {
					tempP = Pfirst; //������������ pointer tempP �� ��� ���� ��� ������ ������ ��� ������ Passenger
					while (tempP->ptr != NULL) { //��� � ����� ���� ��������
						tempP = tempP->ptr; //�������� ���� ������� ����� ��� ������
					}
					tempP->ptr = new PASSENGER;
					tempP = tempP->ptr; //�������� ���� ������� ����� ��� ������

				}
				else {
					Pfirst = new PASSENGER;
					tempP = Pfirst;
				}

				cout << "Plhktrologhste to onomatepwnymo tou epibath" << endl;
				cin.ignore(); //������ ��� ������� ���� buffer
				getline(cin, tempP->name); //�������� �������� �������.
				//����� ��� getline ���� �� ������ ��� ��� ������ �������� ��� ��� ������
				//�� ��� ��������� ����, ��� ��� ���� ��� ����� ���� ���� �� ������� �� ����� cin
				cout << endl << "Plhktrologhste ton arithmo diabathriou" << endl;
				cin >> tempP->numberOfPassport; //�������� ������� ����������� �������
				cout << endl << "Plhktrologhste ethikothta" << endl;
				cin >> tempP->nationality; //�������� ����������� �������
				cout << endl << "Plhktrologhste dieuthinsi" << endl;
				cin.ignore();
				getline(cin, tempP->address); //�������� ���������� �������
				cout << endl << "Plhktrologhste thlefwno" << endl;
				cin >> tempP->telephone; //�������� ��������� �������
				tempP->ptr = NULL; //���������� ������ ��� ������
			}
			else { //��������� ���� �����
				cin.ignore();
				cout << "Plhktrologiste to onomaneponumo sas" << endl;
				getline(cin, passname);
				for (int i = 0;i < num_of_fl;i++) {
					temp = first; //������� ������ ������.

					while (temp != 0) { //��� ���� � ����� ����� ��������

						if (flights[i] == temp->flightId) { //������ ��� ����� ��� ������� �� ������������
							break;
						}
						temp = temp->ptr; //�������� ���� ������� ����� ��� ������
					}
					
					if (temp->first != NULL) { //�� �� �������� ��� ����� �� ��������� ��� ������
						tempQ = temp->first; //�������� ���� ������� ����� ��� ������
						while (tempQ->ptr != 0) { //��� �������� �������� ��� �����
							tempQ = tempQ->ptr; //���� ��� ������� �������� ��� �����
						}
						tempQ->ptr = new QUEUE; //�������� ����� ��� ����� ��� ��� ����� ����� QUEUE
						tempQ = tempQ->ptr; //�������� ���� ������� ����� ��� �����
						tempQ->ptr = 0; //����� �����
						tempQ->passname = passname;

					}
					else {
						tempQ = new QUEUE; //�������� ����� ���� ����� ��� ��� ����� ����� QUEUE
						tempQ->ptr = NULL; //������ ��� ������ ��� �����
						tempQ->passname = passname;
						temp->first = tempQ; //� first �� ������� ���� ���� ������ ��� tempQ
					}
				}

			}
			break;
		FIRST_OPTION: {
			break;
			}
		}//����� case A
		case 'B': {
			//�������� ������������ ������
			int kwdikos_ptisis;
			cout << "Plhktrologhste ton kwdiko ths pthshs gia thn opoia thelete na mathete leptomereies" << endl;
			cin >> kwdikos_ptisis;
			temp = first; //������� ������ ������.
		    while (temp != 0) {
				if (kwdikos_ptisis == temp->flightId) { //��������� ��� �������� ������
						//�������� ���� ����� ���� ��� ��������� ��� �������
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
				temp = temp->ptr; //�������� ���� ������� ����� ��� ������
			}
			//����� ��������� ������������ ������
			break;
		}//����� case B
		case 'C': {
			//�������� ������������ �������
			int diabathrio;
			cout << "Plhktrologhste arithmo diabathriou epibath";
			cin >> diabathrio;
			for (int i = 0; i < num_of_fl;i++) {
				tempP = Pfirst; //������� ������ ������.
				if (tempP == 0) break; //�� ���������� � ��������� �� ���� ����� �� temp ��� ���� 0 ��� �� while ��������
				while (tempP != 0) { //��� � ����� ���� ��������
					if (diabathrio == tempP->numberOfPassport) { //����� ����� ������ ����������� ��� ����� ���� �� ����� ���
						//������ ��� �� ������������, �������� �� �������� ��� �������
						cout << tempP->name << endl;
						cout << tempP->nationality << endl;
						cout << tempP->address << endl;
						cout << tempP->telephone << endl;
						tempP = 0;
						break;
					}
					tempP = tempP->ptr; //�������� ���� ������� ����� ��� ������
				}
				//����� ��������� ������������ �������
			}
			break;
		}//����� case C
		case 'D': {
			cout << "Plhktrologhste ton kwdiko ths pthshs" << endl;
			cin >> fIDinput;
			tempD = first; 
			temp = first;
			while (tempD != 0) { //��� � ����� ���� ��������
				if (tempD->flightId == fIDinput) { 
					//����� ���� ��� ����� �� ������ ����� ��� ������ ��� ��� ������
					break; //��������� ��� ���������
				}
				temp = tempD; //� ��������� temp ������� ��� ���� ��� ������������ ������
				tempD = temp->ptr; //�������� ���� ������� ����� ��� ������
			}
			if(tempD==first) { //�� ������� ��� ����� �������� ��� ������
				temp = tempD->ptr; //�� temp ������� ��� ���� ��� �������� ���������
				delete(tempD); //�������� ��� ������ tempD
				first = temp;
			}
			else if (tempD != 0) { //����� ���� ��� ����� ��� �������
				temp->ptr = tempD->ptr; //� ������������ ������ ������ �� �������
				//���� ����� ��� ������� � ������ � ������ �� ���������
				delete tempD; //�������� ��� ������
			}
			else {
				cout << "Den yparxei pthsh pou na antistoixei sto dwsmeno ID" << endl;
			}
			break;
		}//����� case D
		case 'E': {
			if (first != NULL) { //�� �� ����� �������� ��� ����� ��� �� ���������
				temp = first; //�������� ��� ��� ���� ��� ������
				while (temp->ptr != NULL) { //��� � ����� ���� �������
					temp = temp->ptr; //�������� ���� ������� ����� ��� ������
				}
				temp->ptr = new FLIGHTS; //�������� ����� ���� ����� ��� ��� ����� ����� FLIGHTS
				temp = temp->ptr; //�������� ���� ������� ����� ��� ������
			}
			else {
				first = new FLIGHTS; //�������� ����� ���� ����� ��� ��� ����� ����� FLIGHTS
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
		}//����� case E
		case 'F': { //������� ��������
			cout << "Plhktrologhste ton arithmo ths pthshs thn opoia thelete na akurosete" << endl;
			cin >> fIDinput;
			temp = first;
			while (temp->flightId != fIDinput) { //�������� �� �������� ��� ������ 
				temp = temp->ptr; //��� ����� ���� �� �� fIDinput ��� ������ ��� ��� ������
			}
			if (temp->first != NULL) {
				tempQ = temp->first; //�� tempQ ������� ��� �� �� ����� �������� ��� ������ �� ��� �������
				tempQ = tempQ->ptr; //�� tempQ ���� ��� ������� �������� ��� ������ 
				//�� ������� �� ��� ������� ��� �� ���������� ������� �� 2 " -> "
				delete temp->first; //�������� ��� ������ ��������� ��� ������
				temp->first = tempQ; //�� first ������� ��� �� �� ������� �������� ��� ������
			}
			else {
				cout << "Den yparxei stoixeio sthn oura gia diagrafh" << endl;
				if (temp->numberOfReservations == 0) {
					//�� ��� �������� ���������, ��� ������� ������
				}
				else {
					temp->numberOfReservations = temp->numberOfReservations - 1;
					//������ ��� ������� ��������� ���� ��� ������
				}
			}
		}//����� case F
		case 'G': {
			break;
		}//����� case G
		}//����� switch
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
	