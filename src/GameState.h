#ifndef GAMESTATE_H
#define GAMESTATE_H



class GameState {
public:
    enum class State { MENU, PAUSED, RUNNING, GAME_OVER };

    State getState() const;

    void setState(State newState);

    bool operator==(State state) const;

private:
    State state = State::MENU;



};



#endif //GAMESTATE_H
