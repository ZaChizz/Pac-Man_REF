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

    unitPacman = new Unit('$', (int)PACMAN_DEFAULT_COORD_X, (int)PACMAN_DEFAULT_COORD_Y);
    unitShadow = new Unit('Q', (int)SHADOW_DEFAULT_COORD_X, (int)SHADOW_DEFAULT_COORD_Y);
    unitSpeedy = new Unit('G', (int)SPEEDY_DEFAULT_COORD_X,(int)SPEEDY_DEFAULT_COORD_Y);

    mooverPacman = new Moover(mainLayout, unitPacman);
    mooverShadow = new Moover(mainLayout, unitShadow);
    mooverSpeedy = new Moover(mainLayout, unitSpeedy);

    navigatorShadow = new Navigator(mooverShadow);
    navigatorSpeedy = new Navigator(mooverSpeedy);

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

    delete(navigatorSpeedy);
    delete(navigatorShadow);
    delete(mooverSpeedy);
    delete(mooverShadow);
    delete(mooverPacman);
    delete(unitSpeedy);
    delete(unitShadow);
    delete(unitPacman);
    delete(mainLayout);

    return 0;
}
