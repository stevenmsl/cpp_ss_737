#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol737;
using namespace std;

/*takeaways
  - main difference when comparing to question 734 is that
    transitive is allowed here
  - use union find to group similar words into a set
*/

void SWSet::Union(const string &w1, const string &w2)
{
  auto p1 = Find(w1);
  auto p2 = Find(w2);

  if (p1 == w1 && !parent.count(w1))
    parent[p1] = w1;

  /* merge two sets into one with
     p1 being the parent
     - this already includes the case
       where w2 is not in the set yet
     - if p2 == w2, either w2 is not
       in the set yet or it is the
       root of the set it is in
     - parent[p2] = p1 will take
       care of both cases
  */
  parent[p2] = p1;
}
const string SWSet::Find(const string &w)
{
  /* make the find method easier to use
     - if you are not in any set
       it's the same as you are
       in a set that includes
       you as the only member
  */
  if (!parent.count(w))
    return w;

  auto p = w;
  /* find the root of the set*/
  while (parent[p] != p)
    p = parent[p];
  return p;
}

bool Solution::isSimilar(vector<string> &ws1, vector<string> &ws2,
                         vector<pair<string, string>> pairs)
{
  if (ws1.size() != ws2.size())
    return false;

  SWSet ss;

  for (auto &[w1, w2] : pairs)
    ss.Union(w1, w2);

  for (auto i = 0; i < ws1.size(); i++)
    if (ss.Find(ws1[i]) != ss.Find(ws2[i]))
      return false;

  return true;
}