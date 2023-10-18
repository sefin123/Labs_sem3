#include "Tablet.h"
#include "Laptop.h"
#include "Monoblock.h"
#include "Header.h"

int main() {

	int menuValue = MAGICNUMBER;

	while (menuValue != EXIT) {
		showMenu();
		menuValue = enterWithValidationForScope(MAXMENUVALUE);
		if (menuValue == 1) {

			double screenDiagonal;
			char body[MAXSTRINGSIZE];
			char modelName[MAXSTRINGSIZE];
			char brand[MAXSTRINGSIZE];

			cout << "Enter screen diagonal" << endl;
			cin >> screenDiagonal;
			cout << "Enter body" << endl;
			cin >> body;
			cout << "Enter model name" << endl;
			cin >> modelName;
			cout << "Enter brand" << endl;
			cin >> brand;

			Monoblock monoblock(screenDiagonal, body, brand, modelName);
			monoblock.printMonoblock();

			int choice;
			cout << "1 if u wanna change parametr(2 to not)" << endl;
			choice = enterWithValidationForScope(3);
			if (choice == 2)
				continue;
			bool change = true;
			while (change) {
				cout << "Which parametr u wanna change(5 to stop)" << endl;
				cout << "1.screen diagonal" << endl;
				cout << "2.body" << endl;
				cout << "3.model name" << endl;
				cout << "4.brand" << endl;
				int changevalue = enterWithValidationForScope(6);
				if (changevalue == 5)
					change = false;

				if (changevalue == 1) {
					double newScreenDiagonal;
					cin >> newScreenDiagonal;
					monoblock.setScreenDiagonal(newScreenDiagonal);
				}
				if (changevalue == 2) {
					char newBody[MAXSTRINGSIZE];
					cin >> newBody;
					monoblock.setBody(newBody);
				}
				if (changevalue == 3) {
					char newModelName[MAXSTRINGSIZE];
					cin >> newModelName;
					monoblock.setModelName(newModelName);
				}
				if (changevalue == 4) {
					char newBrand[MAXSTRINGSIZE];
					cin >> newBrand;
					monoblock.setBrand(newBrand);
				}
				monoblock.printMonoblock();
			}
		}
		if (menuValue == 2) {
			int numberOfKeys;
			double screenDiagonal;
			int batteryCharge;
			char modelName[MAXSTRINGSIZE];
			char brand[MAXSTRINGSIZE];

			cout << "Enter number of keys" << endl;
			cin >> numberOfKeys;
			cout << "Enter battery charge" << endl;
			cin >> batteryCharge;
			cout << "Enter screen diagonal" << endl;
			cin >> screenDiagonal;
			cout << "Enter model name" << endl;
			cin >> modelName;
			cout << "Enter brand" << endl;
			cin >> brand;

			Laptop laptop(numberOfKeys, batteryCharge, screenDiagonal, brand, modelName);
			laptop.printLaptop();

			int choice;
			cout << "1 if u wanna change parametr(2 to not)" << endl;
			choice = enterWithValidationForScope(3);
			if (choice == 2)
				continue;
			bool change = true;
			while (change) {
				cout << "Which parametr u wanna change(6 to stop)" << endl;
				cout << "1.screen diagonal" << endl;
				cout << "2.battery charge" << endl;
				cout << "3.model name" << endl;
				cout << "4.brand" << endl;
				cout << "5.number of keys" << endl;
				int changevalue = enterWithValidationForScope(7);
				if (changevalue == 6)
					change = false;

				if (changevalue == 1) {
					double newScreenDiagonal;
					cin >> newScreenDiagonal;
					laptop.setScreenDiagonal(newScreenDiagonal);
				}
				if (changevalue == 2) {
					int newBatteryCharge;
					cin >> newBatteryCharge;
					laptop.setbatteryCharge(newBatteryCharge);
				}
				if (changevalue == 3) {
					char newModelName[MAXSTRINGSIZE];
					cin >> newModelName;
					laptop.setModelName(newModelName);
				}
				if (changevalue == 4) {
					char newBrand[MAXSTRINGSIZE];
					cin >> newBrand;
					laptop.setBrand(newBrand);
				}
				if (changevalue == 5) {
					int newNumberOfKeys;
					cin >> newNumberOfKeys;
					laptop.setNumberOfKeys(newNumberOfKeys);
				}
				laptop.printLaptop();
			}
		}
		if (menuValue == 3) {

			char modem[MAXSTRINGSIZE];
			double screenDiagonal;
			int batteryCharge;
			char modelName[MAXSTRINGSIZE];
			char brand[MAXSTRINGSIZE];

			cout << "Enter modem" << endl;
			cin >> modem;
			cout << "Enter screen diagonal" << endl;
			cin >> screenDiagonal;
			cout << "Enter battery charge" << endl;
			cin >> batteryCharge;
			cout << "Enter model name" << endl;
			cin >> modelName;
			cout << "Enter brand" << endl;
			cin >> brand;
			Tablet tablet(modem, batteryCharge, screenDiagonal, brand, modelName);
			tablet.printTablet();
			int choice;
			cout << "1 if u wanna change parametr(2 to not)" << endl;
			choice = enterWithValidationForScope(3);
			if (choice == 2)
				continue;
			bool change = true;
			while (change) {
				cout << "Which parametr u wanna change(6 to stop)" << endl;
				cout << "1.screen diagonal" << endl;
				cout << "2.battery charge" << endl;
				cout << "3.model name" << endl;
				cout << "4.brand" << endl;
				cout << "5.modem" << endl;
				int changevalue = enterWithValidationForScope(7);
				if (changevalue == 6)
					change = false;

				if (changevalue == 1) {
					double newScreenDiagonal;
					cin >> newScreenDiagonal;
					tablet.setScreenDiagonal(newScreenDiagonal);
				}
				if (changevalue == 2) {
					int newBatteryCharge;
					cin >> newBatteryCharge;
					tablet.setbatteryCharge(newBatteryCharge);
				}
				if (changevalue == 3) {
					char newModelName[MAXSTRINGSIZE];
					cin >> newModelName;
					tablet.setModelName(newModelName);
				}
				if (changevalue == 4) {
					char newBrand[MAXSTRINGSIZE];
					cin >> newBrand;
					tablet.setBrand(newBrand);
				}
				if (changevalue == 5) {
					char newModem[MAXSTRINGSIZE];
					cin >> newModem;
					tablet.setModem(newModem);
				}
				tablet.printTablet();
			}
		}
	}
	return 0;
}