#ifndef SERVER_GENETICS_HPP
#define SERVER_GENETICS_HPP

namespace common
{
 // fwd declaration
  class Creature;
}

namespace server
{

class Genetics
{
    Genetics() = delete;
public:
    static void makeChild(common::Creature*, common::Creature*);
};

} // namespace server

#endif // SERVER_GENETICS_HPP
