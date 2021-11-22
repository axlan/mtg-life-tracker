#include "app.h"

class LifeCounter : public App{
public:
  void Up() override;
  void Down() override;
  void Left() override;
  void Right() override;
  void Increment() override;
  void Decrement() override;
  void Display() override;
};
