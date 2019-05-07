#include <iostream>
#include <memory>

using namespace std;

class Entity
{
public:
  Entity()
  {
    cout << "Created";
  }

  ~Entity()
  {
    cout << "Deleted";
  }

};

void main()
{
  {
    std::unique_ptr<Entity> e0 = std::make_unique<Entity>();
  }

	std::cin.get();
}