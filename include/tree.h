// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(std::vector<char> in_vec) {
        root = new Node;
        root->value = 'r';
        buildTree(root, in_vec);
        Perestanovka(root);
    }
    std::vector take(int _i) {
        if (_i >= param_per.size()) {
            return 0;
        }
        else {
            return param_per[_i];
        }
    }

 private:
    typedef struct {
        char value;
        std::vector<Node*> level;
    } Node;
    Node* root;

    std::vector<char> param_per;

    void buildLevel(Node* root, std::vector<char> _in) {
        if (!_in_vec.size()) {
            return;
        }
        if ('r' != root->value) {
            _in.erase(std::find(_in.begin(), _in.end(), root->value));
        }
        for (int step = 0; step < _in.size(); step++) {
            root->level.push_back(new Node);
        }
        for (int step = 0; step < root->level.size(); step++) {
            root->level[step]->value = _in[step];
            buildLevel(root->level[step], _in);
        }
    }
    void Perestanovka(Node* root, std::vector<char> _v = "") {
        if (!root->level.size()) {
            _v.push_back(root->value);
            param_per.push_back(_v);
        }
        if ('r' != root->value) {
            _v.push_back(root->value);
        }
        for (int step = 0; step < root->level.size(); step++) {
            Perestanovka(root->level[step], _v);
        }
    }
};

#endif  // INCLUDE_TREE_H_
