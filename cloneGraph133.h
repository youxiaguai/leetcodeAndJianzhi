#pragma once
#include "common.h"
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*>visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return node;
        }
        //如果该节点已经被拷贝过，则直接返回
        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }
        //克隆节点
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        //遍历该节点的邻居并更新克隆节点的邻居列表
        for (auto& neighbor : node->neighbors)
        {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;


    }
};