////////////////////////  HW1   /////////////////////////
#include <iostream>
#include <cstdint>
#include <cmath>
//////////////////////// part 1 /////////////////////////
class Power
{
public:
  double A = 0;
  double B = 0;

  void set(double in_A, double in_B) {
    A = in_A;
    B = in_B;
  }
  
  double calculate () {
    double out_C = 0;
    out_C = pow(A, B);
    std::cout << "\n"<< "\n" << "Part 1\n" << A << "^" << B << "= " << out_C <<"\n";
  return out_C;
  }
};  
//////////////////////// part 2 /////////////////////////
class RGBA
{
private:
  std::uint8_t m_red = 0;
  std::uint8_t m_green = 0;
  std::uint8_t m_blue = 0;
  std::uint8_t m_alpha = 255;
  
public:
  RGBA(uint8_t in_red, uint8_t in_green, uint8_t in_blue, uint8_t in_alpha)
  : m_red(in_red), m_green(in_green), m_blue(in_blue), m_alpha(in_alpha)
  {
  }
  
  void print() {
    std::cout << "\nPart 2\n" << "RED = " << m_red << " GREEN = " << m_green << " BLUE = " << m_blue <<  " ALPHA = " << m_alpha << "\n";
  }
};
//////////////////////// part 3 /////////////////////////
#define depth 10
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

class Stack
{
  private:
  
  int stack[depth];
  int point = -1;
  
  public:
  
  void reset(){
    point = -1;
    for(int i = 0; i < depth; i++) {
      stack[i] = 0;
    }
  }
  
  void print() {
    std::cout << "(";
    for (int i = 0; i <= point; i++) {
      std::cout << " " << stack[i] << " ";
    }
    std::cout << ")\n";
  }
  
  boolean push(int data) {
  if (point < depth) {
    stack[++point] = data;
    return true;
  }
  else {
    printf("%s \n", "stack overflow");
    return false;
  }  
}

int pop() {
  if (point != -1) {
    return stack[point--];
    }
    else {
      printf("%s \n", "stack is empty");
      return -1;
    }  
}  

};
///////////////////////// main //////////////////////////
int main (int argc, const char** argv) {
  
  Power p1;
  p1.set(2, 3.5);
  p1.calculate();
  
  RGBA p2('1', '2', '3', '4');
  p2.print();
  
  std::cout << "\nPart 3\n";
  Stack stack;
  stack.reset();
  stack.print();
  
  stack.push(3);
  stack.push(7);
  stack.push(5);
  stack.print();
  
  stack.pop();
  stack.print();
  
  stack.pop();
  stack.pop();
  stack.print();
return 0;
}
