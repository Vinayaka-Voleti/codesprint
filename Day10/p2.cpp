#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
struct ListNode{
  int val;
  ListNode * next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr){}
  ListNode(int x, ListNode *next) : val(x), next(next){}
};
ListNode* delDups(ListNode* head){
  ListNode* current = head;
  while ( current && current->next){
    if(current->val == current->next->val){
      ListNode* temp = current->next;
      current->next = current->next->next;
      delete temp;
    } else{
      current = current->next;
    }
  }
  return head;
}
void print(ListNode* head){
  ListNode* current = head;
  while(current){
    cout << current->val;
    if(current->next) cout << "->";
    current = current->next;
  }
  cout << endl;
}
ListNode* create(const vector<int> &values){
  if(values.empty()) return nullptr;
  ListNode* head = new ListNode(values[0]);
  ListNode* current = head;
  for(size_t i = 1; i<values.size(); i++){
    current->next = new ListNode(values[i]);
    current = current->next;
  }
  return head;
}
vector<int> Input(const string& input){
  vector<int> values;
  istringstream iss(input);
  int num;
  while(iss >> num){
    values.push_back(num);
  }
  return values;
}
int main(){
  string input;
  getline(cin, input);
  vector<int> values = Input(input);
  ListNode* head = create(values);
  ListNode* result = delDups(head);
  print(result);
  while(result){
    ListNode* temp = result;
    result = result->next;
    delete temp;
  }
}