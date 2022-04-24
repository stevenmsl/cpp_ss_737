
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
namespace sol737
{

  class SWSet
  {

  private:
    unordered_map<string, string> parent;

  public:
    void Union(const string &w1, const string &w2);
    const string Find(const string &w);
  };

  class Solution
  {
  private:
  public:
    bool isSimilar(vector<string> &ws1, vector<string> &ws2, vector<pair<string, string>> pairs);
  };
}
#endif