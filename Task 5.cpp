#include "string"
#include <iostream>


std::string RANGE_BETWEEN_CHAR = "\n\n";
int POSE_NPC = 0;
int ATT_NPC = 0;




int AI_def() {
    POSE_NPC += 1;
    return POSE_NPC % 3;
}

int AI_att() {
    ATT_NPC += 1;
    return ATT_NPC % 3;
}

void viz_attack(int i, int j) {
    if (i == 0 and j == 0) {
        std::cout << " * " << "   " << "   " << std::endl;
        std::cout << " * " << "   " << "   " << std::endl;
        std::cout << " * " << "   " << "   " << std::endl;
        return;
    }

    if (i == 1 and j == 1) {
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        return;
    }
    if (i == 2 and j == 2) {
        std::cout << "   " << "   " << " * " << std::endl;
        std::cout << "   " << "   " << " * " << std::endl;
        std::cout << "   " << "   " << " * " << std::endl;
        return;
    }

    if (i == 0 and j == 2) {
        std::cout << " * " << "   " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << "   " << " * " << std::endl;
        return;
    }


    if (i == 2 and j == 1) {
        std::cout << "   " << "   " << " * " << std::endl;
        std::cout << "   " << "   " << " * " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        return;
    }

    if ((i == 2 and j == 0)) {
        std::cout << "   " << "   " << " * " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << " * " << "   " << "   " << std::endl;
        return;
    }

    if (i == 1 and j == 2) {
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << "   " << " * " << std::endl;
        return;
    }

    if (i == 0 and j == 1) {
        std::cout << " * " << "   " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        return;
    }

    if (i == 1 and j == 0) {
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << "   " << " * " << "   " << std::endl;
        std::cout << " * " << "   " << "   " << std::endl;
        return;
    }


}

class Hero
{
private:
    int health = 100;
    int streanght = 10;
    std::string name;
    int type_of_block = 0;


public:

    void viz_pos()
    {
        if (type_of_block == 1) {
            std::cout << std::endl;
            std::cout << "    " << " * " << "    " << std::endl;
            std::cout << "    " << "-|-" << "    " << std::endl;
            std::cout << "    " << "| |" << "    " << std::endl;
            std::cout << std::endl;
        }

        if (type_of_block == 2) {
            std::cout << "    " << "    " << " * " << std::endl;
            std::cout << "    " << "    " << "-|-" << std::endl;
            std::cout << "    " << "    " << "| |" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }

        if (type_of_block == 0) {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << " * " << "    " << "    " << std::endl;
            std::cout << "-|-" << "    " << "    " << std::endl;
            std::cout << "| |" << "    " << "    " << std::endl;
            
        }
    }

    void set_name(std::string name_char)
    {
        name = name_char;
    }

    void set_pose(int N) {

        if ((N != 0) or (N != 1) or (N != 2)) {
            type_of_block = 0;
        }

        type_of_block = N;
    }

    int get_health()
    {
        return health;
    }

    int get_pose()
    {
        return type_of_block;
    }

    void set_health(int HP)
    {
        if (HP < 0)
        {
            std::cout << "wrong inpute HP" << std::endl;;
        }

        health = HP;
    }

    void set_power(int power)
    {
        if (power < 0)
        {
            std::cout << "wrong inpute power" << std::endl;
        }
        streanght = power;
    }

    std::string get_name() {
        return name;
    }

    void strike(Hero &otherHero, int type_attack)
    {
        int damage = 0;
        if (streanght > 0) {
            damage += streanght + rand() % streanght;
        }
        else {
            damage += rand() % 10;
        }

        if (otherHero.get_pose() == type_attack)
        {
            if (streanght > 0) {
                damage += streanght + rand() % streanght;
            }
            else {
                damage += rand() % 10;
            }
        }
        else {
            damage = rand() % (streanght+1);
        }

        otherHero.set_health(otherHero.get_health() - damage);
    }

    void add_cheat(std::string cheat)
    {
        if (cheat == "Otl for this homework") {
            streanght += 10000;
            health += 10000;
            std::cout << "cheat is activate" << std::endl;
        }
        else {
            streanght = 1;
            health = 1;
            std::cout << "wrong answer, your HP is 1 and your str is 1" << std::endl;
        }
    }

};

void manual()
{
    std::cout << "Your quest is kill your enemy" << std::endl;
    std::cout << "Use this number (0, 1, 2) to choose location of your char" << std::endl;
    std::cout << "For attack you need push (0, 1, 2), only ony number!!" << std::endl;
    std::cout << "If char HP down low then 0, char deafted" << std::endl;

}


int main()
{
    manual();
    Hero Hero_1;
    Hero Hero_2;
    std::string name_1;
    std::string name_2;
    std::cout << "input your hero name" << std::endl;
    std::cin >> name_1;
    Hero_1.set_name(name_1);

    std::cout << "Your enemy name is Math" << std::endl;
    name_2 = "Math";
    Hero_2.set_name(name_2);
    int my_attack = 0;
    int my_pose = 0;
    int AI_attack_pos = 0;
    int AI_def_pos = 0;

    std::string using_cheats = "n";
    std::string cheat = "n";

    bool auto_flag = false;

    std::cout << "Do you want use cheats? insert y/n" << std::endl;
    std::cin >> using_cheats;
    
    if (using_cheats == "y") {
        std::cout << "insert your cheat, but beware if it will wrong cheat, you will debafed!" << std::endl;
        std::cin >> cheat;
        Hero_1.add_cheat(cheat);
    }

    std::cout << "Do you want set auto mode? (game will play in auto mode) insert y/n" << std::endl;
    std::cin >> using_cheats;

    if (using_cheats == "y") { 
        auto_flag = true;
    }

    int counter = 0;

    while (Hero_1.get_health() > 0 and Hero_2.get_health() > 0)
    {
        std::cout << std::endl;
        std::cout << "******Battle number:  " << counter << "******" << std::endl;
        std::cout << Hero_1.get_name() << " HP: " << Hero_1.get_health() << std::endl;
        Hero_1.viz_pos();
        std::cout << RANGE_BETWEEN_CHAR << std::endl;

        Hero_2.viz_pos();
        std::cout << Hero_2.get_name() << " HP: " << Hero_2.get_health() << std::endl;

        if (not auto_flag) {
            std::cout << "Input new pose (0, 1, 2): ";
            std::cin >> my_pose;
            std::cout << "Input type of attack (0, 1, 2): ";
            std::cin >> my_attack;
        }
        else {
            my_pose = rand()%3;
            my_attack = rand()%3;
        }
        
        std::cout << std::endl;

        AI_def_pos = AI_def();

        Hero_2.set_pose(AI_def_pos);
        Hero_1.set_pose(my_pose);

        Hero_1.strike(Hero_2, my_attack);
        std::cout << "******RAUND 1******" << std::endl;

        std::cout << Hero_1.get_name() << " HP: " << Hero_1.get_health() << std::endl;
        Hero_1.viz_pos();

        viz_attack(Hero_1.get_pose(), my_attack % 3);

        Hero_2.viz_pos();
        std::cout << Hero_2.get_name() << " HP: " << Hero_2.get_health() << std::endl;
        std::cout << "******RAUND 2******" << std::endl;

        AI_attack_pos = AI_att();
        Hero_2.strike(Hero_1, AI_attack_pos);
        std::cout << Hero_1.get_name() << " HP: " << Hero_1.get_health() << std::endl;
        Hero_1.viz_pos();
        viz_attack(AI_attack_pos, Hero_2.get_pose());
        Hero_2.viz_pos();
        std::cout << Hero_2.get_name() << " HP: " << Hero_2.get_health() << std::endl;

        counter++;
    }

    if (Hero_1.get_health() < 0) {
        std::cout << "You died (Hero Elf died)" << std::endl;
    }
    else {
        std::cout << "You win" << std::endl;
    }
}
