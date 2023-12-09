#include "Tablet.h"
#include "Laptop.h"
#include "Monoblock.h"
#include "Exp.h"

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

			Monoblock monoblock;

			std::cout << "Enter screen diagonal" << endl;
			std::cin >> screenDiagonal;
			try {
				checkDouble(screenDiagonal);
				monoblock.setScreenDiagonal(screenDiagonal);
			}
			catch (ExpInput& problem) {
				problem.show();
			}
			std::cout << "Enter body" << endl;
			cin >> body;
			try {
				checkChar(body);
				monoblock.setBody(body);
			}
			catch (ExpInput& problem) {
				problem.show();
			}
			std::cout << "Enter model name" << endl;
			cin >> modelName;
			try {
				checkChar(modelName);
				monoblock.setModelName(modelName);
			}
			catch (ExpInput& problem) {
				problem.show();
			}
			std::cout << "Enter brand" << endl;
			cin >> brand;
			try {
				checkChar(brand);
				monoblock.setBrand(brand);
			}
			catch (ExpInput& problem) {
				problem.show();
			}

			monoblock.printMonoblock();
			Monoblock copyMonoblock(monoblock);
			int choice;
			std::cout << "1 if u wanna change parametr(2 to not)" << endl;
			choice = enterWithValidationForScope(3);
			if (choice == 2)
				continue;
			bool change = true;
			while (change) {
				std::cout << "Which parametr u wanna change(5 to stop)" << endl;
				std::cout << "1.screen diagonal" << endl;
				std::cout << "2.body" << endl;
				std::cout << "3.model name" << endl;
				std::cout << "4.brand" << endl;
				int changevalue = enterWithValidationForScope(6);
				if (changevalue == 5)
					change = false;

				if (changevalue == 1) {
					double newScreenDiagonal;
					cin >> newScreenDiagonal;
					copyMonoblock.setScreenDiagonal(newScreenDiagonal);
				}
				if (changevalue == 2) {
					char newBody[MAXSTRINGSIZE];
					cin >> newBody;
					copyMonoblock.setBody(newBody);
				}
				if (changevalue == 3) {
					char newModelName[MAXSTRINGSIZE];
					cin >> newModelName;
					copyMonoblock.setModelName(newModelName);
				}
				if (changevalue == 4) {
					char newBrand[MAXSTRINGSIZE];
					cin >> newBrand;
					copyMonoblock.setBrand(newBrand);
				}
				copyMonoblock.printMonoblock();
			}
			
		}
		if (menuValue == 2) {
			int numberOfKeys;
			double screenDiagonal;
			int batteryCharge;
			char modelName[MAXSTRINGSIZE];
			char brand[MAXSTRINGSIZE];

			std::cout << "Enter number of keys" << endl;
			cin >> numberOfKeys;
			std::cout << "Enter battery charge" << endl;
			cin >> batteryCharge;
			std::cout << "Enter screen diagonal" << endl;
			cin >> screenDiagonal;
			std::cout << "Enter model name" << endl;
			cin >> modelName;
			std::cout << "Enter brand" << endl;
			cin >> brand;

			Laptop laptop(numberOfKeys, batteryCharge, screenDiagonal, brand, modelName);
			laptop.printLaptop();
			Laptop copyLaptop(laptop);
			int choice;
			std::cout << "1 if u wanna change parametr(2 to not)" << endl;
			choice = enterWithValidationForScope(3);
			if (choice == 2)
				continue;
			bool change = true;
			while (change) {
				std::cout << "Which parametr u wanna change(6 to stop)" << endl;
				std::cout << "1.screen diagonal" << endl;
				std::cout << "2.battery charge" << endl;
				std::cout << "3.model name" << endl;
				std::cout << "4.brand" << endl;
				std::cout << "5.number of keys" << endl;
				int changevalue = enterWithValidationForScope(7);
				if (changevalue == 6)
					change = false;

				if (changevalue == 1) {
					double newScreenDiagonal;
					cin >> newScreenDiagonal;
					copyLaptop.setScreenDiagonal(newScreenDiagonal);
				}
				if (changevalue == 2) {
					int newBatteryCharge;
					cin >> newBatteryCharge;
					copyLaptop.setbatteryCharge(newBatteryCharge);
				}
				if (changevalue == 3) {
					char newModelName[MAXSTRINGSIZE];
					cin >> newModelName;
					copyLaptop.setModelName(newModelName);
				}
				if (changevalue == 4) {
					char newBrand[MAXSTRINGSIZE];
					cin >> newBrand;
					copyLaptop.setBrand(newBrand);
				}
				if (changevalue == 5) {
					int newNumberOfKeys;
					cin >> newNumberOfKeys;
					copyLaptop.setNumberOfKeys(newNumberOfKeys);
				}
				copyLaptop.printLaptop();
			}
		}
		if (menuValue == 3) {

			char modem[MAXSTRINGSIZE];
			double screenDiagonal;
			int batteryCharge;
			char modelName[MAXSTRINGSIZE];
			char brand[MAXSTRINGSIZE];

			std::cout << "Enter modem" << endl;
			cin >> modem;
			std::cout << "Enter screen diagonal" << endl;
			cin >> screenDiagonal;
			std::cout << "Enter battery charge" << endl;
			cin >> batteryCharge;
			std::cout << "Enter model name" << endl;
			cin >> modelName;
			std::cout << "Enter brand" << endl;
			cin >> brand;
			Tablet tablet(modem, batteryCharge, screenDiagonal, brand, modelName);
			tablet.printTablet();
			Tablet copyTablet(tablet);

			int choice;
			std::cout << "1 if u wanna change parametr(2 to not)" << endl;
			choice = enterWithValidationForScope(3);
			if (choice == 2)
				continue;
			bool change = true;
			while (change) {
				std::cout << "Which parametr u wanna change(6 to stop)" << endl;
				std::cout << "1.screen diagonal" << endl;
				std::cout << "2.battery charge" << endl;
				std::cout << "3.model name" << endl;
				std::cout << "4.brand" << endl;
				std::cout << "5.modem" << endl;
				int changevalue = enterWithValidationForScope(7);
				if (changevalue == 6)
					change = false;

				if (changevalue == 1) {
					double newScreenDiagonal;
					cin >> newScreenDiagonal;
					copyTablet.setScreenDiagonal(newScreenDiagonal);
				}
				if (changevalue == 2) {
					int newBatteryCharge;
					cin >> newBatteryCharge;
					copyTablet.setbatteryCharge(newBatteryCharge);
				}
				if (changevalue == 3) {
					char newModelName[MAXSTRINGSIZE];
					cin >> newModelName;
					copyTablet.setModelName(newModelName);
				}
				if (changevalue == 4) {
					char newBrand[MAXSTRINGSIZE];
					cin >> newBrand;
					copyTablet.setBrand(newBrand);
				}
				if (changevalue == 5) {
					char newModem[MAXSTRINGSIZE];
					cin >> newModem;
					copyTablet.setModem(newModem);
				}
				copyTablet.printTablet();
			}
		}
	}
	return 0;
}