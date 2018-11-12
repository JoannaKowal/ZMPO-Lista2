#include "CMenu.h"
#include "PrintCommand.h"
#include "CMenuItem.h"
#include "CMenuCommand.h"
#include "CTableManager.h"
#include "AddTableCommand.h"
#include "DelallTableCommand.h"
#include "DelTableCommand.h"
#include "PrintTableCommand.h"
#include "LengthTableCommand.h"
#include "ValueTableCommand.h"
#include "RenameTableCommand.h"
#include "CloneTableCommand.h"
#include "ExitCommand.h"

void zadanie1() {
	CTableManager* manager = new CTableManager();
	CMenu* root = new CMenu(std::string("Main"), std::string("main"));
	CMenuCommand* add = new CMenuCommand(std::string("add"), std::string("add"), std::string("Dodaje tabele"));
	add->setCommand(new AddTableCommand(manager));
	CMenuCommand* del = new CMenuCommand(std::string("del"), std::string("del"), std::string("Usuwa tabele"));
	del->setCommand(new DelTableCommand(manager));
	CMenuCommand* print = new CMenuCommand(std::string("print"), std::string("print"), std::string("Wypisuje tabele"));
	print->setCommand(new PrintTableCommand(manager));
	CMenuCommand* delall = new CMenuCommand(std::string("delall"), std::string("delall"), std::string("Usuwa wszystkie tabele"));
	delall->setCommand(new DelallTableCommand(manager));
	CMenuCommand* len = new CMenuCommand(std::string("len"), std::string("len"), std::string("Ustawia dlugosc tabeli"));
	len->setCommand(new LengthTableCommand(manager));
	CMenuCommand* val = new CMenuCommand(std::string("val"), std::string("val"), std::string("Ustawia wartosc na danym offsecie w tabeli"));
	val->setCommand(new ValueTableCommand(manager));
	CMenuCommand* rename = new CMenuCommand(std::string("rename"), std::string("rename"), std::string("Ustawia nazwe tabeli"));
	rename->setCommand(new RenameTableCommand(manager));
	CMenuCommand* clone = new CMenuCommand(std::string("clone"), std::string("clone"), std::string("Kpiuje tabele"));
	clone->setCommand(new CloneTableCommand(manager));

	root->addItem(add);
	root->addItem(del);
	root->addItem(print);
	root->addItem(delall);
	root->addItem(len);
	root->addItem(val);
	root->addItem(rename);
	root->addItem(clone);

	root->run();
	delete root;
	delete manager;
}
void przyklad1() {
	CMenu* root = new CMenu(std::string("Menu glowne"), std::string("main"));
	CMenu* podmenu1 = new CMenu(std::string("Podmenu1"), std::string("menu1"));

	CCommand* runInternet = new PrintCommand(std::string("Uruchamiam internet"));
	CMenuCommand* internet = new CMenuCommand(std::string("Uruchom przegladarke"), std::string("internet"), runInternet, std::string("uruchamia internet"));
	
	CMenu* podmenuPodmenu1 = new CMenu(std::string("Podmenu1"), std::string("menu1"));

	podmenu1->addItem(internet);
	podmenu1->addItem(podmenuPodmenu1);

	root->addItem(podmenu1);

	CMenu* podmenu2 = new CMenu(std::string("Podmenu2"), std::string("menu2"));

	CCommand* cmdTest = new PrintCommand(std::string("Testuje"));
	CMenuCommand* test = new CMenuCommand(std::string("Test"), std::string("test"), cmdTest, std::string("wypisuje testuje"));

	CCommand* cmdDefcom = new CCommand();
	CMenuCommand* defcom = new CMenuCommand(std::string("Default command"), std::string("defcom"), cmdDefcom, std::string("Wypisuje komende domyslna"));

	podmenu2->addItem(test);
	podmenu2->addItem(defcom);
	root->addItem(podmenu2);

	CCommand* printAla = new PrintCommand("Ala ma kota");
	CMenuCommand* ala = new CMenuCommand(std::string("Napisz Ala ma kota"), std::string("ala"), printAla, std::string("Wypisuje Ala ma kota"));
	root->addItem(ala);

	std::cout << root->save();
	root->run();
	delete root;
}

int main() {
	//zadanie1();
	przyklad1();
}


