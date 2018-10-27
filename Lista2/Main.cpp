#include "CMenu.h"
#include "PrintCommand.h"
#include "CMenuItem.h"
#include "CMenuCommand.h"
int main() {
	
}

void przyklad1() {
	CMenu* root = new CMenu(std::string("Menu glowne"), std::string("main"));
	CMenu* podmenu1 = new CMenu(std::string("Podmenu1"), std::string("menu1"));

	CCommand* runInternet = new PrintCommand(std::string("Uruchamiam internet"));
	CMenuCommand* internet = new CMenuCommand(std::string("Uruchom przegladarke"), std::string("internet"), runInternet);

	CMenu* podmenuPodmenu1 = new CMenu(std::string("Podmenu1"), std::string("menu1"));

	podmenu1->addItem(internet);
	podmenu1->addItem(podmenuPodmenu1);

	root->addItem(podmenu1);

	CMenu* podmenu2 = new CMenu(std::string("Podmenu2"), std::string("menu2"));

	CCommand* cmdTest = new PrintCommand(std::string("Testuje"));
	CMenuCommand* test = new CMenuCommand(std::string("Test"), std::string("test"), cmdTest);

	CCommand* cmdDefcom = new CCommand();
	CMenuCommand* defcom = new CMenuCommand(std::string("Default command"), std::string("defcom"), cmdDefcom);

	podmenu2->addItem(test);
	podmenu2->addItem(defcom);
	root->addItem(podmenu2);

	CCommand* printAla = new PrintCommand("Ala ma kota");
	CMenuCommand* ala = new CMenuCommand(std::string("Napisz 'Ala ma kota'"), std::string("ala"), printAla);
	root->addItem(ala);

	root->run();
	delete root;
}

void zadanie1() {

}