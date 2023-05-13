//
// Created by baeri on 13/05/2023.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) : m_player(playerName, 100, 50) {
    this->m_cardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        this->m_cardsArray[i] = cardsArray[i];
    }
    this->m_nextCard = FIRST_CARD;
    this->m_gameStatus = GameStatus::MidGame;
    this->m_numOfCards = numOfCards;
}

Mtmchkin::~Mtmchkin() {
    delete []this->m_cardsArray;
}

void Mtmchkin::playNextCard(){
    this->m_cardsArray[this->m_nextCard].printInfo();
    this->m_cardsArray[this->m_nextCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    this->updateNextCard();
    this->updateGameStatus();
}

void Mtmchkin::updateNextCard(){
    m_nextCard = (this->m_nextCard < this->m_numOfCards - 1) ? m_nextCard + 1 : FIRST_CARD;
}

bool Mtmchkin::isOver() const{
    return this->m_gameStatus != GameStatus::MidGame;
}

GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}

void Mtmchkin::updateGameStatus(){
    if (this->m_player.getLevel() == Player::MAX_LEVEL){
        this->m_gameStatus = GameStatus::Win;
    }
    if (this->m_player.getHP() == Player::MIN_HP){
        this->m_gameStatus = GameStatus::Loss;
    }
}
