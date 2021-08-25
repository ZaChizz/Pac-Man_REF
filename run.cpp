#include <iostream>
#include <windows.h>
#include "lib/getch.h"

#include "hpp/Layout.h"
#include "hpp/Unit.h"
#include "hpp/Moover.h"


int main() {
    FILE* mapIn;
    Layout* mainLayout;
    Unit* unitPacman;
    Unit* unitGhost;
    Moover* mooverPacman;
    Moover* mooverGhost;
    char c;

    mapIn = fopen("map.in", "r");

    mainLayout = new Layout(mapIn);

    unitPacman = new Unit('Q');
    unitGhost = new Unit('G');

    mooverPacman = new Moover(mainLayout, unitPacman);
    mooverGhost = new Moover(mainLayout, unitGhost);

    unitPacman->setStartPoint((int)PACMAN_DEFAULT_COORD_X,(int)PACMAN_DEFAULT_COORD_Y);
    unitGhost->setStartPoint((int)GHOST_DEFAULT_COORD_X,(int)GHOST_DEFAULT_COORD_Y);

    mooverPacman->start();
    mooverGhost->start();

    do {
        system("cls");
        mainLayout->render();
        c = getch();

        mooverPacman->moove(c, '.');
    }
    
    while(c != 27); //Esc

    system("pause");

    return 0;
}
