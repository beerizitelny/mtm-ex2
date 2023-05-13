//
// Created by baeri on 13/05/2023.
//
#include "Player.h"

Player::Player(const char* name, int maxHP = 100, int force = 5){
    this->name = new char [strlen(name) + 1];
    // what if NULL???
    strcpy(this->name, name);
    this->name[strlen(name)] = '\0';
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->force = force;
    this->level = NEW_PLAYER_LEVEL;
    this->coins = MIN_COINS;
}

Player::Player(const Player& player){
    this->name = new char [strlen(player.name) + 1];
    strcpy(this->name, player.name);
    this->name[strlen(player.name)] = '\0';
    this->maxHP = player.maxHP;
    this->HP = player.maxHP;
    this->force = player.force;
    this->level = NEW_PLAYER_LEVEL;
    this->coins = MIN_COINS;
}

Player::~Player(){
    delete this->name;
}

/*
 * setters methods:
 * sets the value of the object, using the given parameter.
 */
void Player::setLevel(int level){
    this->level = level;
}
void Player::setForce(int force){
    this->force = force;
}
void Player::setMaxHP(int maxHP){
    this->maxHP = maxHP;
}
void Player::setCoins(int coins){
    this->coins = coins;
}

int Player::getHP() const{
    return this.HP;
}
void Player::printInfo() const{
    printPlayerInfo(this->name, this->level, this->force, this->HP, this->coins);
}

bool Player::levelUp(){
    if (this->level < MAX_LEVEL){
        this->level++;
        return true;
    }
    return false;
}

int Player::getLevel() const{
    return this->level;
}

void Player::buff(int buffPoints){
    this->force += buffPoints;
}

void Player::heal(int healPoints){
    if (healPoints < 0){
        return;
    }
    this->HP = (this->HP + healPoints > this->maxHP) ? this->maxHP : this->HP + healPoints;
}


void Player::damage(int damage){
    this->HP = (this->HP > damage) ? this->HP - damage : MIN_HP;
}

bool Player::isKnockedOut() const{
    return (this->HP == MIN_HP);
}

void Player::addCoins(int coinsToAdd){
    this->coins += coinsToAdd;
}

bool Player::pay(int price){
    if (this->coins < price){
        return false;
    }
    this->coins -= price;
    return true;
}

int Player::getAttackStrength() const{
    return this->level + this->force;
}

