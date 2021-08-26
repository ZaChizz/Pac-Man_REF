#include <iostream>
#include <windows.h>
#include "lib/getch.h"

#include "hpp/Layout.h"
#include "hpp/Unit.h"
#include "hpp/Moover.h"
#include "hpp/Navigator.h"


int main() {
    FILE* mapIn;
    Layout* mainLayout;
    Unit* unitPacman;
    Unit* unitShadow;
    Unit* unitSpeedy;
    Moover* mooverPacman;
    Moover* mooverShadow;
    Moover* mooverSpeedy;
    Navigator* navigatorShadow;
    Navigator* navigatorSpeedy;
    char c;

    mapIn = fopen("map.in", "r");

    mainLayout = new Layout(mapIn);

    unitPacman = new Unit('$');
    unitShadow = new Unit('Q');
    unitSpeedy = new Unit('G');

    mooverPacman = new Moover(mainLayout, unitPacman);
    mooverShadow = new Moover(mainLayout, unitShadow);
    mooverSpeedy = new Moover(mainLayout, unitSpeedy);

    navigatorShadow = new Navigator(mooverShadow);
    navigatorSpeedy = new Navigator(mooverSpeedy);

    unitPacman->setStartPoint((int)PACMAN_DEFAULT_COORD_X,(int)PACMAN_DEFAULT_COORD_Y);
    unitShadow->setStartPoint((int)SHADOW_DEFAULT_COORD_X,(int)SHADOW_DEFAULT_COORD_Y);
    unitSpeedy->setStartPoint((int)SPEEDY_DEFAULT_COORD_X,(int)SPEEDY_DEFAULT_COORD_Y);

    mooverPacman->start();
    mooverShadow->start();
    mooverSpeedy->start();

    do {
        system("cls");
        mainLayout->render();
        c = getch();

        mooverPacman->moove(c, '.');
        mooverShadow->moove(navigatorShadow->navigate());
        mooverSpeedy->moove(navigatorSpeedy->navigate());
        
    }
    
    while(c != 27); //Esc

    system("pause");

    return 0;
}
