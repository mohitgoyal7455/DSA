class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int k,int v){
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int size;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
        }
    void delNode(Node*oldNode){
        Node*prev=oldNode->prev;
        Node*next=oldNode->next;
        prev->next=next;
        next->prev=prev;
    }    
    void addNode(Node*newnode){
        Node*temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
        }
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
            }
        Node*ansNode=m[key];    
        int ans=ansNode->val;
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;
        return ans;
        }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){
            Node*oldNode=m[key];
            delNode(oldNode);
            m.erase(key);

            
        }
        if(m.size()==size){
           m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node*newnode=new Node(key,val);
        addNode(newnode);
        m[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */