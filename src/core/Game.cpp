#include "Game.hpp"

    
int Game::SCREEN_WIDTH=0;
int Game::SCREEN_HEIGHT=0;

float Game::WORLD_WIDTH=0;
float Game::WORLD_HEIGHT=0;
float Game::SCALEX=0;
float Game::SCALEY=0;

const b2Vec2& Game::screen2world(const b2Vec2& screen_point) {
  static b2Vec2 world_point;
  world_point.x = screen_point.x/(float)(SCREEN_WIDTH/WORLD_WIDTH);
  world_point.y = SCREEN_HEIGHT/(float)(SCREEN_HEIGHT/WORLD_HEIGHT) - screen_point.y/(float)(SCREEN_HEIGHT/WORLD_HEIGHT);
  return world_point;
}

const b2Vec2& Game::world2screen(const b2Vec2& world_point) {
  static b2Vec2 screen_point;
  screen_point.x = world_point.x*(float)(SCREEN_WIDTH/WORLD_WIDTH);
  screen_point.y = (SCREEN_HEIGHT - world_point.y*(float)(SCREEN_HEIGHT/WORLD_HEIGHT));
  return screen_point;
}
