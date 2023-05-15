
#include "Player.h"

Player::Player(const std::string& name, int maxHP, int force){
    this->m_name = std::string(name);
    this->m_maxHP = maxHP > 0 ? maxHP : DEFAULT_MAX_HP;
    this->m_HP = maxHP;
    this->m_force = force >= 0 ? force : DEFAULT_FORCE;
    this->m_level = NEW_PLAYER_LEVEL;
    this->m_coins = MIN_COINS;
}

Player::Player(const Player& player){
    this->m_name =  std::string(player.m_name);
    this->m_maxHP = player.m_maxHP;
    this->m_HP = player.m_maxHP;
    this->m_force = player.m_force;
    this->m_level = NEW_PLAYER_LEVEL;
    this->m_coins = MIN_COINS;
}

Player& Player::operator=(const Player& player){
    if (this == &player){
        return *this;
    }
    this->m_name = std::string(player.m_name);
    this->m_HP = player.m_HP;
    this->m_level = player.m_level;
    this->m_coins = player.m_coins;
    this->m_force = player.m_force;
    this->m_maxHP = player.m_maxHP;
    return *this;
}

int Player::getHP() const{
    return this->m_HP;
}
void Player::printInfo() const{
    char* cTypeStringName = new char[this->m_name.length()+1];
    std::strcpy(cTypeStringName,this->m_name.c_str());
    printPlayerInfo(cTypeStringName, this->m_level, this->m_force, this->m_HP, this->m_coins);
    delete[] cTypeStringName;
}

bool Player::levelUp(){
    if (this->m_level < MAX_LEVEL){
        this->m_level++;
        return true;
    }
    return false;
}

int Player::getLevel() const{
    return this->m_level;
}

void Player::buff(int buffPoints){
    this->m_force += (buffPoints > 0 ? buffPoints : 0);
}

void Player::heal(int healPoints){
    if (healPoints < 0){
        return;
    }
    this->m_HP = (this->m_HP + healPoints > this->m_maxHP) ? this->m_maxHP : this->m_HP + healPoints;
}


void Player::damage(int damage){
    if (damage < 0) {
        return;
    }
    this->m_HP = (this->m_HP > damage) ? this->m_HP - damage : MIN_HP;
}

bool Player::isKnockedOut() const{
    return (this->m_HP == MIN_HP);
}

void Player::addCoins(int coinsToAdd){
    this->m_coins += (coinsToAdd > 0 ? coinsToAdd : 0);
}

bool Player::pay(int price){
    if (this->m_coins < price){
        return false;
    }
    // waiting for piazza @734. for now - accepting perks and not paying invalid payment value (comply with tests)
    if (price > 0) {
        this->m_coins -= price;
    }
    return true;
}

int Player::getAttackStrength() const{
    return this->m_level + this->m_force;
}

