#include <vector>
#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <time.h>
#include <ncurses.h>
#include "pawn.h"
#include "gameEngine.h"
#include "Npc.h"

gameEngine::gameEngine(int argc, char **argv)
{
    system("chcp 1253");
    if (argc != 2)
    {
        std::cout << "Τρέξε το πρόγραμμα ως εξής ./main input.txt" << std::endl;
        exit(1);
    }
    //Χάρτης εκτυπωση και εκχώρηση σε vector
    file.open(argv[1], std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Πρόβλημα με το αρχείο " << std::endl;
        exit(1);
    }

    while (getline(file, str))
    {
        map.push_back(str);
    }
    file.close();

    //Γραμμές και στήλες
    int strsize;
    int vecsize = 0;
    //Συντεταγμένες
    int x;
    int y;
    initscr();
    keypad(stdscr, TRUE);
    start_color();

    strsize = map[0].length() - 1;
    vecsize = map.size();
    y = 0;
    x = 0;
    //Εμφάνιση χάρτη
    for (std::vector<std::string>::iterator it = map.begin(); it != map.end(); it++)
    {
        refresh();
        mvprintw(y++, x, "%s", it->c_str());
    }

    //Αρχικοποίηση
    potter.setName('M');
    potter.initloc(map);
    malfoi.setName('L');
    malfoi.initloc(map);
    diamond.setName('D');
    diamond.initloc(map);

    noecho();

    int ch; //ειδικη μεταβλητη που δέχετε σαν όρισμα το κουμπί που έχει πατηση ο παίχτης 
    int counter = 0; //μετρητης που χρησοιμοοπιήτε απο το πρόγραμμα για να ορίση νές θέση στο διαμάντι
    int flag; //flag που επιστρέφη ακεραία τιμή  για τον έλεγχο νίκης
    do
    {
        ch = getch();
        potter.DoMove(ch, map); //κίνηση παίχτη 
        malfoi.gmeleMoves(diamond.getPositionX(),diamond.getPositionY(),map); //κίνηση του λουκά
        counter++; //προσάυξηση μετρητή 

        flag = condition(potter, malfoi, diamond); //ελεγχος νίκης 

        if (flag == 1)
        {
            clear();
            printw("ΠΕΡΑΣΕΣ \n"); //Νίκη παίχτη 
            break;
        }
        if (flag == 2)
        {
            clear();
            printw("Ο Διαβόητος τζιμελες σου εκανε ενα ξόρκι υπνου οταν εμφανίστηκες δίπλα απο τον Λουκά και κοιμήθηκες  \n");  //Μια κατάσταση να κάνει το παιχνίδη λίγο ποιο διασκεδαστικό
            break;
        }
        if (flag == 3)
        {
            clear();
            printw("Ο ΛΟΥΚΑΣ ΚΕΡΔΙΣΕ \n");  //Νίκη Λουκά
            break;
        }

        if (counter >= rand() % 100 + 1)
        {
            counter = 0;
            diamond.changeLoc(map);
        }

    } while (ch != 27);

    refresh();
    getch();
    endwin();
}

int gameEngine::condition(Pawn &p, Npc &m, Diamond &d)
{
    if (p.getPositionY() == d.getPositionY() && p.getPositionX() == d.getPositionX())
    {
        return 1;
    }
    if (p.getPositionY() == m.getPositionY() && p.getPositionX() == m.getPositionX())
    {
        return 2;
    }
    if (d.getPositionY() == m.getPositionY() && d.getPositionX() == m.getPositionX())
    {
        return 3;
    }
    return 0;
}
