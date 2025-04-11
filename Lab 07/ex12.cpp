#include <iostream>
// 1. Literals for Temperature Conversion
constexpr long double operator"" _Kelvin(long double k) {
    return k - 273.15L;
}
// Celsius = (Fahrenheit - 32) * 5/9
constexpr long double operator"" _Fahrenheit(long double f) {
    return (f - 32.0L) * 5.0L / 9.0L;
}

// 2. Tree Template

// Tree Node structure.
template<typename T>
struct TreeNode {
    T value;
    TreeNode<T>* parent;
    TreeNode<T>** children;
    int numChildren;
    int capacity;

    TreeNode(const T& val, TreeNode<T>* par = nullptr)
        : value(val), parent(par), children(nullptr), numChildren(0), capacity(0) {}

    // Destructor: recursively deletes all children.
    ~TreeNode() {
        for (int i = 0; i < numChildren; i++) {
            delete children[i];
        }
        delete[] children;
    }

    // Add new child at the end.
    void addChild(TreeNode<T>* child) {
        if(numChildren == capacity) {
            // Increase capacity
            int newCapacity = (capacity == 0) ? 2 : capacity * 2;
            TreeNode<T>** newChildren = new TreeNode<T>*[newCapacity];
            // Copy the old children.
            for (int i = 0; i < numChildren; i++) {
                newChildren[i] = children[i];
            }
            delete[] children;
            children = newChildren;
            capacity = newCapacity;
        }
        children[numChildren++] = child;
    }

    // Insert a child at the given index.
    void insertChildAt(TreeNode<T>* child, int index) {
        if (index < 0 || index > numChildren) {
            std::cerr << "Invalid index for insertion.\n";
            return;
        }
        if(numChildren == capacity) {
            int newCapacity = (capacity == 0) ? 2 : capacity * 2;
            TreeNode<T>** newChildren = new TreeNode<T>*[newCapacity];
            // Copy elements.
            for (int i = 0; i < index; i++) {
                newChildren[i] = children[i];
            }
            newChildren[index] = child;
            // Copy the remaining children.
            for (int i = index; i < numChildren; i++) {
                newChildren[i+1] = children[i];
            }
            delete[] children;
            children = newChildren;
            capacity = newCapacity;
            numChildren++;
        } else {
            // Shift children to make space.
            for (int i = numChildren; i > index; i--) {
                children[i] = children[i-1];
            }
            children[index] = child;
            numChildren++;
        }
    }

    // Bubble sort the children.
    void sortChildren(bool (*cmp)(const T&, const T&) = nullptr) {
        for (int i = 0; i < numChildren - 1; i++) {
            for (int j = 0; j < numChildren - i - 1; j++) {
                bool condition;
                if (cmp) {
                    condition = cmp(children[j]->value, children[j+1]->value);
                } else {
                    condition = children[j]->value < children[j+1]->value;
                }
                // If the condition is not met, swap the pointers.
                if (!condition) {
                    TreeNode<T>* temp = children[j];
                    children[j] = children[j+1];
                    children[j+1] = temp;
                }
            }
        }
    }

    // Recursively count the number of nodes.
    int countRecursive() const {
        int count = numChildren;
        for (int i = 0; i < numChildren; i++) {
            count += children[i]->countRecursive();
        }
        return count;
    }
};

// Tree template class.
template<typename T>
class Tree {
public:
    TreeNode<T>* root;

    Tree() : root(nullptr) {}
    
    ~Tree() {
        if(root)
            delete root;
    }
    // add_node:
    TreeNode<T>* add_node(TreeNode<T>* parent, const T& value) {
        if (parent == nullptr) {
            if (root == nullptr) {
                root = new TreeNode<T>(value);
                return root;
            } else {
                std::cerr << "Root already exists; cannot add another root with add_node.\n";
                return nullptr;
            }
        } else {
            TreeNode<T>* newNode = new TreeNode<T>(value, parent);
            parent->addChild(newNode);
            return newNode;
        }
    }

    // get_node:
    TreeNode<T>* get_node(TreeNode<T>* parent) {
        return (parent == nullptr) ? root : parent;
    }

    // delete_node:
    void delete_node(TreeNode<T>* node) {
        if (node == nullptr) return;
        if (node->parent) {
            TreeNode<T>* par = node->parent;
            int idx = -1;
            for (int i = 0; i < par->numChildren; i++) {
                if (par->children[i] == node) {
                    idx = i;
                    break;
                }
            }
            if (idx != -1) {
                for (int i = idx; i < par->numChildren - 1; i++) {
                    par->children[i] = par->children[i+1];
                }
                par->numChildren--;
            }
        } else {
            root = nullptr;
        }
        delete node;
    }

    // find:
    TreeNode<T>* find(TreeNode<T>* node, bool (*compare)(const T&, const T&), const T& target) {
        if (node == nullptr)
            node = root;
        if (node == nullptr)
            return nullptr;
        if (compare(node->value, target))
            return node;
        for (int i = 0; i < node->numChildren; i++) {
            TreeNode<T>* res = find(node->children[i], compare, target);
            if (res)
                return res;
        }
        return nullptr;
    }

    // Overloaded find that starts at the root.
    TreeNode<T>* find(bool (*compare)(const T&, const T&), const T& target) {
        return find(root, compare, target);
    }

    // insert:
    TreeNode<T>* insert(TreeNode<T>* parent, int index, const T& value) {
        if (parent == nullptr) {
            if (root == nullptr) {
                root = new TreeNode<T>(value);
                return root;
            } else {
                std::cerr << "Root already exists; cannot insert another root.\n";
                return nullptr;
            }
        } else {
            TreeNode<T>* newNode = new TreeNode<T>(value, parent);
            parent->insertChildAt(newNode, index);
            return newNode;
        }
    }

    // sort:
    void sort(TreeNode<T>* node, bool (*compare)(const T&, const T&) = nullptr) {
        if (node == nullptr)
            return;
        node->sortChildren(compare);
    }

    // count:
    int count(TreeNode<T>* node) {
        if (node == nullptr)
            node = root;
        if (node == nullptr)
            return 0;
        return node->countRecursive();
    }
};

// A sample comparison function for the find() method.
// Returns true if nodeValue equals target.
bool compareInts(const int& nodeValue, const int& target) {
    return nodeValue == target;
}

// A sample comparison function for sorting (ascending order).
bool compareForSort(const int& a, const int& b) {
    return a < b;
}

int main() {
    // Exercise 1
    // 300 Kelvin converted to Celsius ==> 300 - 273.15 = 26.85 Celsius (approximately)
    // 120 Fahrenheit converted to Celsius ==> (120 - 32)*5/9 = 48.89 Celsius (approximately)
    float celsiusFromKelvin   = 300.0_Kelvin;
    float celsiusFromFahrenheit = 120.0_Fahrenheit;

    std::cout << "300 Kelvin is approximately " << celsiusFromKelvin << " Celsius.\n";
    std::cout << "120 Fahrenheit is approximately " << celsiusFromFahrenheit << " Celsius.\n\n";

    // Exercise 2
    // Create a tree of integers.
    Tree<int> tree;

    // Add the root node.
    TreeNode<int>* root = tree.add_node(nullptr, 10);

    // Add children to the root.
    TreeNode<int>* child1 = tree.add_node(root, 5);
    TreeNode<int>* child2 = tree.add_node(root, 15);
    TreeNode<int>* child3 = tree.add_node(root, 20);

    // Insert a node at a specific index in root's children.
    TreeNode<int>* insertedChild = tree.insert(root, 1, 7);

    // Count children in the tree.
    int totalChildren = tree.count(nullptr);
    std::cout << "Total children count (recursive) starting from the root: " << totalChildren << "\n";

    // Find a node with the value 15.
    TreeNode<int>* foundNode = tree.find(compareInts, 15);
    if (foundNode) {
        std::cout << "Found node with value: " << foundNode->value << "\n";
    } else {
        std::cout << "Node with value 15 not found.\n";
    }

    // Sort the root's children.
    tree.sort(root, compareForSort);
    std::cout << "Root's children after sorting: ";
    for (int i = 0; i < root->numChildren; i++) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";

    // Delete a node.
    tree.delete_node(child1);
    std::cout << "After deletion, total children count is: " << tree.count(nullptr) << "\n";

    return 0;
}