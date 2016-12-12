//
//  main.cpp
//  TreeHeight
//
//  Created by Garrett Wang on 12/12/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <sys/resource.h>



class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;
    
    Node() {
        this->parent = NULL;
    }
    
    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};

int look_for_max_height(Node n, int height);

int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    
    std::vector<Node> nodes;
    nodes.resize(n);
    int root = 0;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        else
            root = child_index;
         nodes[child_index].key = child_index;
    }
    
    return look_for_max_height(nodes[root], 1);
    
}

int look_for_max_height(Node n, int height){
    int tempHeight = height;
    int maxHeight = 0;
    for(int i = 0; i < n.children.size(); i++){
        height = look_for_max_height(*n.children[i], tempHeight+1);
        maxHeight = std::max(maxHeight, height);
    }
    
    return std::max(maxHeight, height);
}

int main (int argc, char **argv)
{
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;
    
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
    
    std::cout << main_with_large_stack_space() << std::endl;
    return 0;
}

