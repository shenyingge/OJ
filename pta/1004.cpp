#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct Node
{
    int id;
    vector<Node*> children;

    Node(int id){
        this->id = id;
        this->children = {};
    }
};

queue<Node*> _queue = {};

vector<int> get_leafs_count(Node* root){
    vector<int> leafs_count = {};
    _queue.push(root);

    while(_queue.size()){
        leafs_count.push_back(0);
        while(_queue.size()){
            Node* cur_node = _queue.front();
            _queue.pop();
            if(cur_node->children.size()){
                leafs_count.back()++;
            }
        }
    }
    return leafs_count;
}


int main(){
    int n, m;
    std::cin>>n>>m;
    std::cout<<n<<" "<<m<<endl;

    map<int, Node*> _map = {};
    for (size_t i = 0; i < m; i++)
    {
        Node* _node = new Node(i+1);
        _map.insert(std::pair<int, Node*>(i+1, _node));
    }


    for (size_t i = 0; i < m; i++)
    {
        int cur_id = 0;
        int k = 0;
        if(i == 0){
            std::cin>>cur_id;
            std::cin>>k;
        }
        Node* cur_node = _map.find(cur_id)->second;
        for (size_t j = 0; j < k; j++)
        {
            int id;
            std::cin>>id;
            Node* _node = _map.find(id)->second;
            cur_node->children.push_back(_node);
        }
    }
    vector<int> leafs_count = get_leafs_count(_map.find(1)->second);
    for (size_t i = 0; i < leafs_count.size(); i++)
    {
        cout<<leafs_count[i];
        if(i != leafs_count.size() - 1){
            cout<<" ";
        }
    }

    return 0;
}
