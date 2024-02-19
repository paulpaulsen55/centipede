#include "GameState.h"

GameState::State GameState::getState() const {
    return state;
}

void GameState::setState(const GameState::State newState) {
    state = newState;
}

bool GameState::operator==(State state) const {
    return this->state == state;
}
