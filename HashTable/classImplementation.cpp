#include<iostream>
#include<cstring>
using namespace std;

//HashMap Implementation(Separate CHAINING)
//Node contating (key+value) and next pointer
//key is string and value is generic(any type) and next is nodde<T>* next 

template<typename T>
class Node{

    public:
        string key;
        T value;
        Node<T>* next;

    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }

    //destructor
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }

};

//Hashtable class implementation
template<typename T>
class Hashtable{

    int table_size;
    
    Node<T>** table; //points to array of pointers

    int hashFn(string key)
    {
        int idx = 0; //find it  
        int p=1; //as first character will be multiplied by 27^0
        for(int j=0;j<key.length();j++) {
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
    return idx;

    }

    void rehash()
    {
        Node<T>** old_table = table;
        int old_table_size = table_size;
        table_size = 2*table_size;
        table = new Node<T>*[table_size]; //table points to new table_size

        

        for(int i=0;i<table_size;i++) {
            table[i] = NULL;
        }

        current_size = 0;

        //shift the elements from old table to new table
        for(int i=0;i<old_table_size;i++)
        {
            //gives head of oldTable LinkedList
            Node<T>*temp = old_table[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);//insert in new table
                temp=temp->next;
            }
            //delete the shifted row
            if(old_table[i]!=NULL)
            {
                delete old_table[i];//points to head i.e. when  not null delete from head to complete using destructor which deletes recutsively
            }
        }
        delete [] old_table;//old table array is deleted
    }

    public:

        int current_size;

        Hashtable(int ts = 5)
        {
            table_size = ts;
            current_size = 0;
            table = new Node<T>* [table_size]; //data type of each entry 

            //initialising all buckets with NULL so that we can chk if dleete possible or not
            for(int i=0;i<table_size;i++){
                table[i] = NULL;
            }
        }

        // int currentSize() { 

        // }

        void insert(string key, T value)
        {
            int idx = hashFn(key);

            //make ll
            Node<T>*n = new Node<T>(key,value);

            //insert at head of the LinkedList starting from table index
            n->next = table[idx];
            table[idx] = n;
            current_size++;

            // Rehashing
            float load_factor = current_size/table_size;
            // cout<<load_factor<<endl;

            if(load_factor > 0.7)
            {
                rehash();
            }


        }

        //looking inside hashtable
        void print()
        {
            for(int i=0;i<table_size;i++)
            {
                cout<<"Bucket "<<i<<" ->";
                Node<T>* temp = table[i];
                while(temp!= NULL)
                {
                    cout<<temp->key<<" -> ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        //search for key's value
        /*to return pointer to value or NULL*/
        T* search(string key){ //if item is present return value and if not return NULL

            //find index of key
            int idx = hashFn(key);
            Node<T>* temp = table[idx];

            while(temp!= NULL)
            {
                if(temp->key==key)
                {
                    return &temp->value; //we will return the address of box which contains value thus, &temp
                }

                //go to next Node
                temp = temp->next;

                return NULL; //null ptr
            }

        }

        T& operator[](string key)
        {
            //if key is present or jnot
            T* findKey = search(key);

            if(findKey==NULL)
            {
                //key is not present.Now make key and insert some garbage value inside it
                T garbage;
                insert(key, garbage);
                findKey = search(key);//now key exists and it will be FOUND
            }
            return *findKey;
        }

        void erase(string key)
        {
            int idx = hashFn(key);
            //traverse in the index and remove
            Node<T>* temp = table[idx];

            //if head is the only value present
            if(temp->key==key)
            {
                table[idx] = temp->next;
                temp->next = NULL;
                delete temp;
                current_size--;
                return;
            }

            while(temp!=NULL)
            {   
                //if key present in the middle of some LL
                if(temp->next->key == key)
                {
                    Node<T>* temp2 = temp->next;//then make in temp2
                    temp->next = temp2->next; //assign table[idx] temp's next to (to be deleted node's next)
                    temp2->next = NULL;// make to be deleted node's next to NULL'
                    delete temp2;
                    //here we will not reduce current size bcoz all keys are not removed
                    return;
                }
                temp = temp->next;
            }
        }

};

int main()
{
    Hashtable<int> price_menu;
    // price_menu.insert("Burger",120);
    // price_menu.insert("Pepsi",20);
    // price_menu.insert("BurgerPizza",150);
    // price_menu.insert("Noodles",25);
    // price_menu.insert("Coke",40);
    // price_menu.insert("Cokonut",80);
    // price_menu.insert("Cok",90);
    price_menu.insert("Geeks",1);
    price_menu.insert("forGeeks",2);
    price_menu.insert("A",3);
    price_menu.insert("Computer",4);
    price_menu.insert("Portal",5);

    //easily insert update and search
    price_menu["Dosa"] = 60;
    price_menu["Dosa"] += 10;

    price_menu.print();
    cout<<"Current size of hashmap is: "<<price_menu.current_size<<endl;


    //SEARCHING IN HASHMAP
    // int *price = price_menu.search("Computer");

    // if(*price == NULL) //or simply use when [] overloaded: price_menu["key"]
    // {
    //     cout<<"NOT FOUND";
    // }
    // else
    // {
    //     cout<<"Price is: "<<*price<<endl;
    // }

    // cout<<"Price of dosa is: "<<price_menu["Dosa"]<<endl;

    //ERASE A PARTICULAR KEY
    price_menu.erase("Portal");

    //again print
    cout<<endl;
    price_menu.print(); //if geeks is deleted thrn current_size is original -1
    cout<<"Current size of hashmap is: "<<price_menu.current_size<<endl;

    return 0;
}

//Easy Access using [] operator
/*
    1. Updating hashtable

        a) Insertion: price_menu["DOSA"] = 60; it will chk if dosa is present. If yes then price updated, if not then inserted newly
        b)Updating: price_menu["DOSA"]+=10;
        c)Search: price_menu["DOSA"];

    Now, the above 3 tasks can be done easily by overloading [] operator
         we will return reference to the box which contains key  |NEXT
                                                            value|
*/