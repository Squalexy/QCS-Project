#include <gtest/gtest.h>
#include "code.cpp"
#include <regex>

using namespace std;

vector<vector<int>> calculateParents(const vector<vector<int>> &childs)
{
    vector<vector<int>> parents(childs.size());

    for (int child = 0; child < childs.size(); ++child)
    {
        for (int parent : childs[child])
        {
            parents[parent].push_back(child);
        }
    }

    return parents;
}

namespace
{
    TEST(Recursion_control, tc1)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 4;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 1, 1, 3, 4};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, -1, -1, 4};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_control, tc8)
    {
        // Setup
        childs = {{}, {2}, {3, 4}, {5}, {5}, {}};
        int node = 3;
        dp = {-1, -1, -1, -1, -1, -1};
        time_ = {0, 1, 3, 2, 1, 4};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, -1, 6, -1, 4};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_control, tc9)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {5}, {}};
        int node = 5;
        dp = {-1, -1, -1, -1, -1, -1};
        time_ = {0, 1, 4, 5, 3, 5};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, -1, -1, -1, 5};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_control, tc10)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {5}, {}};
        int node = 4;
        dp = {-1, -1, -1, -1, -1, -1};
        time_ = {0, 1, 4, 5, 3, 5};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, -1, -1, 8, 5};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_control, tc11)
    {
        // Setup
        childs = {{}, {2}, {3, 4}, {4}, {}};
        int node = 2;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 1, 4, 5, 3};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, 12, 8, 3};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_control, tc12)
    {
        // Setup
        childs = {{}, {2, 3, 4, 5}, {5}, {5}, {5}, {}};
        int node = 1;
        dp = {-1, -1, -1, -1, -1, -1};
        time_ = {0, 1, 4, 5, 3, 5};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, 11, 9, 10, 8, 5};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, node_tc1)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 1;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 2, 7, 4, 3};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, 12, 10, 7, 3};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, node_tc2)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 4;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 2, 7, 4, 3};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, -1, -1, 3};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, leaf_tc3)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 3;
        dp = {-1, -1, 10, -1, 5};
        time_ = {0, 1, 5, 3, 5};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, 10, 8, 5};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, childs_tc4)
    {
        // Setup
        childs = {{}, {2, 3}, {3, 4}, {4}, {}};
        int node = 2;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 1, 5, 3, 5};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, 13, 8, 5};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, dp_tc5)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 2;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 1, 3, 4, 3};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, 6, -1, 3};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, dp_tc6)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 4;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 1, 3, 4, 3};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, -1, -1, -1, 3};
        ASSERT_EQ(dp, dp_after);
    }

    TEST(Recursion_data, max_time_tc7)
    {
        // Setup
        childs = {{}, {2, 3}, {4}, {4}, {}};
        int node = 1;
        dp = {-1, -1, -1, -1, -1};
        time_ = {0, 1, 3, 4, 3};

        // Test
        recursion(node);

        // Assert
        vector<int> dp_after = {-1, 8, 6, 7, 3};
        ASSERT_EQ(dp, dp_after);
    }
}

namespace
{
    TEST(Print_min_order_control, control_flow_p1)
    {
        // Setup
        number_of_tasks = 5;
        first = 1;
        childs = {{}, {2, 3}, {4}, {4}, {5}, {}};
        parents = calculateParents(childs);
        time_ = {0, 1, 4, 2, 2, 1};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "11\n1\n2\n3\n4\n5\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_control, control_loop_twice)
    {
        // Setup
        number_of_tasks = 3;
        first = 2;
        childs = {{}, {3}, {1, 3}, {}};
        parents = calculateParents(childs);
        time_ = {0, 3, 3, 2};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "9\n2\n1\n3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_control, control_loop_max)
    {
        // Setup
        number_of_tasks = 5;
        first = 1;
        childs = {{}, {2}, {3, 4}, {5}, {5}, {}};
        parents = calculateParents(childs);
        time_ = {0, 1, 3, 2, 1, 4};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "12\n1\n2\n3\n4\n5\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, number_of_tasks)
    {
        // Setup
        number_of_tasks = 5;
        first = 2;
        childs = {{}, {4, 5}, {1, 3, 4}, {5}, {}, {4}};
        parents = calculateParents(childs);
        time_ = {0, 2, 7, 4, 3, 2};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "19\n2\n1\n3\n5\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, degree)
    {
        // Setup
        number_of_tasks = 6;
        first = 1;
        childs = {{}, {2, 3}, {4}, {4, 6}, {5}, {}, {5}};
        parents = calculateParents(childs);
        time_ = {0, 2, 5, 2, 8, 1, 3};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "22\n1\n2\n3\n4\n6\n5\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, visited)
    {
        // Setup
        number_of_tasks = 4;
        first = 1;
        childs = {{}, {2, 4}, {3}, {4}, {}};
        parents = calculateParents(childs);
        time_ = {0, 4, 2, 1, 1};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "9\n1\n2\n3\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, time_)
    {
        // Setup
        number_of_tasks = 4;
        first = 4;
        childs = {{}, {2}, {3}, {}, {1, 2}};
        parents = calculateParents(childs);
        time_ = {0, 5, 3, 4, 1};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "14\n4\n1\n2\n3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, first)
    {
        // Setup
        number_of_tasks = 5;
        first = 3;
        childs = {{}, {2}, {}, {5}, {2}, {1, 2, 4}};
        parents = calculateParents(childs);
        time_ = {0, 2, 3, 4, 1, 5};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "16\n3\n5\n1\n4\n2\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, childs)
    {
        // Setup
        number_of_tasks = 5;
        first = 4;
        childs = {{}, {5}, {1, 5}, {2}, {3}, {}};
        parents = calculateParents(childs);
        time_ = {0, 6, 5, 4, 6, 1};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "23\n4\n3\n2\n1\n5\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, np)
    {
        // Setup
        number_of_tasks = 5;
        first = 3;
        childs = {{}, {2}, {4}, {1, 2, 4, 5}, {}, {4}};
        parents = calculateParents(childs);
        time_ = {0, 4, 2, 3, 5, 8};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "23\n3\n1\n2\n5\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(Print_min_order_data, parents)
    {
        // Setup
        number_of_tasks = 6;
        first = 1;
        childs = {{}, {2, 3}, {5, 6}, {4}, {6}, {6}, {}};
        parents = calculateParents(childs);
        time_ = {0, 3, 3, 2, 2, 5, 2};

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        mininum_amount_of_time_AND_sequence();
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "18\n1\n2\n3\n4\n5\n6\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

}

namespace
{
    TEST(helper_control, tc1)
    {
        // Setup
        int n = 4;

        pq.push(4);
        degree = {0, 0, 1, 1, 2};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, true, true, false};
        visited = stack_;

        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc2)
    {
        // Setup
        int n = 3;

        pq.push(3);
        degree = {0, 0, 1, 1};
        childs = {{}, {2, 3}, {}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, true, false};

        visited = stack_;

        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc4)
    {
        // Setup
        int n = 2;

        pq.push(2);

        degree = {0, 0, 1, 0, 0};
        childs = {{}, {2}, {3, 4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "4\n2\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc5)
    {
        // Setup
        int n = 2;

        pq.push(2);
        pq.push(3);

        // printPriorityQueue(pq);

        degree = {0, 0, 1, 1, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc6)
    {
        // Setup
        int n = 3;

        pq.push(3);

        // printPriorityQueue(pq);

        degree = {0, 0, 1, 1, 1};
        childs = {{}, {2}, {3}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, true, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc7)
    {
        // Setup
        int n = 2;

        pq.push(2);

        // printPriorityQueue(pq);

        degree = {0, 0, 1, 0};
        childs = {{}, {2}, {3}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "2\n3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc8)
    {
        // Setup
        int n = 1;

        pq.push(1);

        // printPriorityQueue(pq);

        degree = {0, 0, 0, 0, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, false, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "1\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_control, tc9)
    {
        // Setup
        int n = 1;

        pq.push(1);

        degree = {0, 0, 0, 0, 0, 0};
        childs = {{}, {2, 3, 4, 5}, {5}, {5}, {5}, {}};
        parents = calculateParents(childs);
        stack_ = {false, false, false, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "1\n5\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc1)
    {
        // Setup
        int n = 2;

        pq.push(2);

        degree = {0, 0, 1, 0};
        childs = {{}, {2}, {3}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "2\n3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc2)
    {
        // Setup
        int n = 1;

        pq.push(1);

        degree = {0, 0, 0, 0, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, false, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "1\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc3)
    {
        // Setup
        int n = 3;

        pq.push(3);

        degree = {0, 0, 1, 2};
        childs = {{}, {2, 3}, {3}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, true, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc4)
    {
        // Setup
        int n = 3;

        pq.push(3);

        degree = {0, 0, 1, 2};
        childs = {{}, {2, 3}, {3}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, true, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "3\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc5)
    {
        // Setup
        int n = 2;

        pq.push(2);
        pq.push(3);

        degree = {0, 0, 1, 1, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc6)
    {
        // Setup
        int n = 1;

        pq.push(1);

        degree = {0, 0, 0, 0, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, false, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "1\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc7)
    {
        // Setup
        int n = 2;

        pq.push(2);
        pq.push(3);

        degree = {0, 0, 1, 1, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, true, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

    TEST(helper_data_flow, tc8)
    {
        // Setup
        int n = 1;

        pq.push(1);

        degree = {0, 0, 0, 0, 0};
        childs = {{}, {2, 3}, {4}, {4}, {}};
        parents = calculateParents(childs);
        stack_ = {false, false, false, false, false};

        visited = stack_;
        visited_childs = stack_;
        visited_parents = stack_;

        // Test
        stringstream captured_output;
        streambuf *original_stdout = cout.rdbuf();
        cout.rdbuf(captured_output.rdbuf());
        helper_function(n);
        cout.rdbuf(original_stdout);

        // Assert
        string expected_output = "1\n4\n";
        ASSERT_EQ(captured_output.str(), expected_output);
    }

}
