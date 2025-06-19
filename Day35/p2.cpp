#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countHeights(vector<int> &h)
{
  vector<int> freq(10001, 0);
  int count = 0;

  for (int i = 0; i < h.size(); i++)
  {
    freq[h[i]]++;
  }

  for (int i = 0; i < freq.size(); i++)
  {
    if (freq[i] > 1)
    {
      count++;
    }
  }
  return count;
}

int main()
{
  int n;
  cout << "Enter number of students: ";
  cin >> n;

  vector<int> h(n);
  cout << "Enter highness values of students: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  int res = countHeights(h);

  cout << "Number of that appear more than once: " << res << endl;

  return 0;
}