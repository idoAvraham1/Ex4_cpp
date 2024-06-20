// written by Ido Avraham : 208699181
// EMAIL: idoavraham086@gmail.com
#include "../include/doctest.h"
#include "../include/Tree.h"
#include "../include/Complex.h"

using namespace std;

template<typename Iterator, typename T>
void check_iterator_values2(Iterator begin, Iterator end, const std::vector<T> &expected_values) {
    auto it = begin;
    size_t index = 0;
    for (const auto &expected_value: expected_values) {
        if (it == end) {
            std::cerr << "Iterator reached the end prematurely at index " << index << std::endl;
            REQUIRE(it != end);  // Ensure we haven't reached the end prematurely
            return;
        }
        if ((*it)->value != expected_value) {
            std::cerr << "Value mismatch at index " << index << ": expected " << expected_value << ", got "
                      << (*it)->value << std::endl;
        }
        REQUIRE((*it)->value == expected_value);  // Check the value
        ++it;
        ++index;
    }
    if (it != end) {
        std::cerr << "Iterator did not reach the end. Stopped at index " << index << std::endl;
    }
    REQUIRE(it == end);  // Ensure the iterator reaches the end
}


/**
 * @brief Helper method to check if the values in the iterator range match the expected values.
 *
 * @tparam Iterator The type of the iterator.
 * @tparam T The type of the values.
 * @param begin The beginning of the iterator range.
 * @param end The end of the iterator range.
 * @param expected_values The expected values to compare against.
 */
template<typename Iterator, typename T>
void check_iterator_values(Iterator begin, Iterator end, const vector<T> &expected_values) {
    auto it = begin;
    for (const auto &expected_value: expected_values) {
        REQUIRE(it != end);  // Ensure we haven't reached the end prematurely
        REQUIRE((*it)->value == expected_value);  // Check the value
        ++it;
    }
    REQUIRE(it == end);  // Ensure the iterator reaches the end
}

/**
 * @brief Helper method to create a binary tree.
 *
 * @tparam T The type of the node values.
 * @param node_structure The structure of the binary tree as pairs of nodes and their children.
 * @return Tree<T> The created binary tree.
 */
template<typename T>
Tree<T> create_binary_tree(const vector<pair<Node<T> *, vector<Node<T> *>>> &node_structure) {
    Tree<T> tree;
    if (!node_structure.empty()) {
        tree.add_root(*node_structure[0].first);
        for (const auto &[parent, children]: node_structure) {
            for (const auto &child: children) {
                tree.add_sub_node(*parent, *child);
            }
        }
    }
    return tree;
}

/**
 * @brief Helper method to create a k-ary tree.
 *
 * @tparam T The type of the node values.
 * @tparam k The number of children each node can have.
 * @param node_structure The structure of the k-ary tree as pairs of nodes and their children.
 * @return Tree<T, k> The created k-ary tree.
 */
template<typename T, size_t k>
Tree<T, k> create_k_ary_tree(vector<pair<Node<T> *, vector<Node<T> *>>> &node_structure) {
    Tree<T, k> tree;
    if (!node_structure.empty()) {
        tree.add_root(*node_structure[0].first);
        for (const auto &[parent, children]: node_structure) {
            for (const auto &child: children) {
                tree.add_sub_node(*parent, *child);
            }
        }
    }
    return tree;
}


TEST_CASE("Test tree creation") {
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    vector<pair<Node<double> *, vector<Node<double> *>>> binary_structure = {
            {&root_node, {&n1, &n2}},
            {&n1,        {&n3, &n4}},
            {&n2,        {&n5}}
    };

    vector<pair<Node<double> *, vector<Node<double> *>>> k_ary_structure = {
            {&root_node, {&n1, &n2, &n3}},
            {&n1,        {&n4}},
            {&n2,        {&n5}}
    };

    SUBCASE("Test default k") {
        Tree<double> tree = create_binary_tree(binary_structure);

        vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        auto it = tree.begin();
        auto it_end = tree.end();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("Test k=3") {
        Tree<double, 3> three_ary_tree = create_k_ary_tree<double, 3>(k_ary_structure);

        vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        auto it = three_ary_tree.begin();
        auto it_end = three_ary_tree.end();
        check_iterator_values(it, it_end, expected_values);
    }
}

TEST_CASE("Test iterators doubles") {
    Node<double> root_node_double(1.1);
    Node<double> n1_double(1.2);
    Node<double> n2_double(1.3);
    Node<double> n3_double(1.4);
    Node<double> n4_double(1.5);
    Node<double> n5_double(1.6);

    vector<pair<Node<double> *, vector<Node<double> *>>> binary_structure_double = {
            {&root_node_double, {&n1_double, &n2_double}},
            {&n1_double,        {&n3_double, &n4_double}},
            {&n2_double,        {&n5_double}}
    };

    Node<string> root_node_string("root");
    Node<string> n1_string("n1");
    Node<string> n2_string("n2");
    Node<string> n3_string("n3");
    Node<string> n4_string("n4");
    Node<string> n5_string("n5");


    vector<pair<Node<string> *, vector<Node<string> *>>> binary_structure_string = {
            {&root_node_string, {&n1_string, &n2_string}},
            {&n1_string,        {&n3_string, &n4_string}},
            {&n2_string,        {&n5_string}}
    };

    Tree<double> tree = create_binary_tree(binary_structure_double);

    SUBCASE("Pre order double") {
        vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        auto it = tree.begin_pre_order();
        auto it_end = tree.end_pre_order();
        check_iterator_values(it, it_end, expected_values);
    }


    SUBCASE("Post order double") {
        vector<double> expected_values = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
        auto it = tree.begin_post_order();
        auto it_end = tree.end_post_order();
        check_iterator_values(it, it_end, expected_values);
    }


    SUBCASE("In order double") {
        vector<double> expected_values = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
        auto it = tree.begin_in_order();
        auto it_end = tree.end_in_order();
        check_iterator_values(it, it_end, expected_values);
    }


    SUBCASE("DFS double") {
        vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it, it_end, expected_values);
    }


    SUBCASE("BFS double") {
        vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it, it_end, expected_values);
    }


    SUBCASE("MinHeap Iterator") {

        SUBCASE("MinHeap double") {
            vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
            auto it = tree.begin_min_heap();
            auto it_end = tree.end_min_heap();
            check_iterator_values(it, it_end, expected_values);
        }


        SUBCASE("MinHeap int") {
            Node<int> root_node_int(10);
            Node<int> n1_int(20);
            Node<int> n2_int(30);
            Node<int> n3_int(40);
            Node<int> n4_int(50);
            Node<int> n5_int(60);
            Node<int> n6_int(70);
            Node<int> n7_int(80);
            Node<int> n8_int(-10);
            Node<int> n9_int(-20);

            vector<pair<Node<int> *, vector<Node<int> *>>> binary_structure_int = {
                    {&root_node_int, {&n1_int, &n2_int}},
                    {&n1_int,        {&n3_int, &n4_int}},
                    {&n2_int,        {&n5_int, &n6_int}},
                    {&n3_int,        {&n7_int, &n8_int}},
                    {&n4_int,        {&n9_int}}
            };

            Tree<int> ints_tree = create_binary_tree(binary_structure_int);
            vector<int> expected_values = {-20, -10, 10, 20, 30, 40, 50, 60, 70, 80};
            auto it = ints_tree.begin_min_heap();
            auto it_end = ints_tree.end_min_heap();
            check_iterator_values(it, it_end, expected_values);
        }

    }

}

TEST_CASE("Test iterators strings") {

    Node<string> root_node_string("root");
    Node<string> n1_string("n1");
    Node<string> n2_string("n2");
    Node<string> n3_string("n3");
    Node<string> n4_string("n4");
    Node<string> n5_string("n5");


    vector<pair<Node<string> *, vector<Node<string> *>>> binary_structure_string = {
            {&root_node_string, {&n1_string, &n2_string}},
            {&n1_string,        {&n3_string, &n4_string}},
            {&n2_string,        {&n5_string}}
    };
    Tree<string> tree = create_binary_tree(binary_structure_string);

    SUBCASE("Pre order string") {

        vector<string> expected_values = {"root", "n1", "n3", "n4", "n2", "n5"};
        auto it = tree.begin_pre_order();
        auto it_end = tree.end_pre_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("Post order string") {

        vector<string> expected_values = {"n3", "n4", "n1", "n5", "n2", "root"};
        auto it = tree.begin_post_order();
        auto it_end = tree.end_post_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("In order string") {

        vector<string> expected_values = {"n3", "n1", "n4", "root", "n5", "n2"};
        auto it = tree.begin_in_order();
        auto it_end = tree.end_in_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("DFS string") {

        vector<string> expected_values = {"root", "n1", "n3", "n4", "n2", "n5"};
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("BFS string") {

        vector<string> expected_values = {"root", "n1", "n2", "n3", "n4", "n5"};
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("MinHeap strings") {
        vector<string> expected_values = {"n1", "n2", "n3", "n4", "n5", "root"};
        auto it = tree.begin_min_heap();
        auto it_end = tree.end_min_heap();
        check_iterator_values(it, it_end, expected_values);
    }
}

TEST_CASE("Test iterators k>2") {
    Node<double> root_node_double(1.1);
    Node<double> n1_double(1.2);
    Node<double> n2_double(1.3);
    Node<double> n3_double(1.4);
    Node<double> n4_double(1.5);
    Node<double> n5_double(1.6);
    Node<double> n6_double(1.7);
    Node<double> n7_double(1.8);
    Node<double> n8_double(1.9);
    Node<double> n9_double(2.0);

    vector<pair<Node<double> *, vector<Node<double> *>>> ktree_structure_double = {
            {&root_node_double, {&n1_double}},
            {&n1_double,        {&n3_double, &n4_double, &n2_double}},
            {&n2_double,        {&n5_double, &n6_double}},
            {&n5_double,        {&n7_double, &n8_double, &n9_double}}
    };

    Tree<double, 3> tree = create_k_ary_tree<double, 3>(ktree_structure_double);

    /* expected tree structure:
          1.1
           |
          1.2
         / | \
      1.4 1.5 1.3
              /  \
             1.6  1.7
            / |  \
          1.8 1.9 2
 */

    SUBCASE("DFS k>2") {
        vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 1.8, 1.9, 2.0, 1.7};
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("BFS k>2") {
        vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 1.7, 1.8, 1.9, 2.0};
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it, it_end, expected_values);
    }

    SUBCASE("In/Post/Pre order and MinHeap k>2") {
        SUBCASE("PreOrder") {
            vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 1.8, 1.9, 2.0, 1.7};
            auto it = tree.begin_pre_order();
            auto it_end = tree.end_pre_order();
            check_iterator_values(it, it_end, expected_values);
        }
        SUBCASE("PostOrder") {
            vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 1.8, 1.9, 2.0, 1.7};
            auto it = tree.begin_post_order();
            auto it_end = tree.end_post_order();
            check_iterator_values(it, it_end, expected_values);
        }
        SUBCASE("inOrder") {
            vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 1.8, 1.9, 2.0, 1.7};
            auto it = tree.begin_in_order();
            auto it_end = tree.end_in_order();
            check_iterator_values(it, it_end, expected_values);
        }

        SUBCASE("minHeap") {
            vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 1.8, 1.9, 2.0, 1.7};
            CHECK_THROWS_AS(auto it = tree.begin_min_heap(), std::runtime_error);
            CHECK_THROWS_AS(auto it_end = tree.end_min_heap(), std::runtime_error);

        }
    }

}

TEST_CASE("Test iterators complexes") {
    // Create Complex objects
    Complex c1(1, 7);
    Complex c2(5, 4);
    Complex c3(8, 3);
    Complex c4(7, 6);
    Complex c5(9, 6);
    Complex c6(-3, 6);
    Complex c7(-9, 6);
    Complex c8(11, 6);


    // Create nodes
    Node<Complex> root_node_complex(c1);
    Node<Complex> n2_complex(c2);
    Node<Complex> n3_complex(c3);
    Node<Complex> n4_complex(c4);
    Node<Complex> n5_complex(c5);
    Node<Complex> n6_complex(c6);
    Node<Complex> n7_complex(c7);
    Node<Complex> n8_complex(c8);


    // create the binary complex tree structure
    vector<pair<Node<Complex>*, vector<Node<Complex>*>>> complex_tree_structure = {
            {&root_node_complex , {&n2_complex,&n3_complex}},
            {&n2_complex , {&n4_complex,&n5_complex}},
            {&n3_complex,{&n8_complex}} ,
            {&n4_complex , {&n6_complex}} ,
            {&n6_complex , {&n7_complex}}
    };
    /*
     Expected tree structure:
                                    (1, 7i)
                                    /       \
                                (5, 4i)     (8, 3i)
                                /    \         /
                             (7, 6i) (9, 6i)  (11, 6i)
                             /
                          (-3, 6i)
                          /
                      (-9, 6i)
     */

    Tree<Complex> tree = create_binary_tree(complex_tree_structure);

    SUBCASE("in order iterator"){
        vector<Complex> expectedValues = {c7,c6,c4, c2 ,c5 ,c1 ,c8 , c3 };
        auto it = tree.begin_in_order();
        auto it_end = tree.end_in_order();
        check_iterator_values(it , it_end , expectedValues);
    }

    SUBCASE("post order iterator"){
        vector<Complex> expectedValues = {c7,c6,c4, c5 ,c2 ,c8 , c3 , c1};
        auto it = tree.begin_post_order();
        auto it_end = tree.end_post_order();
        check_iterator_values(it , it_end , expectedValues);
    }

    SUBCASE("pre order iterator"){
        vector<Complex> expectedValues = {c1, c2, c4, c6, c7, c5, c3, c8};
        auto it = tree.begin_pre_order();
        auto it_end = tree.end_pre_order();
        check_iterator_values(it , it_end , expectedValues);
    }
    SUBCASE("DFS iterator"){
        vector<Complex> expectedValues = {c1, c2 , c4 , c6 , c7 , c5 , c3 , c8 };
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it , it_end , expectedValues);
    }

    SUBCASE("BFS iterator"){
        vector<Complex> expectedValues = {c1, c2 , c3 , c4 , c5 , c8 , c6 ,c7 };
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it , it_end , expectedValues);
    }

    SUBCASE("Min heap iterator"){ // note that the comparing is happening according to the complex magnitude
        vector<Complex> expectedValues = {c2 , c6 , c1 , c3 , c4 , c5 , c7, c8};
        auto it = tree.begin_min_heap();
        auto it_end = tree.end_min_heap();
        check_iterator_values(it , it_end , expectedValues);
    }
}

TEST_CASE("Extreme cases") {

    SUBCASE("Empty tree") {
        Tree<int> empty_tree;

        CHECK(empty_tree.begin() == empty_tree.end());
        CHECK(empty_tree.begin_pre_order() == empty_tree.end_pre_order());
        CHECK(empty_tree.begin_post_order() == empty_tree.end_post_order());
        CHECK(empty_tree.begin_in_order() == empty_tree.end_in_order());
        CHECK(empty_tree.begin_bfs_scan() == empty_tree.end_bfs_scan());
        CHECK(empty_tree.begin_min_heap() == empty_tree.end_min_heap());
    }

    SUBCASE("Single node tree") {
        Node<int> root_node(42);
        Tree<int> single_node_tree;
        single_node_tree.add_root(root_node);

        vector<int> expected_values = {42};

        check_iterator_values(single_node_tree.begin(), single_node_tree.end(), expected_values);
        check_iterator_values(single_node_tree.begin_pre_order(), single_node_tree.end_pre_order(), expected_values);
        check_iterator_values(single_node_tree.begin_post_order(), single_node_tree.end_post_order(), expected_values);
        check_iterator_values(single_node_tree.begin_in_order(), single_node_tree.end_in_order(), expected_values);
        check_iterator_values(single_node_tree.begin_bfs_scan(), single_node_tree.end_bfs_scan(), expected_values);
        check_iterator_values(single_node_tree.begin_min_heap(), single_node_tree.end_min_heap(), expected_values);
    }
}
