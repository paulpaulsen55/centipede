#include "GameState.h"

GameState::State GameState::getState() const {
    return state;
}

void GameState::setState(const State newState) {
    state = newState;
}

bool GameState::operator==(const State state) const {
    return this->state == state;
}
