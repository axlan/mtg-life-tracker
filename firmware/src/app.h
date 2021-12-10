#pragma once

class App {
public:
  virtual void Up() = 0;
  virtual void Down() = 0;
  virtual void Left() = 0;
  virtual void Right() = 0;
  virtual void Increment() = 0;
  virtual void Decrement() = 0;
  virtual void Display() = 0;
  virtual const char* GetName() const = 0;
};
