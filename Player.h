#ifndef MTM_EX2_PLAYER_H
#define MTM_EX2_PLAYER_H

#include <string>
#include <cstring>
#include "utilities.h"

class Player{
    std::string m_name;
    int m_level;
    int m_force;
    int m_HP;
    int m_maxHP;
    int m_coins;


public:
    // %%%%% constants values: %%%%%
    static const int MAX_LEVEL = 10;
    static const int MIN_HP = 0;
    static const int MIN_COINS = 0;
    static const int NEW_PLAYER_LEVEL = 1;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;

    // %%%%% METHODS: %%%%%
    /*
     * method Player:
     * Construct a new Player object with a given name, HP equal to a given value of maxHP and given value of force.
     * A new Player's level is 1 and it has 0 coins. The default values of maxHP is 100 and of force is 5.
     * when given a reference to a Player object the constructor will clone it to a new one.
     */
    explicit Player(const std::string& name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    Player(const Player&);

    /*
     * assignment operator
     */
    Player& operator=(const Player& player);

    /*
     * destructor for Player object -> use default destructor
     */
     ~Player() = default;

    /*
     * method getHP:
     * returns the HP of the player
     */
    int getHP() const;

    /*
     * method printInfo:
     * prints the information of the Player by the order: Name, Level, Force, HP, Coins.
     */
    void printInfo() const;

    /*
     * method levelUp:
     * upgrades the level of the player by 1, unless the player's level is 10 (the maximum level).
     * returns true if the players level upgraded and false otherwise.
     */
    bool levelUp();

    /*
     * method getLevel:
     * returns the level of the player.
     */
    int getLevel() const;

    /*
     * method buff:
     * upgrades the player's force by a given integer.
     */
    void buff(int);

    /*
     * method heal:
     * upgrades the HP of the player by a given integer up to the value of maxHP.
     * if the given integer is lower then 0 the method will change noting.
     */
    void heal(int);

    /*
     * method damage:
     * decrease's the player's HP by a given integer up to 0 (the minimum HP value).
     */
    void damage(int);

    /*
     * method isKnockedOut:
     * return true if the players HP is 0 and false otherwise.
     */
    bool isKnockedOut() const;

    /*
     * method addCoins:
     * upgrades the value of the player's coins bu a given integer.
     */
    void addCoins(int);

    /*
     * method pay:
     * receive an integer price to pay, if the players has enough coins he will lose this coins and the method will
     * return true, otherwise the player will not lose coins and the method will return false.
     */
    bool pay(int);

    /*
     * method getAttackStrength:
     * returns the strength of the player's attack: level + force.
     */
    int getAttackStrength() const;
};
#endif //MTM_EX2_PLAYER_H
