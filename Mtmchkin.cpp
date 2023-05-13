//
// Created by baeri on 13/05/2023.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this->player = Player(playerName, 100, 5);
    this->cardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        this->cardsArray[i] = cardsArray[i];
    }
    this->nextCard = FIRST_CARD;
    this->gameStatus = GameStatus::MidGame;
}

void Mtmchkin::playNextCard(){
    this->cardsArray[this->nextCard].printInfo();
    this->cardsArray[this->nextCard].applyEncounter(this->player);
    this->player.printInfo();
    this->updateNextCard();

    if (this->player.getLevel() == Player::MAX_LEVEL){
        this->gameStatus = GameStatus::Win;
    }

    if (this->player.getHP() == Player::MIN_HP){
        this->gameStatus = GameStatus::Loss;
    }
}

void Mtmchkin::updateNextCard(){
    nextCard = (this->nextCard < this->numOfCards - 1) ? nextCard + 1 : FIRST_CARD;
}

bool Mtmchkin::isOver() const{
    return this->gameStatus != GameStatus::MidGame;
}

GameStatus Mtmchkin::getGameStatus() const{
    return this->gameStatus;
}