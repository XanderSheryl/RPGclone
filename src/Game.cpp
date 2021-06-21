#include "Game.h"

Game::Game()
{
    sAppName = L"RPG Clone";
    nConsoleScreenWidth = 120;
    nConsoleScreenHeight = 35;
}

Game::~Game()
{
}

bool Game::Start()
{
    player = 'X';
    pos = { 10, 10 };
    return true;
}

bool Game::Update()
{
    if (GetKeyPressed(alexio::W) || GetKeyPressed(alexio::UP))
        pos.y--;
    if (GetKeyPressed(alexio::S) || GetKeyPressed(alexio::DOWN))
        pos.y++;
    if (GetKeyPressed(alexio::A) || GetKeyPressed(alexio::LEFT))
        pos.x--;
    if (GetKeyPressed(alexio::D) || GetKeyPressed(alexio::RIGHT))
        pos.x++;

    Clear();

    DrawChar(pos, player, alexio::FG_BLUE);

    return !GetKeyPressed(alexio::ESCAPE);
}
