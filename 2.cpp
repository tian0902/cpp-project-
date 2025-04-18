#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};
class LinkList{
    private:
    Node* head;
    public:
    LinkList():head(nullptr){}
    ~LinkList(){clear();}
    void insertAthead(int val){
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            return;
        }
        newnode->next=head;
        head=newnode;
    }
    void insertAttail(int val){
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            return;
        }
        Node* current=head;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newnode;
    }
    void deleteNode(int val){
        Node* current=head;
        if(head==nullptr){
            return;
        }
        if(head->data==val){
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        while(current->next!=nullptr&&current->next->data!=val){
            current=current->next;
        }
        if(current->next==nullptr){
            return;
        }
        Node* temp=current->next;
        current->next=current->next->next;
        delete temp;

    }
    Node* search(int val){
        Node* current=head;
        if(head==nullptr){
            return nullptr;
        }
        while(current!=nullptr){
            if(current->data==val){
                return current;
            }
            current=current->next;
        }
        return nullptr;
    }
    void printList(){
        Node* current=head;
        if(head==nullptr){
            return;
        }
        while(current!=nullptr){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    void clear(){
        Node* current=head;
        while(current!=nullptr){
            Node* temp=current;
            current=current->next;
            delete temp;
        }
        head=nullptr;
    }
};
int main(){
    LinkList list;
    list.insertAthead(10);
    list.insertAthead(20);
    list.insertAthead(30);
    list.insertAttail(40);
    list.insertAttail(50);
    list.printList();
    list.deleteNode(30);
    list.printList();
    Node* found=list.search(40);
    if(found!=nullptr){
        cout<<"Found: "<<found->data<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    list.clear();
    list.printList();
}