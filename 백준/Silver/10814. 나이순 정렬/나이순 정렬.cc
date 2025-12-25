#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
  int age;
  string name;
  int index;

  bool operator<(const Info& other) const {
    if(age == other.age) {
      return index < other.index;
    }

    return age < other.age;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<Info> informations(n);

  for(int i = 0; i < n; i++) {
    cin >> informations[i].age >> informations[i].name;

    informations[i].index = i;
  }

  sort(informations.begin(), informations.end());

  for(auto [age, name, index]: informations) {
    cout << age << " " << name << "\n";
  }

  return 0;
}