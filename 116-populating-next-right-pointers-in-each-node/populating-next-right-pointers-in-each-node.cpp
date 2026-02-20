class Solution {
public:
    
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while (q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                prev = NULL;
                if (q.size() == 0) {
                    break;
                }
                q.push(NULL);
            }
            else {
                if (prev != NULL) {
                    prev->next = curr;
                }

                prev = curr;

                if (curr->left != NULL) {
                    q.push(curr->left);
                }

                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};