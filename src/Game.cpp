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
    config_json = std::make_unique<JsonParser>("data/config/config.json");
    return true;
}

bool Game::Update()
{
    if (config_json->GetKeyPressed("Up"))
        pos.y--;
    if (config_json->GetKeyPressed("Down"))
        pos.y++;
    if (config_json->GetKeyPressed("Left"))
        pos.x--;
    if (config_json->GetKeyPressed("Right"))
        pos.x++;

    Clear();

    DrawChar(pos, player, alexio::FG_BLUE);

    return !GetKeyPressed(alexio::ESCAPE);
}
