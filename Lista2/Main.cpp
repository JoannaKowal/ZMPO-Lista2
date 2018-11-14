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

const std::string MAIN = "Main";
const std::string MAIN_MENU = "Menu glowne";
const std::string ALA_MENU = "Napisz Ala ma kota";
const std::string SUBMENU_1 = "Podmenu1";
const std::string SUBMENU_2 = "Podmenu2";
const std::string INTERNET = "Uruchamiam przegladarke";
const std::string RUN_BROWSER = "Uruchom przegladarke";
const std::string TEST = "Test";
const std::string PRINT_TEST = "Testuje";
const std::string PRINT_ALA = "Ala ma kota";
const std::string DEFAULT_COMMAND_MENU = "Default command";
const std::string COMMAND_DEFCOM = "defcom";
const std::string COMMAND_ALA = "ala";
const std::string COMMAND_TEST = "test";
const std::string COMMAND_INTERNET = "internet";
const std::string COMMAND_MAIN = "main";
const std::string COMMAND_MENU_1 = "menu1";
const std::string COMMAND_MENU_2 = "menu2";
const std::string DESCRIPTION_ADD = "Dodaje tabele";
const std::string DESCRIPTION_DEL = "Usuwa tabele";
const std::string DESCRIPTION_PRINT = "Wypisuje tabele";
const std::string DESCRIPTION_DELALL = "Usuwa wszystkie tabele";
const std::string DESCRIPTION_TAB_LEN = "Ustawia dlugosc tabeli";
const std::string DESCRIPTION_VAL = "Ustawia wartosc na danym offsecie w tabeli";
const std::string DESCRIPTION_RENAME = "Ustawia nazwe tabeli";
const std::string DESCRIPTION_CLONE = "Kpiuje tabele";
const std::string DESCRIPTION_INTERNET = "Uruchamia przegladarke";
const std::string DESCRIPTION_TEST= "Wypisuje testuje";
const std::string DESCRIPTION_DEFCOM = "Wypisuje komende domyslna";
const std::string DESCRIPTION_ALA = "Wypisuje Ala ma kota";


void zadanie1() {
	CTableManager* manager = new CTableManager();
	CMenu* root = new CMenu(MAIN, COMMAND_MAIN);
	CMenuCommand* add = new CMenuCommand(COMMAND_ADD, COMMAND_ADD, DESCRIPTION_ADD);
	add->setCommand(new AddTableCommand(manager));
	CMenuCommand* del = new CMenuCommand(COMMAND_DEL, COMMAND_DEL, DESCRIPTION_DEL);
	del->setCommand(new DelTableCommand(manager));
	CMenuCommand* print = new CMenuCommand(COMMAND_PRINT, COMMAND_PRINT, DESCRIPTION_PRINT);
	print->setCommand(new PrintTableCommand(manager));
	CMenuCommand* delall = new CMenuCommand(COMMAND_DELALL, COMMAND_DELALL, DESCRIPTION_DELALL);
	delall->setCommand(new DelallTableCommand(manager));
	CMenuCommand* len = new CMenuCommand(COMMAND_TAB_LEN, COMMAND_TAB_LEN, DESCRIPTION_TAB_LEN);
	len->setCommand(new LengthTableCommand(manager));
	CMenuCommand* val = new CMenuCommand(COMMAND_VAL, COMMAND_VAL, DESCRIPTION_VAL);
	val->setCommand(new ValueTableCommand(manager));
	CMenuCommand* rename = new CMenuCommand(COMMAND_RENAME, COMMAND_RENAME, DESCRIPTION_RENAME);
	rename->setCommand(new RenameTableCommand(manager));
	CMenuCommand* clone = new CMenuCommand(COMMAND_CLONE, COMMAND_CLONE, DESCRIPTION_CLONE);
	clone->setCommand(new CloneTableCommand(manager));

	root->addItem(add);
	root->addItem(del);
	root->addItem(print);
	root->addItem(delall);
	root->addItem(len);
	root->addItem(val);
	root->addItem(rename);
	root->addItem(clone);

	std::cout << root->save();
	std::cout << std::endl << std::endl;
	std::string tree = root->save();
	root->saveFromString(tree, 0);
	std::cout << root->save();
	root->run();
	delete root;
	delete manager;
}
void przyklad1() {
	CMenu* root = new CMenu(MAIN_MENU, COMMAND_MAIN);
	CMenu* podmenu1 = new CMenu(SUBMENU_1, COMMAND_MENU_1);

	CCommand* runInternet = new PrintCommand(INTERNET);
	CMenuCommand* internet = new CMenuCommand(RUN_BROWSER, COMMAND_INTERNET, runInternet, DESCRIPTION_INTERNET);
	
	CMenu* podmenuPodmenu1 = new CMenu(SUBMENU_1, COMMAND_MENU_1);

	podmenu1->addItem(internet);
	podmenu1->addItem(podmenuPodmenu1);

	root->addItem(podmenu1);

	CMenu* podmenu2 = new CMenu(SUBMENU_2, COMMAND_MENU_2);

	CCommand* cmdTest = new PrintCommand(PRINT_TEST);
	CMenuCommand* test = new CMenuCommand(TEST, COMMAND_TEST, cmdTest, DESCRIPTION_TEST);

	CCommand* cmdDefcom = new CCommand();
	CMenuCommand* defcom = new CMenuCommand(DEFAULT_COMMAND_MENU, COMMAND_DEFCOM, cmdDefcom, DESCRIPTION_DEFCOM);

	podmenu2->addItem(test);
	podmenu2->addItem(defcom);
	root->addItem(podmenu2);

	CCommand* printAla = new PrintCommand(PRINT_ALA);
	CMenuCommand* ala = new CMenuCommand(ALA_MENU, COMMAND_ALA, printAla, DESCRIPTION_ALA);
	root->addItem(ala);

	//Zapis do stringa i czytanie ze stringa
	std::cout << root->save();
	std::cout << std::endl << std::endl;
	std::string tree = root->save();
	root->saveFromString(tree, 0);
	std::cout << root->save() << std::endl;
	std::cout << std::endl << std::endl;

	//Test
	/*root->saveFromString(std::string("(Ala','Ma')"), 0);
	root->saveFromString(std::string("('Ala''Ma')"), 0);
	root->saveFromString(std::string("('Ala','Ma'()"), 0);
	root->saveFromString(std::string("('Ala','Ma';[ala'])"), 0);*/

	root->run();
	delete root;
}

int main() {
	//zadanie1();
	przyklad1();
}


