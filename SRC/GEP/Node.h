#ifndef NODE_H
#define NODE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Element.h"
#include <memory>

namespace GEP
{
////////////////////////////////////////////////////////////
/// \brief Node is used to create tree in expression.
/// Also Node is used to calculate fitness in expression.
/// When Node is constante or variable, them this Node is leaf.
////////////////////////////////////////////////////////////
class Node;
typedef std::shared_ptr<Node> PtrNode;

class Node
{
public:
    Node(Element _element):element(_element) {}

public:
    Element element;
    PtrNode left = nullptr;
    PtrNode right= nullptr;
};

} // namespace GEP
#endif // NODE_H
