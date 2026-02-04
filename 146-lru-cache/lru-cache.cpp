class Node{
    public:
    int key,val;
    Node*next;
    Node*prev;
    Node(int k,int v){
        key=k;
        val=v;
        prev=next=NULL;


    }
};
class LRUCache{
    public:
    int size;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    unordered_map<int,Node*>m;
    LRUCache(int capacity){
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void delnode(Node*oldnode){
        Node*prev=oldnode->prev;
        Node*next=oldnode->next;
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
    int get(int key){
        if(m.find(key)==m.end()){
            return -1;
        }
        Node*ansNode=m[key];
        int ans=ansNode->val;
        m.erase(key);
        delnode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;

         return ans;

    }
    void put(int key,int val){
        if(m.find(key)!= m.end()){
            Node*oldnode=m[key];
            delnode(oldnode);
            m.erase(key);


        }
        if(m.size()==size){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        

        }
        Node*newNode=new Node(key,val);
        addNode(newNode);
        m[key]=newNode;


    }


};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */