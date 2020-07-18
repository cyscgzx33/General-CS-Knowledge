#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
struct GraphNode
{
    int id;       // start id
    int duration; // in seconds
    int next;     // end id
    int indegree;
    int accum_duration;
  
    GraphNode(int s, int d, int n) : id(s), duration(d), next(n), indegree(0), accum_duration(d) {}
};

void processText(string& text)
{

}

int main(int argc, char** argv)
{
    vector<GraphNode*> nodes;
    unordered_map<int, GraphNode*> map;
    unordered_map<GraphNode*, bool> visit;

    nodes.emplace_back(1, 60, 23);
    nodes.emplace_back(2, 23, 3);
    nodes.emplace_back(3, 12, 0);
    nodes.emplace_back(23, 30, 0);

    // put everything in map
    // check error:
    // (1) 1 -> multiple
    for (auto node: nodes)
    {
        if (map.count(node->id) == 0)
            map[node->id] = node;
        else
        {
            if (node->next != map[node->id]->next) // 1 -> multiple
                cout << "garbage\n"; 
        }
    }

    queue<GraphNode*> nodes_q;
    // count indegree
    for (auto node : nodes)
        map[node->next]->indegree++;


    // put indegree == 1 into the queue
    for (auto node : nodes)
    {
        if (node->indegree == 1)
            nodes_q.push(node);
    }

    while (nodes_q.size() > 0)
    {
        auto cur_node = nodes_q.front();
        if (cur_node->next == 0)
        {

        }
    }

    return 0;
}