#include "menu.h"

using namespace std;

int main() {
	srand(time(NULL));
	Menu menuPrincipal;
	menuPrincipal.procesarArchivo();
	menuPrincipal.mostrarMenu();
	return 0;
}
