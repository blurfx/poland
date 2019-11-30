template<class T>
class ListElement {
    public:
        ListElement(const T& value) {
            next = NULL;
            data = value;
        }
        ~ListElement() {}

        ListElement<T>* getNext() const {
            return next;
        }
        const T& getValue() const {
            return data;
        }
        void setNext(ListElement<T> *el) {
            next = el;
        }
        void setValue(const T& value) {
            data = value; 
        }

    private:
        T data;
        ListElement<T>* next;
};

template<class T>
class List {
    public:
        List() {
            root = NULL;
        }
        ~List() {}
        
        void insert(const T& value) {
            if(root == NULL) {
                root = new ListElement<T>(value);
            } else {
                ListElement<T>* cur = root;
                while(cur->getNext() != NULL) cur = cur->getNext();
                cur->setNext(new ListElement<T>(value));
            }
        }

        void remove(ListElement<T>* el) {
            
            ListElement<T>* cur = root;
            if(el == root) {
                if (root->getNext() == NULL) {
                    delete root;
                    root = NULL;
                } else {
                    cur = root->getNext();
                    delete root;
                    root = cur;
                }
            } else {
                while(cur->getNext() != el) {
                    cur = cur->getNext();
                }
                ListElement<T>* delNode = cur->getNext();
                cur->setNext(delNode->getNext());
                delete delNode;
            }
        }

        ListElement<T>* search(const T& value) {
            ListElement<T>* cur = root;
            while(cur != NULL) {
                if(cur->getValue() == value) {
                    return cur;
                }
                cur = cur->getNext();
            }
            return NULL;
        }

    private:
        ListElement<T>* root;
};
