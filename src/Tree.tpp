#include "../include/Tree.h"
#include <sstream>
#include <string>

template <typename T, size_t k>
Tree<T, k>::Tree() : root(nullptr) { // Constructor with default arity
  if (k <= 0) {
    throw std::runtime_error("Arity of the tree must be greater than 0");
  }
}

template <typename T, size_t k> Tree<T, k>::~Tree() { clear(root); }

template <typename T, size_t k> void Tree<T, k>::clear(Node<T> *node) {
  if (node) {
    for (auto child : node->children) {
      clear(child);
    }
    delete node;
  }
}

template <typename T, size_t k> void Tree<T, k>::add_root(Node<T> &root_node) {
  root =
      new Node<T>(root_node.value, k); // Initialize root with the correct arity
}

template <typename T, size_t k>
bool Tree<T, k>::add_sub_node(Node<T> &parent_node, Node<T> &sub_node) {
  Node<T> *parent = find_node(root, parent_node.value);
  if (parent) {
    for (size_t i = 0; i < parent->k; ++i) {
      if (!parent->children[i]) {
        parent->children[i] = new Node<T>(
            sub_node.value, k); // Initialize sub_node with the correct arity
        return true;
      }
    }
  }
  return false;
}

template <typename T, size_t k>
Node<T> *Tree<T, k>::find_node(Node<T> *node, T value) {
  if (!node)
    return nullptr;

  if (node->value == value)
    return node;

  for (auto child : node->children) {
    Node<T> *result = find_node(child, value);
    if (result)
      return result;
  }

  return nullptr;
}

// Iterator methods
template <typename T, size_t k>
typename IteratorType<T, k>::PreOrder Tree<T, k>::begin_pre_order() {
  return typename IteratorType<T, k>::PreOrder(root);
}

template <typename T, size_t k>
typename IteratorType<T, k>::PreOrder Tree<T, k>::end_pre_order() {
  return typename IteratorType<T, k>::PreOrder(nullptr);
}

template <typename T, size_t k>
typename IteratorType<T, k>::PostOrder Tree<T, k>::begin_post_order() {
  return typename IteratorType<T, k>::PostOrder(root);
}

template <typename T, size_t k>
typename IteratorType<T, k>::PostOrder Tree<T, k>::end_post_order() {
  return typename IteratorType<T, k>::PostOrder(nullptr);
}

template <typename T, size_t k>
typename IteratorType<T, k>::InOrder Tree<T, k>::begin_in_order() {
  return typename IteratorType<T, k>::InOrder(root);
}

template <typename T, size_t k>
typename IteratorType<T, k>::InOrder Tree<T, k>::end_in_order() {
  return typename IteratorType<T, k>::InOrder(nullptr);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::begin_bfs_scan() {
  return BFSIterator<T, k>(root);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::end_bfs_scan() {
  return BFSIterator<T, k>(nullptr);
}

template <typename T, size_t k> DFSIterator<T, k> Tree<T, k>::begin_dfs() {
  return DFSIterator<T, k>(root);
}

template <typename T, size_t k> DFSIterator<T, k> Tree<T, k>::end_dfs() {
  return DFSIterator<T, k>(nullptr);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::begin() {
  return BFSIterator<T, k>(root);
}

template <typename T, size_t k> BFSIterator<T, k> Tree<T, k>::end() {
  return BFSIterator<T, k>(nullptr);
}

template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::begin_min_heap() {
  if (k == 2)
    return MinHeapIterator<T, k>(root);
  else
    throw std::runtime_error("The tree isn't binary tree!");
}

template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::end_min_heap() {
  if (k == 2)
    return MinHeapIterator<T, k>(nullptr); // End iterator
  else
    throw std::runtime_error("The tree isn't binary tree!");
}


template <typename T, size_t k>
void Tree<T, k>::drawTree() {
   if (!root) return;

   if (!root) return;

    // Constants for drawing
    const float windowWidth = 800;
    const float windowHeight = 600;
    const float nodeRadius = 40; // Increased node radius
    const float verticalSpacing = 130;

    // Create a window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tree Visualization");

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("fonts/waltograph42.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    // Function to recursively draw the nodes
    std::function<void(Node<T>*, float, float, float)> drawNode =
        [&](Node<T>* node, float x, float y, float xOffset) {
            if (!node) return;

            // Recursively draw the children
            float newXOffset = xOffset / 2;
            float childX = x - xOffset * ((node->children.size() - 1) / 2.0f);
            float childY = y + verticalSpacing;
            for (auto child : node->children) {
                if (child) {
                    // Draw the line connecting the node to its child
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(x, y), sf::Color::Red),
                        sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Red)
                    };
                    window.draw(line, 2, sf::Lines);

                    // Draw the child node
                    drawNode(child, childX, childY, newXOffset);
                    childX += xOffset;
                }
            }

            // Draw the node
            sf::CircleShape circle(nodeRadius);
            circle.setFillColor(sf::Color::White); // White fill color for empty circle
            circle.setOutlineColor(sf::Color::Blue); // Blue outline color
            circle.setOutlineThickness(3); // Outline thickness to create empty circle effect
            circle.setPosition(x - nodeRadius, y - nodeRadius);
            window.draw(circle);

            
          
            // Draw the node's value
            std::string to_draw = to_string(node->get_value());
            sf::Text text(to_draw, font, 20);
            text.setFillColor(sf::Color::Black); // Black text color
            // Center the text in the circle
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
            text.setPosition(x, y);
            window.draw(text);
        };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White); // White background color
        drawNode(root, windowWidth / 2, nodeRadius * 2, windowWidth / 4);
        window.display();
    }
}