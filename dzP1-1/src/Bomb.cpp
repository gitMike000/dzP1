#include "include/Bomb.h"
#include <iostream>
#include "include/ScreenSingleton.h"

void Bomb::Draw() const {
  //ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
  ScreenSingleton::getInstance().GotoXY(x, y);
  std::cout << "*";
}
